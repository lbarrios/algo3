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
  vector< vector< list<uint32_t> > > _indiceDeColores;
  list<uint32_t> _indiceSecuencial;
  //IteradorIndiceDePiezas* _it;
  //
public:
  IndiceDePiezas( uint32_t, vector<TestCaseEj3::Pieza>&, Tablero& );
  ~IndiceDePiezas();
  IteradorIndiceDePiezas& dameIterador( uint32_t );
  //: listaDePiezas(p_listaDePiezas), v(p_cantidadDeColores, vector<listaDisponibles>(3, listaDisponibles()) ){

};

#include "IteradorIndiceDePiezas.h"

//#include "IteradorMedio.h"

#endif

