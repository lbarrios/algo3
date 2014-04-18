#include "IteradorNormal.h"

IteradorNormal::IteradorNormal( IndiceDePiezas& ip, uint32_t posicion )
  : IteradorIndiceDePiezas( ip, posicion )
{
  _v = &( this->_indiceSecuencial );
  _v_it = _v->begin();
}
IteradorNormal& IteradorNormal::operator++( int )
{
  _C( "IteradorNormal::++" );
  ( this->_v_it )++;

  if ( this->_v_it == this->_v->end() )
  {
    IteradorIndiceDePiezas::operator++( 0 );
  }

  return *this;
}
IteradorNormal::~IteradorNormal()
{
}
bool IteradorNormal::hayPiezasPosibles( )
{
  bool hayPiezasPosibles = this->_v_it != this->_v->end();
  return hayPiezasPosibles || IteradorIndiceDePiezas::hayPiezasPosibles();
}


