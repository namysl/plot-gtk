#!/bin/bash

g++ -c -o interface.o interface.cpp

gcc -c -o main.o main.c

g++ -o main.out main.o interface.o

chmod +x main.out
