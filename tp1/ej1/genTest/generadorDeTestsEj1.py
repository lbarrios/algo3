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

class generadorDeTestsEj1 (generadorDeTests):
  """ Generador de test para el ejercicio 1"""
  limIntervaloInspector = 10**4 # número máximo que se le asigna al intervalo del inspector.
  limFechasCamiones = 10**6 # Número máximo que se le asigna a la fecha de los camiones.

  def __init__(self, inputDir = "input", outputDir = "output"):
    super(generadorDeTestsEj1, self).__init__(inputDir, outputDir)
    self.nombresFuncionesGeneradoras = { 
                        "casoAleatorio": self.nuevoCasoAleatorio,
                        "mejorCaso": self.nuevoCasoOrdenadoCrecientemente,
                        "peorCaso": self.nuevoCasoOrdenadoDecrecientemente,
                      }



  def nuevoCasoAleatorio (self, n):
    """Genera un caso de test completamente aleatorio"""
    intervaloInspector = random.randint(1, self.limIntervaloInspector)
    fechasCamiones = []
    for i in range(n):
      fechasCamiones.append( str( random.randint(1, self.limFechasCamiones)))
    return "{0} {1} {2}".format(intervaloInspector,n, " ".join(fechasCamiones))

  def nuevoCasoOrdenadoCrecientemente (self, n):
    """Genera un caso prueba con las fechas de camiones ordeandas ascendentemente."""
    intervaloInspector = random.randint( 1, self.limIntervaloInspector)
    intervaloMaximo = intervaloInspector # esta variable está por separado porque este valor se podría querer cambiar.
    fechasCamiones = []
    fechaActual = random.randint( 1, intervaloMaximo )
    for i in range(n):
      fechasCamiones.append( str(fechaActual) )
      fechaActual += random.randint( 1, intervaloMaximo )
    return "{0} {1} {2}".format(intervaloInspector,n, " ".join(fechasCamiones))

  def nuevoCasoOrdenadoDecrecientemente (self, n):
    """Genera un caso prueba con las fechas de camiones ordeandas decrecientemente."""
    intervaloInspector = random.randint( 1, self.limIntervaloInspector)
    intervaloMaximo = min (self.limFechasCamiones // n, intervaloInspector )
    fechasCamiones = []
    fechaActual = self.limFechasCamiones - random.randint( 1, intervaloMaximo )
    for i in range(n):
      fechasCamiones.append( str(fechaActual) )
      fechaActual -= random.randint( 1, intervaloMaximo )
    return "{0} {1} {2}".format(intervaloInspector,n, " ".join(fechasCamiones))






if __name__ == '__main__':
  coso = generadorDeTestsEj1();
  print ( coso.nuevoCasoAleatorio(3))
  print (coso.nuevoCasoOrdenadoCrecientemente(10))
  print (coso.nuevoCasoOrdenadoDecrecientemente(10))
  coso.generarTest(3, "casoAleatorio",10)
  coso.generarTest(1, "casoAleatorio",10)
