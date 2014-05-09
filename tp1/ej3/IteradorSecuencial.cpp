#include "IteradorSecuencial.h"

IteradorSecuencial::IteradorSecuencial( IndiceDePiezas& ip, uint32_t posicion )
  : IteradorIndiceDePiezas( ip, posicion )
{
  _v = &( this->_indiceSecuencial );
  _v_it = _v->begin();

  if ( !this->_indicePiezasDisponibles[*( this->_v_it )] ||
       !this->_ip.puedeColorarPiezaEnPosicion( *( this->_v_it ), this->_posicion  )
     )
  {
    this->operator++( 0 );
  }
}
IteradorSecuencial::~IteradorSecuencial()
{
}
IteradorSecuencial& IteradorSecuencial::operator++( int )
{
  // Primero, avanzo al menos una pieza en el vector secuencial
  if ( this->_v_it != this->_v->end() )
  {
    _C( "IteradorSecuencial::++" );
    ( this->_v_it )++;
  }

  /*
    Luego avanzo, mientras queden piezas en el vector secuencial
    siempre que las piezas que me encuentre ya esten utilizadas,
    o que esten desocupadas pero no me sirvan...
  */
  while ( this->_v_it != this->_v->end() && (
            !this->_indicePiezasDisponibles[*( this->_v_it )] ||
            !this->_ip.puedeColorarPiezaEnPosicion( *( this->_v_it ), this->_posicion )
          ) )
  {
    _C( "IteradorSecuencial::++" );
    ( this->_v_it )++;
  }

  // Si ya no hay piezas en el vector secuencial, llamo a mi papa
  if ( this->_v_it == this->_v->end() )
  {
    IteradorIndiceDePiezas::operator++( 0 );
    return *this;
  }

  return *this;
}
bool IteradorSecuencial::hayPiezasPosibles( )
{
  bool hayPiezasPosibles = this->_v_it != this->_v->end();
  return hayPiezasPosibles || IteradorIndiceDePiezas::hayPiezasPosibles();
}


