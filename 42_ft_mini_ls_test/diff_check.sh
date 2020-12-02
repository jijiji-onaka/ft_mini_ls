#!/bin/bash

SRC=$1
DST=$2
OP=$3

if test "$3" == ""; then
    echo "Usage : test.sh <file1> <file2> <file3>"
    exit 2
fi

diff ${SRC} ${DST} > /dev/null
EDCODE=$?

if [ ${EDCODE} -eq 1 ] ; then
    echo -e "\033[1;31m[KO!!!]\033[0;m"
    echo -e "\033[4;33m$3\033[0;m"
elif [ ${EDCODE} -eq 0 ] ; then
    exit 1
fi
