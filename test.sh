#!/bin/bash

# make files
make clean
make neon
make scalar

./neon
if [ $? != "0" ]; then
    echo "[FAILURE] Incorrect Calculation for neon"
    exit
fi

./scalar
if [ $? != "0" ]; then
    echo "[FAILURE] Incorrect Calculation for scalar"
    exit
fi
