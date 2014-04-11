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

  def generarTest(self, params, nombre, cantCasos = 20):
    """ Genera un test completo y lo guarda en el directorio que se asignó para los inputs """
    n = params["n"]
    a = params.get("amplitud", False)
    cwd = os.getcwd();
    genCasos = self.nombresFuncionesGeneradoras.get(nombre)
    if not genCasos:
      raise Exception("Nombre debe pertenecer a la lista: [ {} ]".format( " ,".join( [ key for key in nombresFuncionesGeneradoras.keys() ])))
    os.chdir ( self.inputDir )
    nombreArchivo = "{}_{:0>10}.txt".format(nombre, n) if not a else "{}_{:1.4f}".format(nombre,a)
    if os.path.isfile( nombreArchivo ):
      os.remove( nombreArchivo)

    with open( nombreArchivo , "a") as archivo:
      test = []
      for i in range( cantCasos ):
        test.append (genCasos( params ))
      archivo.write( "\n".join(test))
      archivo.write( "\n0" )
    os.chdir (cwd)

class generadorDeTestsEj1 (generadorDeTests):
  """ Generador de test para el ejercicio 1"""
  limIntervaloInspector_p = 500 # número máximo que se le asigna al intervalo del inspector.
  limFechasCamiones_p = 4000 # Número máximo que se le asigna a la fecha de los camiones.

  def __init__(self, inputDir = "input", outputDir = "output"):
    super(generadorDeTestsEj1, self).__init__(inputDir, outputDir)
    self.nombresFuncionesGeneradoras = { 
                        "casoAleatorio": self.nuevoCasoAleatorio,
                        "casoAscendente": self.nuevoCasoOrdenadoCrecientemente,
                        "casoDescendente": self.nuevoCasoOrdenadoDecrecientemente,
                      }



  def nuevoCasoAleatorio (self, params):
    """Genera un caso de test completamente aleatorio"""
    n = params["n"]
    limIntervaloInspector =params.get( "limIntervaloInspector", self.limIntervaloInspector_p )
    limFechasCamiones = params.get( "limFechasCamiones", self.limFechasCamiones_p )
    intervaloInspector = random.randint(1, limIntervaloInspector)
    fechasCamiones = []
    for i in range(n):
      fechasCamiones.append( str( random.randint(1, limFechasCamiones)))
    return "{0} {1} {2}".format(intervaloInspector,n, " ".join(fechasCamiones))

  def nuevoCasoOrdenadoCrecientemente (self, params):
    """Genera un caso prueba con las fechas de camiones ordeandas ascendentemente.
    Se pueden tocar los parámetros para poner un intervaloInspector fijo y una determinada
    amplitud en las fechas"""

    n = params["n"]
    factorAmplitud = params.get("amplitud", 1)

    if not "intervaloInspector" in params:
      limIntervaloInspector = params.get( "limIntervaloInspector", self.limIntervaloInspector_p )
      intervaloInspector = random.randint(1, limIntervaloInspector)
    else:
      intervaloInspector = params["intervaloInspector"]

    intervaloMaximo = int(intervaloInspector*factorAmplitud) # está variable está por separado porque este valor se podría querer cambiar.
    fechasCamiones = []
    for i in range(n):
      fechaActual = random.randint( 1, intervaloMaximo )
      fechasCamiones.append( fechaActual )

    fechasCamiones.sort()
    fechasCamiones = [str(fecha) for fecha in fechasCamiones]
    return "{0} {1} {2}".format(intervaloInspector,n, " ".join(fechasCamiones))

  def nuevoCasoOrdenadoDecrecientemente (self, params):
    """Genera un caso prueba con las fechas de camiones ordeandas decrecientemente.
    Se pueden tocar los parámetros para poner un intervaloInspector fijo y una determinada
    amplitud en las fechas"""

    n = params["n"]
    factorAmplitud = params.get("amplitud", 10)

    if not "intervaloInspector" in params:
      limIntervaloInspector = params.get( "limIntervaloInspector", self.limIntervaloInspector_p )
      intervaloInspector = random.randint(1, limIntervaloInspector)
    else:
      intervaloInspector = params["intervaloInspector"]

    intervaloMaximo = intervaloInspector*factorAmplitud # está variable está por separado porque este valor se podría querer cambiar.
    fechasCamiones = []
    for i in range(n):
      fechaActual = random.randint( 1, intervaloMaximo )
      fechasCamiones.append( fechaActual )

    fechasCamiones.sort()
    fechasCamiones.reverse()
    fechasCamiones = [str(fecha) for fecha in fechasCamiones]
    return "{0} {1} {2}".format(intervaloInspector,n, " ".join(fechasCamiones))
    





if __name__ == '__main__':
  coso = generadorDeTestsEj1();
  print ( coso.nuevoCasoAleatorio({"n":3}) )
  print ( coso.nuevoCasoOrdenadoCrecientemente( {"n":10}))
  print ( coso.nuevoCasoOrdenadoCrecientemente( {"n":10, "intervaloInspector":30, "amplitud":5}))
