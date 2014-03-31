import os
import random
import sys


from .generadorDeTests import generadorDeTests

class generadorDeTestsEj2 (generadorDeTests):
  """ Generador de test para el ejercicio 1"""
  limPerdidaDiaria = 10**3 # número máximo que se le asigna al intervalo del inspector.
  limTiempoDeElaboracion = 10**3 # Número máximo que se le asigna a la fecha de los camiones.

  def __init__(self, inputDir = "input", outputDir = "output"):
    super(generadorDeTestsEj2, self).__init__(inputDir, outputDir)
    self.nombresFuncionesGeneradoras =  {
                                          "casoAleatorio": self.nuevoCasoAleatorio,
                                        }

  def nuevoCasoAleatorio (self, n):
    """Genera un caso de test completamente aleatorio"""
    listaPiezas = []
    for i in range(n):
      listaPiezas.append( "{} {}".format(random.randint(1, self.limPerdidaDiaria), random.randint(1, self.limTiempoDeElaboracion)))
    return "{0}\n{1}".format(n, "\n".join(listaPiezas))







if __name__ == '__main__':
  coso = generadorDeTestsEj2();
  print ( coso.nuevoCasoAleatorio(3))
  coso.generarTest(3, "casoAleatorio")
  coso.generarTest(5, "casoAleatorio")
