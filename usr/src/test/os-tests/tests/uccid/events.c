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
 * Verify that we can receive events from the device.
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

int
main(int argc, char *argv[])
{
	uccid_event_t ce;
	port_event_t pe;
	int fd, port;

	fd = open_ccid(argc, argv);

	port = create();

	setup(fd, &ce);

	associate(port, &ce, UCCID_EVENTS_DESIRED);

	get(port, &pe, NULL);

	dissociate(port, &ce);

	verify(fd, &pe, &ce);

	check(pe.portev_events, UCCID_EVENT_READY_INSERTED_ON);

	return (0);
}
