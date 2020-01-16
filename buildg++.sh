#!/bin/bash
COMPILO=/usr/bin/g++-6
echo "Building demo model g++"
$COMPILO -g -std=c++11 src/main.cpp \
    src/terminal/ansi.hpp \
    src/demo/demo_temperature.hpp src/demo/demo_temperature.cpp \
    src/demo/demo_templated_temperature.hpp src/demo/demo_templated_temperature.cpp \
    src/model/liste_template.hpp \
    src/model/liste_temperature.hpp src/model/liste_temperature.cpp \
    src/profile/profile.hpp src/profile/profile.cpp \
    -o build/demo
echo "Compilation completed"
echo "Runtime is ./build/demo"