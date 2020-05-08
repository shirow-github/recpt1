#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ(2.59)
AC_INIT([recpt1], [1.2.5], shirowxxx@gmail.com)
AC_CONFIG_SRCDIR([recpt1.c])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC

# Checks for b25 support.
AC_ARG_ENABLE(b25,
  [AS_HELP_STRING([--enable-b25],[enable b25 support])],
  [AC_CHECK_LIB([pcsclite], [main], , [AC_MSG_WARN(libpcsclite is not available.)])]
  [AC_CHECK_LIB([aribb25], [create_arib_std_b25], , [AC_MSG_WARN(libaribb25 is not available.)], [-lpcsclite])]
)
AC_ARG_ENABLE(softcas,
  [AS_HELP_STRING([--enable-softcas],[enable b25 support (software B-CAS card emulator)])],
  [AC_CHECK_LIB([pcsclitebcas], [main], , [AC_MSG_WARN(libpcsclitebcas is not available.)])]
  [AC_CHECK_LIB([aribb25], [create_arib_std_b25], , [AC_MSG_WARN(libaribb25 is not available.)], [-lpcsclitebcas])]
)

if test x"${enable_b25}" = x"yes"; then
	if test x"${enable_softcas}" = x"yes"; then
		AC_DEFINE(HAVE_LIBPCSCLITEBCAS, 0, [Define to 1 if you want to ensure libpcsclitebcas])
	fi
fi

# Checks for libraries.
AC_CHECK_LIB([m], [log10])
AC_CHECK_LIB([pthread], [pthread_kill])

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
