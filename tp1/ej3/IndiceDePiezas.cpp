#include "IndiceDePiezas.h"

IndiceDePiezas::IndiceDePiezas( uint32_t p_cantidadDeColores, vector<TestCaseEj3::Pieza>& p_listaDePiezas, Tablero& t ):
  _t( t ),
  _listaDePiezas( p_listaDePiezas ),
  _indiceDeDosColores(
    p_cantidadDeColores,
    vector< stack< listaDePiezas > >(
      p_cantidadDeColores,
      stack< listaDePiezas >(
        deque<listaDePiezas>( 1, listaDePiezas( 0 ) )
      )
    )
  ),
  _indiceSecuencial(
    deque<listaDePiezas>( 1, listaDePiezas( 0 ) )
  )
{
  for ( uint32_t i = 1; i < this->_listaDePiezas.size(); i++ )
  {
    TestCaseEj3::Pieza pieza = this->_listaDePiezas[i];
    uint32_t colorDerecha = pieza.colorDerecha;
    uint32_t colorAbajo = pieza.colorAbajo;
    _indiceDeDosColores[colorDerecha - 1][colorAbajo - 1].top().push_back( i );
    _indiceSecuencial.top().push_back( i );
  }
}

IndiceDePiezas::~IndiceDePiezas( )
{
  for ( vector<IteradorIndiceDePiezas*>::iterator it = this->_iteradores.begin(); it != this->_iteradores.end(); ++it )
  {
    delete *it;
  }
}

IteradorIndiceDePiezas& IndiceDePiezas::dameIterador( uint32_t posicion )
{
  IteradorIndiceDePiezas* it = NULL;
  // Obtengo las piezas de la izquierda y de arriba
  //uint32_t piezaIzquierda = _t.dameLaPiezaDeIzquierdaDePosicion( posicion );
  //uint32_t piezaArriba = _t.dameLaPiezaDeArribaDePosicion( posicion );
  /*
  // Si es primera columna pero no primera fila
  if ( this->_primeraColumna && !this->_primeraFila )
  {
    _C( "IC::IT() El casillero es primera columna pero no es primera fila" );
    this->_avanza = &Iterador::_avanzaIteradorPrimeraColumna;
    this->_hayPosibles = &Iterador::_hayPosiblesPrimeraColumna;
    this->_colorDerechaActual = 0;
    this->_colorAbajoActual = _ic.colorAbajo( p_a );
  }

  // Si es primera fila pero no primera columna
  if ( this->_primeraFila && !this->_primeraColumna )
  {
    _C( "IC::IT() El casillero es primera fila pero no es primera columna" );
    this->_avanza = &Iterador::_avanzaIteradorPrimeraFila;
    this->_hayPosibles = &Iterador::_hayPosiblesPrimeraFila;
    this->_colorDerechaActual = _ic.colorDerecha( p_i );
    this->_colorAbajoActual = 0;
  }

  // Si no es ni primera columna ni primera fila
  if ( !this->_primeraFila && !this->_primeraColumna )
  {
    _C( "IC::IT() El casillero no es primera columna ni primera fila" );
    this->_avanza = &Iterador::_avanzaIteradorNormal;
    this->_hayPosibles = &Iterador::_hayPosiblesNormal;
    this->_colorDerechaActual = _ic.colorDerecha( p_i );
    this->_colorAbajoActual = _ic.colorAbajo( p_a );
  }

  // Si es el primer casillero (1ra columna y 1ra fila a la vez)
  if ( this->_primeraColumna && this->_primeraFila )
  {
    _C( "IC::IT() El casillero es primera columna y primera fila (1er casillero)" );
    this->_avanza = &Iterador::_avanzaIteradorPrimerCasillero;
    this->_hayPosibles = &Iterador::_hayPosiblesPrimerCasillero;
    this->_quitarPieza = &IndiceDeColores::_quitarPieza;
    this->_colorDerechaActual = 0;
    this->_colorAbajoActual = 0;
    //this->_indice = 1;
  }
  */
  //it = new IteradorIndiceDePiezas( posicion );
  it = new IteradorNormal( *this, posicion );
  this->_iteradores.push_back( it );
  return *it;
}
void IndiceDePiezas::marcarPiezaUtilizada( IteradorIndiceDePiezas& )
{
}


