#ifndef __TABLERO_H__
#define __TABLERO_H__
#include "ej3.h"

class Tablero
{
private:
  vector<uint32_t> _piezasEnElTablero;
public:
  Tablero( uint32_t p_filas, uint32_t p_columnas );
  /**
   * Operador binario, indica si un tablero es menor a otro
   */
  inline bool operator< ( Tablero& t )
  {
    return this->cantidadDePosicionesVacias > t.cantidadDePosicionesVacias;
  }
  /**
   * Permite acceder a la pieza ubicada en una posición determinada
   */
  const inline uint32_t& operator[] ( uint32_t posicion ) const
  {
    return this->_piezasEnElTablero[posicion];
  }
  /**
   * Dada una posición en el tablero,
   * devuelve la pieza que se encuentra a la izquierda
   */
  const uint32_t dameLaPiezaDeIzquierdaDePosicion( uint32_t );
  /**
   * Dada una posición en el tablero,
   * devuelve la pieza que se encuentra arriba
   */
  const uint32_t dameLaPiezaDeArribaDePosicion( uint32_t );
  /**
   * Dada una posición en el tablero,
   * devuelve la pieza que se encuentra en esa posición
   */
  //const uint32_t dameLaPiezaEnPosicion( uint32_t );
  /**
   * Coloca una pieza en la posición indicada
   */
  void ponerPiezaEnPosicion( uint32_t, uint32_t );
  uint32_t cantidadDeFilas;
  uint32_t cantidadDeColumnas;
  uint32_t cantidadDePosiciones;
  uint32_t cantidadDePosicionesVacias;
  inline const uint32_t cantidadDePosicionesLlenas( void )
  {
    return this->cantidadDePosiciones - this->cantidadDePosicionesVacias;
  };
private:

};

#endif
