#!/bin/bash

g++ -O2 -DRESULTS ej3.cpp ../common/Timer.cpp -o ej3
g++ -O2 -DTIME ej3.cpp ../common/Timer.cpp -o ej3.time
g++ -O2 -DGRAF -DTIME ej3.cpp ../common/Timer.cpp -o ej3.graf

