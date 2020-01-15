#!/bin/bash
echo "Building demo model"
g++ -g -std=c++11 src/main.cpp \
    src/demo/demo.hpp src/demo/demo.cpp \
    src/model/liste.hpp \
    src/model/liste_temperature.hpp src/model/liste_temperature.cpp \
    src/profile/profile.hpp src/profile/profile.cpp \
    -o build/demo
echo "Compilation completed"
echo "Runtime is ./build/demo"