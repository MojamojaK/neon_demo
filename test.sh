#!/bin/bash

# make files
make clean
make

./neon
if [ $? != "0" ]; then
    echo "[FAILURE] Incorrect Calculation"
    exit
fi
