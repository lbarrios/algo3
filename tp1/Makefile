#include Makefile.gen
USES= gmake

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
    MAKE := make
endif
ifeq ($(UNAME_S),FreeBSD)
    MAKE := gmake
endif
ifeq (shell hash rar 1 > /dev/null, 1)
  TAR := rar
else
  ifeq (shell hash zip 1 > /dev/null, 1)
    TAR := zip
  else
    TAR := tar
  endif
endif

.PHONY: all allBSD clean cleanBSD entrega

all:
	cd ej1 && $(MAKE) all
	cd ej2 && $(MAKE) all
	cd ej3 && $(MAKE) all
	cd informe && $(MAKE) all

clean:
	cd ej1 && $(MAKE) clean
	cd ej2 && $(MAKE) clean
	cd ej3 && $(MAKE) clean
	cd informe && $(MAKE) clean clean-trash
	rm -rf entrega entrega.zip entrega.rar entrega.tar.gz entrega.tar.gz.crypt

entrega: clean
	mkdir entrega
	cp -R ej1 entrega
	cp -R ej2 entrega
	cp -R ej3 entrega
	cp -R informe entrega
	rm -rf `find entrega -type d -name .svn`
	cp Makefile Makefile.gen ParserDeParametros.h testcases.h headers.h LEER_COMPILACION entrega/
	ifeq ($(TAR), "rar")
		@rar a -hpalgo3 entrega.rar entrega
	else
		ifeq ($(TAR), zip)
			@zip -r9 -P algo3 entrega.zip entrega
		else
			@tar cfzv entrega.tar.gz entrega
 			#@enigma algo3 < entrega.tar.gz > entrega.tar.gz.crypt
		endif
	endif
	@clear && echo "Se creó el archivo 'entrega.rar' con password 'algo3'"
