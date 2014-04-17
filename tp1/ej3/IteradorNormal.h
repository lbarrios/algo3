#ifndef __ITERADORNORMAL_H__
#define __ITERADORNORMAL_H__
#include "IteradorIndiceDePiezas.h"

class IteradorNormal : public IteradorIndiceDePiezas
{
public:
  IteradorNormal( IndiceDePiezas&, uint32_t );
  ~IteradorNormal();
  IteradorNormal& operator++( int );
  bool hayPiezasPosibles();
private:
  //list<uint32_t>& _v;
  //list<uint32_t>::iterator _v_it;
};

#endif




