#!/bin/bash

ccache clang ./src/*.c -W -Wall -O3 -lm -lreadline -o ./bin/Shell_Linux

cd ./bin
./Shell_Linux
