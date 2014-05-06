#!/usr/bin/env bash

g++ -O2 ej1.cpp ../common/Timer.cpp -o ej1
g++ -O2 -DTIME ej1.cpp ../common/Timer.cpp -o ej1.time
