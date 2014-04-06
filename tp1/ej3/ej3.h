#ifndef EJ3_H
#define EJ3_H

#include "../common/headers.h"
#include "../common/ParserDeParametros.h"
#include "TestCaseEj3.h"


class Tablero {
public:
  bool operator< (Tablero &t){
    return this->cantidadDePosicionesLlenas() < t.cantidadDePosicionesLlenas();
  }
  Tablero( uint32_t p_filas, uint32_t p_columnas)
    : cantidadDeFilas(p_filas), cantidadDeColumnas(p_columnas){
    this->_cantidadDePosiciones = p_filas*p_columnas;
    this->_cantidadDePosicionesVacias = this->_cantidadDePosiciones;
    this->_piezasEnElTablero = new uint32_t[p_filas * p_columnas];
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
      //return _piezasEnElTablero[posicion1];
      return 1;
    } else {
      return TestCaseEj3::PIEZA_VACIA;
    }
  };
  /**
   * Dada una posición en el tablero,
   * devuelve la pieza que se encuentra arriba
   */
  uint32_t dameLaPiezaDeArribaDe( uint32_t posicion ){
    bool noEsPrimeraFila = ( posicion<cantidadDeColumnas );
    if( noEsPrimeraFila ){
      return 1;
    } else {
      return TestCaseEj3::PIEZA_VACIA;
    }
  };
  uint32_t dameLaPiezaEnPosicion( uint32_t posicion ){
    return _piezasEnElTablero[posicion];
  }
  void ponerPiezaEnPosicion( uint32_t pieza, uint32_t posicion ){
    _piezasEnElTablero[posicion] = pieza;
  }
  uint32_t cantidadDeFilas;
  uint32_t cantidadDeColumnas;
  uint32_t cantidadDePosicionesLlenas(void){
    return _cantidadDePosiciones - _cantidadDePosicionesVacias;
  };
private:
  uint32_t *_piezasEnElTablero; // Guarda una referencia a la posición en listaDePiezas
  uint32_t _cantidadDePosicionesVacias;
  uint32_t _cantidadDePosiciones;
};

class IndiceDeColores {
public:
  IndiceDeColores( uint32_t p_cantidadDeColores, vector<TestCaseEj3::Pieza> &p_listaDePiezas ) 
    : listaDePiezas(p_listaDePiezas){
    // Agrego las piezas al índice de piezas por color
    for (uint32_t i = 1; i<this->listaDePiezas.size()+1; i++){
      this->agregarPieza( i );
    }
    this->agregarPieza( TestCaseEj3::PIEZA_VACIA );
    /** PSEUDOCODIGO
    vector< list< uint32_t > > bla; vector.reserve(cantidadDeColores);
    inicializar v con bla * cantidadDeColores;
    **/
  };
  /**
   * Dado un ID de pieza y los colores de la derecha y de abajo de esa pieza
   * la agrega al vector de piezas
   */
  void agregarPieza ( uint32_t indice ){
    uint32_t colorDerecha = listaDePiezas[indice].colorDerecha;
    uint32_t colorAbajo = listaDePiezas[indice].colorAbajo;
    v_color_derecha_abajo[colorDerecha][colorAbajo].push_back(indice);
    v_color_abajo[colorAbajo].push_back(indice);
    v_color_derecha[colorDerecha].push_back(indice);
  }
  /**
   * Dado un ID de pieza, lo quita del índice
   */
  void quitarPieza ( uint32_t indice ){
    uint32_t colorDerecha = listaDePiezas[indice].colorDerecha;
    uint32_t colorAbajo = listaDePiezas[indice].colorAbajo;
    v_color_derecha_abajo[colorDerecha][colorAbajo].push_front(indice);
    v_color_abajo[colorAbajo].push_front(indice);
    v_color_derecha[colorDerecha].push_front(indice);
    //v[colorDerecha][colorAbajo]
  }
  /**
   * Dadas las piezas de la izquierda y de arriba devuelve una lista 
   * con los ID de las posibles piezas que se pueden agregar
   */
  list<uint32_t> &damePiezasPosibles( uint32_t piezaIzquierda, uint32_t piezaArriba){
    uint32_t colorDerecha = listaDePiezas[piezaIzquierda].colorDerecha;
    uint32_t colorAbajo = listaDePiezas[piezaArriba].colorAbajo;
    return v_color_derecha_abajo[colorDerecha][colorAbajo];
  }
  list<uint32_t> &damePiezasPosiblesParaAbajoDe( uint32_t piezaArriba ){
    uint32_t colorAbajo = listaDePiezas[piezaArriba].colorAbajo;
    return v_color_abajo[colorAbajo];
  }
  list<uint32_t> &damePiezasPosiblesParaLaDerechaDe( uint32_t piezaIzquierda ){
    uint32_t colorDerecha = listaDePiezas[piezaIzquierda].colorDerecha;
    return v_color_derecha[colorDerecha];
  }
  /*void calcularPiezasPosibles( uint32_t piezaIzquierda, uint32_t piezaArriba ){

  }*/
  /*bool hayPiezasPosibles(void){
    return false;
  }*/
  /*list< uint32_t >::iterator dameSiguientePiezaPosible(void){
    //return 0;
  }*/
private:
  vector< vector< list< uint32_t > > > v_color_derecha_abajo;
  vector< list< uint32_t > > v_color_abajo;
  vector< list< uint32_t > > v_color_derecha;
  vector<TestCaseEj3::Pieza> &listaDePiezas;
};

void backtrack( Tablero &, IndiceDeColores &, uint32_t, uint32_t );

#endif
