#ifndef __ITERADORSECUENCIAL_H__
#define __ITERADORSECUENCIAL_H__
#include "IteradorIndiceDePiezas.h"

class IteradorSecuencial : public IteradorIndiceDePiezas
{
public:
  IteradorSecuencial( IndiceDePiezas&, uint32_t );
  ~IteradorSecuencial();
  IteradorSecuencial& operator++( int );
  bool hayPiezasPosibles();
private:
  //list<uint32_t>& _v;
  //list<uint32_t>::iterator _v_it;
};

#endif




