#ifndef __ITERADORINDICEDEPIEZAS_H__
#define __ITERADORINDICEDEPIEZAS_H__
#include "ej3.h"

//class IndiceDePiezas;
#include "IndiceDePiezas.h"
class IteradorIndiceDePiezas
{
private:
  bool _piezaTransparenteUtilizada;
  bool _utilizarPiezaTransparente;
protected:
  vector<bool>& _indicePiezasDisponibles;
  vector<uint32_t>& _indiceSecuencial;
  IndiceDePiezas::listaDePiezas* _v;
  IndiceDePiezas::listaDePiezas::iterator _v_it;
  //IteradorIndiceDePiezas ( IteradorIndiceDePiezas::*avanzar )( int );
public:
  IteradorIndiceDePiezas( IndiceDePiezas&, uint32_t );
  virtual ~IteradorIndiceDePiezas() = 0;
  virtual bool hayPiezasPosibles() = 0;
  virtual IteradorIndiceDePiezas& operator++( int );
  virtual uint32_t operator*();
  void utilizarPiezaTransparente();
};

#include "IteradorSecuencial.h"
#endif




