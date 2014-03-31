#!/usr/bin/python3
from genTest.generadorDeTestsEj2 import generadorDeTestsEj2
import sys

generador = generadorDeTestsEj2()
desde = 1
hasta = 1000
casosPorTest = 50
paso = 1

print (
"""
Usted está a punto de generar muuuuchos tests... Muchos.
Cuando la ejecución de esto termine su carpeta "input" va a pesar
aproximadamente 1gb y van a haber pasado unos cuantos minutos.

Usted está advertido.

Si desea cambiar los parámetros de este escript
lo puede hacer mediante un rudimentario sistema:
  Abriendo el archivo para editarlo va a encontrar 4
  variables globales:
    - desde: Desde que 'n' quiere generar tests
    - hasta: Hasta que 'n' quiere generar tests
    - casosPorTest: cantos casos se generan por cada 'n'
    - paso: el "step" de los 'n'. Es decir el paso que hay entre cada test quese genera.

Para continuar... Presione ENTER.
Para abortar precione CTRL-C o escriba "salir" y precione ENTER
"""
      )

escape = input()
if escape == "salir":
  sys.exit()
  


for i in range( desde , hasta, paso):
  print( i)
  generador.generarTest(i, "casoAleatorio", casosPorTest)

print (" Los test se generaron correctamente ")
