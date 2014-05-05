#!/usr/bin/env python3
from glob import glob
import os
import sys

# Parámetros:
inputDirList = ["input/graficoComparacion", "input/graficoDivision"]

try:
    arg = sys.argv[1]
except:
    arg = "-time"



if( arg == "-resultados"):
    def correr(archivo):
        os.system("./ej1 < {} > {}".format(archivo, output))
elif (arg == "-todo"):
    def correr(archivo):
        os.system("./ej1 < {} > {}".format(archivo, output))
        os.system("./ej1.time < {} > {}".format(archivo, output + ".time"))
else:
    def correr(archivo):
        os.system("./ej1.time < {} > {}".format(archivo, output+ ".time"))


for dir in inputDirList:
    inputFiles = glob( "{}/*.txt".format(dir))
    for file in sorted(inputFiles):
        output = file.replace("input","output")
        print("corriendo:", file)
        correr(file)

