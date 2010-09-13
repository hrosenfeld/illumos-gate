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

/* : : generated by proto : : */
/* : : generated from /home/gisburn/ksh93/ast_ksh_20100309/build_sparc_32bit/src/lib/libast/features/map.c by iffe version 2009-12-04 : : */
#ifndef _def_map_ast
#if !defined(__PROTO__)
#  if defined(__STDC__) || defined(__cplusplus) || defined(_proto) || defined(c_plusplus)
#    if defined(__cplusplus)
#      define __LINKAGE__	"C"
#    else
#      define __LINKAGE__
#    endif
#    define __STDARG__
#    define __PROTO__(x)	x
#    define __OTORP__(x)
#    define __PARAM__(n,o)	n
#    if !defined(__STDC__) && !defined(__cplusplus)
#      if !defined(c_plusplus)
#      	define const
#      endif
#      define signed
#      define void		int
#      define volatile
#      define __V_		char
#    else
#      define __V_		void
#    endif
#  else
#    define __PROTO__(x)	()
#    define __OTORP__(x)	x
#    define __PARAM__(n,o)	o
#    define __LINKAGE__
#    define __V_		char
#    define const
#    define signed
#    define void		int
#    define volatile
#  endif
#  define __MANGLE__	__LINKAGE__
#  if defined(__cplusplus) || defined(c_plusplus)
#    define __VARARG__	...
#  else
#    define __VARARG__
#  endif
#  if defined(__STDARG__)
#    define __VA_START__(p,a)	va_start(p,a)
#  else
#    define __VA_START__(p,a)	va_start(p)
#  endif
#  if !defined(__INLINE__)
#    if defined(__cplusplus)
#      define __INLINE__	extern __MANGLE__ inline
#    else
#      if defined(_WIN32) && !defined(__GNUC__)
#      	define __INLINE__	__inline
#      endif
#    endif
#  endif
#endif
#if !defined(__LINKAGE__)
#define __LINKAGE__		/* 2004-08-11 transition */
#endif

#define _def_map_ast	1
#define _sys_types	1	/* #include <sys/types.h> ok */
                  

/*
 * prototypes provided for standard interfaces hijacked
 * by ast and mapped to _ast_* but already prototyped
 * unmapped in native headers included by <ast_std.h>
 */

#if _BLD_ast && defined(__EXPORT__)
#undef __MANGLE__
#define __MANGLE__ __LINKAGE__		__EXPORT__
#endif


