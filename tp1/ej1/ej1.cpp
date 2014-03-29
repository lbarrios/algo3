#include "ej1.h"
#include "TestCaseEj1.h"

int main( int argc, char** argv ){
	/*
		Parseo los parámetros con que fue llamado
		el ejecutable
	*/
	ParserDeParametros parser( argc, argv );
    TestCaseEj1 testcase ( parser.tipoInput() );
    testcase.imprimir();
	/*
	if( ! parser . parametrosSonValidos() ) {
		return -1;
	}
	*/

	/*
		Creo una instancia nula del ejercicio y luego
		itero sobre el input hasta obtener input nulo
	*/
/*
	while( obtenerInput( parser.input() ) ){
		ejercicio.resolver();
		#ifndef TIME
			//imprimirOutput( parser.output() );
		#else
			//imprimirTiempo();
		#endif
	}
*/
	cout << "Testeando..." << endl;
	return 0;
}

bool obtenerInput(istream &input){
	int testcase;
	input >> testcase;
	return false;
}
