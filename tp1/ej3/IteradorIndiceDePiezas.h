#ifndef __ITERADORINDICEDEPIEZAS_H__
#define __ITERADORINDICEDEPIEZAS_H__
#include "ej3.h"

//class IndiceDePiezas;
#include "IndiceDePiezas.h"
class IteradorIndiceDePiezas
{
private:
  bool _piezaTransparenteUtilizada;
protected:
  list<uint32_t>& _indiceSecuencial;
  list<uint32_t>* _v;
  list<uint32_t>::iterator _v_it;
  //IteradorIndiceDePiezas ( IteradorIndiceDePiezas::*avanzar )( int );
public:
  IteradorIndiceDePiezas( IndiceDePiezas&, uint32_t );
  virtual ~IteradorIndiceDePiezas() = 0;
  virtual bool hayPiezasPosibles() = 0;
  virtual IteradorIndiceDePiezas& operator++( int );
  virtual uint32_t operator*();
};

#include "IteradorNormal.h"
#endif




