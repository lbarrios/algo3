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





class generadorDeTestsEj3 (generadorDeTests):
  """ Generador de test para el ejercicio 1"""
  limPerdidaDiaria = 10**3 # número máximo que se le asigna al intervalo del inspector.
  limTiempoDeElaboracion = 10**3 # Número máximo que se le asigna a la fecha de los camiones.

  def __init__(self, inputDir = "input", outputDir = "output"):
    super(generadorDeTestsEj3, self).__init__(inputDir, outputDir)
    self.nombresFuncionesGeneradoras =  {
                                          "casoAleatorio": self.nuevoCasoAleatorio,
                                          "casoPiezasIncompatibles": self.nuevoCasoPiezasIncompatibles,
                                          "casoTrivial": self.nuevoCasoTrivial,
                                        }

  def nuevoCasoAleatorio (self, params):
    """Genera un caso de test completamente aleatorio
    Toma un diccionario de parámetros."""
    n = params["n"]
    m = params["m"]
    colores = params["colores"]
    primeraLinea = "{} {} {}".format(n,m, colores)
    listaPiezas = []
    for i in range(n*m):
      valor = lambda: random.randint(1,colores)
      listaPiezas.append( "{} {} {} {}".format( valor(), valor(), valor(), valor()))

    return "{}\n{}".format( primeraLinea, "\n".join(listaPiezas))


  def nuevoCasoPiezasIncompatibles(self, params):
    n = params["n"]
    m = params["m"]
    colores = 4 # Uno para cada esquina
    primeraLinea = "{} {} {}".format(n,m,colores)
    listaPiezas = []
    for i in range(n*m):
      listaPiezas.append("1 2 3 4")
    return "{}\n{}".format( primeraLinea, "\n".join(listaPiezas))


  def nuevoCasoTrivial(self, params):
    n = params["n"]
    m = params["m"]
    colores = 4 # Podría ser 1.
    primeraLinea = "{} {} {}".format(n,m,colores)
    listaPiezas = []
    for i in range(n*m):
      listaPiezas.append("1 1 1 1")
    return "{}\n{}".format( primeraLinea, "\n".join(listaPiezas))



  def generarTest(self, params, nombre, cantCasos = 1):
    """ Genera un test completo y lo guarda en el directorio que se asignó para los inputs """
    n = params["n"]
    m = params["m"]
    colores = params["colores"]
    genCasos = self.nombresFuncionesGeneradoras.get(nombre)
    if not genCasos:
      raise Exception("Nombre debe pertenecer a la lista: [ {} ]".format( " ,".join( [ key for key in nombresFuncionesGeneradoras.keys() ])))
    os.chdir ( self.inputDir )
    nombreArchivo = "{}_n{:0>4}m{:0>4}c{:0>4}.txt".format(nombre, n, m, colores)
    if os.path.isfile( nombreArchivo ):
      os.remove( nombreArchivo)

    with open( nombreArchivo , "a") as archivo:
      test = []
      for i in range( cantCasos ):
        test.append (genCasos({"n":n,"m":m,"colores":colores}))
      archivo.write( "\n".join(test))
      archivo.write( "\n0" )
    os.chdir ("..")





if __name__ == '__main__':
  coso = generadorDeTestsEj3();
  print ( coso.nuevoCasoAleatorio({"n":3,"m":3,"colores":4}))
  coso.generarTest({"n":3,"m":4,"colores":10} , "casoAleatorio")
  print (coso.nuevoCasoPiezasIncompatibles({"n":3,"m":3,"colores":10}))
  print (coso.nuevoCasoTrivial({"n":3,"m":3,"colores":10}))
