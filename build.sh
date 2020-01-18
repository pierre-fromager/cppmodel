#!/bin/bash

COMPILO=/usr/bin/g++-6
#DEBUGOPT="-g"
DEBUGOPT=""
CPPSTD="-std=c++11"
CPPOPTIM="-O3" # https://gcc.gnu.org/onlinedocs/gcc/Optimize-Options.html
GLOBOPT="-Wall -Wextra"
OUT="build/demo"
echo "Building demo model g++"

rm $OUT

$COMPILO $DEBUGOPT $CPPSTD $GLOBOPT $CPPOPTIM \
    src/main.cpp \
    src/model/liste_temperature.cpp \
    src/profile/profile.cpp \
    src/demo/demo_generic.cpp \
    src/demo/demo_specific.cpp \
    -o $OUT

echo "Compilation completed"
echo "Runtime is ./build/demo"