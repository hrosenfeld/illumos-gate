#!/usr/sbin/dtrace -s
/*
 * CDDL HEADER START
 *
 * The contents of this file are subject to the terms of the
 * Common Development and Distribution License (the "License").
 * You may not use this file except in compliance with the License.
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
 * Copyright (c) 2010, Oracle and/or its affiliates. All rights reserved.
 */

tcp:::connect-established
{
	start[args[1]->cs_cid] = timestamp;
}

tcp:::receive
/start[args[1]->cs_cid] && (args[2]->ip_plength - args[4]->tcp_offset) > 0/
{
	@latency["1st Byte Latency (ns)", args[2]->ip_saddr] =
	    quantize(timestamp - start[args[1]->cs_cid]);
	start[args[1]->cs_cid] = 0;
}
