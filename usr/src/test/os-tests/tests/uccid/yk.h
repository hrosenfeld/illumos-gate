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

#ifndef _TESTS_UCCID_YK_H
#define	_TESTS_UCCID_YK_H

#include <stdint.h>
#include <unistd.h>
#include <sys/debug.h>

#include "perr.h"

#ifdef __cplusplus
extern "C" {
#endif

static const uint8_t yk_req[] = {
	0x00, 0xa4, 0x04, 0x00, 0x07, 0xa0, 0x00, 0x00, 0x05, 0x27, 0x20, 0x01
};

static const uint8_t yk_ans[] = {
	0x04, 0x03, 0x07, 0x01, 0x05, 0x00, 0x06, 0x0f, 0x00, 0x00, 0x90, 0x00
};

static inline void
write_yk(int fd)
{
	if (write(fd, yk_req, sizeof (yk_req)) < 0)
		perr(EXIT_FAILURE, "failed to write data");
}

static inline void
read_yk(int fd)
{
	uint8_t buf[UCCID_APDU_SIZE_MAX];
	int ret;

	if ((ret = read(fd, buf, sizeof (buf))) < 0) {
		err(EXIT_FAILURE, "failed to read data");
	}

	VERIFY3S(ret, ==, sizeof (yk_ans));

	VERIFY3S(memcmp(buf, yk_ans, sizeof (yk_ans)), ==, 0);
}

#ifdef __cplusplus
}
#endif

#endif /* _TESTS_UCCID_YK_H */
