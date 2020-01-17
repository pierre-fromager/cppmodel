#!/bin/bash
COMPILO=/usr/bin/g++-6
echo "Building demo model g++"

$COMPILO -g -std=c++11 -Wall -Wextra \
    src/main.cpp \
    src/model/liste_temperature.cpp \
    src/profile/profile.cpp \
    src/demo/demo_temperature.cpp \
    src/demo/demo_templated_temperature.cpp \
    -o build/demo

echo "Compilation completed"
echo "Runtime is ./build/demo"