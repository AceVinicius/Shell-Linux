#!/bin/bash

# Install dependencies
sudo dnf install gcc
sudo dnf install ccache
sudo dnf install readline*

sudo dnf update
sudo dnf upgrade


#compile and run Shell Linux
bash run.sh
