#include "IteradorIndiceDePiezas.h"

IteradorIndiceDePiezas::IteradorIndiceDePiezas( IndiceDePiezas& ip, uint32_t posicion )
  : _v( ip._indiceSecuencial )
{
  this->_piezaTransparenteUtilizada = false;
}

IteradorIndiceDePiezas::~IteradorIndiceDePiezas()
{
  _C( "IteradorIndiceDePiezas::~IteradorIndiceDePiezas()" );
}

bool IteradorIndiceDePiezas::hayPiezasPosibles()
{
  return !_piezaTransparenteUtilizada;
}
IteradorIndiceDePiezas& IteradorIndiceDePiezas::operator++( int )
{
  this->_piezaTransparenteUtilizada = true;
  return *this;
}
uint32_t IteradorIndiceDePiezas::operator*()
{
  if ( this->_piezaTransparenteUtilizada )
  {
    return TestCaseEj3::PIEZA_VACIA;
  }
  else
  {
    return *( this->_v_it );
  }
}


