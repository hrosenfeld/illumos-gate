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
 * Verify that we can update the object by associating again, and that an
 * increased generation number causes the respective event to be ignored.
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

#include "events.h"
#include "uccid.h"

#define	NEVENT 10

int
main(int argc, char *argv[])
{
	port_event_t pe[NEVENT] = { 0 };
	uccid_event_t ce = { 0 };
	timespec_t to = { 0 };
	uint_t npe = NEVENT;
	uccid_cmd_status_t cs;
	int fd, port;

	fd = open_ccid(argc, argv);

	port = create();

	begin_txn(fd);

	setup(fd, &ce);

	associate(port, &ce, UCCID_EVENTS_DESIRED);

	(void) sleep(1);

	getn(port, pe, NEVENT, &npe, &to);

	/*
	 * There should be one event ready indicating that the ICC is
	 * inserted, powered on, and ready for command submission.
	 */
	VERIFY3U(npe, ==, 1);

	verify(fd, &pe[0], &ce);
	check(pe[0].portev_events, UCCID_EVENT_READY);

	status(fd, &cs);

	/*
	 * Reset causes two events, one for powering the card off
	 * and another one for insert/power on. Skip both by increasing
	 * the generation numbers.
	 */
	ce.ce_icc_off_gen = ce.ce_icc_insert_gen = ce.ce_icc_on_gen =
	    cs.ucs_gen + 2;

	associate(port, &ce, UCCID_EVENTS_DESIRED);

	end_txn(fd, UCCID_TXN_END_RESET);

	(void) sleep(1);

	getn(port, pe, NEVENT, &npe, &to);

	/*
	 * Now there should be just one event indicating that
	 * the device is ready for a transaction.
	 */
	VERIFY3U(npe, ==, 1);
	verify(fd, &pe[0], &ce);
	check(pe[0].portev_events, UCCID_EVENT_TRANSACTION_READY);

	return (0);
}
