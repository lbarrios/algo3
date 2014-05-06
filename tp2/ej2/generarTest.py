#!/usr/bin/env python3
from testGen.generadorDeTestsEj2 import GeneradorDeTestsEj2



# Parámetros gráfico de comparación"
inputDir = "input"
limInf = 0
limSup = 50001
paso = 50
casosPorTest = 30





testGen = GeneradorDeTestsEj2(inputDir)

for n in range(limInf, limSup, paso):
  print(n)
  testGen.generarTest({"n":n}, "casoAleatorio", casosPorTest )

