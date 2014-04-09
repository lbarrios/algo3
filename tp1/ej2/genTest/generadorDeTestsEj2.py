import os
import random
import sys


class generadorDeTests:
  
  def __init__ (self, inputDir = "input", outputDir= "output"):
    self.inputDir = inputDir
    self.outputDir = outputDir
    if not os.path.exists( self.inputDir ):
      raise Exception ("No existe el direcorio de input")
    if not os.path.exists( self.outputDir ):
      raise Exception ("No existe el directio de output")
    self.nombresFuncionesGeneradoras = {}

  def generarTest(self, n, nombre, cantCasos = 20):
    """ Genera un test completo y lo guarda en el directorio que se asignó para los inputs """
    genCasos = self.nombresFuncionesGeneradoras.get(nombre)
    if not genCasos:
      raise Exception("Nombre debe pertenecer a la lista: [ {} ]".format( " ,".join( [ key for key in nombresFuncionesGeneradoras.keys() ])))
    os.chdir ( self.inputDir )
    nombreArchivo = "{}_{:0>10}.txt".format(nombre, n)
    if os.path.isfile( nombreArchivo ):
      os.remove( nombreArchivo)

    with open( nombreArchivo , "a") as archivo:
      test = []
      for i in range( cantCasos ):
        test.append (genCasos(n))
      archivo.write( "\n".join(test))
      archivo.write( "\n0" )
    os.chdir ("..")


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