#define	_map_libc	1
#undef	basename
#define basename	_ast_basename
#undef	dirname
#define dirname		_ast_dirname
#undef	eaccess
#define eaccess		_ast_eaccess
#undef	execvpe
#define execvpe		_ast_execvpe
extern __MANGLE__ int		execvpe __PROTO__((const char*, char* const[], char* const[]));
#undef	fnmatch
#define fnmatch		_ast_fnmatch
#undef	fts_children
#define fts_children    _ast_fts_children
#undef	fts_close
#define fts_close       _ast_fts_close
#undef	fts_flags
#define fts_flags       _ast_fts_flags
#undef	fts_notify
#define fts_notify      _ast_fts_notify
#undef	fts_open
#define fts_open	_ast_fts_open
#undef	fts_read
#define fts_read	_ast_fts_read
#undef	fts_set
#define fts_set		_ast_fts_set
#undef	ftw
#define ftw		_ast_ftw
#undef	ftwalk
#define ftwalk		_ast_ftwalk
#undef	ftwflags
#define ftwflags	_ast_ftwflags
#undef	getcwd
#define getcwd		_ast_getcwd
extern __MANGLE__ char*		getcwd __PROTO__((char*, size_t));
#undef	getdate
#define getdate		_ast_getdate
#undef	getopt
#define getopt		_ast_getopt
#undef	getsubopt
#define getsubopt       _ast_getsubopt
#undef	getopt_long
#define getopt_long	_ast_getopt_long
#undef	getopt_long_only
#define getopt_long_only _ast_getopt_long_only
#undef	optopt
#define optopt		_ast_optopt
#undef	optarg
#define optarg		_ast_optarg
#undef	optind
#define optind		_ast_optind
#undef	opterr
#define opterr		_ast_opterr
#undef	getwd
#define getwd		_ast_getwd
extern __MANGLE__ char*		getwd __PROTO__((char*));
#undef	glob
#define glob		_ast_glob
#undef	globfree
#define globfree	_ast_globfree
#undef	memdup
#define memdup		_ast_memdup
#undef	memfatal
#define memfatal	_ast_memfatal
#undef	memhash
#define memhash		_ast_memhash
#undef	memsum
#define memsum		_ast_memsum
#undef	mkstemp
#define mkstemp		_ast_mkstemp
extern __MANGLE__ int		mkstemp __PROTO__((char*));
#undef	mktemp
#define mktemp		_ast_mktemp
extern __MANGLE__ char*		mktemp __PROTO__((char*));
#undef	mktime
#define mktime		_ast_mktime
#undef	nftw
#define nftw		_ast_nftw
#undef	optctx
#define optctx		_ast_optctx
#undef	optesc
#define optesc		_ast_optesc
#undef	optget
#define optget		_ast_optget
#undef	opthelp
#define opthelp		_ast_opthelp
#undef	optjoin
#define optjoin		_ast_optjoin
#undef	optstr
#define optstr		_ast_optstr
#undef	optusage
#define optusage	_ast_optusage
#undef	pathaccess
#define pathaccess	_ast_pathaccess
#undef	pathbin
#define pathbin		_ast_pathbin
#undef	pathcanon
#define pathcanon	_ast_pathcanon
#undef	pathcat
#define pathcat		_ast_pathcat
#undef	pathcd
#define pathcd		_ast_pathcd
#undef	pathcheck
#define pathcheck	_ast_pathcheck
#undef	pathexists
#define pathexists	_ast_pathexists
#undef	pathfind
#define pathfind	_ast_pathfind
#undef	pathgetlink
#define pathgetlink	_ast_pathgetlink
#undef	pathinclude
#define pathinclude	_ast_pathinclude
#undef	pathkey
#define pathkey		_ast_pathkey
#undef	pathnative
#define pathnative	_ast_pathnative
#undef	pathpath
#define pathpath	_ast_pathpath
#undef	pathposix
#define pathposix	_ast_pathposix
#undef	pathprobe
#define pathprobe	_ast_pathprobe
#undef	pathprog
#define pathprog	_ast_pathprog
#undef	pathrepl
#define pathrepl	_ast_pathrepl
#undef	pathsetlink
#define pathsetlink	_ast_pathsetlink
#undef	pathshell
#define pathshell	_ast_pathshell
#undef	pathstat
#define pathstat	_ast_pathstat
#undef	pathtemp
#define pathtemp	_ast_pathtemp
#undef	pathtmp
#define pathtmp		_ast_pathtmp
#undef	procclose
#define procclose	_ast_procclose
#undef	procfree
#define procfree	_ast_procfree
#undef	procopen
#define procopen	_ast_procopen
#undef	procrun
#define procrun		_ast_procrun
#undef	putenv
#define putenv		_ast_putenv
#undef	re_comp
#define re_comp		_ast_re_comp
#undef	re_exec
#define re_exec		_ast_re_exec
#undef	realpath
#define realpath	_ast_realpath
extern __MANGLE__ char*		realpath __PROTO__((const char*, char*));
#undef	regaddclass
#define regaddclass	_ast_regaddclass
#undef	regalloc
#define regalloc	_ast_regalloc
#undef	regcache
#define regcache	_ast_regcache
#undef	regclass
#define regclass	_ast_regclass
#undef	regcmp
#define regcmp		_ast_regcmp
#undef	regcollate
#define regcollate      _ast_regcollate
#undef	regcomb
#define regcomb		_ast_regcomb
#undef	regcomp
#define regcomp		_ast_regcomp
#undef	regdecomp
#define regdecomp	_ast_regdecomp
#undef	regdup
#define regdup		_ast_regdup
#undef	regerror
#define regerror	_ast_regerror
#undef	regex
#define regex		_ast_regex
#undef	regexec
#define regexec		_ast_regexec
#undef	regfatal
#define regfatal	_ast_regfatal
#undef	regfatalpat
#define regfatalpat     _ast_regfatalpat
#undef	regfree
#define regfree		_ast_regfree
#undef	regncomp
#define regncomp	_ast_regncomp
#undef	regnexec
#define regnexec	_ast_regnexec
#undef	regrecord
#define regrecord       _ast_regrecord
#undef	regrexec
#define regrexec	_ast_regrexec
#undef	regstat
#define regstat		_ast_regstat
#undef	regsub
#define regsub		_ast_regsub
#undef	regsubcomp
#define regsubcomp	_ast_regsubcomp
#undef	regsubexec
#define regsubexec	_ast_regsubexec
#undef	regsubflags
#define regsubflags	_ast_regsubflags
#undef	regsubfree
#define regsubfree	_ast_regsubfree
#undef	remove
#define remove		_ast_remove
extern __MANGLE__ int		remove __PROTO__((const char*));
#undef	resolvepath
#define resolvepath	_ast_resolvepath
extern __MANGLE__ int		resolvepath __PROTO__((const char*, char*, size_t));
#undef	setenv
#define setenv		_ast_setenv
extern __MANGLE__ int		setenv __PROTO__((const char*, const char*, int));
#undef	setenviron
#define setenviron      _ast_setenviron
#undef	sigcritical
#define sigcritical      _ast_sigcritical
#undef	signal
#define signal      	_ast_signal
#undef	sigunblock
#define sigunblock      _ast_sigunblock
#undef	stracmp
#define stracmp		_ast_stracmp
#undef	strcopy
#define strcopy		_ast_strcopy
#undef	strelapsed
#define strelapsed	_ast_strelapsed
#undef	stresc
#define stresc		_ast_stresc
#undef	streval
#define streval		_ast_streval
#undef	strexpr
#define strexpr		_ast_strexpr
#undef	strftime
#define strftime	_ast_strftime
#undef	strgid
#define strgid		_ast_strgid
#undef	strgrpmatch
#define strgrpmatch	_ast_strgrpmatch
#undef	strhash
#define strhash		_ast_strhash
#undef	strkey
#define strkey		_ast_strkey
#undef	strlcat
#define strlcat		_ast_strlcat
extern __MANGLE__ size_t		strlcat __PROTO__((char*, const char*, size_t));
#undef	strlcpy
#define strlcpy		_ast_strlcpy
extern __MANGLE__ size_t		strlcpy __PROTO__((char*, const char*, size_t));
#undef	strlook
#define strlook		_ast_strlook
#undef	strmatch
#define strmatch	_ast_strmatch
#undef	strmode
#define strmode		_ast_strmode
#undef	strnacmp
#define strnacmp	_ast_strnacmp
#undef	strncopy
#define strncopy	_ast_strncopy
#undef	strntod
#define strntod		_ast_strntod
#undef	strntol
#define strntol		_ast_strntol
#undef	strntold
#define strntold	_ast_strntold
#undef	strntoll
#define strntoll	_ast_strntoll
#undef	strntoul
#define strntoul	_ast_strntoul
#undef	strntoull
#define strntoull	_ast_strntoull
#undef	stropt
#define stropt		_ast_stropt
#undef	strperm
#define strperm		_ast_strperm
#undef	strpsearch
#define strpsearch	_ast_strpsearch
#undef	strptime
#define strptime	_ast_strptime
#undef	strsearch
#define strsearch	_ast_strsearch
#undef	strsort
#define strsort		_ast_strsort
#undef	strsubmatch
#define strsubmatch	_ast_strsubmatch
#undef	strsum
#define strsum		_ast_strsum
#undef	strtape
#define strtape		_ast_strtape
#undef	strtoip4
#define strtoip4	_ast_strtoip4
#undef	strton
#define strton		_ast_strton
#undef	strtonll
#define strtonll	_ast_strtonll
#undef	struid
#define struid		_ast_struid
#undef	struniq
#define struniq		_ast_struniq
#undef	system
#define system		_ast_system
extern __MANGLE__ int		system __PROTO__((const char*));
#undef	tempnam
#define tempnam		_ast_tempnam
extern __MANGLE__ char*		tempnam __PROTO__((const char*, const char*));
#undef	tmpnam
#define tmpnam		_ast_tmpnam
extern __MANGLE__ char*		tmpnam __PROTO__((char*));
#undef	touch
#define touch		_ast_touch
#undef	wordexp
#define wordexp		_ast_wordexp
#undef	wordfree
#define wordfree	_ast_wordfree
#undef	unsetenv
#define unsetenv	_ast_unsetenv

