#!/usr/bin/env python3
from genTest.generadorDeTestsEj3 import generadorDeTestsEj3
import sys

generador = generadorDeTestsEj3()
 
 
# desde_n = 1
# hasta_n = 4
# paso_n = 1
# desde_m = 1
# hasta_m = 4
# paso_m = 1
# paso_colores = 1
# desde_colores = 1
# hasta_colores = 10

# for color in range( desde_colores , hasta_colores, paso_colores):
#   for n in range( desde_n, hasta_n, paso_n):
#     for m in range( desde_m, hasta_m, paso_m):
#       print("n:{},m:{}, c:{}".format(n,m,color))
#       params = {"n":n,"m":m,"colores":color}
#       generador.generarTest(params, "casoAleatorio")
#       generador.generarTest(params, "casoPiezasIncompatibles")
#       generador.generarTest(params, "casoTrivial")


# generador = generadorDeTestsEj3()
# desde_n = 4
# hasta_n = 5
# paso_n = 1
# desde_m = 4
# hasta_m = 5
# paso_m = 1
# paso_colores = 1
# desde_colores = 6
# hasta_colores = 7

# for color in range( desde_colores , hasta_colores, paso_colores):
#   for n in range( desde_n, hasta_n, paso_n):
#     for m in range( desde_m, hasta_m, paso_m):
#       print("n:{},m:{}, c:{}".format(n,m,color))
#       params = {"n":n,"m":m,"colores":color}
#       generador.generarTest(params, "casoAleatorio")
#       generador.generarTest(params, "casoPiezasIncompatibles")
#       generador.generarTest(params, "casoTrivial")


generador.generarTest({"n":5,"m":1,"colores":2}, "casoAleatorio")
generador.generarTest({"n":5,"m":1,"colores":2}, "casoPiezasIncompatibles")
generador.generarTest({"n":5,"m":1,"colores":2}, "casoTrivial")
generador.generarTest({"n":5,"m":1,"colores":3}, "casoAleatorio")
generador.generarTest({"n":5,"m":1,"colores":3}, "casoPiezasIncompatibles")
generador.generarTest({"n":5,"m":1,"colores":3}, "casoTrivial")
generador.generarTest({"n":5,"m":1,"colores":2}, "casoAleatorio")
generador.generarTest({"n":5,"m":1,"colores":2}, "casoPiezasIncompatibles")
generador.generarTest({"n":5,"m":1,"colores":2}, "casoTrivial")
generador.generarTest({"n":5,"m":1,"colores":4}, "casoAleatorio")
generador.generarTest({"n":5,"m":1,"colores":4}, "casoPiezasIncompatibles")
generador.generarTest({"n":5,"m":1,"colores":4}, "casoTrivial")
generador.generarTest({"n":5,"m":1,"colores":5}, "casoAleatorio")
generador.generarTest({"n":5,"m":1,"colores":5}, "casoPiezasIncompatibles")
generador.generarTest({"n":5,"m":1,"colores":5}, "casoTrivial")

generador.generarTest({"n":5,"m":2,"colores":2}, "casoAleatorio")
generador.generarTest({"n":5,"m":2,"colores":2}, "casoPiezasIncompatibles")
generador.generarTest({"n":5,"m":2,"colores":2}, "casoTrivial")
generador.generarTest({"n":5,"m":2,"colores":3}, "casoAleatorio")
generador.generarTest({"n":5,"m":2,"colores":3}, "casoPiezasIncompatibles")
generador.generarTest({"n":5,"m":2,"colores":3}, "casoTrivial")
generador.generarTest({"n":5,"m":2,"colores":2}, "casoAleatorio")
generador.generarTest({"n":5,"m":2,"colores":2}, "casoPiezasIncompatibles")
generador.generarTest({"n":5,"m":2,"colores":2}, "casoTrivial")
generador.generarTest({"n":5,"m":2,"colores":4}, "casoAleatorio")
generador.generarTest({"n":5,"m":2,"colores":4}, "casoPiezasIncompatibles")
generador.generarTest({"n":5,"m":2,"colores":4}, "casoTrivial")
generador.generarTest({"n":5,"m":2,"colores":5}, "casoAleatorio")
generador.generarTest({"n":5,"m":2,"colores":5}, "casoPiezasIncompatibles")
generador.generarTest({"n":5,"m":2,"colores":5}, "casoTrivial")

