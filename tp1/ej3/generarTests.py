#!/usr/bin/python3
from genTest.generadorDeTestsEj3 import generadorDeTestsEj3
import sys

generador = generadorDeTestsEj3()
desde_n = 1
hasta_n = 40
paso_n = 1
desde_m = 1
hasta_m = 40
paso_m = 1
paso_colores = 1
desde_colores = 1
hasta_colores = 100
casosPorTest = 10

print (
"""
Usted está a punto de generar muuuuchos tests... Muchos.
Cuando la ejecución de esto termine su carpeta "input" va a pesar
aproximadamente 3gb y van a haber pasado muchos muchos minutos.

Usted está advertido.

Si desea cambiar los parámetros de este escript
lo puede hacer mediante un rudimentario sistema:
  Al abrir el archivo para editarlo se encontrará
  con una serie de variables globales con nombre
  descriptivo. Las mismas determinan el funcionamiento
  del generador de tests.
  Variables globales:
    - desde_x: Desde que valor del parámetro 'x' quiere generar tests
    - hasta_x: Hasta que valor de 'x' quiere generar tests
    - paso_x: el "step" del parámetro 'x'. Es decir el paso que hay entre cada test quese genera.
    - casosPorTest: cuantos casos se generan por cada combinación de parámetros

Para continuar... Presione ENTER.
Para abortar precione CTRL-C o escriba "salir" y precione ENTER
"""
      )

escape = input()
if escape == "salir":
  sys.exit()
  


for color in range( desde_colores , hasta_colores, paso_colores):
  for n in range( desde_n, hasta_n, paso_n):
    for m in range( desde_m, hasta_m, paso_m):
      print("n:{},m:{}, c:{}".format(n,m,color))
      generador.generarTest(n, m, color, "casoAleatorio", casosPorTest)


print (" Los test se generaron correctamente ")
