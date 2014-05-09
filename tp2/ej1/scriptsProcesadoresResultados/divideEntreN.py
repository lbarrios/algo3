from glob import glob

def extraerParametro( nomArch, nomPar="n", lenPar=6):
    posIni = nomArch.find( nomPar )+ len(nomPar)
    return nomArch[ posIni : posIni+lenPar]



listaArchivos = glob("../output/graficoDivision/*.txt.time")



for archivo in listaArchivos:
    n = int(extraerParametro(archivo.split("/")[-1]))
    nuevasLineas = []
    with open(archivo) as contenido:
        for linea in contenido:
            nuevaLinea = linea.split()
            nuevaLinea[1] = "{:.3f}".format(int( nuevaLinea[1]) /n)
            nuevasLineas.append( " ".join( nuevaLinea ))
   with open(archivo, "w") as arch:
        arch.write( "\n".join( nuevasLineas ))

