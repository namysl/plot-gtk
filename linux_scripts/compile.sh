#!/bin/bash

#usage: ./compile gui

gcc -o $1.out $1.c `pkg-config --cflags --libs gtk+-3.0 libnotify`

chmod +x $1.out
