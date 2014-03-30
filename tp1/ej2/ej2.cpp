#include "ej2.h"
#include "TestCaseEj2.h"

#include <iomanip>

void imprime_piezas(vector<TestCaseEj2::Pieza> *p){
}

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
    TestCaseEj2 testcase ( parser.dameInput() );
  /*
    Itero sobre los distintos casos de prueba
    hasta obtener un testcase nulo
  */
  while( testcase.tomarDatos() != TestCase::TESTCASE_NULL ){
    // Mido el tiempo inicial
    tomarTiempoInicial();
    // Obtengo los parámetros del testcase.
    uint32_t numeroDePiezas = testcase.dameNumeroDePiezasAFabricar();
    vector<TestCaseEj2::Pieza> *piezas = testcase.dameListadoDePiezas();
    sort( piezas->begin(), piezas->end() );
    /* 
      TODO
      ...
      ...
    */
    // Mido el tiempo final
    imprimirTiempoFinal();
    // Devuelvo el resultado con el formato solicitado
    #ifndef TIME
      uint32_t perdidaTotal = 0, tiempoDeFabricacion = 0;
      for(vector<TestCaseEj2::Pieza>::iterator it_pieza = piezas->begin(); 
      it_pieza!=piezas->end(); it_pieza++){
        parser.dameOutput() << (*it_pieza).numeroDeOrden << " ";
        tiempoDeFabricacion += (*it_pieza).tiempoDeFabricacion;
        perdidaTotal += tiempoDeFabricacion*(*it_pieza).perdidaDiariaDeGanancia;
        
        // DEBUG
        cerr << setfill(' ');
        cerr << "Pieza: ";
        cerr << setw(4) << setiosflags(ios::right) << (*it_pieza).numeroDeOrden << ", ";
        cerr << "perdidaDiaria: ";
        cerr << setw(4) << setiosflags(ios::right) << (*it_pieza).perdidaDiariaDeGanancia << ", ";
        cerr << "tiempoPieza: ";
        cerr << setw(4) << setiosflags(ios::right) << (*it_pieza).tiempoDeFabricacion << ", ";
        cerr << "tiempoTotal: ";
        cerr << setw(4) << setiosflags(ios::right) << tiempoDeFabricacion << ", ";
        cerr << "pérdida: ";
        cerr << setw(4) << setiosflags(ios::right) << tiempoDeFabricacion*(*it_pieza).perdidaDiariaDeGanancia << ", ";
        cerr << "pérdidaTotal: ";
        cerr << setw(4) << setiosflags(ios::right) << perdidaTotal << endl;
      }
      parser.dameOutput() << perdidaTotal << endl; 
    #endif
  }
}
