#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys
import os
import numpy as np
from glob import glob
from collections import defaultdict

def make_listdict():
  return defaultdict(list)

def make_listdictdict():
  return defaultdict(make_listdict)

tests = defaultdict(make_listdictdict)

files = sorted(glob("./output/graficoTiempoLiso/*.time"))
for f in files:
  file = open(f)
  testname = f.split("/")[-1].split("_")[0]
  testsize = f.split("/")[-1].split("_")[1].split(".")[0][1:]
  for line in file:
    testtype = line.split()[0]
    value = line.split()[1]
    x = int(testsize)
    y = int(value)
    tests[testname][testtype][x].append(y)
  file.close()

tests_mean_xy = defaultdict(make_listdict)
tests_mean_p_xy = defaultdict(make_listdict)
for testname in tests:
  for testtype in tests[testname]:
    for testsize in tests[testname][testtype]:
      y_values = tests[testname][testtype][testsize]
      y_p_values = [yp for yp in y_values if yp < np.percentile(y_values,75) and yp > np.percentile(y_values,25) ]
      # -
      x = testsize
      y = float( np.mean( y_values ) / float(1e9) )
      y_p = float( np.mean( y_p_values ) / float(1e9) )
      # -
      tests_mean_xy[testname][testtype].append( (x,y) )
      tests_mean_p_xy[testname][testtype].append( (x,y_p) )
    tests_mean_xy[testname][testtype].sort()
    tests_mean_p_xy[testname][testtype].sort()

t_names = len(tests_mean_xy)
t_types = len(tests_mean_xy[testname])

colors = ['blue','green','red','cyan','magenta','yellow','black','grey','white']


import matplotlib.pyplot as plt
import matplotlib.ticker as tck
from time import strftime
# - Arreglo la columna tiempo
formatter = tck.EngFormatter(unit='s', places=1) # Formato "segundos"
formatter.ENG_PREFIXES[-6] = 'u' # Arreglo el símbolo "mu"
# - Creo los subplot
#fig, subplot = plt.subplots(nrows=t_types, ncols=1, sharex=True, sharey=False)
fig,subplot = plt.subplots()
subplot.yaxis.set_major_formatter(formatter)

# Aplico formato
plt.grid(True)
plt.title("Ejercicio 2")
plt.ylabel('Tiempo (segundos)')
plt.xlabel(u'Tamaño de entrada (sapos)')

"""
linestyle or ls [ ‘-‘ | ‘--’ | '.' | ‘-.’ | ‘:’ | ‘steps’ | ...]
marker  [ ‘+’ | ‘,’ | ‘.’ | ‘1’ | ‘2’ | ‘3’ | ‘4’ ]
"""

for test_number in range(0,t_names):
  testname = tests_mean_xy.keys()[test_number]
  testtype = tests_mean_xy[testname].keys()[0]#[int(i/t_names)]
  #x = np.array( zip(*tests_mean_xy[testname][testtype])[0] )
  #y = np.array( zip(*tests_mean_xy[testname][testtype])[1] )
  #plt.plot(x, y, linestyle='-',  color=colors[test_number], linewidth=0.2, label=testname, alpha=1)
  x = np.array( zip(*tests_mean_p_xy[testname][testtype])[0] )
  y = np.array( zip(*tests_mean_p_xy[testname][testtype])[1] )
  plt.plot(x, y, linestyle='-',  color=colors[test_number], linewidth=0.6, label=testname, alpha=1) #, marker='.', markersize=0.3)

subplot.plot(x, ((x*x)*24)/float(1e9),    '--', color='black', linewidth=2, label="$c.x^2$")
plt.legend(loc=2)

#plt.show()
if not os.path.exists('./graficos/') or not os.path.isdir('./graficos/'):
  os.makedirs('./graficos/')
plt.savefig("graficos/test_tiempoLiso.pdf")
