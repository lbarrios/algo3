#ifndef EJ3_H
#define EJ3_H

#include "../common/headers.h"
#include "../common/ParserDeParametros.h"
#include "../common/Timer.h"
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
  static const uint32_t COLOR_NULO = 0;
  struct Iterador{
    Iterador( vector< vector< list< uint32_t > > > p_v, uint32_t cd, uint32_t ca ) 
    : _v(p_v), _colorDerecha(cd), _colorAbajo(ca) 
    {
      if(cd!=IndiceDeColores::COLOR_NULO){ this->_colorDerechaActual = cd; }
      else { this->_colorDerechaActual = 1; }
      if(ca!=IndiceDeColores::COLOR_NULO){ this->_colorAbajoActual = ca; }
      else { this->_colorAbajoActual = 1; }
      this->_it = this->_v[_colorDerechaActual][_colorAbajoActual].begin();
    }
    bool hayPiezasPosibles( void ){
      if (this->_it != this->_v[_colorDerechaActual][_colorAbajoActual].end())
      {
        return true;
      }
      if(this->_colorDerecha==IndiceDeColores::COLOR_NULO && this->_colorDerechaActual < _v.size())
      {
        return true;
      }
      if(this->_colorAbajo==IndiceDeColores::COLOR_NULO && this->_colorAbajoActual < _v[0].size())
      {
        return true;
      }
      return false;
    }
    /**
     * Avanza el iterador.
     * El usuario debe revisar si hayPiezasPosibles() primero.
     */
    void avanzarIterador( void ){
      if (this->_it != this->_v[_colorDerechaActual][_colorAbajoActual].end())
      {
        this->_it++;
      } 
      else 
      {
        if(this->_colorAbajo==IndiceDeColores::COLOR_NULO && this->_colorAbajoActual < _v[0].size())
        {
          this->_colorAbajoActual++;
          this->_it = this->_v[_colorDerechaActual][_colorAbajoActual].begin();
        }
        else
        {
          this->_colorDerechaActual++;
          if(this->_colorAbajo==IndiceDeColores::COLOR_NULO)
          {
            this->_colorAbajoActual = 1;
          }
          this->_it = this->_v[_colorDerechaActual][_colorAbajoActual].begin();
        }
      }
    }
    list<uint32_t>::iterator &dameIterador( void ){
      return this->_it;
    }
    vector< vector< list< uint32_t > > > _v;
    list< uint32_t >::iterator _it;
    uint32_t _colorDerecha;
    uint32_t _colorAbajo;
    uint32_t _colorDerechaActual;
    uint32_t _colorAbajoActual;
  };
  IndiceDeColores( uint32_t p_cantidadDeColores, vector<TestCaseEj3::Pieza> &p_listaDePiezas ) 
    : listaDePiezas(p_listaDePiezas){
    v_color_derecha_abajo.resize(p_cantidadDeColores+1); DEBUG_INT( v_color_derecha_abajo.size() );
    for(vector< vector< list< uint32_t > > >::iterator it = v_color_derecha_abajo.begin(); 
      it < v_color_derecha_abajo.end(); it++){
      (*it).resize(p_cantidadDeColores+1); DEBUG_INT( (*it).size() );
    }
    //v_color_abajo.resize(p_cantidadDeColores);
    //v_color_derecha.resize(p_cantidadDeColores);
    _C("Agrego las piezas al índice de piezas por color");
    // Agrego las piezas al índice de piezas por color
    for (uint32_t i = 1; i<this->listaDePiezas.size()+1; i++){
      _C("this->agregarPieza( "<<i<<" );");
      this->agregarPieza( i );
    }
    _C("this->agregarPieza( "<<"TestCaseEj3::PIEZA_VACIA"<<" );");
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
  /*void agregarPiezaIt ( uint32_t indice, list< uint32_t >::iterator& it ){
    uint32_t colorDerecha = listaDePiezas[indice].colorDerecha - 1; DEBUG_INT(colorDerecha);
    uint32_t colorAbajo = listaDePiezas[indice].colorAbajo - 1; DEBUG_INT(colorAbajo);
    v_color_derecha_abajo[colorDerecha][colorAbajo].insert(it, indice);
    _C("v_color_derecha_abajo[colorDerecha][colorAbajo].insert(it, indice);");
    v_color_abajo[colorAbajo].insert(it, indice);
    _C("v_color_abajo[colorAbajo].insert(it, indice);");
    v_color_derecha[colorDerecha].insert(it, indice);
    _C("v_color_derecha[colorDerecha].insert(it, indice);");
  }*/
  /**
   * Dado un ID de pieza, lo quita del índice
   */
    list< uint32_t >::iterator quitarPieza ( IndiceDeColores::Iterador& indiceIt )
    {
    //list< uint32_t >::iterator siguienteIt = indiceIt; siguienteIt++;
      list< uint32_t >::iterator piezaIt = indiceIt.dameIterador();
      list< uint32_t >::iterator itSiguiente = list< uint32_t >::iterator(piezaIt);
      itSiguiente++;
      uint32_t colorDerecha = listaDePiezas[*piezaIt].colorDerecha;
      uint32_t colorAbajo = listaDePiezas[*piezaIt].colorAbajo;
      v_color_derecha_abajo[colorDerecha+1][colorAbajo+1].erase(piezaIt);
      return itSiguiente;
    //v_color_abajo[colorAbajo].push_front(*indiceIt);
    //v_color_derecha[colorDerecha].push_front(*indiceIt);
    //IndiceDeColores::siguienteIt sig;
    //return siguienteIt;
    }
  /**
   * Dadas las piezas de la izquierda y de arriba devuelve una lista 
   * con los ID de las posibles piezas que se pueden agregar
   */
  Iterador &damePiezasPosibles( uint32_t piezaIzquierda, uint32_t piezaArriba)
  {
    uint32_t colorDerecha = listaDePiezas[piezaIzquierda].colorDerecha;
    uint32_t colorAbajo = listaDePiezas[piezaArriba].colorAbajo;
    Iterador *it = new Iterador( v_color_derecha_abajo, colorDerecha, colorAbajo);
    return *it;
    //return v_color_derecha_abajo[colorDerecha][colorAbajo];
  }
  /*
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
  */
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
  //vector< list< uint32_t > > v_color_abajo;
  //vector< list< uint32_t > > v_color_derecha;
  vector<TestCaseEj3::Pieza> &listaDePiezas;
  void agregarPieza ( uint32_t indice )
  {
    uint32_t colorDerecha = listaDePiezas[indice].colorDerecha; DEBUG_INT(colorDerecha);
    uint32_t colorAbajo = listaDePiezas[indice].colorAbajo; DEBUG_INT(colorAbajo);
    v_color_derecha_abajo[colorDerecha+1][colorAbajo+1].push_back(indice);
    //v_color_abajo[colorAbajo].push_back(indice);
    //v_color_derecha[colorDerecha].push_back(indice);
  }
};

void backtrack( Tablero &, IndiceDeColores &, uint32_t, uint32_t );

#endif
