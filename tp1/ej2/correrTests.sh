#!/usr/bin/env bash
EXE=${PWD##*/}
INPUT_FOLDER=input
OUTPUT_FOLDER=output
VERBOSE=false
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

for i in "$@"
do
case $i in
  -v|--verbose)
  VERBOSE=true
  shift
  ;;
  #-b=*|--blabla=*)
  #BLABLA="${i#*=}"
  #shift
  #;;
  *)
    # unknown option
  ;;
esac
done

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
        else
          if [ $VERBOSE == true ]; then
            cat $OUTPUT
          else
            echo $VERBOSE
          fi
        fi
    done
    echo ""
    echo ""
    echo ""
    echo "                                         Fin de las pruebas"
else
    echo "El programa no compiló bien!!!"
fi
