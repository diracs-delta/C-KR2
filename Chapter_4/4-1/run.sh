#!/bin/bash

# stop if anything returns non-zero exit status
set -e

gcc 4-1.c
cat 4-1_stdin.txt | ./a.out > stdout.txt
less stdout.txt
