#!/usr/bin/env bash
set -e
scons
./build/test
kcov .coverage ./build/test
xdg-open .coverage/index.html
