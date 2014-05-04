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





class GeneradorDeTestsEj1 (GeneradorDeTests):
  """ Generador de test para el ejercicio 1"""
  rangoCartas = 1000

  def __init__(self, inputDir = "input", outputDir = "output"):
    super(GeneradorDeTestsEj1, self).__init__(inputDir)
    self.nombresFuncionesGeneradoras =  {
                                          "casoAleatorio": self.nuevoCasoAleatorio,
                                          "mejorCaso": self.nuevoCasoTodosPositivos,
                                          "peorCaso": self.nuevoCasoTodosNegativosIguales,
                                        }

  def nuevoCasoAleatorio (self, params):
    """Genera un caso de test completamente aleatorio
    Toma un diccionario de parámetros."""
    n = params["n"]
    listaPiezas = [ str(random.randint(-self.rangoCartas, self.rangoCartas)) for i in range(n) ]
    return " ".join( [str(n)] + listaPiezas )

  def nuevoCasoTodosPositivos (self, params):
    """Genera un caso de test donde todas las cartas tienen númerospositiovos
    Toma un diccionario de parámetros."""
    n = params["n"]
    listaPiezas = [str( random.randint(1, self.rangoCartas) ) for i in range(n) ]
    return " ".join( [str(n)] + listaPiezas )

  def nuevoCasoTodosNegativosIguales(self, params):
    """Genera un caso de test donde todos los números son negativos iguales"""
    return "{} {}".format( str( params["n"]) , " ".join( [str( random.randint(-self.rangoCartas, 0) )]* params["n"])) # Perdón por poner todo en una línea. Era demasiado tentador.



if __name__ == '__main__':
  coso = GeneradorDeTestsEj1();
  print ( coso.nuevoCasoAleatorio({"n":3}))
  print ( coso.nuevoCasoTodosPositivos( {"n":10}))
  print ( coso.nuevoCasoTodosNegativosIguales({"n":10}) )
  coso.generarTest({"n":5}, "casoAleatorio")
  coso.generarTest({"n":10, "zapato":3, "lalafra":6}, "mejorCaso")
  coso.generarTest({"n":100}, "peorCaso")
