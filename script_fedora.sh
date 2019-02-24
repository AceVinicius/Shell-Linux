#!/bin/bash

sudo dnf install gcc
sudo dnf install ccache
sudo dnf install readline*


sudo dnf update
sudo dnf upgrade


ccache gcc *.c -lm -lreadline -o shell

./shell
