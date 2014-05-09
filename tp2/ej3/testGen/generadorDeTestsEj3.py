import os
import random
import sys


class GeneradorDeTests:
  """Generador de test genérico. Es una clase virtual, no se debe instanciar."""
  
  def __init__ (self, inputDir = "input"):
    self.inputDir = inputDir
    if not os.path.exists( self.inputDir ):
      raise Exception ("No existe el direcorio de input")
    self.nombresFuncionesGeneradoras = {}

  def generarTest(self, params, nombre, cantCasos = 20):
    """ Genera un test completo y lo guarda en el directorio que se asignó para los inputs """
    cwd = os.getcwd()
    genCasos = self.nombresFuncionesGeneradoras.get(nombre)
    if not genCasos:
      raise Exception("Nombre debe pertenecer a la lista: [ {} ]".format( " ,".join( [ key for key in nombresFuncionesGeneradoras.keys() ])))
    os.chdir ( self.inputDir )
    nombreArchivo = nombre + "_"
    for k,v in sorted(params.items()):
      nombreArchivo += "{}{:0>6}_".format(k,v)
    nombreArchivo = nombreArchivo[:-1]+".txt"
    if os.path.isfile( nombreArchivo ):
      os.remove( nombreArchivo)
    with open( nombreArchivo , "a") as archivo:
      test = []
      for i in range( cantCasos ):
        test.append (genCasos(params))
      archivo.write( "\n".join(test) )
      archivo.write( "\n0\n" )
    os.chdir (cwd)





class GeneradorDeTestsEj3 (GeneradorDeTests):
  """ Generador de test para el ejercicio 1"""
  tamMapa = 1000

  def __init__(self, inputDir = "input", outputDir = "output"):
    super(GeneradorDeTestsEj3, self).__init__(inputDir)
    self.nombresFuncionesGeneradoras =  {
                                          "casoAleatorio": self.nuevoCasoAleatorio,
                                        }

  def nuevoCasoAleatorio (self, params):
    """Genera un caso de test completamente aleatorio
    Toma un diccionario de parámetros.
    El "n" es obligatorio pero el "k" es opcional.
    """

    n = params["n"]
    k = params.get("k")
    primeraLinea ="{} {} {} {} {} {}".format(n, random.randint(1, n), random.randint(1, n), random.randint(1, n), random.randint(1,n), k or random.randint(1, 2*n))
    tablero = [ " ".join([ str(random.randint(1,n)) for j in range(n) ]) for i in range(n) ]
    return "{}\n{}".format( primeraLinea, "\n".join(tablero))


if __name__ == '__main__':
  coso = GeneradorDeTestsEj3();
  print ( coso.nuevoCasoAleatorio({"n":3}))
