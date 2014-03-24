#include "headers.h"
struct ParserDeParametros{
private:
	istream *_input;
	ostream *_output;
	fstream finput, foutput;
	bool _sonValidos;
	char* _nombrePrograma;
public:
	istream &input();
	ostream &output();
	bool parametrosSonValidos( void );
	ParserDeParametros(int argc, char** argv);
	void imprimirAyuda( void );
};
