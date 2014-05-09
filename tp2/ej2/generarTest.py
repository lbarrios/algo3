#!/usr/bin/env python3
from testGen.generadorDeTestsEj2 import GeneradorDeTestsEj2



# Parámetros gráfico de comparación"
inputDir = "input/graficoTiempoLiso"
limInf = 1
limSup = 1001
paso = 10
casosPorTest = 100



# Gráfico tiempo liso

testGen = GeneradorDeTestsEj2(inputDir)

for n in range(limInf, limSup, paso):
  print(n)
  testGen.generarTest({"n":n}, "casoAleatorio", casosPorTest )



# Gráfico n fijo, varía k.

testGen = GeneradorDeTestsEj2("input/graficoCentrales")

for i in range(1000, step = 10 ):
    print(n)
    testGen.generarTest( {"n": 1000, "k": i}, "casoAleatorio", casosPorTest )
