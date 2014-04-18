#include "Tablero.h"

Tablero::Tablero( uint32_t p_filas, uint32_t p_columnas )
  : cantidadDeFilas( p_filas ), cantidadDeColumnas( p_columnas ), cantidadDePosiciones( p_filas* p_columnas ),
    cantidadDePosicionesVacias( p_filas* p_columnas )
{
  this->cantidadDePosicionesVacias = this->cantidadDePosiciones;
  this->_piezasEnElTablero.assign( p_filas * p_columnas, 0 );
}
const uint32_t Tablero::dameLaPiezaDeArribaDePosicion( uint32_t posicion )
{
  bool noEsPrimeraFila = ( posicion >= this->cantidadDeColumnas );

  if ( noEsPrimeraFila )
  {
    _C( "La pieza arriba de la posición " << posicion + 1 << " es: " <<
        this->_piezasEnElTablero[posicion - 1] );
    return this->_piezasEnElTablero[posicion - this->cantidadDeColumnas];
  }
  else
  {
    _C( "La posición " << posicion + 1 << " contiene una pieza vacía a arriba" );
    return TestCaseEj3::PIEZA_VACIA;
  }
}
const uint32_t Tablero::dameLaPiezaDeIzquierdaDePosicion( uint32_t posicion )
{
  bool noEsPrimeraColumna = ( posicion % this->cantidadDeFilas != 0 );

  if ( noEsPrimeraColumna )
  {
    _C( "La pieza izquierda de la posición " << posicion + 1 << " es: " << this->_piezasEnElTablero[posicion - 1] );
    return this->_piezasEnElTablero[posicion - 1];
  }
  else
  {
    _C( "La posición " << posicion + 1 << " contiene una pieza vacía a su izquierda" );
    return TestCaseEj3::PIEZA_VACIA;
  }
}
/*
uint32_t Tablero::cantidadDePosiciones( void )
{
  return this->_cantidadDePosiciones;
}
*/
void Tablero::ponerPiezaEnPosicion( uint32_t pieza, uint32_t posicion )
{
  _C( "Poniendo pieza: " << pieza << " en posicion: " << posicion + 1 );

  if ( this->_piezasEnElTablero[posicion] == TestCaseEj3::PIEZA_VACIA )
  {
    if ( pieza != TestCaseEj3::PIEZA_VACIA )
    {
      this->cantidadDePosicionesVacias--;
      this->_piezasEnElTablero[posicion] = pieza;
    }
  }
  else
  {
    if ( pieza == TestCaseEj3::PIEZA_VACIA )
    {
      this->cantidadDePosicionesVacias++;
    }

    this->_piezasEnElTablero[posicion] = pieza;
  }

#ifdef DEBUG
  this->imprimeTablero();
#else
  /*
  cerr << " ";

  for ( uint32_t x = 0; x < ( this->cantidadDeColumnas * 2 ) + 1; x++ )
  {
    cerr << "-";
  }

  cerr << endl;

  for ( uint32_t y = 0; y < this->cantidadDeFilas; y++ )
  {
    cerr << "| ";

    for ( uint32_t x = 0; x < this->cantidadDeColumnas; x++ )
    {
      uint32_t posicion = y * this->cantidadDeColumnas + x;
      cerr << Tablero::operator[]( posicion ) << " ";
    }

    cerr << "|";
    cerr << endl;
  }

  cerr << " ";

  for ( uint32_t x = 0; x < ( this->cantidadDeColumnas * 2 ) + 1; x++ )
  {
    cerr << "-";
  }

  cerr << endl;
  */
#endif
}
void Tablero::imprimeTablero()
{
  for ( uint32_t y = 0; y < this->cantidadDeFilas; y++ )
  {
    for ( uint32_t x = 0; x < this->cantidadDeColumnas; x++ )
    {
      uint32_t posicion = y * this->cantidadDeColumnas + x;
      cerr << Tablero::operator[]( posicion ) << " ";
    }

    cerr << endl;
  }
}

