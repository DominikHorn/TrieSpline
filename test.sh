#!/bin/bash

COMPILER=clang++
OUT_DIR=build
PROG_NAME=test

set -e
cd "$(dirname "$0")"

mkdir -p ${OUT_DIR} 
${COMPILER} -std=c++20 -O0 -g -fsanitize=address,leak,undefined test.cpp -o ${OUT_DIR}/${PROG_NAME}
${OUT_DIR}/${PROG_NAME}
