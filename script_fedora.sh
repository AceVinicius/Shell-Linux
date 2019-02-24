#!/bin/bash

sudo dnf install gcc
sudo dnf install ccache

sudo dnf install readline*


ccache gcc *.c -lm -lreadline -o shell

./shell
