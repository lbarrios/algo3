#!/usr/bin/env bash
EXE=${PWD##*/}
INPUT_FOLDER=input/testParaIntervaloInspector
OUTPUT_FOLDER=output/testParaIntervaloInspector
VERBOSE=false
TIME=false
HELP=false
DEFAULT=true
DESDE=false
HASTA=false
TIPODEPRUEBA=false
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
  read -p "Presione la tecla [Enter] para continuar."
}
if [[ "$unamestr" == 'Linux' ]]; then
  platform='linux'
elif [[ "$unamestr" == 'FreeBSD' ]]; then
  platform='freebsd'
  MAKE=gmake
fi

if [ $# = 0 ]; then
  echo "Se deben introducir parámetros para ejecutar este script.
Para más información, ejecutar con el parámetro --help.
Chau."
  exit 0
fi

for i in "$@"
do
case $i in
  -v|--verbose)
  VERBOSE=true
  shift
  ;;
  -t|--time|--tiempo)
  TIME=true
  shift
  ;;
  --desde=*)
  DESDE="${i#*=}"
  shift
  ;;
  --hasta=*)
  HASTA="${i#*=}"
  shift
  ;;
  --tipodeprueba=*)
  TIPODEPRUEBA="${i#*=}"
  shift
  ;;
  -h|--help)
  HELP=true
  shift
  ;;
  --todo)
  shift
  ;;
  #-b=*|--blabla=*)
  #BLABLA="${i#*=}"
  #shift
  #;;
  *)
    echo "Parámetro no reconocido.
Chau."
  exit -1
  ;;
esac
done


if [ $TIME = true ]; then
  EXE=$EXE.time
fi


if [ $HELP = true ]; then
  echo "
El script corre el ejecutable EXE desde la carpeta INPUT_FOLDER
y los guarda con el mismo nombre en la carpeta OUTPUT_FOLDER.

Valores por defecto:
    INPUT_FOLDER: ./input/
    OUTPUT_FOLDER: ./output/

Opciones disponibles:
  --help | -h:
    Muestra este mensaje de ayuda.

	--desde=d, --hasta=h, --tipodeprueba=nombre:
    Especifica el tamaño de entrada mínimo,
    tamaño de entrada máximo, y tipo de prueba
    que ejecutar.

	--todo:
    Especifica que se correrán TODOS los tests que
    se encuentren en la carpeta INPUT_FOLDER.

  --verbose | -v:
    Muestra el output obtenido al correr los tests.

  --time | --tiempo | -t:
    Realiza mediciones de tiempo.
    Los archivos se guardarán con la extension '.time'
"
  exit 0
fi

if [ $DESDE = false ] && [ $HASTA = false ] && [ $TIPODEPRUEBA = false ]; then
	RANGO=false
else
	if [ $DESDE != false ] && [ $HASTA != false ] && [ $TIPODEPRUEBA != false ]; then
		RANGO=true
	else
		echo "Los parámetros --desde, --hasta y --tipodeprueba
deben ser introducidos en conjunto."
		if [ $DESDE = false ]; then
			echo "No se ha introducido el parametro --desde"
		fi
		if [ $HASTA = false ]; then
			echo "No se ha introducido el parametro --hasta"
		fi
		if [ $TIPODEPRUEBA = false ]; then
			echo "No se ha introducido el parametro --tipodeprueba"
		fi
			echo "Chau"
			exit 0
	fi
fi


#                                                                              #
#                                                                              #
################################################################################
#                                                                              #
################################################################################
#                                                                              #
################################################################################
#                                                                              #
################################################################################
#                                                                              #
#                                                                              #

clear
$MAKE $EXE
if [ $? = 0 ]; then
  if [ $RANGO = false ]; then
    pause "Se correra el programa para TODOS los archivos de input 
que se encuentren en la carpeta '$INPUT_FOLDER'.

Los resultados serán volcados a la carpeta '$OUTPUT_FOLDER'
             Esto puede demorar mucho.

Puede obtener ayuda sobre el programa ejecutando --help.
Si desea cancelar la ejecución, ahora es el momento."
    clear
    INPUTS=$INPUT_FOLDER/*.txt
  else
    INPUTS=$INPUT_FOLDER/${TIPODEPRUEBA}_*.txt
  fi
  for INPUT in $INPUTS
  do
      OUTPUT=$OUTPUT_FOLDER/${INPUT##*/}
      EXE_PARAM="-i $INPUT -o $OUTPUT"
      if [ $TIME = true ]; then
        EXE_PARAM="$EXE_PARAM -t $OUTPUT.time"
      fi
      echo "EJECUTANDO: ./$EXE $EXE_PARAM"
      ./$EXE $EXE_PARAM
      if [ $? != 0 ]; then
           echo "HUBO UN ERROR AL CORRER EL INPUT ${INPUT##*/}!!!"
      else
        if [ $VERBOSE == true ]; then
          if [ $TIME = true ]; then
            cat $OUTPUT.time
          else
            cat $OUTPUT
          fi
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