generador.generarTest({"n":4,"m":1,"colores":2}, "casoAleatorio")
generador.generarTest({"n":4,"m":1,"colores":2}, "casoPiezasIncompatibles")
generador.generarTest({"n":4,"m":1,"colores":2}, "casoTrivial")
generador.generarTest({"n":4,"m":1,"colores":3}, "casoAleatorio")
generador.generarTest({"n":4,"m":1,"colores":3}, "casoPiezasIncompatibles")
generador.generarTest({"n":4,"m":1,"colores":3}, "casoTrivial")
generador.generarTest({"n":4,"m":1,"colores":2}, "casoAleatorio")
generador.generarTest({"n":4,"m":1,"colores":2}, "casoPiezasIncompatibles")
generador.generarTest({"n":4,"m":1,"colores":2}, "casoTrivial")
generador.generarTest({"n":4,"m":1,"colores":4}, "casoAleatorio")
generador.generarTest({"n":4,"m":1,"colores":4}, "casoPiezasIncompatibles")
generador.generarTest({"n":4,"m":1,"colores":4}, "casoTrivial")

generador.generarTest({"n":4,"m":2,"colores":2}, "casoAleatorio")
generador.generarTest({"n":4,"m":2,"colores":2}, "casoPiezasIncompatibles")
generador.generarTest({"n":4,"m":2,"colores":2}, "casoTrivial")
generador.generarTest({"n":4,"m":2,"colores":3}, "casoAleatorio")
generador.generarTest({"n":4,"m":2,"colores":3}, "casoPiezasIncompatibles")
generador.generarTest({"n":4,"m":2,"colores":3}, "casoTrivial")
generador.generarTest({"n":4,"m":2,"colores":2}, "casoAleatorio")
generador.generarTest({"n":4,"m":2,"colores":2}, "casoPiezasIncompatibles")
generador.generarTest({"n":4,"m":2,"colores":2}, "casoTrivial")
generador.generarTest({"n":4,"m":2,"colores":4}, "casoAleatorio")
generador.generarTest({"n":4,"m":2,"colores":4}, "casoPiezasIncompatibles")
generador.generarTest({"n":4,"m":2,"colores":4}, "casoTrivial")


generador.generarTest({"n":4,"m":3,"colores":2}, "casoAleatorio")
generador.generarTest({"n":4,"m":3,"colores":2}, "casoPiezasIncompatibles")
generador.generarTest({"n":4,"m":3,"colores":2}, "casoTrivial")
generador.generarTest({"n":4,"m":3,"colores":3}, "casoAleatorio")
generador.generarTest({"n":4,"m":3,"colores":3}, "casoPiezasIncompatibles")
generador.generarTest({"n":4,"m":3,"colores":3}, "casoTrivial")
generador.generarTest({"n":4,"m":3,"colores":2}, "casoAleatorio")
generador.generarTest({"n":4,"m":3,"colores":2}, "casoPiezasIncompatibles")
generador.generarTest({"n":4,"m":3,"colores":2}, "casoTrivial")
generador.generarTest({"n":4,"m":3,"colores":4}, "casoAleatorio")
generador.generarTest({"n":4,"m":3,"colores":4}, "casoPiezasIncompatibles")
generador.generarTest({"n":4,"m":3,"colores":4}, "casoTrivial")


generador.generarTest({"n":6,"m":1,"colores":2}, "casoAleatorio")
generador.generarTest({"n":6,"m":1,"colores":2}, "casoPiezasIncompatibles")
generador.generarTest({"n":6,"m":1,"colores":2}, "casoTrivial")
generador.generarTest({"n":6,"m":1,"colores":3}, "casoAleatorio")
generador.generarTest({"n":6,"m":1,"colores":3}, "casoPiezasIncompatibles")
generador.generarTest({"n":6,"m":1,"colores":3}, "casoTrivial")
generador.generarTest({"n":6,"m":1,"colores":2}, "casoAleatorio")
generador.generarTest({"n":6,"m":1,"colores":2}, "casoPiezasIncompatibles")
generador.generarTest({"n":6,"m":1,"colores":2}, "casoTrivial")
generador.generarTest({"n":6,"m":1,"colores":4}, "casoAleatorio")
generador.generarTest({"n":6,"m":1,"colores":4}, "casoPiezasIncompatibles")
generador.generarTest({"n":6,"m":1,"colores":4}, "casoTrivial")

