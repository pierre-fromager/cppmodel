#!/bin/bash
echo "Compilation started";
g++ -g -std=c++11 src/main.cpp src/model/model.cpp src/profile/profile.cpp src/model/model.h src/profile/profile.h -o build/model
echo "Compilation finished";
echo "Runtime is ./build/model";