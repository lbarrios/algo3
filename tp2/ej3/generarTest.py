#!/usr/bin/env python3
from testGen.generadorDeTestsEj3 import GeneradorDeTestsEj3



# Parámetros gráfico de tiempo normal
inputDir = "input/graficoTiempoLiso"
limInf = 1
limSup = 250
paso = 3
casosPorTest = 100

# Parámetros grafico ordenado por salida
inputDir_s = "input/graficoOrdenadoPorSalida"



testGen = GeneradorDeTestsEj3(inputDir)

for n in range(limInf, limSup, paso):
  print(n)
  testGen.generarTest({"n":n}, "casoAleatorio", casosPorTest )


testGen = GeneradorDeTestsEj3( inputDir_s )


for i in range(10000):
  print(i)
  testGen.generarTest( {"n": 100, "k":5, "id":i}, "casoAleatorio", 1)
