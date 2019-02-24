#!/bin/bash

sudo apt install gcc
sudo apt install ccache

sudo apt install readline*


ccache gcc *.c -lm -lreadline -o shell

./shell
