#define RUBY_VERSION "1.9.0"
#define RUBY_RELEASE_DATE "2008-11-28"
#define RUBY_VERSION_CODE 190
#define RUBY_RELEASE_CODE 20081128
#define RUBY_PATCHLEVEL 0

#define RUBY_VERSION_MAJOR 1
#define RUBY_VERSION_MINOR 9
#define RUBY_VERSION_TEENY 0
#define RUBY_RELEASE_YEAR 2008
#define RUBY_RELEASE_MONTH 11
#define RUBY_RELEASE_DAY 28

#ifdef RUBY_EXTERN
RUBY_EXTERN const char ruby_version[];
RUBY_EXTERN const char ruby_release_date[];
RUBY_EXTERN const char ruby_platform[];
RUBY_EXTERN const int ruby_patchlevel;
RUBY_EXTERN const char ruby_description[];
RUBY_EXTERN const char ruby_copyright[];
#endif

#define RUBY_AUTHOR "Yukihiro Matsumoto"
#define RUBY_BIRTH_YEAR 1993
#define RUBY_BIRTH_MONTH 2
#define RUBY_BIRTH_DAY 24

#ifndef RUBY_REVISION
#include "revision.h"
#endif
#ifndef RUBY_REVISION
#define RUBY_REVISION 0
#endif

#if RUBY_PATCHLEVEL
#define RUBY_PATCHLEVEL_STR " patchlevel "STRINGIZE(RUBY_PATCHLEVEL)
#else
#define RUBY_PATCHLEVEL_STR ""
#endif
#if RUBY_REVISION
#ifdef RUBY_BRANCH_NAME
#define RUBY_REVISION_STR " "RUBY_BRANCH_NAME" "STRINGIZE(RUBY_REVISION)
#else
#define RUBY_REVISION_STR " revision "STRINGIZE(RUBY_REVISION)
#endif
#else
#define RUBY_REVISION_STR ""
#endif

# define RUBY_DESCRIPTION	    \
    "ruby "RUBY_VERSION		    \
    " ("RUBY_RELEASE_DATE	    \
    RUBY_PATCHLEVEL_STR		    \
    RUBY_REVISION_STR") "	    \
    "["RUBY_PLATFORM"]"
# define RUBY_COPYRIGHT 	    \
    "ruby - Copyright (C) "	    \
    STRINGIZE(RUBY_BIRTH_YEAR)"-"   \
    STRINGIZE(RUBY_RELEASE_YEAR)" " \
    RUBY_AUTHOR
