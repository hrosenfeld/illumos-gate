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

#ifndef _TESTS_UCCID_UCCID_H
#define	_TESTS_UCCID_UCCID_H

#include <stdint.h>
#include <unistd.h>

#include "perr.h"

#ifdef __cplusplus
extern "C" {
#endif

static inline int
open_ccid(int argc, char **argv)
{
	int fd;

	if (argc != 2)
		errx(EXIT_FAILURE, "missing required ccid path");

	if ((fd = open(argv[1], O_RDWR | O_EXCL)) < 0)
		err(EXIT_FAILURE, "failed to open %s", argv[1]);

	return (fd);
}

static inline void
begin_txn(int fd)
{
	uccid_cmd_txn_begin_t begin = { .uct_version = UCCID_CURRENT_VERSION };

	if (ioctl(fd, UCCID_CMD_TXN_BEGIN, &begin) != 0)
		err(EXIT_FAILURE, "failed to issue begin ioctl");
}

static inline void
end_txn(int fd, int flags)
{
	uccid_cmd_txn_end_t end = {
		.uct_version = UCCID_CURRENT_VERSION,
		.uct_flags = flags
	};

	if (ioctl(fd, UCCID_CMD_TXN_END, &end) != 0)
		err(EXIT_FAILURE, "failed to issue end ioctl");
}

static inline void
status(int fd, uccid_cmd_status_t *status)
{
	bzero(status, sizeof (uccid_cmd_status_t));
	status->ucs_version = UCCID_CURRENT_VERSION;

	if (ioctl(fd, UCCID_CMD_STATUS, status) != 0)
		err(EXIT_FAILURE, "failed to issue status ioctl");
}

#ifdef __cplusplus
}
#endif

#endif /* _TESTS_UCCID_UCCID_H */
