
/* : : generated by proto : : */
/* : : generated from /home/gisburn/ksh93/ast_ksh_20100309/build_i386_64bit/src/lib/libdll/features/dll by iffe version 2009-12-04 : : */
                  
#ifndef _def_dll_dll
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

#define _def_dll_dll	1
#define _sys_types	1	/* #include <sys/types.h> ok */
#define _LIB_ast	1	/* /home/gisburn/ksh93/ast_ksh_20100309/build_i386_64bit/arch/sol11.i386/lib/libast.a is a library */
#define _LIB_m	1	/* -lm is a library */
#define _hdr_dlfcn	1	/* #include <dlfcn.h> ok */
#define _LIB_dl	1	/* -ldl is a library */
#define _lib_dlopen	1	/* dlopen() in default lib(s) */
#define _DLL_NEXT_PATH	"/usr/lib/libc.so.1"

#if defined(__MVS__) && !defined(__SUSV3)
#define __SUSV3		1
#endif
#include <dlfcn.h>

#define DLL_INFO_PREVER	0x0001	/* pre-suffix style version */
#define DLL_INFO_DOTVER	0x0002	/* post-suffix style version */

typedef struct Dllinfo_s
{
	char**	sibling;	/* sibling dirs on $PATH */
	char*	prefix;		/* library name prefix */
	char*	suffix;		/* library name suffix */
	char*	env;		/* library path env var */
	int	flags;		/* DLL_INFO_* flags */
#ifdef _DLLINFO_PRIVATE_
	_DLLINFO_PRIVATE_
#endif
} Dllinfo_t;

typedef struct Dllent_s
{
	char*		path;
	char*		name;
#ifdef _DLLENT_PRIVATE_
	_DLLENT_PRIVATE_
#endif
} Dllent_t;

typedef struct Dllscan_s
{
	__V_*		pad;
#ifdef _DLLSCAN_PRIVATE_
	_DLLSCAN_PRIVATE_
#endif
} Dllscan_t;

#if _BLD_dll && defined(__EXPORT__)
#undef __MANGLE__
#define __MANGLE__ __LINKAGE__          __EXPORT__
#endif

extern __MANGLE__ Dllinfo_t*	dllinfo __PROTO__((void));
extern __MANGLE__ __V_*		dllplug __PROTO__((const char*, const char*, const char*, int, char*, size_t));
extern __MANGLE__ __V_*		dllfind __PROTO__((const char*, const char*, int, char*, size_t));
extern __MANGLE__ __V_*		dllopen __PROTO__((const char*, int));
extern __MANGLE__ __V_*		dllnext __PROTO__((int));
extern __MANGLE__ __V_*		dlllook __PROTO__((__V_*, const char*));

extern __MANGLE__ Dllscan_t*	dllsopen __PROTO__((const char*, const char*, const char*));
extern __MANGLE__ Dllent_t*	dllsread __PROTO__((Dllscan_t*));
extern __MANGLE__ int		dllsclose __PROTO__((Dllscan_t*));

#undef __MANGLE__
#define __MANGLE__ __LINKAGE__

#endif
