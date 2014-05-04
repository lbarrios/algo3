#!/usr/bin/env python3
from testGen.generadorDeTestsEj1 import GeneradorDeTestsEj1



# Parámetros gráfico de comparación"
inputDir_c = "input/graficoComparacion"
limInf_c = 0
limSup_c = 10001
paso_c = 100
casosPorTest_c = 30

# Parámetros para gráfico de división
inputDir_d = "input/graficoDivision"
limInf_d = 0
limSup_d = 10001
paso_d = 100
casosPorTest_d = 30



# Generar casos de prueba gráfico de comparación

testGen = GeneradorDeTestsEj1(inputDir_c)

for n in range(limInf_c, limSup_c, paso_c):
  print(n)
  testGen.generarTest({"n":n}, "casoAleatorio", casosPorTest_c )
  testGen.generarTest({"n":n}, "mejorCaso", casosPorTest_c )
  testGen.generarTest({"n":n}, "peorCaso", casosPorTest_c )


# Generar casos de prueba gráfico de división

testGen = GeneradorDeTestsEj1(inputDir_d)

for n in range(limInf_d, limSup_d, paso_d):
  print(n)
  testGen.generarTest({"n":n}, "casoAleatorio", casosPorTest_d)