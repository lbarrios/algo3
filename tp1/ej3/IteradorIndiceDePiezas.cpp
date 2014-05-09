#include "IteradorIndiceDePiezas.h"

IteradorIndiceDePiezas::IteradorIndiceDePiezas( IndiceDePiezas& ip, uint32_t posicion )
  : _indicePiezasDisponibles( ip._indicePiezasDisponibles ),
    _indiceSecuencial ( ip._indiceSecuencial.top() ),

    _ip( ip ),
    _posicion( posicion )
{
  uint32_t piezaIzquierda = ip._t.dameLaPiezaDeIzquierdaDePosicion( posicion );
  uint32_t piezaArriba = ip._t.dameLaPiezaDeArribaDePosicion( posicion );

  if ( piezaIzquierda != TestCaseEj3::PIEZA_VACIA && piezaArriba != TestCaseEj3::PIEZA_VACIA )
  {
    this->_indiceColores = &( ip._indiceDeDosColores
                              [ip._listaDePiezas[piezaIzquierda].colorDerecha]
                              [ip._listaDePiezas[piezaArriba].colorAbajo]
                              .top() );
  }

  this->_piezaTransparenteUtilizada = false;
  this->_utilizarPiezaTransparente = false;
  _C( "Inicializado IteradorIndiceDePiezas" );
}

IteradorIndiceDePiezas::~IteradorIndiceDePiezas()
{
}

bool IteradorIndiceDePiezas::hayPiezasPosibles()
{
  return !_piezaTransparenteUtilizada;
}
IteradorIndiceDePiezas& IteradorIndiceDePiezas::operator++( int )
{
  _C( "IteradorIndiceDePiezas::operator++" );
  this->_utilizarPiezaTransparente = true;
  return *this;
}
uint32_t IteradorIndiceDePiezas::operator*()
{
  if ( this->_utilizarPiezaTransparente )
  {
    _C( "Utilizando pieza transparente" );
    return TestCaseEj3::PIEZA_VACIA;
  }
  else
  {
    return *( this->_v_it );
  }
}
void IteradorIndiceDePiezas::utilizarPiezaTransparente()
{
  this->_piezaTransparenteUtilizada = true;
}

