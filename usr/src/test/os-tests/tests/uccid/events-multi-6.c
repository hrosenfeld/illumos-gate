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
 * Verify that we can dissociate from the port in the parent and that
 * the child won't be able to receive events anymore.
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
	char p = '\0';
	int fd, port, ret, pfd[2];

	fd = open_ccid(argc, argv);

	port = create();

	setup(fd, &ce);

	associate(port, &ce, UCCID_EVENTS_DESIRED);

	if (pipe(pfd) != 0) {
		err(EXIT_FAILURE, "failed to create pipe");
	}

	pid = fork();

	if (pid == -1) {
		err(EXIT_FAILURE, "failed to fork");
	}

	if (pid != 0) {
		dissociate(port, &ce);

		/* signal child that we have dissociated */
		if (write(pfd[1], &p, 1) != 1)
			err(EXIT_FAILURE, "failed to write 1 byte to pipe");

		if (wait(&ret) != pid)
			err(EXIT_FAILURE, "failed to get child status");

		if (ret != 0)
			return (ret >> 8);

		return (0);
	}

	pid = getpid();

	/* wait for parent to dissociate */
	if (read(pfd[0], &p, 1) != 1) {
		perr(EXIT_FAILURE, "failed to read 1 byte from pipe");
	}

	getn(port, pe, NEVENT, &npe, &to);

	VERIFY3S(npe, ==, 0);

	begin_txn(fd);

	getn(port, pe, NEVENT, &npe, &to);

	VERIFY3S(npe, ==, 0);

	return (0);
}
