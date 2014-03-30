#!/usr/bin/env bash
EXE=ej1

clear
make $EXE
if [ $? = 0 ]; then
    INPUT=1.txt
    OUTPUT=$INPUT
    ./$EXE -i input/$INPUT -o output/$OUTPUT
    if [ $? = 0 ]; then
        cat output/$OUTPUT
    fi
else
    echo "El programa no compiló bien!!!"
fi
