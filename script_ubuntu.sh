#!/bin/bash

sudo apt install gcc
sudo apt install ccache
sudo apt install readline*


sudo apt update
sudo apt upgrade


ccache gcc *.c -lm -lreadline -o shell

./shell
