#ifndef __INDICEDEPIEZAS_H__
#define __INDICEDEPIEZAS_H__
#include "ej3.h"
#include "Tablero.h"

class IteradorIndiceDePiezas;
class IndiceDePiezas
{
  friend class IteradorIndiceDePiezas;
private:
  Tablero& _t;
  vector<TestCaseEj3::Pieza>& _listaDePiezas;
  vector<IteradorIndiceDePiezas*> _iteradores;
  typedef vector<uint32_t> listaDePiezas;
  vector< vector< stack< listaDePiezas > > > _indiceDeDosColores;
  vector<bool> _indicePiezasDisponibles;
  stack< listaDePiezas > _indiceSecuencial;
  void _imprimirIndiceDeDosColores();
  //listaDePiezas _indiceSecuencial;
  //IteradorIndiceDePiezas* _it;
  //
public:
  IndiceDePiezas( uint32_t, vector<TestCaseEj3::Pieza>&, Tablero& );
  ~IndiceDePiezas();
  IteradorIndiceDePiezas& dameIterador( uint32_t );
  bool puedeColorarPiezaEnPosicion( uint32_t, uint32_t );
  void marcarPiezaUtilizada( IteradorIndiceDePiezas& );
  void marcarPiezaDisponible( IteradorIndiceDePiezas& );

  //: listaDePiezas(p_listaDePiezas), v(p_cantidadDeColores, vector<listaDisponibles>(3, listaDisponibles()) ){

};

#include "IteradorIndiceDePiezas.h"
//#include "IteradorMedio.h"

#endif

