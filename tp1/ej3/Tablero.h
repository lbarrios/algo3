#ifndef __TABLERO_H__
#define __TABLERO_H__

#include "ej3.h"

class Tablero {
public:
  inline bool operator< (Tablero &t)
  {
    return this->_cantidadDePosicionesVacias > t._cantidadDePosicionesVacias;
  }
  inline uint32_t operator[] (uint32_t posicion)
  {
    return this->_piezasEnElTablero[posicion];
  }
  Tablero( uint32_t p_filas, uint32_t p_columnas)
    : cantidadDeFilas(p_filas), cantidadDeColumnas(p_columnas){
    this->_cantidadDePosiciones = p_filas*p_columnas;
    this->_cantidadDePosicionesVacias = this->_cantidadDePosiciones;
    //this->_piezasEnElTablero = new uint32_t[p_filas * p_columnas];
    //fill_n(this->_piezasEnElTablero,p_filas * p_columnas,0);
    this->_piezasEnElTablero.assign(p_filas*p_columnas,0);
    /*this->_piezasEnElTablero = new uint32_t*[filas];
    if (filas > 0){
      this->_piezasEnElTablero[0] = new uint32_t[filas * filas];
      for (int i=1; i<filas; i++){
        this->_piezasEnElTablero[i] = this->_piezasEnElTablero[0] + (i*columnas);
      }
    }*/
  };
  uint32_t cantidadDePosiciones(void){
    return this->_cantidadDePosiciones;
  }
  /**
   * Dada una posición en el tablero,
   * devuelve la pieza que se encuentra a la izquierda
   */
  uint32_t dameLaPiezaDeIzquierdaDe( uint32_t posicion ){
    bool noEsPrimeraColumna = ( posicion%this->cantidadDeFilas != 0 );
    if( noEsPrimeraColumna ){
      return this->_piezasEnElTablero[posicion-1];
    } else {
      return TestCaseEj3::PIEZA_VACIA;
    }
  };
  /**
   * Dada una posición en el tablero,
   * devuelve la pieza que se encuentra arriba
   */
  uint32_t dameLaPiezaDeArribaDe( uint32_t posicion ){
    bool noEsPrimeraFila = ( posicion>=this->cantidadDeColumnas );
    if( noEsPrimeraFila ){
      return this->_piezasEnElTablero[posicion-this->cantidadDeColumnas];
    } else {
      return TestCaseEj3::PIEZA_VACIA;
    }
  };
  uint32_t dameLaPiezaEnPosicion( uint32_t posicion ){
    return this->_piezasEnElTablero[posicion];
  }
  void ponerPiezaEnPosicion( uint32_t pieza, uint32_t posicion )
  {    
    _C("Poniendo pieza: "<<pieza<<" en posicion: "<<posicion);
    if (this->_piezasEnElTablero[posicion] == TestCaseEj3::PIEZA_VACIA)
    {
      if (pieza != TestCaseEj3::PIEZA_VACIA){
        this->_cantidadDePosicionesVacias--;
        this->_piezasEnElTablero[posicion] = pieza;
      }
    }
    else
    {
      if (pieza == TestCaseEj3::PIEZA_VACIA)
      {
        this->_cantidadDePosicionesVacias++;
      }
      this->_piezasEnElTablero[posicion] = pieza;
    }
  }
  uint32_t cantidadDeFilas;
  uint32_t cantidadDeColumnas;
  uint32_t cantidadDePosicionesLlenas(void){
    return _cantidadDePosiciones - _cantidadDePosicionesVacias;
  };
private:
  //uint32_t *_piezasEnElTablero; // Guarda una referencia a la posición en listaDePiezas
  vector<uint32_t> _piezasEnElTablero;
  uint32_t _cantidadDePosicionesVacias;
  uint32_t _cantidadDePosiciones;
};

#endif
