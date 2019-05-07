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
 * Verify that we can close a device with a port still associated and then
 * can no longer receive any outstanding events.
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
	timespec_t to = { .tv_sec = 1, .tv_nsec = 0 };
	uccid_event_t ce;
	port_event_t pe;
	int fd, port;
	uint_t npe;

	fd = open_ccid(argc, argv);

	port = create();

	setup(fd, &ce);

	associate(port, &ce, UCCID_EVENTS_DESIRED);

	(void) close(fd);

	get_fail(port, &pe, &to);

	getn_fail(port, &pe, 1, &npe, &to);

	dissociate(port, &ce);

	return (0);
}
