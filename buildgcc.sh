#!/bin/bash
#COMPILO=/usr/bin/g++-6
COMPILO=gcc
echo "Building demo model"
$COMPILO -c -std=c++11 src/main.cpp -o build/demo.o
$COMPILO -o build/demo.o -L/usr/lib -lGL -o demo
echo "Compilation completed"
echo "Runtime is ./build/demo"