#include "IteradorColores.h"

IteradorColores::IteradorColores( IndiceDePiezas& ip, uint32_t posicion )
  : IteradorIndiceDePiezas( ip, posicion )
{
  _C( "Inicializando IteradorColores." );
  _v = this->_indiceColores;
  _v_it = _v->begin();
  _C( "El tamanio del iterador de colores es: " << _v->size() );

  if ( _v->begin() == _v->end() )
  {
    this->operator++( 0 );
  }
}
IteradorColores::~IteradorColores()
{
}
IteradorColores& IteradorColores::operator++( int )
{
  // Primero, avanzo al menos una pieza en el vector
  if ( this->_v_it != this->_v->end() )
  {
    _C( "IteradorColores::++" );
    ( this->_v_it )++;
  }

  if ( this->_v_it == this->_v->end() )
  {
    IteradorIndiceDePiezas::operator++( 0 );
  }

  return *this;
}
bool IteradorColores::hayPiezasPosibles( )
{
  bool hayPiezasPosibles = this->_v_it != this->_v->end();
  return hayPiezasPosibles || IteradorIndiceDePiezas::hayPiezasPosibles();
}


