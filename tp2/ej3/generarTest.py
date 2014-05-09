#!/usr/bin/env python3
from testGen.generadorDeTestsEj3 import GeneradorDeTestsEj3



# Parámetros gráfico de tiempo normal
inputDir = "input/graficoTiempoLiso"
limInf = 1
limSup = 250
paso = 3
casosPorTest = 100

# Parámetros para gráfico con "n" fijo
inputDir_fijo = "input/graficoPotExtra"
cantTest = 300
n_fijo = 100


# Parámetros grafico ordenado por salida
inputDir_s = "input/graficoOrdenadoPorSalida"






# test tiempo liso
testGen = GeneradorDeTestsEj3(inputDir)

for n in range(limInf, limSup, paso):
  print(n)
  testGen.generarTest({"n":n}, "casoAleatorio", casosPorTest )




# n fijo, varía k
testGen = GeneradorDeTestsEj3(inputDir_fijo)

for k in range( cantTest ):
    print( k )
    testGen.generarTest( {"n": n_fijo, "k" : k}, "casoAleatorio", 100)
    

testGen = GeneradorDeTestsEj3("input/graficoOrdenadoPorSalida")

# Test ordenados por salida.
testGen = GeneradorDeTestsEj3( inputDir_s )

testGen.generarTest( {"n":150, "k":5}, "casoLargo" , 1000)

