#include "ej3.h"

Tablero& backtrack( Tablero&, IndiceDePiezas&, uint32_t );
void imprimeTablero( Tablero& );

int main( int argc, char** argv )
{
  // Parseo los parámetros con que fue llamado el ejecutable
  ParserDeParametros parser( argc, argv );
  // Esta clase representa un caso de prueba, y lo toma desde el input que le provee el parser
  TestCaseEj3 testcase ( parser.dameInput() );
  Timer timer ( parser.dameTime() );

  // Itero sobre los distintos casos de prueba hasta obtener un testcase nulo
  while ( testcase.tomarDatos() != false )
  {
    // Mido el tiempo inicial.
    timer.setInitialTime( "todoElCiclo" );
    // Obtengo los parámetros del testcase.
    uint32_t cantidadDeFilas = testcase.dameCantidadDeFilas();
    uint32_t cantidadDeColumnas = testcase.dameCantidadDeColumnas();
    uint32_t cantidadDeColores = testcase.dameCantidadDeColores();
    vector<TestCaseEj3::Pieza>& listaDePiezas = testcase.dameListaDePiezas();
    // Inicializo el tablero (estructura auxiliar)
    Tablero tablero( cantidadDeFilas, cantidadDeColumnas );
    // Inicializo el índice de piezas (estructura auxiliar)
    IndiceDePiezas indiceDePiezas( cantidadDeColores, listaDePiezas );
    
    //Obtengo el mejor tablero a través de backtracking
    Tablero& mejorTablero = backtrack( tablero, indiceDePiezas, 0 );
    // Mido el tiempo final
    timer.setFinalTime( "todoElCiclo" );
    timer.saveAllTimes();
    // Devuelvo el resultado con el formato solicitado
#ifndef TIME
    /*
    for( uint32_t columna = 0; columna < mejorTablero.cantidadDeColumnas; columna++)
    {
      for( uint32_t fila = 0; fila < mejorTablero.cantidadDeFilas; fila++)
      {
        uint32_t posicion = (columna * mejorTablero.cantidadDeFilas) + fila;
        uint32_t pieza = mejorTablero.dameLaPiezaEnPosicion( posicion );
        parser.dameOutput() << pieza << " ";
      }
      parser.dameOutput() << endl;
    }
    */
#endif
    delete &mejorTablero;
  }

  return 0;
}

Tablero& backtrack( Tablero& t, IndiceDePiezas& ic, uint32_t posicion )
{
  _C( "Entrando posición: " << posicion ); imprimeTablero( t ); DEBUG_ENTER;
  Tablero* mejorTablero = NULL;
  // Obtengo las piezas de la izquierda y de arriba
  uint32_t piezaIzquierda = t.dameLaPiezaDeIzquierdaDePosicion( posicion );
  uint32_t piezaArriba = t.dameLaPiezaDeArribaDePosicion( posicion );
  piezasPosibles = ic.obtenerPiezasPosibles(piezaIzquierda, piezaArriba);
  // Me fijo si estoy antes de la última posición
  if ( posicion < t.cantidadDePosiciones - 1 )
  {
    // Si es así, entonces llamo a backtrack para cada pieza posible
    while( piezasPosibles.hayPiezasPosibles() )
    {
      pieza = *piezasPosibles;
      t.ponerPiezaEnPosicion( pieza, posicion );
      piezasPosibles.usarPiezaActual();
      if (mejorTablero == NULL)
      {
        mejorTablero = &( backtrack( t, ic, posicion + 1 ) );
      }
      else
      {
        Tablero* otroTablero = &( backtrack( t, ic, posicion + 1 ) );
        if ( otroTablero > mejorTablero )
        {
          mejorTablero = otroTablero;
        }
      }
      piezasPosibles.liberarPiezaActual();
      piezasPosibles++;
    }
  }
  else
  {
    // (si estoy en la última posición del tablero)
    // Intento colocar la última pieza
    // Retorno una copia del tablero final
    mejorTablero = new Tablero( t );
  }

  return *mejorTablero;
}

/**
 * Dado un tablero, lo imprime a consola (stderr).
 */
