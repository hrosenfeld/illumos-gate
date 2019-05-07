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
 * Verify that all events generated after fork are received by the parent.
 */

#include <err.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
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

#define	NEVENT 10

int
main(int argc, char *argv[])
{
	uccid_event_t ce = { 0 };
	port_event_t pe[NEVENT] = { 0 };
	timespec_t to = { 0 };
	uint_t npe = NEVENT;
	boolean_t parent = B_FALSE;
	int ret = 0;
	int fd, port;

	fd = open_ccid(argc, argv);

	port = create();

	setup(fd, &ce);

	associate(port, &ce, UCCID_EVENTS_DESIRED);

	pid = fork();
	if (pid == -1) {
		err(EXIT_FAILURE, "failed to fork");
	}

	if (pid != 0)
		parent = B_TRUE;

	pid = getpid();

	getn(port, pe, NEVENT, &npe, &to);

	if (parent) {
		VERIFY3U(npe, !=, 0);
		verify(fd, &pe[0], &ce);
	} else {
		VERIFY3U(npe, ==, 0);
	}

	begin_txn(fd);

	getn(port, pe, NEVENT, &npe, &to);

	if (parent) {
		VERIFY3U(npe, !=, 0);
		verify(fd, &pe[0], &ce);
	} else {
		VERIFY3U(npe, ==, 0);
	}

	end_txn(fd, UCCID_TXN_END_RESET);

	if (parent)
		if (wait(&ret) == -1)
			perr(EXIT_FAILURE, "failed to get child status");

	getn(port, pe, NEVENT, &npe, &to);

	if (parent) {
		VERIFY3U(npe, !=, 0);
		verify(fd, &pe[0], &ce);
	} else {
		VERIFY3U(npe, ==, 0);
	}

	return (ret >> 8);
}
