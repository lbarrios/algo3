#!/usr/bin/env python3
from testGen.generadorDeTestsEj3 import GeneradorDeTestsEj3



# Parámetros gráfico de tiempo normal
inputDir = "input/graficoTiempoLiso"
limInf = 1
limSup = 250
paso = 3
casosPorTest = 5

# Parámetros grafico ordenado por salida
inputDir_s = "input/graficoOrdenadoPorSalida"


# test tiempo liso
testGen = GeneradorDeTestsEj3(inputDir)

for n in range(limInf, limSup, paso):
  print(n)
  testGen.generarTest({"n":n}, "casoAleatorio", casosPorTest )

 test n fijo k variable

testGen = GeneradorDeTestsEj3("input/graficoPotExtra")


for k in range( 300 ):
    print( k )
    testGen.generarTest( {"n": 100, "k" : k}, "casoAleatorio")
    

testGen = GeneradorDeTestsEj3("input/graficoOrdenadoPorSalida")

# Test ordenados por salida.
testGen = GeneradorDeTestsEj3( inputDir_s )

testGen.generarTest( {"n":150, "k":5}, "casoLargo" , 1000)

