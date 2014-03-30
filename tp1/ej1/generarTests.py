from genTest.generadorDeTests import generadorDeTestsEj1

generador = generadorDeTestsEj1()

print (
"""Usted está a punto de generar muuuuchos tests... Muchos.
Cuando la ejecución de esto termine su carpeta "input" va a pesar
aproximadamente 1gb y van a haber pasado unos cuantos minutos.

Usted está advertido.

Para continuar... Presione ENTER"""
      )

input()


for i in range(1,1000):
  print( i)
  generador.generarTest(i, "casoAleatorio", 50)
  generador.generarTest(i, "mejorCaso", 50)
  generador.generarTest(i, "peorCaso", 50)


print (" Los test se generaron correctamente ")
