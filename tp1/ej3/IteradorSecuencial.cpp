#include "IteradorSecuencial.h"

IteradorSecuencial::IteradorSecuencial( IndiceDePiezas& ip, uint32_t posicion )
  : IteradorIndiceDePiezas( ip, posicion )
{
  _v = &( this->_indiceSecuencial );
  _v_it = _v->begin();

  if ( !this->_indicePiezasDisponibles[*( this->_v_it )] )
  {
    this->operator++( 0 );
  }
}
IteradorSecuencial& IteradorSecuencial::operator++( int )
{
  _C( "IteradorSecuencial::++" );

  // Avanzo al menos una pieza en el vector secuencial
  if ( this->_v_it != this->_v->end() )
  {
    ( this->_v_it )++;
  }

  // Si hay piezas en el vector secuencial pero ya están ocupadas...
  while ( this->_v_it != this->_v->end() && !this->_indicePiezasDisponibles[*( this->_v_it )] )
  {
    ( this->_v_it )++;
  }

  // Si ya no hay piezas en el vector secuencial, llamo a mi papá
  if ( this->_v_it == this->_v->end() )
  {
    IteradorIndiceDePiezas::operator++( 0 );
    return *this;
  }

  return *this;
}
IteradorSecuencial::~IteradorSecuencial()
{
}
bool IteradorSecuencial::hayPiezasPosibles( )
{
  bool hayPiezasPosibles = this->_v_it != this->_v->end();
  return hayPiezasPosibles || IteradorIndiceDePiezas::hayPiezasPosibles();
}


