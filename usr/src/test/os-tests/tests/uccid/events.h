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

#ifndef _TESTS_UCCID_EVENTS_H
#define	_TESTS_UCCID_EVENTS_H

#include <sys/debug.h>
#include <port.h>

#include <sys/usb/clients/ccid/uccid.h>

#include "perr.h"

#ifdef __cplusplus
extern "C" {
#endif

#define	UCCID_EVENTS_DESIRED			\
	(UCCID_EVENT_ICC_INSERTED |		\
	UCCID_EVENT_ICC_REMOVED |		\
	UCCID_EVENT_ICC_POWERED_ON |		\
	UCCID_EVENT_ICC_POWERED_OFF |		\
	UCCID_EVENT_TRANSACTION_READY |		\
	UCCID_EVENT_COMMAND_SUBMISSION_READY |	\
	UCCID_EVENT_COMMAND_COMPLETED)

#define	UCCID_EVENT_INSERTED_ON \
	(UCCID_EVENT_ICC_INSERTED | UCCID_EVENT_ICC_POWERED_ON)

#define	UCCID_EVENT_READY \
	(UCCID_EVENT_COMMAND_SUBMISSION_READY | \
	UCCID_EVENT_ICC_INSERTED | UCCID_EVENT_ICC_POWERED_ON)

#define	UCCID_EVENT_READY_INSERTED_ON \
	(UCCID_EVENT_TRANSACTION_READY | UCCID_EVENT_ICC_INSERTED |	\
	UCCID_EVENT_ICC_POWERED_ON)

#define	UCCID_EVENT_AFTER_RESET \
	(UCCID_EVENT_ICC_POWERED_OFF | UCCID_EVENT_ICC_POWERED_ON |	\
	UCCID_EVENT_ICC_INSERTED)

static inline void
verify(int fd, port_event_t *pe, uccid_event_t *ce)
{
	VERIFY3U(pe->portev_source, ==, PORT_SOURCE_DEVICE);
	VERIFY3P(pe->portev_object, ==, ce);
	VERIFY3P(pe->portev_user, ==, NULL);

	VERIFY3S(ce->ce_dev_obj.do_fd, ==, fd);
	VERIFY3U(ce->ce_version, ==, UCCID_VERSION_ONE);
	VERIFY3U(ce->ce_size, ==, sizeof (uccid_event_t));
}

static inline void
setup(int fd, uccid_event_t *ce)
{
	bzero(ce, sizeof (uccid_event_t));
	ce->ce_dev_obj.do_version = PORT_DEVICE_VERSION_1;
	ce->ce_dev_obj.do_fd = fd;
	ce->ce_version = UCCID_VERSION_ONE;
	ce->ce_size = sizeof (uccid_event_t);
}

static inline void
check(int fired, int desired)
{
	if ((fired & desired) != desired)
		perr(EXIT_FAILURE, "events mismatch, expected %x, got %x",
		    desired, fired);
}

static inline int
create(void)
{
	int port;

	if ((port = port_create()) == -1)
		perr(EXIT_FAILURE, "failed to create event port: %d", port);

	return (port);
}

static inline void
associate(int port, uccid_event_t *ce, int events)
{
	if (port_associate(port, PORT_SOURCE_DEVICE, (uintptr_t)ce,
	    events, NULL) != 0)
		perr(EXIT_FAILURE, "failed to associate");
}

static inline void
get(int port, port_event_t *pe, const timespec_t *to)
{
	if (port_get(port, pe, to) != 0)
		perr(EXIT_FAILURE, "failed to port_get()");
}

static inline void
get_fail(int port, port_event_t *pe, const timespec_t *to)
{
	if (port_get(port, pe, to) == 0)
		perr(EXIT_FAILURE, "unexpectedly succeeded to port_get()");
}

static inline void
getn(int port, port_event_t *pe, uint_t n, uint_t *npe, timespec_t *to)
{
	*npe = n;

	if (port_getn(port, pe, n, npe, to) != 0)
		perr(EXIT_FAILURE, "failed to port_get()");
}

static inline void
getn_fail(int port, port_event_t *pe, uint_t n, uint_t *npe, timespec_t *to)
{
	*npe = n;

	if (port_getn(port, pe, n, npe, to) == 0)
		perr(EXIT_FAILURE, "unexpectedly succeeded to port_getn()");
}

static inline void
dissociate(int port, uccid_event_t *ce)
{
	if (port_dissociate(port, PORT_SOURCE_DEVICE, (uintptr_t)ce) != 0) {
		perr(EXIT_FAILURE, "failed to dissociate");
	}
}

static inline void
dissociate_fail(int port, uccid_event_t *ce)
{
	if (port_dissociate(port, PORT_SOURCE_DEVICE, (uintptr_t)ce) == 0) {
		perr(EXIT_FAILURE, "unexpectedly succeeded to dissociate");
	}
}

#ifdef __cplusplus
}
#endif

#endif /* _TESTS_UCCID_EVENTS_H */
