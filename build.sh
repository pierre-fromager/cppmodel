#!/bin/bash
echo "Compilation started";
g++ -g -std=c++11 src/main.cpp \
src/model/model.h src/model/model.cpp \
src/profile/profile.h src/profile/profile.cpp \
-o build/model
echo "Compilation finished";
echo "Runtime is ./build/model";