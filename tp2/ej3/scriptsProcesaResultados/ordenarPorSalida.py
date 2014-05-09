from glob import glob

listaDeArchivos = glob("../output/graficoOrdenadoPorSalida/*.txt")

for a in listaDeArchivos:
    print( a )
    
