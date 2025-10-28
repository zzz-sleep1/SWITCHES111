#!/bin/bash

# Translate Application
switches -s multicore 2 4 -i rk4.c -t 4 -nsga -f nsga.in

# Compile Application
make -f Makefile

