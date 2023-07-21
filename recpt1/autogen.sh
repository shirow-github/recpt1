#!/bin/sh

[ -f configure.ac ] || {
  echo "autogen.sh: run this command only at the top of a recpt1 source tree."
  exit 1
}

DIE=0

(autoconf --version) < /dev/null > /dev/null 2>&1 || {
  echo
  echo "You must have autoconf installed to compile recpt1."
  echo "Get ftp://ftp.gnu.org/pub/gnu/autoconf/autoconf-2.62.tar.gz"
  echo "(or a newer version if it is available)"
  DIE=1
  NO_AUTOCONF=yes
}

(automake --version) < /dev/null > /dev/null 2>&1 || {
  echo
  echo "You must have automake installed to compile recpt1."
  echo "Get ftp://ftp.gnu.org/pub/gnu/automake/automake-1.10.1.tar.gz"
  echo "(or a newer version if it is available)"
  DIE=1
  NO_AUTOMAKE=yes
}

# if no automake, don't bother testing for aclocal
test -n "$NO_AUTOMAKE" || (aclocal --version) < /dev/null > /dev/null 2>&1 || {
  echo
  echo "**Error**: Missing \`aclocal'.  The version of \`automake'"
  echo "installed doesn't appear recent enough."
  echo "Get ftp://ftp.gnu.org/pub/gnu/automake/automake-1.10.1.tar.gz"
  echo "(or a newer version if it is available)"
  DIE=1
}

# if no autoconf, don't bother testing for autoheader
test -n "$NO_AUTOCONF" || (autoheader --version) < /dev/null > /dev/null 2>&1 || {
  echo
  echo "**Error**: Missing \`autoheader'.  The version of \`autoheader'"
  echo "installed doesn't appear recent enough."
  echo "Get ftp://ftp.gnu.org/pub/gnu/autoconf/autoconf-2.62.tar.gz"
  echo "(or a newer version if it is available)"
  DIE=1
}

if test "$DIE" -eq 1; then
        exit 1
fi

# pt1_dev.h tuner device setting
ground=""
satellite=""

tunerSet()
{
  local devicebase='/dev/'$1
  local number=0
  while [ -e ${devicebase}${number} ]
  do
    if [ ${satellite} ]; then
      satellite=${satellite}','
      ground=${ground}','
    fi
    satellite=${satellite}'"'${devicebase}${number}'",'
    number=`expr $number + 1`
    satellite=${satellite}'"'${devicebase}${number}'"'
    number=`expr $number + 1`
    ground=${ground}'"'${devicebase}${number}'",'
    number=`expr $number + 1`
    ground=${ground}'"'${devicebase}${number}'"'
    number=`expr $number + 1`
  done
}

tunerSet 'pt1video'
tunerSet 'pt3video'
tunerSet 'px4video'
for i in $@; do
  tunerSet ${i}
done

if [ ${satellite} ]; then
  sed -e "s!%SATELLITE%!${satellite}!" -e "s!%GROUND%!${ground}!" ./pt1_dev.base.h > ./pt1_dev.h
else
  echo 'Tuner device unfind.'
  exit 1
fi

echo "Generating configure script and Makefiles for recpt1."

echo "Running aclocal ..."
aclocal -I .
echo "Running autoheader ..."
autoheader
echo "Running autoconf ..."
autoconf