generador.generarTest({"n":7,"m":1,"colores":2}, "casoAleatorio")
generador.generarTest({"n":7,"m":1,"colores":2}, "casoPiezasIncompatibles")
generador.generarTest({"n":7,"m":1,"colores":2}, "casoTrivial")
generador.generarTest({"n":7,"m":1,"colores":3}, "casoAleatorio")
generador.generarTest({"n":7,"m":1,"colores":3}, "casoPiezasIncompatibles")
generador.generarTest({"n":7,"m":1,"colores":3}, "casoTrivial")
generador.generarTest({"n":7,"m":1,"colores":2}, "casoAleatorio")
generador.generarTest({"n":7,"m":1,"colores":2}, "casoPiezasIncompatibles")
generador.generarTest({"n":7,"m":1,"colores":2}, "casoTrivial")
generador.generarTest({"n":7,"m":1,"colores":4}, "casoAleatorio")
generador.generarTest({"n":7,"m":1,"colores":4}, "casoPiezasIncompatibles")
generador.generarTest({"n":7,"m":1,"colores":4}, "casoTrivial")
generador.generarTest({"n":7,"m":1,"colores":5}, "casoAleatorio")
generador.generarTest({"n":7,"m":1,"colores":5}, "casoPiezasIncompatibles")
generador.generarTest({"n":7,"m":1,"colores":5}, "casoTrivial")

generador.generarTest({"n":8,"m":1,"colores":2}, "casoAleatorio")
generador.generarTest({"n":8,"m":1,"colores":2}, "casoPiezasIncompatibles")
generador.generarTest({"n":8,"m":1,"colores":2}, "casoTrivial")
generador.generarTest({"n":8,"m":1,"colores":3}, "casoAleatorio")
generador.generarTest({"n":8,"m":1,"colores":3}, "casoPiezasIncompatibles")
generador.generarTest({"n":8,"m":1,"colores":3}, "casoTrivial")
generador.generarTest({"n":8,"m":1,"colores":2}, "casoAleatorio")
generador.generarTest({"n":8,"m":1,"colores":2}, "casoPiezasIncompatibles")
generador.generarTest({"n":8,"m":1,"colores":2}, "casoTrivial")
generador.generarTest({"n":8,"m":1,"colores":4}, "casoAleatorio")
generador.generarTest({"n":8,"m":1,"colores":4}, "casoPiezasIncompatibles")
generador.generarTest({"n":8,"m":1,"colores":4}, "casoTrivial")
generador.generarTest({"n":8,"m":1,"colores":5}, "casoAleatorio")
generador.generarTest({"n":8,"m":1,"colores":5}, "casoPiezasIncompatibles")
generador.generarTest({"n":8,"m":1,"colores":5}, "casoTrivial")

generador.generarTest({"n":9,"m":1,"colores":2}, "casoAleatorio")
generador.generarTest({"n":9,"m":1,"colores":2}, "casoPiezasIncompatibles")
generador.generarTest({"n":9,"m":1,"colores":2}, "casoTrivial")
generador.generarTest({"n":9,"m":1,"colores":3}, "casoAleatorio")
generador.generarTest({"n":9,"m":1,"colores":3}, "casoPiezasIncompatibles")
generador.generarTest({"n":9,"m":1,"colores":3}, "casoTrivial")
generador.generarTest({"n":9,"m":1,"colores":2}, "casoAleatorio")
generador.generarTest({"n":9,"m":1,"colores":2}, "casoPiezasIncompatibles")
generador.generarTest({"n":9,"m":1,"colores":2}, "casoTrivial")
generador.generarTest({"n":9,"m":1,"colores":4}, "casoAleatorio")
generador.generarTest({"n":9,"m":1,"colores":4}, "casoPiezasIncompatibles")
generador.generarTest({"n":9,"m":1,"colores":4}, "casoTrivial")
generador.generarTest({"n":9,"m":1,"colores":5}, "casoAleatorio")
generador.generarTest({"n":9,"m":1,"colores":5}, "casoPiezasIncompatibles")
generador.generarTest({"n":9,"m":1,"colores":5}, "casoTrivial")


