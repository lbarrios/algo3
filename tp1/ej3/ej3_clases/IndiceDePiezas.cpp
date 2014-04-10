#include "IndiceDePiezas.h"


IndiceDePiezas::IndiceDePiezas( uint32_t p_cantidadDeColores, vector<TestCaseEj3::Pieza>& p_listaDePiezas )
{
}

IteradorIndiceDePiezas& IndiceDePiezas::dameIterador( uint32_t posicion )
{
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
  IteradorIndiceDePiezas* it = NULL;
  it = new IteradorIndiceDePiezas();
  return *it;
}


