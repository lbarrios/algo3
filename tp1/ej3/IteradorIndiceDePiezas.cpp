#include "IteradorIndiceDePiezas.h"

IteradorIndiceDePiezas::IteradorIndiceDePiezas( IndiceDePiezas& ip, uint32_t posicion )
  : _indiceSecuencial( ip._indiceSecuencial.top() )
{
  this->_piezaTransparenteUtilizada = false;
}

IteradorIndiceDePiezas::~IteradorIndiceDePiezas()
{
  //_C( "IteradorIndiceDePiezas::~IteradorIndiceDePiezas()" );
}

bool IteradorIndiceDePiezas::hayPiezasPosibles()
{
  return !_piezaTransparenteUtilizada;
}
IteradorIndiceDePiezas& IteradorIndiceDePiezas::operator++( int )
{
  _C( "IteradorIndiceDePiezas::operator++" );
  this->_piezaTransparenteUtilizada = true;
  return *this;
}
uint32_t IteradorIndiceDePiezas::operator*()
{
  _C( "IteradorIndiceDePiezas::operator*" );
  DEBUG_BOOL( this->_piezaTransparenteUtilizada );

  if ( this->_piezaTransparenteUtilizada )
  {
    _C( "Utilizando pieza transparente" );
    return TestCaseEj3::PIEZA_VACIA;
  }
  else
  {
    return *( this->_v_it );
  }
}