void imprimeTablero( Tablero& t )
{
  for ( uint32_t y = 0; y < t.cantidadDeFilas; y++ )
  {
    for ( uint32_t x = 0; x < t.cantidadDeColumnas; x++ )
    {
      uint32_t posicion = y * t.cantidadDeColumnas + x;
      cerr << t[posicion] << " ";
    }

    cerr << endl;
  }

  cerr << endl;
}

/**
 * Devuelve la cantidad máxima de posiciones llenas encontradas
 */


/*

Tablero& backtrack( Tablero &t, IndiceDeColores &ic, uint32_t posicion )
{
  _C("Entrando posición: " << posicion);
  imprimeTablero(t);
  DEBUG_ENTER;
  // Obtengo las piezas de la izquierda y de arriba
  uint32_t piezaIzquierda = t.dameLaPiezaDeIzquierdaDe( posicion );
  uint32_t piezaArriba = t.dameLaPiezaDeArribaDe( posicion );
  // Obtengo la lista de piezas posibles según el índice
  _C("Obteniendo lista de piezas posibles");
  IndiceDeColores::Iterador &piezasPosibles = ic.damePiezasPosibles(piezaIzquierda, piezaArriba);
  // Me fijo si estoy antes de la última posición del tablero
  if( posicion < t.cantidadDePosiciones() - 1 )
  {
    // Si es así, entonces calculo la máxima cantidad de piezas para todas las ramas, y la retorno
    Tablero *mejorTablero = NULL;
    while( piezasPosibles.hayPiezasPosibles() )
    {
      uint32_t pieza = *piezasPosibles; // Obtengo la nueva pieza
      DEBUG_INT(pieza);
      uint32_t piezaAnterior = t[posicion]; // Resguardo pieza anterior
      t.ponerPiezaEnPosicion( pieza, posicion ); // Pongo nueva pieza en tablero
      if( pieza != TestCaseEj3::PIEZA_VACIA )
      {
        //_C("Quitando pieza " << *piezasPosibles << " del índice de colores.");
        piezasPosibles.quitarPieza(); // Quito la pieza del índice y obtengo puntero al siguiente
      }
      if ( mejorTablero == NULL )
      {
        _C("BT: Llamando primer backtrack("<<posicion+1<<") desde posicion("<<posicion<<")");
        mejorTablero = &(backtrack(t,ic,posicion+1));
        _C("BT: Regresando de backtrack("<<posicion+1<<") hacia posicion("<<posicion<<")");
      }
      else
      {
        //_C("Llamando backtrack("<<posicion+1<<") desde posicion("<<posicion<<")");
        Tablero *tableroBacktrack = &(backtrack(t,ic,posicion+1));
        //_C("Regresando de backtrack("<<posicion+1<<") hacia posicion("<<posicion<<")");
        if( (*mejorTablero) < (*tableroBacktrack) )
        {
          delete mejorTablero;
          mejorTablero = tableroBacktrack;
        }
        else
        {
          delete tableroBacktrack;
        }
      }
      // Agrego la pieza nuevamente al índice
      imprimeTablero(t);
      if( pieza != TestCaseEj3::PIEZA_VACIA )
      {
        ic.restaurarPieza( piezasPosibles );
      }
      t.ponerPiezaEnPosicion( piezaAnterior, posicion ); // Recupero pieza vieja a tablero
      piezasPosibles++;
    }
    _C("         NO HAY MAS PIEZAS POSIBLES EN LA POSICION "<<posicion);
    delete &piezasPosibles;
    return *mejorTablero;
  }
  else
  { // De lo contrario (si estoy en la última posición del tablero)
    // Intento colocar la última pieza
    if (*piezasPosibles != TestCaseEj3::PIEZA_VACIA)
    { // Si es distinta de "PIEZA VACIA", la pongo en el tablero
      t.ponerPiezaEnPosicion( *piezasPosibles, posicion );
    }
    // Retorno una copia del tablero final
    delete &piezasPosibles;
    Tablero *newTablero = new Tablero(t);
    t.ponerPiezaEnPosicion(TestCaseEj3::PIEZA_VACIA, posicion);
    imprimeTablero(*newTablero);
    return *newTablero;
  }
}

*/

