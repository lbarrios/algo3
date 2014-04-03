import os
import random
import sys


from generadorDeTests import generadorDeTests

class generadorDeTestsEj3 (generadorDeTests):
  """ Generador de test para el ejercicio 1"""
  limPerdidaDiaria = 10**3 # número máximo que se le asigna al intervalo del inspector.
  limTiempoDeElaboracion = 10**3 # Número máximo que se le asigna a la fecha de los camiones.

  def __init__(self, inputDir = "input", outputDir = "output"):
    super(generadorDeTestsEj3, self).__init__(inputDir, outputDir)
    self.nombresFuncionesGeneradoras =  {
                                          "casoAleatorio": self.nuevoCasoAleatorio,
                                        }

  def nuevoCasoAleatorio (self, params):
    """Genera un caso de test completamente aleatorio
    Toma un diccionario de parámetros."""
    n = params["n"]
    m = params["m"]
    colores = params["colores"]
    primeraLinea = "{} {} {}".format(n,m, colores)
    listaPiezas = []
    for i in range(n):
      valor = lambda: random.randint(1,colores+1)
      listaPiezas.append( "{} {} {} {}".format( valor(), valor(), valor(), valor()))

    return "{}\n{}".format( primeraLinea, "\n".join(listaPiezas))


if __name__ == '__main__':
  coso = generadorDeTestsEj3();
  print ( coso.nuevoCasoAleatorio({"n":3,"m":3,"colores":4}))
  coso.generarTest({"n":3,"m":4,"colores":10} , "casoAleatorio")
