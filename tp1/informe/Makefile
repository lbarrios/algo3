LATEX = pdflatex
OPTS  = --shell-escape
# La condicion OPTS es para que compile con imagenes .eps
LISTINGOBJS = listings.sty lstdoc.sty lstlang1.sty lstlang2.sty lstlang3.sty lstmisc.sty listings.cfg listings.dtx lstdrvrs.dtx

.PHONY: all clean clean-trash

all: clean introduccion ej1 ej2 ej3 codigo informe

informe: 
# $(LISTINGOBJS)
  @$(LATEX) $(OPTS) informe.tex > /dev/null # Lo corremos dos veces, la primera para que se haga bien el índice
  $(LATEX) $(OPTS) informe.tex
  #@make clean-trash # Para no sobrecargar el directorio

introduccion: introduccion.tex
  $(LATEX) $(OPTS) introduccion.tex
ej1: ej1.tex
  $(LATEX) $(OPTS) ej1.tex
ej2: ej2.tex
  $(LATEX) $(OPTS) ej2.tex
ej3: ej3.tex
  $(LATEX) $(OPTS) ej3.tex
codigo: codigo-fuente.tex
  $(LATEX) $(OPTS) codigo-fuente.tex

#$(LISTINGOBJS):
#  @cp listings/$@ $@

clean-trash: clean
  #@rm -f $(LISTINGOBJS) 
  @rm -f introduccion.pdf ej1.pdf ej2.pdf ej3.pdf codigo-fuente.pdf build
  #@rm -f img/*-eps-converted-to.pdf

clean:
  rm -f *.log *.aux *.toc
