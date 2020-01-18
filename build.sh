#!/bin/bash

echo "Compiling"
make CXX=g++-6
echo "Compilation end"
echo "run : ./demo"
echo "clean : make clean"
echo "recompile : make clean & make"
