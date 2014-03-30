#!/usr/bin/env bash
EXE=${PWD##*/}

platform='unknown'
MAKE=make
unamestr=`uname`
function pause(){
  clear
  echo "

---------------------- ATENCION -----------------------------------------------
"
  echo "$*"
  echo "
-------------------------------------------------------------------------------"
  read -p "Presione la tecla [Enter] para continuar de todas formas.
DE LO CONTRARIO APAGUE LA PC."
}
if [[ "$unamestr" == 'Linux' ]]; then
  platform='linux'
elif [[ "$unamestr" == 'FreeBSD' ]]; then
  platform='freebsd'
  MAKE=gmake
fi

clear

INPUT_FOLDER=input
OUTPUT_FOLDER=output

clear
$MAKE $EXE
if [ $? = 0 ]; then
    pause "Se correra el programa para todos los archivos de input 
que se encuentren en la carpeta '$INPUT_FOLDER'.

Los resultados serán volcados a la carpeta '$OUTPUT_FOLDER'
             Esto puede demorar."
    clear
    INPUTS=$INPUT_FOLDER/*.txt
    for INPUT in $INPUTS
    do
        OUTPUT=$OUTPUT_FOLDER/${INPUT##*/}
        echo ".........ejecutando ./$EXE -i $INPUT -o $OUTPUT"
        ./$EXE -i $INPUT -o $OUTPUT
        if [ $? != 0 ]; then
             echo "HUBO UN ERROR AL CORRER EL INPUT ${INPUT##*/}!!!"
        #else
        #    cat output/$OUTPUT
        fi
    done
    echo ""
    echo ""
    echo ""
    echo "                                         Fin de las pruebas"
else
    echo "El programa no compiló bien!!!"
fi
