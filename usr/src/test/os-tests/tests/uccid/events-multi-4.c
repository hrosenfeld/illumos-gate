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
 * Verify that we can associate the same fd twice on different ports using
 * different objects.
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
	int fd, port, port2;
	uccid_event_t ce, ce2;

	fd = open_ccid(argc, argv);

	port = create();

	port2 = create();

	setup(fd, &ce);

	associate(port, &ce, UCCID_EVENTS_DESIRED);

	setup(fd, &ce2);

	associate(port2, &ce2, UCCID_EVENTS_DESIRED);

	return (0);
}
