#!/bin/bash

echo "Compiling"
make clean
make -j 4 CXX=g++-6 LD=g++-6
echo "Compilation end"
echo "run : ./demo"
echo "clean : make clean"
echo "recompile : make clean & make"
