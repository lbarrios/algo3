#include "ej3.h"
#include "TestCaseEj3.h"

class Tablero {
public:
  Tablero( uint32_t filas, uint32_t columnas){
    cantidadDePosiciones = filas*columnas;
  };
  uint32_t piezas[cantidadDeFilas][cantidadDeColumnas]; // Referencia a listaDePiezas
  uint32_t cantidadDeCeros;
  uint32_t cantidadDePosiciones;
};

class IndiceDeColores {
public:
  IndiceDeColores( uint32_t cantidadDeColores ){
    /** PSEUDOCODIGO
    vector< list< uint32_t > > bla; vector.reserve(cantidadDeColores);
    inicializar v con bla * cantidadDeColores;
    **/
  };
  vector< vector< list< uint32_t > > > v;
  agregarPieza ( uint32_t indice, uint32_t colorIzquierda, uint32_t colorDerecha ){

  }
};

uint32_t maximoDePiezas;
vector<TestCaseEj3::Pieza> *listaDePiezas;

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
    uint32_t cantidadDeFilas = testcase.dameCantidadDeFilas();
    uint32_t cantidadDeColumnas = testcase.dameCantidadDeColumnas(void);
    uint32_t cantidadDeColores = testcase.dameCantidadDeColores(void);
    // Inicializo estructuras del Ej.
    listaDePiezas = testcase.dameListaDePiezas(void);
    IndiceDeColores indiceDeColores(cantidaDeColores);
    Tablero tablero(cantidaDeFilas, cantidadColumnas);
    // Agrego las piezas al índice de piezas por color
    for (int i = 0; i<listaDePiezas->size(); i++){
      uint32_t colorIzquierda = listaDePiezas[i].colorIzquierda;
      uint32_t colorDerecha = listaDePiezas[i].colorDerecha;
      indiceDeColores.agregarPieza( i, colorIzquierda, colorDerecha );
    }

    backtrack( tablero, indiceDeColores, x, y );

    // Mido el tiempo final
    imprimirTiempoFinal();
    // Devuelvo el resultado con el formato solicitado
    #ifndef TIME
    parser.dameOutput() << endl;
    #endif
  }
}

void backtrack( Tablero &t, IndiceDeColores &ic, uint32_t x, uint32_t y ){
  
}
