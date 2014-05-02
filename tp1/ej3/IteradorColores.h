#ifndef __ITERADORCOLORES_H__
#define __ITERADORCOLORES_H__
#include "IteradorIndiceDePiezas.h"

class IteradorColores : public IteradorIndiceDePiezas
{
public:
  IteradorColores( IndiceDePiezas&, uint32_t );
  ~IteradorColores();
  IteradorColores& operator++( int );
  bool hayPiezasPosibles();
private:
};

#endif

