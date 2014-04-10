#ifndef __INDICEDEPIEZAS_H__
#define __INDICEDEPIEZAS_H__
#include "../common/headers.h"
#include "TestCaseEj3.h"
#include "IteradorIndiceDePiezas.h"

class IndiceDePiezas
{
private:
  //IteradorIndiceDePiezas* _it;
  //
public:
  IndiceDePiezas( uint32_t p_cantidadDeColores, vector<TestCaseEj3::Pieza>& p_listaDePiezas );
  IteradorIndiceDePiezas& dameIterador( uint32_t );
  //: listaDePiezas(p_listaDePiezas), v(p_cantidadDeColores, vector<listaDisponibles>(3, listaDisponibles()) ){
  friend class IteradorIndiceDePiezas;
};

//#include "IteradorMedio.h"

#endif
