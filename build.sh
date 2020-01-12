#!/bin/bash
echo "Compilation started";
g++ -g -std=c++17 main.cpp model.cpp profile.cpp model.h profile.h -o model 
echo "Compilation finished";
echo "Runtime is ./model";