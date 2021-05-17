#!/bin/bash
gcc -o my_exe *.c -lm
./my_exe $1 #allows command line arguments. if there are more arguments, $2,$3...$n.
