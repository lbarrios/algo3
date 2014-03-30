#include "ej3.h"
#include "TestCaseEj3.h"

int main( int argc, char** argv ){
  /*
    Parseo los parámetros con que fue llamado
    el ejecutable
  */
  ParserDeParametros parser( argc, argv );
  /*
    Esta clase representa un caso de prueba,
    y lo toma desde el input que le provee el parser
  */
    TestCaseEj3 testcase ( parser.dameInput() );
  /*
    Itero sobre los distintos casos de prueba
    hasta obtener un testcase nulo
  */
  while( testcase.tomarDatos() != false ){
    // Mido el tiempo inicial
    tomarTiempoInicial();
    // Obtengo los parámetros del testcase.
    
    /**
     *
     *
     *  COMPLETAR CÓDIGO
     *
     * 
     */

    // Mido el tiempo final
    imprimirTiempoFinal();
    // Devuelvo el resultado con el formato solicitado
    #ifndef TIME
    parser.dameOutput() << endl;
    #endif
  }
}
