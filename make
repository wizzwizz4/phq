#!/bin/sh

gcc src/main.c src/compiler.c -o bin/phq -Wall -Wpedantic -Wextra -Werror "$@"
