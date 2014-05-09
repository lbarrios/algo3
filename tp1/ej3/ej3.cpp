#include "ej3.h"
#include "Tablero.h"
#include "IndiceDePiezas.h"

Tablero& backtrack( Tablero&, IndiceDePiezas&, uint32_t );
void imprimeTablero( Tablero& );

int main( int argc, char** argv )
{
  // Parseo los parametros con que fue llamado el ejecutable
  ParserDeParametros parser( argc, argv );
  // Esta clase representa un caso de prueba, y lo toma desde el input que le provee el parser
  TestCaseEj3 testcase ( parser.dameInput() );
  Timer timer ( parser.dameTime() );

  // Itero sobre los distintos casos de prueba hasta obtener un testcase nulo
  while ( testcase.tomarDatos() != false )
  {
    // Mido el tiempo inicial.
    timer.setInitialTime( "todoElCiclo" );
    // Obtengo los parametros del testcase.
    uint32_t cantidadDeFilas = testcase.dameCantidadDeFilas();
    uint32_t cantidadDeColumnas = testcase.dameCantidadDeColumnas();
    uint32_t cantidadDeColores = testcase.dameCantidadDeColores();
    vector<TestCaseEj3::Pieza>& listaDePiezas = testcase.dameListaDePiezas();
    // Inicializo el tablero (estructura auxiliar)
    Tablero tablero( cantidadDeFilas, cantidadDeColumnas, listaDePiezas );
    // Inicializo el indice de piezas (estructura auxiliar)
    IndiceDePiezas indiceDePiezas( cantidadDeColores, listaDePiezas, tablero );
    //Obtengo el mejor tablero a traves de backtracking
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
  DEBUG_ENTER; _C( "Entrando a recursion en posicion: " << posicion + 1 );
  Tablero* mejorTablero = NULL;
#ifndef SINPODAOBJETIVO

  if ( t.yaEncontreUnTableroMejor( posicion ) )
  {
    _C( "PODANDO EN POS " << posicion << " PORQUE EXISTE UN TABLERO mejor QUE CUALQUIERA DE ESTA RAMA" );
    return *mejorTablero;
  }

#endif
  IteradorIndiceDePiezas& it = ip.dameIterador( posicion );
  _C( "Obtenido iterador al indice de piezas" );

  // Me fijo si estoy antes de la ultima posicion
  if ( posicion < t.cantidadDePosiciones - 1 )
  {
#ifndef SINOPTIMIZACION

    while ( it.hayPiezasPosibles() )
    {
      _C( "Pieza disponible: " << *it );
      // Si es asi, entonces llamo a backtrack para cada pieza posible
      t.ponerPiezaEnPosicion( *it, posicion );
      ip.marcarPiezaUtilizada( it );
      // Hago recursion en el backtracking
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
          // Si la recursion me devolvio un puntero a nulo termino el BT
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

#else

    for ( uint32_t it = 1; it < t.cantidadDePiezas(); it++ )
    {
      t.ponerPiezaEnPosicion( it, posicion );
      // Hago recursion en el backtracking
      Tablero* otroTablero = NULL;
      otroTablero = &( backtrack( t, ip, posicion + 1 ) );

      if ( !mejorTablero )
      {
        mejorTablero = otroTablero;
      }
      else
      {
        if ( !otroTablero )
        {
          // Si la recursion me devolvio un puntero a nulo termino el BT
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
    }

    t.ponerPiezaEnPosicion( TestCaseEj3::PIEZA_VACIA, posicion );
    Tablero* otroTablero = NULL;
    otroTablero = &( backtrack( t, ip, posicion + 1 ) );

    if ( !mejorTablero )
    {
      mejorTablero = otroTablero;
    }
    else
    {
      if ( !otroTablero )
      {
        // Si la recursion me devolvio un puntero a nulo termino el BT
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

#endif
  }
  else
  {
    // (si estoy en la ultima posicion del tablero)
    // Intento colocar la ultima pieza
    if ( it.hayPiezasPosibles() )
    {
      t.ponerPiezaEnPosicion( *it, posicion );
    }

    // Creo una copia del tablero final
    mejorTablero = new Tablero( t );
    // Pongo una pieza transparente en el lugar donde puse (o no) una pieza
    t.ponerPiezaEnPosicion( TestCaseEj3::PIEZA_VACIA, posicion );
  }

  delete ( &it );
  _C( "Saliendo de recursion en posicion: " << posicion + 1 ); DEBUG_ENTER;
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


