#ifndef __INDICEDECOLORES_H__
#define __INDICEDECOLORES_H__
#include "ej3.h"

class IndiceDeColores 
{
private:
  struct piezaIndexada
  {
    piezaIndexada (uint32_t ip, uint32_t id) : indiceEnListaDePiezas(ip), indiceEnListaDisponibles(id) {};
    uint32_t indiceEnListaDePiezas;
    uint32_t indiceEnListaDisponibles;
  };
  struct listaDisponibles
  {
    listaDisponibles( ) : principio(0){ };
    vector< piezaIndexada > lista;
    uint32_t principio;
  };
  vector<TestCaseEj3::Pieza> &listaDePiezas;
  vector< vector< listaDisponibles > > v;
  inline uint32_t colorDerecha (uint32_t indice)
  {
    return this->listaDePiezas[indice].colorDerecha - 1;
  }
  inline uint32_t colorAbajo (uint32_t indice)
  {
    return this->listaDePiezas[indice].colorAbajo - 1;
  }
public:
  struct Iterador{
    IndiceDeColores& _ic;
    inline void quitarPieza()
    {
      (this->_ic.*_quitarPieza)( *this );
    }
    vector< vector< listaDisponibles > >& _v;
    vector< piezaIndexada >* _v_res;
    uint32_t _indice;
    bool _primeraColumna;
    bool _primeraFila;
    uint32_t _colorDerechaActual;
    uint32_t _colorAbajoActual;
    bool _piezaTransparenteUtilizada;
    void (Iterador::*_avanza)();
    bool (Iterador::*_hayPosibles)();
    void (IndiceDeColores::*_quitarPieza)( IndiceDeColores::Iterador & );
    /**
     * Inicializa el iterador
     */
    inline void _avanzaIteradorNormal() {
      this->_indice++;
    }
    inline void _avanzaIteradorPrimerCasillero()
    {
      _C("_avanzaIteradorPrimerCasillero();");
      this->_avanzaIteradorNormal();
      if ( !this->_hayPosiblesNormal() )
      {
        _C("No hay posibles en este color " << this->_colorAbajoActual);
        listaDisponibles l;
        while(true)
        {
          this->_colorAbajoActual++;
          if (this->_colorAbajoActual >= this->_v.size())
          {
            this->_colorAbajoActual = 0;
            this->_colorDerechaActual++;
          }
          l = _v[this->_colorDerechaActual][this->_colorAbajoActual];
          if ((l.lista.size() - l.principio) > 0)
          {
            _C("Encontrado color disponible: derecha:" << this->_colorDerechaActual << ", abajo: " << this->_colorAbajoActual);
            break;
          }
        }
        this->_v_res = &(l.lista);
        this->_indice = l.principio;
      }
    }
    inline void _avanzaIteradorPrimeraColumna(){
      _C("_avanzaIteradorPrimeraColumna();");
      this->_avanzaIteradorNormal();
      if ( !this->_hayPosiblesNormal() )
      {
        _C("No hay posibles en este color " << this->_colorAbajoActual);
        listaDisponibles l;
        while(true)
        {
          this->_colorDerechaActual++;
           l = _v[this->_colorDerechaActual][this->_colorAbajoActual];
          if ((l.lista.size() - l.principio) > 0)
          {
            _C("Encontrado color disponible: derecha:" << this->_colorDerechaActual << ", abajo: " << this->_colorAbajoActual);
            break;
          }
        }
        this->_v_res = &(l.lista);
        this->_indice = l.principio;
      }
    }
    inline void _avanzaIteradorPrimeraFila()
    {
      _C("_avanzaIteradorPrimeraFila();");
      this->_avanzaIteradorNormal();
      if ( !this->_hayPosiblesNormal() )
      {
        _C("No hay posibles en este color " << this->_colorAbajoActual);
        listaDisponibles l;
        while(true)
        {
          this->_colorAbajoActual++;
           l = _v[this->_colorDerechaActual][this->_colorAbajoActual];
          if ((l.lista.size() - l.principio) > 0)
          {
            _C("Encontrado color disponible: derecha:" << this->_colorDerechaActual << ", abajo: " << this->_colorAbajoActual);
            break;
          }
        }
        this->_v_res = &(l.lista);
        this->_indice = l.principio;
      }
    }
    inline bool _hayPosiblesNormal() 
    {
      _C("Verificando hayPosiblesNormal. indice: "<< this->_indice <<", this->_v_res->size=" << this->_v_res->size());
      DEBUG_BOOL(this->_indice < this->_v_res->size());
      return (this->_indice < this->_v_res->size());
    }
    inline bool _hayPosiblesPrimeraColumna() 
    {
      if (this->_hayPosiblesNormal())
      {
        return true;
      }
      _C("hayPosiblesPrimeraColumna: Debe cambiar de color");
      DEBUG_INT(this->_colorDerechaActual);
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
      _C("HayPosiblesPrimeraFila: Debe cambiar de color");
      DEBUG_INT(this->_colorAbajoActual);
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
      if (this->_hayPosiblesNormal())
      {
        return true;
      }
      for(uint32_t i = this->_colorAbajoActual; i<this->_v.size(); i++)
      {
        for(uint32_t j = this->_colorDerechaActual+1; j<this->_v.size(); j++)
        {
          listaDisponibles l = _v[j][i];
          if ((l.lista.size() - l.principio) > 0)
          {
            return true;
          }
        }
      }
      return false;
    }
    Iterador( IndiceDeColores& p_ic, uint32_t p_i, uint32_t p_a ) : 
      _ic(p_ic),
      _v(p_ic.v),
      _primeraColumna(p_i==TestCaseEj3::PIEZA_VACIA),
      _primeraFila(p_a==TestCaseEj3::PIEZA_VACIA),
      _piezaTransparenteUtilizada(false)
      {
        // Si es primera columna pero no primera fila
        if(this->_primeraColumna && !this->_primeraFila)
        {
          _C("IC::IT() El casillero es primera columna pero no es primera fila");
          this->_avanza = &Iterador::_avanzaIteradorPrimeraColumna;
          this->_hayPosibles = &Iterador::_hayPosiblesPrimeraColumna;
          this->_colorDerechaActual = 0;
          this->_colorAbajoActual = _ic.colorAbajo(p_a);
        }
        // Si es primera fila pero no primera columna
        if(this->_primeraFila && !this->_primeraColumna)
        {
          _C("IC::IT() El casillero es primera fila pero no es primera columna");
          this->_avanza = &Iterador::_avanzaIteradorPrimeraFila;
          this->_hayPosibles = &Iterador::_hayPosiblesPrimeraFila;
          this->_colorDerechaActual = _ic.colorDerecha(p_i); 
          this->_colorAbajoActual = 0;
        }
        // Si no es ni primera columna ni primera fila
        if(!this->_primeraFila && !this->_primeraColumna)
        {
          _C("IC::IT() El casillero no es primera columna ni primera fila");
          this->_avanza = &Iterador::_avanzaIteradorNormal;
          this->_hayPosibles = &Iterador::_hayPosiblesNormal;
          this->_colorDerechaActual = _ic.colorDerecha(p_i); 
          this->_colorAbajoActual = _ic.colorAbajo(p_a);
        }
        // Si es el primer casillero (1ra columna y 1ra fila a la vez)
        if(this->_primeraColumna && this->_primeraFila)
        {
          _C("IC::IT() El casillero es primera columna y primera fila (1er casillero)");
          this->_avanza = &Iterador::_avanzaIteradorPrimerCasillero;
          this->_hayPosibles = &Iterador::_hayPosiblesPrimerCasillero;
          this->_quitarPieza = &IndiceDeColores::_quitarPieza;
          this->_colorDerechaActual = 0; 
          this->_colorAbajoActual = 0;
          //this->_indice = 1;
        }
        else
        {
          this->_quitarPieza = &IndiceDeColores::_quitarPieza;
        }
        this->_v_res = &(this->_v[_colorDerechaActual][_colorAbajoActual].lista);
        this->_indice = this->_v[this->_colorDerechaActual][this->_colorAbajoActual].principio;
        _C("IC::IT() colorDerechaActual= "<< this->_colorDerechaActual <<", colorAbajoActual= " << this->_colorAbajoActual << ", indice= " << this->_indice);
        if(this->_v_res->size() == 0)
        {
          _C("IC::IT(); avanzando hasta colorDerechaActual= "<< this->_colorDerechaActual <<", colorAbajoActual= " << this->_colorAbajoActual << ", indice= " << this->_indice);
          (this->*_avanza)();
        }
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
        _C("Avanzando el iterador. Ya no quedan piezas. (pieza transparente).");
        this->_piezaTransparenteUtilizada = true;
        return *this;
      }
      _C("Avanzando el iterador normalmente");
      (this->*_avanza)();
      return *this;
    }
    /**
     * Devuelve el contenido del iterador
     */
    inline uint32_t operator*( void ) 
    {
      if (!((this->*_hayPosibles)()))
      {
        return TestCaseEj3::PIEZA_VACIA;
      }
      DEBUG_INT(this->_indice);
      DEBUG_INT((*this->_v_res).size());
      return (*this->_v_res)[this->_indice].indiceEnListaDePiezas;
      /*
      if( !(this->_primeraColumna && this->_primeraFila) )
      {
        return (*this->_v_res)[this->_indice].indiceEnListaDePiezas;
      }
      else
      {
        return _indice;
      }
      */
    }
  };
  IndiceDeColores( uint32_t p_cantidadDeColores, vector<TestCaseEj3::Pieza> &p_listaDePiezas ) 
  : listaDePiezas(p_listaDePiezas), v(p_cantidadDeColores, vector<listaDisponibles>(3, listaDisponibles()) ){
    //this->_v_pieza_indexada.push_back(IndiceDeColores::piezaIndexada(0,0));
    // Agrego las piezas al índice de piezas por color, me salteo pieza vacía
    for (uint32_t i = 1; i<this->listaDePiezas.size(); i++){
      TestCaseEj3::Pieza pieza = this->listaDePiezas[i];
      uint32_t colorDerecha = this->colorDerecha(i);
      uint32_t colorAbajo = this->colorAbajo(i);
      v[colorDerecha][colorAbajo].lista.push_back(IndiceDeColores::piezaIndexada(i,v[colorDerecha][colorAbajo].lista.size()));
      //this->_v_pieza_indexada.push_back(IndiceDeColores::piezaIndexada(i,v[colorDerecha][colorAbajo].lista.size()));
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
    void _quitarPieza ( Iterador &it )
    {
      uint32_t colorDerecha = this->colorDerecha(*it);// listaDePiezas[*it].colorDerecha;
      uint32_t colorAbajo = this->colorAbajo(*it);// listaDePiezas[*it].colorAbajo;
      listaDisponibles& listaDisp = v[colorDerecha][colorAbajo];
      DEBUG_INT(it._indice);
      DEBUG_INT((*it._v_res)[it._indice].indiceEnListaDisponibles);
      DEBUG_INT(listaDisp.principio);
      // Me aseguro que el elemento que quiero "borrar" quede al principio
      if ( (*it._v_res)[it._indice].indiceEnListaDisponibles != listaDisp.principio )
      {
        // Si no está al principio, swapeo
        uint32_t bak = listaDisp.lista[it._indice].indiceEnListaDePiezas;
        listaDisp.lista[it._indice].indiceEnListaDePiezas = listaDisp.lista[listaDisp.principio].indiceEnListaDePiezas;
        listaDisp.lista[listaDisp.principio].indiceEnListaDePiezas = bak;
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
        uint32_t bak = listaDisp.lista[it._indice].indiceEnListaDePiezas;
        listaDisp.lista[it._indice] = listaDisp.lista[listaDisp.principio];
        listaDisp.lista[listaDisp.principio].indiceEnListaDePiezas = bak;
      }
    }
  /**
   * Dadas las piezas de la izquierda y de arriba devuelve una lista 
   * con los ID de las posibles piezas que se pueden agregar
   */
  Iterador &damePiezasPosibles( uint32_t piezaIzquierda, uint32_t piezaArriba)
  {
    if(piezaIzquierda != TestCaseEj3::PIEZA_VACIA && piezaArriba != TestCaseEj3::PIEZA_VACIA){ _C("IC::IT damePiezasPosibles("<< piezaIzquierda <<","<< piezaArriba <<") -> con piezas no nulas");}
    if(piezaIzquierda == TestCaseEj3::PIEZA_VACIA && piezaArriba != TestCaseEj3::PIEZA_VACIA){ _C("IC::IT damePiezasPosibles("<< piezaIzquierda <<","<< piezaArriba <<") -> con pieza izquierda nula");}
    if(piezaIzquierda != TestCaseEj3::PIEZA_VACIA && piezaArriba == TestCaseEj3::PIEZA_VACIA){ _C("IC::IT damePiezasPosibles("<< piezaIzquierda <<","<< piezaArriba <<") -> con pieza arriba nula");}
    if(piezaIzquierda == TestCaseEj3::PIEZA_VACIA && piezaArriba == TestCaseEj3::PIEZA_VACIA){ _C("IC::IT damePiezasPosibles("<< piezaIzquierda <<","<< piezaArriba <<") -> con ambas piezas nulas");}
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

#endif
