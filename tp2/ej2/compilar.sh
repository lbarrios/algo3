#!/usr/bin/env bash

g++ -O2 ej2.cpp ../common/Timer.cpp -o ej2
g++ -O2 -DTIME ej2.cpp ../common/Timer.cpp -o ej2.time
g++ -DDEBUG ej2.cpp ../common/Timer.cpp -o ej2.debug