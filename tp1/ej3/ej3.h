#ifndef EJ3_H
#define EJ3_H

#include "../common/headers.h"
#include "../common/ParserDeParametros.h"
#include "../common/Timer.h"
#include "TestCaseEj3.h"


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

class IndiceDeColores {
private:
  struct listaDisponibles{
    listaDisponibles( void )
    { 
      principio = 0;
    };
    vector< uint32_t > lista;
    //uint32_t tamanio;
    uint32_t principio;
  };
  vector< vector< listaDisponibles > > v;
  vector<TestCaseEj3::Pieza> &listaDePiezas;
  inline uint32_t colorDerecha (uint32_t indice)
  {
    return this->listaDePiezas[indice].colorDerecha - 1;
  }
  inline uint32_t colorAbajo (uint32_t indice)
  {
    return this->listaDePiezas[indice].colorAbajo - 1;
  }
public:
  //static const uint32_t COLOR_NULO = 0;
  struct Iterador{
    /**
     * Inicializa el iterador
     */
    inline void _avanzaIteradorNormal() {
      this->_indice++;
    }
    inline void _avanzaIteradorPrimerCasillero(){
      this->_indice++;
    }
    inline void _avanzaIteradorPrimeraColumna(){
      if (this->_hayPosiblesNormal()){
        this->_indice++;
      }
      else
      {
        listaDisponibles l;
        while(true)
        {
          this->_colorDerechaActual++;
           l = _v[this->_colorDerechaActual][this->_colorAbajoActual];
          if ((l.lista.size() - l.principio) > 0)
          {
            break;
          }
        }
        this->_v_res = &(l.lista);
        this->_indice = l.principio;
      }
    }
    inline void _avanzaIteradorPrimeraFila(){
      if (this->_hayPosiblesNormal()){
        this->_indice++;
      }
      else
      {
        listaDisponibles l;
        while(true)
        {
          this->_colorAbajoActual++;
           l = _v[this->_colorDerechaActual][this->_colorAbajoActual];
          if ((l.lista.size() - l.principio) > 0)
          {
            break;
          }
        }
        this->_v_res = &(l.lista);
        this->_indice = l.principio;
      }
    }
    inline bool _hayPosiblesNormal() 
    {
      return (this->_indice < this->_v_res->size());
    }
    inline bool _hayPosiblesPrimeraColumna() 
    {
      if (this->_hayPosiblesNormal())
      {
        return true;
      }
      for(uint32_t i = this->_colorDerechaActual+1;i<this->_v.size();i++)
      {
        listaDisponibles l = _v[i][this->_colorAbajoActual];
        if ((l.lista.size() - l.principio) > 0)
        {
          return true;
        }
      }
      return false;
    }
    inline bool _hayPosiblesPrimeraFila() 
    {
      if (this->_hayPosiblesNormal())
      {
        return true;
      }
      for(uint32_t i = this->_colorAbajoActual+1;i<this->_v.size();i++)
      {
        listaDisponibles l = _v[this->_colorDerechaActual][i];
        if ((l.lista.size() - l.principio) > 0)
        {
          return true;
        }
      }
      return false;
    }
    inline bool _hayPosiblesPrimerCasillero() 
    {
      return this->_indice < this->_ic.listaDePiezas.size();
    }
    Iterador( IndiceDeColores& p_ic, uint32_t p_i, uint32_t p_a ) : 
      _ic(p_ic),
      _v(p_ic.v),
      _piezaTransparenteUtilizada(false),
      _primeraColumna(p_i==TestCaseEj3::PIEZA_VACIA),
      _primeraFila(p_a==TestCaseEj3::PIEZA_VACIA)
      {
        // Si es primera columna pero no primera fila
        if(this->_primeraColumna && !this->_primeraFila)
        {
          this->_avanza = &Iterador::_avanzaIteradorPrimeraColumna;
          this->_hayPosibles = &Iterador::_hayPosiblesPrimeraColumna;
          this->_colorDerechaActual = 0;
          this->_colorAbajoActual = _ic.colorAbajo(p_a);
        }
        // Si es primera fila pero no primera columna
        if(this->_primeraFila && !this->_primeraColumna)
        {
          this->_avanza = &Iterador::_avanzaIteradorPrimeraFila;
          this->_hayPosibles = &Iterador::_hayPosiblesPrimeraFila;
          this->_colorDerechaActual = _ic.colorDerecha(p_i); 
          this->_colorAbajoActual = 0;
        }
        // Si no es ni primera columna ni primera fila
        if(!this->_primeraFila && !this->_primeraColumna)
        {
          this->_avanza = &Iterador::_avanzaIteradorNormal;
          this->_hayPosibles = &Iterador::_hayPosiblesNormal;
          this->_colorDerechaActual = _ic.colorDerecha(p_i); 
          this->_colorAbajoActual = _ic.colorAbajo(p_a);
        }
        // Si es el primer casillero (1ra columna y 1ra fila a la vez)
        if(this->_primeraColumna && this->_primeraFila)
        {
          this->_avanza = &Iterador::_avanzaIteradorPrimerCasillero;
          this->_hayPosibles = &Iterador::_hayPosiblesPrimerCasillero;
          this->_colorDerechaActual = 0; 
          this->_colorAbajoActual = 0;
          this->_indice = 1;
        }
        else
        {
          this->_indice = this->_v[this->_colorDerechaActual][this->_colorAbajoActual].principio;
        }
        this->_v_res = &(this->_v[_colorDerechaActual][_colorAbajoActual].lista);
      }
    /**
     * Describe si hay piezas disponibles en el iterador
     */
    bool hayPiezasPosibles( void )
    {
      if ((this->*_hayPosibles)())
      {
        _C("hayPosibles = true");
        return true;
      }
      _C("hayPosibles = false, utilizando PIEZA TRANSPARENTE");
      return !this->_piezaTransparenteUtilizada;
    }
    /**
     * Avanza el iterador.
     * El usuario debe revisar si hayPiezasPosibles() primero.
     */
    inline Iterador& operator++( int )
    {
      if (!((this->*_hayPosibles)())){
        this->_piezaTransparenteUtilizada = true;
        return *this;
      }
      (this->*_avanza)();
      return *this;

      /*
      if (this->_indice < this->_v[_colorDerechaActual][_colorAbajoActual].lista.size())
      {
        _C("Avanzo piezas posibles, _indice = " << this->_indice);
        this->_indice++;
        return *this;
      }
      if(this->_primeraColumna && this->_colorAbajoActual < _v.size())
      {
        this->_colorAbajoActual++;
        this->_indice = this->_v[_colorDerechaActual][_colorAbajoActual].principio;
      }
      else
      {
        if(this->_primeraColumna && this->_colorDerechaActual < _v.size())
        {
          this->_colorDerechaActual++;
          if(this->_primeraFila)
          {
            this->_colorAbajoActual = 0;
          }
          this->_indice = this->_v[_colorDerechaActual][_colorAbajoActual].principio;
        }
        else
        {
          this->_piezaTransparenteUtilizada = true;
        }
      }
      return *this;
      */
    }
    inline uint32_t operator*( void ) 
    {
      if (!((this->*_hayPosibles)()))
      {
        return TestCaseEj3::PIEZA_VACIA;
      }
      else
      {
        if( !(this->_primeraColumna && this->_primeraFila) )
        {
          return (*_v_res)[this->_indice];
        }
        else
        {
          return _indice;
        }
      }
            /*
      
        
          return _v[_colorDerechaActual][_colorAbajoActual].lista[this->_indice];
        }
        else{
          return 
        }
      }

      */
    }
    //vector<uint32_t>::iterator &dameIterador( void ){
    //  return this->_it;
    //}
    IndiceDeColores& _ic;
    vector< vector< listaDisponibles > >& _v;
    vector<uint32_t>* _v_res;
    //vector< uint32_t >::iterator _it;
    uint32_t _indice;
    //uint32_t _piezaIzquierda;
    //uint32_t _piezaArriba;
    bool _primeraColumna;
    bool _primeraFila;
    uint32_t _colorDerechaActual;
    uint32_t _colorAbajoActual;
    bool _piezaTransparenteUtilizada;
    void (Iterador::*_avanza)();
    bool (Iterador::*_hayPosibles)();
  };
  IndiceDeColores( uint32_t p_cantidadDeColores, vector<TestCaseEj3::Pieza> &p_listaDePiezas ) 
  : listaDePiezas(p_listaDePiezas), v(p_cantidadDeColores, vector<listaDisponibles>(3, listaDisponibles()) ){
    // Agrego las piezas al índice de piezas por color, me salteo pieza vacía
    for (uint32_t i = 1; i<this->listaDePiezas.size(); i++){
      TestCaseEj3::Pieza pieza = this->listaDePiezas[i];
      uint32_t colorDerecha = this->colorDerecha(i);
      uint32_t colorAbajo = this->colorAbajo(i);
      v[colorDerecha][colorAbajo].lista.push_back(i);
    }
    /*
    // Agrego piezas transparentes para todos los colores
    for (uint32_t i = 0; i<this->listaDePiezas.size(); i++)
    {
      for (uint32_t j=0; j<this->listaDePiezas.size(); j++)
      {
        v[i][j].lista.push_back( TestCaseEj3::PIEZA_VACIA );
      }
    }
    */
  };
  /**
   * Dado un ID de pieza y los colores de la derecha y de abajo de esa pieza
   * la agrega al vector de piezas
   */
  /*void agregarPiezaIt ( uint32_t indice, list< uint32_t >::iterator& it ){
    uint32_t colorDerecha = listaDePiezas[indice].colorDerecha - 1;
    uint32_t colorAbajo = listaDePiezas[indice].colorAbajo - 1;
    v_color_derecha_abajo[colorDerecha][colorAbajo].insert(it, indice);
    v_color_abajo[colorAbajo].insert(it, indice);
    v_color_derecha[colorDerecha].insert(it, indice);
  }*/
  /**
   * Dado un ID de pieza, lo quita del índice
   */
    void quitarPieza ( IndiceDeColores::Iterador& it )
    {
      uint32_t colorDerecha = this->colorDerecha(*it);// listaDePiezas[*it].colorDerecha;
      uint32_t colorAbajo = this->colorAbajo(*it);// listaDePiezas[*it].colorAbajo;
      DEBUG_INT(colorDerecha);
      listaDisponibles& listaDisp = v[colorDerecha][colorAbajo];
      // Me aseguro que el elemento que quiero "borrar" quede al principio
      DEBUG_INT(*it);
      DEBUG_INT(it._indice);
      DEBUG_INT(listaDisp.principio);
      if (it._indice != listaDisp.principio)
      {
        // Si no está al principio, swapeo
        uint32_t bak = listaDisp.lista[it._indice];
        listaDisp.lista[it._indice] = listaDisp.lista[listaDisp.principio];
        listaDisp.lista[listaDisp.principio] = bak;
      }
      // Aumento el "principio" de la lista
      (listaDisp.principio)++;

    }
    void restaurarPieza ( IndiceDeColores::Iterador& it )
    {
      uint32_t colorDerecha = this->colorDerecha(*it);// listaDePiezas[*it].colorDerecha;
      uint32_t colorAbajo = this->colorAbajo(*it);// listaDePiezas[*it].colorAbajo;
      listaDisponibles& listaDisp = v[colorDerecha][colorAbajo];
      // Disminuyo el "principio" de la lista
      (listaDisp.principio)--; 
      // Si no estaba al principio, restauro el elemento a su posición original
      if (it._indice != listaDisp.principio)
      {
        uint32_t bak = listaDisp.lista[it._indice];
        listaDisp.lista[it._indice] = listaDisp.lista[listaDisp.principio];
        listaDisp.lista[listaDisp.principio] = bak;
      }
    }
  /**
   * Dadas las piezas de la izquierda y de arriba devuelve una lista 
   * con los ID de las posibles piezas que se pueden agregar
   */
  Iterador &damePiezasPosibles( uint32_t piezaIzquierda, uint32_t piezaArriba)
  {
    Iterador *it = new Iterador( *this, piezaIzquierda, piezaArriba );
    return *it;
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
  /*
  void agregarPieza ( uint32_t indice )
  {
    uint32_t colorDerecha = listaDePiezas[indice].colorDerecha;
    uint32_t colorAbajo = listaDePiezas[indice].colorAbajo;
    v[colorDerecha+1][colorAbajo+1].push_back(indice);
  }
  */
};

void backtrack( Tablero &, IndiceDeColores &, uint32_t, uint32_t );

#endif
