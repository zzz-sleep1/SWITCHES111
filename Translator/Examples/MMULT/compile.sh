#!/bin/bash

# Translate Application
switches -s multicore 2 4 -i mmult.c -t 4 -nsga -f nsga.in "$PWD"

# Compile Application
make -f Makefile

