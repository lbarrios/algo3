#!/usr/bin/env python3
from genTest.generadorDeTestsEj1 import generadorDeTestsEj1
import sys

carpetaInput = "input/testParaDivision"
desde = 100
hasta = 40000
casosPorTest = 40
paso = 100


print (
"""
Usted está a punto de generar muuuuchos tests... Muchos.
Cuando la ejecución de esto termine su carpeta "input" va a pesar
aproximadamente 1gb y van a haber pasado unos cuantos minutos.

Usted está advertido.

Si desea cambiar los parámetros de este script
lo puede hacer mediante un rudimentario sistema:
  Abriendo el archivo para editarlo va a encontrar 4
  variables globales:
    - desde: Desde que 'n' quiere generar tests
    - hasta: Hasta que 'n' quiere generar tests
    - casosPorTest: cuantos casos se generan por cada 'n'
    - paso: el "step" de los 'n'. Es decir el paso que hay entre cada test que se genera.

Para continuar... Presione ENTER.
Para abortar precione CTRL-C o escriba "salir" y presione ENTER
"""
      )

escape = input()
if escape == "salir":
  sys.exit()
  

generador = generadorDeTestsEj1(carpetaInput)

for i in range( desde , hasta, paso):
  print( i)
  params = {"n":i}
  generador.generarTest( params, "casoAleatorio", casosPorTest)


print (" Los test se generaron correctamente ")
