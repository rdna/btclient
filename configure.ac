#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([btclient], [0.0.1], [rdna@rdna.ru])
AC_CONFIG_SRCDIR([src/btclient.cc])
AM_INIT_AUTOMAKE

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC

# Checks for C libraries.
AC_CHECK_LIB([crypto], [HMAC])
AC_CHECK_LIB([curl], [curl_easy_setopt])

# Checks for C++ libraries.
AC_LANG_PUSH([C++])
SAVED_LDFLAGS=$LDFLAGS
LDFLAGS="$LDFLAGS -ljsoncpp"
AC_LINK_IFELSE(	[AC_LANG_PROGRAM([#include <json/json.h>], [Json::Value root])],
		[LIBS="$LIBS -ljsoncpp"] [HAVE_JSONCPP=1],
		[AC_MSG_ERROR([libjsoncpp is not installed.])])
LDFLAGS=$SAVED_LDFLAGS
AC_LANG_POP([C++])

# Checks for header files.
AC_CHECK_HEADERS([err.h])
AC_CHECK_HEADERS([unistd.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_HEADER_STDBOOL
AC_C_INLINE
AC_TYPE_SIZE_T

AC_OUTPUT(Makefile src/Makefile)
