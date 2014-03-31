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

files = sorted(glob("./output/*.time"))
for f in files:
  file = open(f)
  testname = f.split("/")[len(f.split("/"))-1].split("_")[0]
  testsize = f.split("/")[len(f.split("/"))-1].split("_")[1].split(".")[0]
  for line in file:
    testtype = line.split()[0]
    value = line.split()[1]
    x = int(testsize)
    y = int(value)
    tests[testname][testtype][x].append(y)
  file.close()

tests_average_xy = defaultdict(make_listdict)
for testname in tests:
  for testtype in tests[testname]:
    for testsize in tests[testname][testtype]:
      x = testsize
      y = float ( np.mean(tests[testname][testtype][testsize]) / float(1e9) )
      tests_average_xy[testname][testtype].append( (x,y) )
    tests_average_xy[testname][testtype].sort()

t_names = len(tests_average_xy)
t_types = len(tests_average_xy[testname])

colors = ['red','blue','black','green']


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
plt.title("Ejercicio 1")
plt.ylabel('Tiempo (segundos)')
plt.xlabel(u'Tamaño de entrada (camiones)')

for test_number in range(0,t_names):
  testname = tests_average_xy.keys()[test_number]
  testtype = tests_average_xy[testname].keys()[0]#[int(i/t_names)]
  x = np.array( zip(*tests_average_xy[testname][testtype])[0] )
  y = np.array( zip(*tests_average_xy[testname][testtype])[1] )
  plt.plot(x, y, linestyle='-',  color=colors[test_number], linewidth=.6, label=testname)

subplot.plot(x, ((x*np.log(x))*10)/float(1e9),    '--', color='black', linewidth=2, label="c.x.log2(x)")
plt.legend(loc=2)

#plt.show()
if not os.path.exists('./graficos/') or not os.path.isdir('./graficos/'):
  os.makedirs('./graficos/')
plt.savefig("graficos/test_%s.pdf"%strftime("%Y-%m-%d_%H-%M-%S"))