/* cannot override local malloc */
#define	_map_malloc	1
#undef	calloc
#define calloc		_ast_calloc
extern __MANGLE__ __V_*		calloc __PROTO__((size_t, size_t));
#undef	cfree
#define cfree		_ast_cfree
extern __MANGLE__ void		cfree __PROTO__((__V_*));
#undef	free
#define free		_ast_free
extern __MANGLE__ void		free __PROTO__((__V_*));
#undef	malloc
#define malloc		_ast_malloc
extern __MANGLE__ __V_*		malloc __PROTO__((size_t));
#undef	memalign
#define memalign	_ast_memalign
extern __MANGLE__ __V_*		memalign __PROTO__((size_t, size_t));
#undef	realloc
#define realloc		_ast_realloc
extern __MANGLE__ __V_*		realloc __PROTO__((__V_*, size_t));
#undef	strdup
#define strdup		_ast_strdup
extern __MANGLE__ char*		strdup __PROTO__((const char*));
#undef	valloc
#define valloc		_ast_valloc
extern __MANGLE__ __V_*		valloc __PROTO__((size_t));
#undef	strtol
#define strtol		_ast_strtol
#undef	strtoul
#define strtoul		_ast_strtoul
#undef	strtoll
#define strtoll		_ast_strtoll
#undef	strtoull
#define strtoull	_ast_strtoull
#undef	strtod
#define strtod		_ast_strtod
#undef	strtold
#define strtold		_ast_strtold
extern __MANGLE__ long		strtol __PROTO__((const char*, char**, int));
extern __MANGLE__ unsigned long	strtoul __PROTO__((const char*, char**, int));
extern __MANGLE__ double		strtod __PROTO__((const char*, char**));
#if !_UWIN
#undef __MANGLE__
#define __MANGLE__ __LINKAGE__
#endif
extern __MANGLE__ _ast_fltmax_t	strtold __PROTO__((const char*, char**));
#undef __MANGLE__
#define __MANGLE__ __LINKAGE__
extern __MANGLE__ _ast_intmax_t		strtoll __PROTO__((const char*, char**, int));
extern __MANGLE__ unsigned _ast_intmax_t	strtoull __PROTO__((const char*, char**, int));

#undef __MANGLE__
#define __MANGLE__ __LINKAGE__
#endif
