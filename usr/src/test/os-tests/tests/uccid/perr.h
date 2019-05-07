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

#ifndef _TESTS_UCCID_PERR_H
#define	_TESTS_UCCID_PERR_H

#include <sys/types.h>
#include <err.h>
#include <stdarg.h>

#ifdef __cplusplus
extern "C" {
#endif

static pid_t pid;

static inline void
perr(int eval, char *fmt, ...)
{
	va_list ap;

	va_start(ap, fmt);

	if (pid != 0)
		(void) asprintf(&fmt, "pid %d: %s", pid, fmt);

	verr(eval, fmt, ap);
	/* verr never returns, don't bother freeing fmt */
}

#ifdef __cplusplus
}
#endif

#endif /* _TESTS_UCCID_PERR_H */
