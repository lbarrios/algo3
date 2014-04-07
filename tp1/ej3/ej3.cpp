#include "ej3.h"

Tablero& backtrack( Tablero &, IndiceDeColores &, uint32_t );

int main( int argc, char** argv ){
  // Parseo los parámetros con que fue llamado el ejecutable
  ParserDeParametros parser( argc, argv );
  // Esta clase representa un caso de prueba, y lo toma desde el input que le provee el parser
  TestCaseEj3 testcase ( parser.dameInput() );
  Timer timer ( parser.dameTime() );
  _C("Itero sobre los distintos casos de prueba hasta obtener un testcase nulo");
  // Itero sobre los distintos casos de prueba hasta obtener un testcase nulo
  while( testcase.tomarDatos() != false ){
    _C("Mido el tiempo inicial.");
    // Mido el tiempo inicial.
    timer.setInitialTime("todoElCiclo");
    // Obtengo los parámetros del testcase.
    _C("Obtengo los parámetros del testcase.");
    uint32_t cantidadDeFilas = testcase.dameCantidadDeFilas(); DEBUG_UINT(cantidadDeFilas);
    uint32_t cantidadDeColumnas = testcase.dameCantidadDeColumnas(); DEBUG_UINT(cantidadDeColumnas);
    uint32_t cantidadDeColores = testcase.dameCantidadDeColores(); DEBUG_UINT(cantidadDeColores);
    _C("Inicializo estructuras del Ej.");
    // Inicializo estructuras del Ej.
    vector<TestCaseEj3::Pieza>& listaDePiezas = testcase.dameListaDePiezas(); DEBUG_INT(listaDePiezas.size());
    IndiceDeColores indiceDeColores(cantidadDeColores, listaDePiezas);
    Tablero tablero(cantidadDeFilas, cantidadDeColumnas); DEBUG_INT(tablero.cantidadDePosiciones());
    _C("Obtengo el mejor tablero a través de backtracking");
    Tablero &mejorTablero = backtrack( tablero, indiceDeColores, 0 );
    _C("Mido el tiempo final");
    // Mido el tiempo final
    timer.setFinalTime("todoElCiclo");
    imprimirTiempoFinal();
    // Devuelvo el resultado con el formato solicitado
    #ifndef TIME
    for( uint32_t columna = 0; columna < mejorTablero.cantidadDeColumnas; columna++){
      for( uint32_t fila = 0; fila < mejorTablero.cantidadDeFilas; fila++){
        uint32_t posicion = (columna * mejorTablero.cantidadDeFilas) + fila;
        uint32_t pieza = mejorTablero.dameLaPiezaEnPosicion( posicion );
        parser.dameOutput() << pieza << " ";
      }
      parser.dameOutput() << endl;
    }
    #else
    timer.saveAllTimes();
    #endif
  }
  return 0;
}
/**
 * Devuelve la cantidad máxima de posiciones llenas encontradas
 */
Tablero& backtrack( Tablero &t, IndiceDeColores &ic, uint32_t posicion ){
  // Obtengo las piezas de la izquierda y de arriba
  uint32_t piezaIzquierda = t.dameLaPiezaDeIzquierdaDe( posicion );
  uint32_t piezaArriba = t.dameLaPiezaDeArribaDe( posicion );
  // Obtengo la lista de piezas posibles según el índice
  list< uint32_t > *piezasPosibles;
  if( piezaIzquierda == TestCaseEj3::PIEZA_VACIA ){
    piezasPosibles = &(ic.damePiezasPosiblesParaAbajoDe( piezaArriba ));
  }
  else{
    if ( piezaArriba == TestCaseEj3::PIEZA_VACIA ){
      piezasPosibles = &(ic.damePiezasPosiblesParaLaDerechaDe( piezaIzquierda ));
    }
    else{
      piezasPosibles = &(ic.damePiezasPosibles(piezaIzquierda, piezaArriba));
    }
  }
  // Me fijo si estoy antes de la última posición del tablero
  if( posicion < t.cantidadDePosiciones() - 1 ){
    // Si es así, entonces calculo la máxima cantidad de piezas
    // para todas las ramas, y la retorno
    Tablero *mejorTablero = NULL;
    for( list< uint32_t >::iterator pieza = piezasPosibles->begin(); pieza != piezasPosibles->end(); pieza++){
      t.ponerPiezaEnPosicion( *pieza, posicion ); // Pongo pieza en tablero
      ic.quitarPieza( *pieza ); // Quito la pieza del índice
      if ( mejorTablero == NULL ){
        mejorTablero = &(backtrack(t,ic,posicion+1));
      }
      else {
        Tablero *tableroBacktrack = &(backtrack(t,ic,posicion+1));
        if( (*mejorTablero) < (*tableroBacktrack) ){
          delete mejorTablero;
          mejorTablero = tableroBacktrack;
        }
        else {
          delete tableroBacktrack;
        }
      }
      ic.agregarPieza( *pieza ); // Agrego la pieza al índice
    }
    return *mejorTablero;
  } 
  else {
    // De lo contrario (si estoy en la última posición del tablero)
    // retorno una copia de ese tablero
      Tablero& ret = (*new Tablero(t));
      return ret;
  }
}
