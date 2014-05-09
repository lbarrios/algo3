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
};

#endif




