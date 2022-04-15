#!/bin/bash
# Remove old un-needed files, if any.
rm *.o
rm *.out
gcc -c -Wall -m64 -no-pie -o rt.o token.c -std=c17
gcc -m64 -no-pie -o rt.out rt.o -std=c17 # Link object files
./rt.out # Run the program