generador.generarTest({"n":10,"m":1,"colores":2}, "casoAleatorio")
generador.generarTest({"n":10,"m":1,"colores":2}, "casoPiezasIncompatibles")
generador.generarTest({"n":10,"m":1,"colores":2}, "casoTrivial")
generador.generarTest({"n":10,"m":1,"colores":3}, "casoAleatorio")
generador.generarTest({"n":10,"m":1,"colores":3}, "casoPiezasIncompatibles")
generador.generarTest({"n":10,"m":1,"colores":3}, "casoTrivial")
generador.generarTest({"n":10,"m":1,"colores":2}, "casoAleatorio")
generador.generarTest({"n":10,"m":1,"colores":2}, "casoPiezasIncompatibles")
generador.generarTest({"n":10,"m":1,"colores":2}, "casoTrivial")
generador.generarTest({"n":10,"m":1,"colores":4}, "casoAleatorio")
generador.generarTest({"n":10,"m":1,"colores":4}, "casoPiezasIncompatibles")
generador.generarTest({"n":10,"m":1,"colores":4}, "casoTrivial")
generador.generarTest({"n":10,"m":1,"colores":5}, "casoAleatorio")
generador.generarTest({"n":10,"m":1,"colores":5}, "casoPiezasIncompatibles")
generador.generarTest({"n":10,"m":1,"colores":5}, "casoTrivial")

generador.generarTest({"n":11,"m":1,"colores":2}, "casoAleatorio")
generador.generarTest({"n":11,"m":1,"colores":2}, "casoPiezasIncompatibles")
generador.generarTest({"n":11,"m":1,"colores":2}, "casoTrivial")
generador.generarTest({"n":11,"m":1,"colores":3}, "casoAleatorio")
generador.generarTest({"n":11,"m":1,"colores":3}, "casoPiezasIncompatibles")
generador.generarTest({"n":11,"m":1,"colores":3}, "casoTrivial")
generador.generarTest({"n":11,"m":1,"colores":2}, "casoAleatorio")
generador.generarTest({"n":11,"m":1,"colores":2}, "casoPiezasIncompatibles")
generador.generarTest({"n":11,"m":1,"colores":2}, "casoTrivial")
generador.generarTest({"n":11,"m":1,"colores":4}, "casoAleatorio")
generador.generarTest({"n":11,"m":1,"colores":4}, "casoPiezasIncompatibles")
generador.generarTest({"n":11,"m":1,"colores":4}, "casoTrivial")
generador.generarTest({"n":11,"m":1,"colores":5}, "casoAleatorio")
generador.generarTest({"n":11,"m":1,"colores":5}, "casoPiezasIncompatibles")
generador.generarTest({"n":11,"m":1,"colores":5}, "casoTrivial")

generador.generarTest({"n":12,"m":1,"colores":2}, "casoAleatorio")
generador.generarTest({"n":12,"m":1,"colores":2}, "casoPiezasIncompatibles")
generador.generarTest({"n":12,"m":1,"colores":2}, "casoTrivial")
generador.generarTest({"n":12,"m":1,"colores":3}, "casoAleatorio")
generador.generarTest({"n":12,"m":1,"colores":3}, "casoPiezasIncompatibles")
generador.generarTest({"n":12,"m":1,"colores":3}, "casoTrivial")
generador.generarTest({"n":12,"m":1,"colores":2}, "casoAleatorio")
generador.generarTest({"n":12,"m":1,"colores":2}, "casoPiezasIncompatibles")
generador.generarTest({"n":12,"m":1,"colores":2}, "casoTrivial")
generador.generarTest({"n":12,"m":1,"colores":4}, "casoAleatorio")
generador.generarTest({"n":12,"m":1,"colores":4}, "casoPiezasIncompatibles")
generador.generarTest({"n":12,"m":1,"colores":4}, "casoTrivial")
generador.generarTest({"n":12,"m":1,"colores":5}, "casoAleatorio")
generador.generarTest({"n":12,"m":1,"colores":5}, "casoPiezasIncompatibles")
generador.generarTest({"n":12,"m":1,"colores":5}, "casoTrivial")


print (" Los test se generaron correctamente ")
