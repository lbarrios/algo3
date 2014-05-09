#!/usr/bin/env python3
from testGen.generadorDeTestsEj2 import GeneradorDeTestsEj2



# Parámetros gráfico de comparación"
inputDir = "input/graficoTiempoLiso"
limInf = 1
limSup = 1001
paso = 10
casosPorTest = 100

# Parámetros gráfico n fijo, varía k.
inputDir_fijo = "input/graficoCentrales"
limSup_k = 1000
n_fijo = 1000
paso_fijo = 10
casosPorTest_fijo = 30


# Gráfico tiempo liso

testGen = GeneradorDeTestsEj2(inputDir)

for n in range(limInf, limSup, paso):
  print(n)
  testGen.generarTest({"n":n}, "casoAleatorio", casosPorTest )



# Gráfico n fijo, varía k.

testGen = GeneradorDeTestsEj2( inputDir_fijo )

for i in range( limSup_k, step = paso_fijo ):
    print(n)
    testGen.generarTest( {"n": n_fijo , "k": i}, "casoAleatorio", casosPorTest_fijo )
