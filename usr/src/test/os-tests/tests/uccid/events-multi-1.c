/*
 * This file and its contents are supplied under the terms of the
 * Common Development and Distribution License ("CDDL"), version 1.0.
 * You may only use this file in accordance with the terms of version
 * 1.0 of the CDDL.
 *
 * A full copy of the text of the CDDL should have accompanied this
 * source.  A copy of the CDDL is also available via the Internet at
 * http://www.illumos.org/license/CDDL.
 */

/*
 * Copyright 2019, Joyent, Inc.
 */

/*
 * Verify that four processes can open the same device and receive
 * events whenever the device is ready.
 */

#include <err.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <strings.h>
#include <unistd.h>
#include <errno.h>
#include <sys/debug.h>
#include <poll.h>
#include <port.h>

#include <sys/usb/clients/ccid/uccid.h>

#include "perr.h"
#include "events.h"
#include "uccid.h"
#include "yk.h"

static void
read_from_yk(int fd, int port, uccid_event_t *ce)
{
	port_event_t pe;

	get(port, &pe, NULL);

	verify(fd, &pe, ce);

	check(pe.portev_events, UCCID_EVENT_INSERTED_ON);

	VERIFY3U(ce->ce_icc_insert_gen, >, ce->ce_icc_remove_gen);
	VERIFY3U(ce->ce_icc_on_gen, >, ce->ce_icc_off_gen);

	while ((pe.portev_events & UCCID_EVENT_TRANSACTION_READY) == 0) {
		get(port, &pe, NULL);

		verify(fd, &pe, ce);
	}

	begin_txn(fd);

	get(port, &pe, NULL);

	verify(fd, &pe, ce);

	while ((pe.portev_events & UCCID_EVENT_COMMAND_SUBMISSION_READY) == 0) {
		get(port, &pe, NULL);

		verify(fd, &pe, ce);
	}

	write_yk(fd);

	get(port, &pe, NULL);

	verify(fd, &pe, ce);

	check(pe.portev_events, UCCID_EVENT_COMMAND_COMPLETED);

	read_yk(fd);

	get(port, &pe, NULL);

	verify(fd, &pe, ce);

	check(pe.portev_events, UCCID_EVENT_COMMAND_SUBMISSION_READY);

	end_txn(fd, UCCID_TXN_END_RESET);

	get(port, &pe, NULL);

	verify(fd, &pe, ce);

	check(pe.portev_events, UCCID_EVENT_AFTER_RESET);

	VERIFY3U(ce->ce_icc_insert_gen, >, ce->ce_icc_remove_gen);
	VERIFY3U(ce->ce_icc_on_gen, >, ce->ce_icc_off_gen);

	get(port, &pe, NULL);

	verify(fd, &pe, ce);

	check(pe.portev_events, UCCID_EVENT_TRANSACTION_READY);
}

int
main(int argc, char *argv[])
{
	uccid_event_t ce;
	int fd, port, i;

	if (fork() == -1) {
		err(EXIT_FAILURE, "failed to fork child process");
	}

	if (fork() == -1) {
		err(EXIT_FAILURE, "failed to fork child process");
	}

	pid = getpid();

	port = create();

	fd = open_ccid(argc, argv);

	setup(fd, &ce);

	associate(port, &ce, UCCID_EVENTS_DESIRED);

	for (i = 0; i != 10; i++)
		read_from_yk(fd, port, &ce);

	dissociate(port, &ce);

	return (0);
}
