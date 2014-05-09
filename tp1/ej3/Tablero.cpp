#include "Tablero.h"

Tablero::Tablero( uint32_t p_filas, uint32_t p_columnas, vector<TestCaseEj3::Pieza>& listaDePiezas )
  :
  _listaDePiezas( listaDePiezas ),
  _cantidadDePosicionesVacias( p_filas* p_columnas ),
  _mejorCantidadDePosicionesVacias( _cantidadDePosicionesVacias / 2 + 1 ),
  cantidadDeFilas( p_filas ),
  cantidadDeColumnas( p_columnas ),
  cantidadDePosiciones( p_filas* p_columnas )
{
  this->_piezasEnElTablero.assign( p_filas * p_columnas, 0 );
  // Poda
  this->_calcularMejorCantidadDePiezasPosible();
}
const uint32_t Tablero::dameLaPiezaDeArribaDePosicion( uint32_t posicion )
{
  bool noEsPrimeraFila = ( posicion >= this->cantidadDeColumnas );

  if ( noEsPrimeraFila )
  {
    _C( "La pieza arriba de la posicion " << posicion + 1 << " es: " <<
        this->_piezasEnElTablero[posicion - this->cantidadDeColumnas] );
    return this->_piezasEnElTablero[posicion - this->cantidadDeColumnas];
  }
  else
  {
    _C( "La posicion " << posicion + 1 << " contiene una pieza vacia a arriba" );
    return TestCaseEj3::PIEZA_VACIA;
  }
}
const uint32_t Tablero::dameLaPiezaDeIzquierdaDePosicion( uint32_t posicion )
{
  bool noEsPrimeraColumna = ( posicion % this->cantidadDeFilas != 0 );

  if ( noEsPrimeraColumna )
  {
    _C( "La pieza izquierda de la posicion " << posicion + 1 << " es: " << this->_piezasEnElTablero[posicion - 1] );
    return this->_piezasEnElTablero[posicion - 1];
  }
  else
  {
    _C( "La posicion " << posicion + 1 << " contiene una pieza vacia a su izquierda" );
    return TestCaseEj3::PIEZA_VACIA;
  }
}
uint32_t Tablero::cantidadDePiezas( void )
{
  return this->_listaDePiezas.size();
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
      this->_cantidadDePosicionesVacias--;
      this->_piezasEnElTablero[posicion] = pieza;

      if ( this->_cantidadDePosicionesVacias < this->_mejorCantidadDePosicionesVacias )
      {
        _C( "Se encontro un nuevo mejor tablero, con " << this->_cantidadDePosicionesVacias << " posiciones vacias, la mejor era " <<
            this->_mejorCantidadDePosicionesVacias << "." );
        this->_mejorCantidadDePosicionesVacias = this->_cantidadDePosicionesVacias;
      }
    }
  }
  else
  {
    if ( pieza == TestCaseEj3::PIEZA_VACIA )
    {
      this->_cantidadDePosicionesVacias++;
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
  this->_ultimaPosicionAgregada = posicion;
}
/*uint32_t Tablero::mejorTableroHastaElMomento( void )
{
  return this->cantidadDePosiciones - _mejorCantidadDePosicionesVacias;
}*/
bool Tablero::yaEncontreElMejorTableroPosible( void )
{
  return _mejorCantidadDePosicionesVacias <= this->_mejorCantidadDePosicionesVaciasPosible;
}
bool Tablero::yaEncontreUnTableroMejor ( uint32_t posicion )
{
  DEBUG_INT( this->_mejorCantidadDePosicionesVacias );
  DEBUG_INT( this->cantidadDePosiciones );
  DEBUG_INT( posicion );
  DEBUG_INT( this->_mejorCantidadDePosicionesVacias + this->cantidadDePosiciones - posicion );
  DEBUG_INT( _cantidadDePosicionesVacias );
  return this->_mejorCantidadDePosicionesVacias + this->cantidadDePosiciones - posicion
         <= _cantidadDePosicionesVacias;
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
void Tablero::_calcularMejorCantidadDePiezasPosible()
{
  _mejorCantidadDePosicionesVaciasPosible = 0;
  return;
  multiset<uint32_t> coloresIzquierda;
  multiset<uint32_t> coloresDerecha;
  multiset<uint32_t> coloresArriba;
  multiset<uint32_t> coloresAbajo;

  for ( uint32_t i = 1; i < this->_listaDePiezas.size(); i++ )
  {
    coloresIzquierda.insert( this->_listaDePiezas[i].colorIzquierda );
    coloresDerecha.insert( this->_listaDePiezas[i].colorDerecha );
    coloresArriba.insert( this->_listaDePiezas[i].colorArriba );
    coloresAbajo.insert( this->_listaDePiezas[i].colorAbajo );
  }

  multiset<uint32_t>::iterator it, it2;

  for ( it = coloresIzquierda.begin(); it != coloresIzquierda.end(); it++ )
  {
    it2 = coloresDerecha.find( *it );

    if ( it2 != coloresDerecha.end() )
    {
      coloresDerecha.erase( it2 );
    }
  }

  for ( it = coloresDerecha.begin(); it != coloresDerecha.end(); it++ )
  {
    it2 = coloresIzquierda.find( *it );

    if ( it2 != coloresIzquierda.end() )
    {
      coloresIzquierda.erase( it2 );
    }
  }

  for ( it = coloresArriba.begin(); it != coloresArriba.end(); it++ )
  {
    it2 = coloresAbajo.find( *it );

    if ( it2 != coloresAbajo.end() )
    {
      coloresAbajo.erase( it2 );
    }
  }

  for ( it = coloresAbajo.begin(); it != coloresAbajo.end(); it++ )
  {
    it2 = coloresArriba.find( *it );

    if ( it2 != coloresArriba.end() )
    {
      coloresArriba.erase( it2 );
    }
  }

  uint32_t piezasInfumables = max( coloresDerecha.size(), max( coloresIzquierda.size(), max( coloresArriba.size(), coloresAbajo.size() ) ) );
  _C( "Atencion: Hay como minimo " << piezasInfumables << " piezas incompatibles en este tablero" );
  this->_mejorCantidadDePosicionesVaciasPosible = piezasInfumables / 2;
  this->_mejorCantidadDePosicionesVaciasPosible = 0;
  _C( "Atencion: Se estima un minimo de " << this->_mejorCantidadDePosicionesVaciasPosible << " posiciones en blanco para este tablero." );
  //this->_mejorCantidadDePosicionesVaciasPosible = 0;
}
