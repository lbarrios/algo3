#include "ej3.h"
#include "Tablero.h"
#include "IndiceDePiezas.h"

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
    Tablero tablero( cantidadDeFilas, cantidadDeColumnas, listaDePiezas );
    // Inicializo el índice de piezas (estructura auxiliar)
    IndiceDePiezas indiceDePiezas( cantidadDeColores, listaDePiezas, tablero );
    //Obtengo el mejor tablero a través de backtracking
    Tablero& mejorTablero = backtrack( tablero, indiceDePiezas, 0 );
    // Mido el tiempo final
    timer.setFinalTime( "todoElCiclo" );
    timer.saveAllTimes();
    // Devuelvo el resultado con el formato solicitado
#ifndef TIME

    for ( uint32_t columna = 0; columna < mejorTablero.cantidadDeColumnas; columna++ )
    {
      for ( uint32_t fila = 0; fila < mejorTablero.cantidadDeFilas; fila++ )
      {
        uint32_t posicion = ( columna * mejorTablero.cantidadDeFilas ) + fila;
        uint32_t pieza = mejorTablero[ posicion ];
        parser.dameOutput() << pieza << " ";
      }

      parser.dameOutput() << endl;
    }

#endif
    delete &mejorTablero;
  }

  return 0;
}

Tablero& backtrack( Tablero& t, IndiceDePiezas& ip, uint32_t posicion )
{
  DEBUG_ENTER; _C( "Entrando a recursión en posición: " << posicion + 1 );
  Tablero* mejorTablero = NULL;

  /*
  // Poda
  if ( t.yaEncontreElMejorTableroPosible() )
  {
    _C( "PODANDO CON MEJOR TABLERO POSIBLE" );
    // Si ya encontré el mejor tablero posible,
    // corto todas las recursiones retornando nulo
    return *mejorTablero;
  }
  */

	#ifndef SINPODAOBJETIVO
  if ( t.yaEncontreUnTableroMejor( posicion ) )
  {
    _C( "PODANDO EN POS " << posicion <<" PORQUE EXISTE UN TABLERO mejor QUE CUALQUIERA DE ESTA RAMA" );
    return *mejorTablero;
  }
  #endif
  

  IteradorIndiceDePiezas& it = ip.dameIterador( posicion );
  _C("Obtenido iterador al indice de piezas");

  // Me fijo si estoy antes de la última posición
  if ( posicion < t.cantidadDePosiciones - 1 )
  {
    while ( it.hayPiezasPosibles() )
    {
      _C( "Pieza disponible: " << *it );
      // Si es así, entonces llamo a backtrack para cada pieza posible
      t.ponerPiezaEnPosicion( *it, posicion );
      ip.marcarPiezaUtilizada( it );
      // Hago recursión en el backtracking
      Tablero* otroTablero = NULL;
      otroTablero = &( backtrack( t, ip, posicion + 1 ) );
      _C( "VOLVIENDO A POSICION " << posicion );

      if ( !mejorTablero )
      {
        mejorTablero = otroTablero;
      }
      else
      {
        if ( !otroTablero )
        {
          ip.marcarPiezaDisponible ( it );
          // Si la recursión me devolvió un puntero a nulo termino el BT
          break;
        }
        else
        {
          if ( *mejorTablero < *otroTablero )
          {
            delete mejorTablero;
            mejorTablero = otroTablero;
          }
          else
          {
            delete otroTablero;
          }
        }
      }

      ip.marcarPiezaDisponible ( it );
      it++;
    }
  }
  else
  {
    // (si estoy en la última posición del tablero)
    // Intento colocar la última pieza
    if ( it.hayPiezasPosibles() )
    {
      t.ponerPiezaEnPosicion( *it, posicion );
    }

    // Creo una copia del tablero final
    mejorTablero = new Tablero( t );
    // Pongo una pieza transparente en el lugar donde puse (o no) una pieza
    t.ponerPiezaEnPosicion( TestCaseEj3::PIEZA_VACIA, posicion );
  }

  delete (&it);
  _C( "Saliendo de recursión en posición: " << posicion + 1 ); DEBUG_ENTER;
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


