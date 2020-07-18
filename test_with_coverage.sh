#!/usr/bin/env bash
set -e
scons
valgrind ./build/test > /dev/null
kcov .coverage ./build/test
xdg-open .coverage/index.html
