#!/usr/bin/env python3
from genTest.generadorDeTestsEj3 import generadorDeTestsEj3
import sys

generador = generadorDeTestsEj3()
desde_n = 1
hasta_n = 6
paso_n = 1
desde_m = 1
hasta_m = 6
paso_m = 1
paso_colores = 1
desde_colores = 1
hasta_colores = 10

for color in range( desde_colores , hasta_colores, paso_colores):
  for n in range( desde_n, hasta_n, paso_n):
    for m in range( desde_m, hasta_m, paso_m):
      print("n:{},m:{}, c:{}".format(n,m,color))
      params = {"n":n,"m":m,"colores":color}
      generador.generarTest(params, "casoAleatorio")

print (" Los test se generaron correctamente ")
