#include "IteradorIndiceDePiezas.h"

IteradorIndiceDePiezas::IteradorIndiceDePiezas( IndiceDePiezas& ip, uint32_t posicion )
  : _indicePiezasDisponibles( ip._indicePiezasDisponibles ),
    _indiceSecuencial ( ip._indiceSecuencial )
{
  this->_piezaTransparenteUtilizada = false;
  this->_utilizarPiezaTransparente = false;
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

