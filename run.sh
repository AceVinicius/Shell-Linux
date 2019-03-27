#!/bin/bash

# Compile Shell Linux
ccache gcc *.c -lm -lreadline -o shell
./shell
