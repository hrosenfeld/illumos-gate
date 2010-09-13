
/* : : generated by proto : : */
/***********************************************************************
*                                                                      *
*               This software is part of the ast package               *
*          Copyright (c) 1985-2010 AT&T Intellectual Property          *
*                      and is licensed under the                       *
*                  Common Public License, Version 1.0                  *
*                    by AT&T Intellectual Property                     *
*                                                                      *
*                A copy of the License is available at                 *
*            http://www.opensource.org/licenses/cpl1.0.txt             *
*         (with md5 checksum 059e8cd6165cb4c31e351f2b69388fd9)         *
*                                                                      *
*              Information and Software Systems Research               *
*                            AT&T Research                             *
*                           Florham Park NJ                            *
*                                                                      *
*                 Glenn Fowler <gsf@research.att.com>                  *
*                  David Korn <dgk@research.att.com>                   *
*                   Phong Vo <kpv@research.att.com>                    *
*                                                                      *
***********************************************************************/
                  

/*
 * Glenn Fowler
 * AT&T Research
 *
 * character code map interface
 *
 * NOTE: used for mapping between 8-bit character encodings
 *	 ISO character sets are handled by sfio
 */

#ifndef _CHARCODE_H
#if !defined(__PROTO__)
#include <prototyped.h>
#endif
#if !defined(__LINKAGE__)
#define __LINKAGE__		/* 2004-08-11 transition */
#endif

#define _CHARCODE_H	1

#include <ast_common.h>
#include <ast_ccode.h>

typedef struct Ccmap_s
{
	const char*	name;	/* code set name		*/
	const char*	match;	/* strmatch() pattern		*/
	const char*	desc;	/* code set description		*/
	const char*	canon;	/* canonical name format	*/
	const char*	index;	/* default index		*/
	int		ccode;	/* <ccode.h> code index		*/
	__V_*		data;	/* map specific data		*/
} Ccmap_t;

#if _BLD_ast && defined(__EXPORT__)
#undef __MANGLE__
#define __MANGLE__ __LINKAGE__		__EXPORT__
#endif

extern __MANGLE__ unsigned char*	_ccmap __PROTO__((int, int));
extern __MANGLE__ __V_*		_ccmapcpy __PROTO__((unsigned char*, __V_*, const __V_*, size_t));
extern __MANGLE__ __V_*		_ccmapstr __PROTO__((unsigned char*, __V_*, size_t));

extern __MANGLE__ int		ccmapid __PROTO__((const char*));
extern __MANGLE__ char*		ccmapname __PROTO__((int));
extern __MANGLE__ __V_*		ccnative __PROTO__((__V_*, const __V_*, size_t));
extern __MANGLE__ Ccmap_t*		ccmaplist __PROTO__((Ccmap_t*));

#undef __MANGLE__
#define __MANGLE__ __LINKAGE__

#define CCOP(i,o)		((i)==(o)?0:(((o)<<8)|(i)))
#define CCIN(x)			((x)&0xFF)
#define CCOUT(x)		(((x)>>8)&0xFF)
#define CCCONVERT(x)		((x)&0xFF00)

#define CCCVT(x)		CCMAP(x,0)
#define CCMAP(i,o)		((i)==(o)?(unsigned char*)0:_ccmap(i,o))
#define CCMAPCHR(m,c)		((m)?(m)[c]:(c))
#define CCMAPCPY(m,t,f,n)	((m)?_ccmapcpy(m,t,f,n):memcpy(t,f,n))
#define CCMAPSTR(m,s,n)		((m)?_ccmapstr(m,s,n):(__V_*)(s))

#define ccmap(i,o)		CCMAP(i,o)
#define ccmapchr(m,c)		CCMAPCHR(m,c)
#define ccmapcpy(m,t,f,n)	CCMAPCPY(m,t,f,n)
#define ccmapstr(m,s,n)		CCMAPSTR(m,s,n)

#define CCMAPC(c,i,o)		((i)==(o)?(c):CCMAP(i,o)[c])
#define CCMAPM(t,f,n,i,o)	((i)==(o)?memcpy(t,f,n):_ccmapcpy(CCMAP(i,o),t,f,n))
#define CCMAPS(s,n,i,o)		((i)==(o)?(__V_*)(s):_ccmapstr(CCMAP(i,o),s,n))

#define ccmapc(c,i,o)		CCMAPC(c,i,o)
#define ccmapm(t,f,n,i,o)	CCMAPM(t,f,n,i,o)
#define ccmaps(s,n,i,o)		CCMAPS(s,n,i,o)

#endif
