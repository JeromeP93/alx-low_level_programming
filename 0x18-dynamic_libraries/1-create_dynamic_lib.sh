#!/bin/bash

# Compile each .c file into position-independent code
gcc -fPIC -c *.c

# Link the compiled object files into a shared library
gcc -shared -o liball.so *.o
