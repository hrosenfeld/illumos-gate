/*
 * CDDL HEADER START
 *
 * The contents of this file are subject to the terms of the
 * Common Development and Distribution License, Version 1.0 only
 * (the "License").  You may not use this file except in compliance
 * with the License.
 *
 * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE
 * or http://www.opensolaris.org/os/licensing.
 * See the License for the specific language governing permissions
 * and limitations under the License.
 *
 * When distributing Covered Code, include this CDDL HEADER in each
 * file and include the License file at usr/src/OPENSOLARIS.LICENSE.
 * If applicable, add the following below this CDDL HEADER, with the
 * fields enclosed by brackets "[]" replaced with your own identifying
 * information: Portions Copyright [yyyy] [name of copyright owner]
 *
 * CDDL HEADER END
 */
/*
 * Copyright (c) 1985,1997-1998 by Sun Microsystems, Inc.
 * All rights reserved.
 */

/*
 * This file describes a virtual user input device (vuid) state
 * maintainence package (see ../sundev/vuid_event.h for a description
 * of what vuid is).  This header file defines the interface that a
 * client of this package sees.	 This package is used to maintain the
 * state of all the events generated by an arbitrary number of physical
 * devices which are all producing Firm_events.
 */

#ifndef _SYS_VUID_STATE_H
#define	_SYS_VUID_STATE_H

#pragma ident	"%Z%%M%	%I%	%E% SMI"	/* SunOS 1.5 */

#ifdef	__cplusplus
extern "C" {
#endif

typedef caddr_t Vuid_state;
#define	VUID_STATE_NULL ((Vuid_state)0)

void	vuid_set_value();	/* (Vuid_state *state, Firm_event *event) */
				/* Don't call in critical section or */
				/* at interrupt level */
int	vuid_get_value();	/* (Vuid_state state, ushort_t id) */
void	vuid_destroy_state();	/* (Vuid_state state) Don't call in critical */
				/* section or at interrupt level */
Vuid_state vuid_copy_state();	/* (Vuid_state state) Don't call in critical */
				/* section or at interrupt level */

#ifdef	__cplusplus
}
#endif

#endif	/* _SYS_VUID_STATE_H */
