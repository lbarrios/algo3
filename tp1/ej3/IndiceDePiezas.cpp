#include "IndiceDePiezas.h"

IndiceDePiezas::IndiceDePiezas( uint32_t p_cantidadDeColores, vector<TestCaseEj3::Pieza>& p_listaDePiezas, Tablero& t ):
  _t( t ),
  _listaDePiezas( p_listaDePiezas ),
  _indiceDeDosColores(
    p_cantidadDeColores + 1,
    vector< stack< listaDePiezas > >(
      p_cantidadDeColores + 1,
      stack< listaDePiezas >(
        deque<listaDePiezas>( 1, listaDePiezas( 0 ) )
      )
    )
  ),
  _indicePiezasDisponibles(
    p_listaDePiezas.size(), true
  ),
  _indiceSecuencial(
    deque<listaDePiezas>( 1, listaDePiezas( 0 ) )
  )
{
  for ( uint32_t i = 1; i < this->_listaDePiezas.size(); i++ )
  {
    TestCaseEj3::Pieza pieza = this->_listaDePiezas[i];
    uint32_t colorIzquierda = pieza.colorIzquierda;
    uint32_t colorArriba = pieza.colorArriba;
    _indiceDeDosColores[colorIzquierda][colorArriba].top().push_back( i );
    _indiceSecuencial.top().push_back( i );
  }

  _imprimirIndiceDeDosColores();
}

void IndiceDePiezas::_imprimirIndiceDeDosColores()
{
  for ( uint32_t i = 1; i < _indiceDeDosColores.size(); i++ )
  {
    for ( uint32_t j = 1; j < _indiceDeDosColores.size(); j++ )
    {
      for ( vector<uint32_t>::iterator it = _indiceDeDosColores[i][j].top().begin(); it != _indiceDeDosColores[i][j].top().end(); it++ )
      {
        _C( "IC[" << i << "][" << j << "] = " << *it );
      }
    }
  }
}

IndiceDePiezas::~IndiceDePiezas( )
{
}

IteradorIndiceDePiezas& IndiceDePiezas::dameIterador( uint32_t posicion )
{
  IteradorIndiceDePiezas* it = NULL;
  // Obtengo las piezas de la izquierda y de arriba
  uint32_t piezaIzquierda = _t.dameLaPiezaDeIzquierdaDePosicion( posicion );
  uint32_t piezaArriba = _t.dameLaPiezaDeArribaDePosicion( posicion );
#ifndef SINPODASELECCION
  bool arribaVacio = ( piezaArriba == TestCaseEj3::PIEZA_VACIA );
  bool izquierdaVacio = ( piezaIzquierda == TestCaseEj3::PIEZA_VACIA );

  if ( arribaVacio || izquierdaVacio )
  {
    _C( "Creando iterador secuencial" );
    it = new IteradorSecuencial( *this, posicion );
  }
  else
  {
    _C( "Creando iterador por colores" );
    it = new IteradorColores( *this, posicion );
  }

#else
  _C( "Creando iterador secuencial" );
  it = new IteradorSecuencial( *this, posicion );
#endif
  //this->_iteradores.push_back( it );
  return *it;
}
void IndiceDePiezas::marcarPiezaUtilizada( IteradorIndiceDePiezas& it )
{
  _C( "Marcando como utilizada la pieza: " << *it );

  if ( *it == TestCaseEj3::PIEZA_VACIA )
  {
    _C( "La pieza es vacia" );
    it.utilizarPiezaTransparente();
  }
  else
  {
    _imprimirIndiceDeDosColores();
    // Marco la pieza como no disponible
    this->_indicePiezasDisponibles[*it] = false;
    // Obtengo la pieza del listado de piezas
    TestCaseEj3::Pieza pieza = this->_listaDePiezas[*it];
    _C( "Pusheo una copia del indice para esos dos colores" );
    this->_indiceDeDosColores[pieza.colorIzquierda][pieza.colorArriba].push(
      this->_indiceDeDosColores[pieza.colorIzquierda][pieza.colorArriba].top()
    );
    _C( "Borro el elemento de la nueva lista" );
    this->_indiceDeDosColores[pieza.colorIzquierda][pieza.colorArriba].top().erase(
      lower_bound( this->_indiceDeDosColores[pieza.colorIzquierda][pieza.colorArriba].top().begin(),
                   this->_indiceDeDosColores[pieza.colorIzquierda][pieza.colorArriba].top().end(), *it )
    );
    _C( "Pusheo una copia del indice secuencial" );
    this->_indiceSecuencial.push(
      this->_indiceSecuencial.top()
    );
    _C( "Borro el elemento del indice secuencial" );
    this->_indiceSecuencial.top().erase(
      lower_bound( this->_indiceSecuencial.top().begin(),
                   this->_indiceSecuencial.top().end(), *it )
    );
    DEBUG_INT( this->_indiceSecuencial.top().size() );
  }
}
void IndiceDePiezas::marcarPiezaDisponible( IteradorIndiceDePiezas& it )
{
  if ( *it != TestCaseEj3::PIEZA_VACIA )
  {
    _C( "Marcando como disponible la pieza: " << *it );
    // Marco la pieza como disponible
    this->_indicePiezasDisponibles[*it] = true;
    // Obtengo la pieza del listado de piezas
    TestCaseEj3::Pieza pieza = this->_listaDePiezas[*it];
    this->_indiceDeDosColores[pieza.colorIzquierda][pieza.colorArriba].pop();
    this->_indiceSecuencial.pop();
  }
}

bool IndiceDePiezas::puedeColorarPiezaEnPosicion( uint32_t i_pieza, uint32_t posicion )
{
  TestCaseEj3::Pieza pieza = this->_listaDePiezas[i_pieza];
  uint32_t piezaArriba = this->_t.dameLaPiezaDeArribaDePosicion( posicion );
  bool arriba = piezaArriba == TestCaseEj3::PIEZA_VACIA || pieza.colorArriba == this->_listaDePiezas[piezaArriba].colorAbajo;
  uint32_t piezaIzquierda = this->_t.dameLaPiezaDeIzquierdaDePosicion( posicion );
  bool izquierda = piezaIzquierda == TestCaseEj3::PIEZA_VACIA || pieza.colorIzquierda == this->_listaDePiezas[piezaIzquierda].colorDerecha;
  return arriba && izquierda;
}
