#!/bin/bash

g++ main.cpp -std=c++11 -I/usr/include/python2.7 -lpython2.7 -o main.out
chmod +x main.out
