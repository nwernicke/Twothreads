#!/usr/bin/env bash

reset
if [ -d build ]; then rm -rf build; fi
mkdir -p build

pushd build
    #g++ -std=c++11 -pthread printer.cpp generator.cpp main.cpp -o Twothreads
    g++ -std=c++11 -pthread -c ../main.cpp ../printer.cpp ../generator.cpp ../memorizer.cpp
    g++ -std=c++11 -pthread -o Twothreads main.o printer.o generator.o memorizer.o
popd