#include Makefile.gen
USES= gmake

.PHONY: all allBSD clean cleanBSD

all:
	cd ej1 && make all
	cd ej2 && make all
	cd ej3 && make all
	cd informe && make all

allBSD:
	cd ej1 && gmake all
	cd ej2 && gmake all
	cd ej3 && gmake all
	#cd informe && gmake all # igual no tengo latex

cleanBSD:
	cd ej1 && gmake clean
	cd ej2 && gmake clean
	cd ej3 && gmake clean
	cd informe && gmake clean clean-trash

clean:
	cd ej1 && make clean
	cd ej2 && make clean
	cd ej3 && make clean
	cd informe && make clean clean-trash
