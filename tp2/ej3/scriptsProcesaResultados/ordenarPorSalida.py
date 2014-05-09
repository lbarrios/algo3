from glob import glob
import os

def extraerParametro( nomArch, nomPar="n", lenPar=6):
    posIni = nomArch.find( nomPar )+ len(nomPar)
    return nomArch[ posIni : posIni+lenPar]



listaDeArchivos = glob("../output/graficoOrdenadoPorSalida/*.txt")

tamDeCada = {}

for nombre in listaDeArchivos:
    valor = 0
    with open(nombre) as archivo:
        valor = archivo.readline()
    tamDeCada[ extraerParametro( nombre.split("/")[-1], "id") ] = int(valor)


listaDeTiempos = glob("../output/graficoOrdenadoPorSalida/*.txt.time")

for nombre in listaDeTiempos:
    id = extraerParametro( nombre.split("/")[-1], "id" )
    #os.rename( nombre, nombre.replace(".txt.time", "{}.txt.time".format() )
    print( nombre.replace(".txt.time", "res_{}.txt.time".format( tamDeCada[id] )))


