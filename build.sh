#!/bin/bash

COMPILO=/usr/bin/g++-6
#DEBUGOPT="-g"
DEBUGOPT=""
CPPSTD="-std=c++11"
GLOBOPT="-Wall -Wextra";
echo "Building demo model g++"

$COMPILO $DEBUGOPT $CPPSTD $GLOBOPT \
    src/main.cpp \
    src/model/liste_temperature.cpp \
    src/profile/profile.cpp \
    src/demo/demo_temperature.cpp \
    src/demo/demo_templated_temperature.cpp \
    -o build/demo

echo "Compilation completed"
echo "Runtime is ./build/demo"