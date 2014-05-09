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
  vector<uint32_t>* _indiceColores;
  IndiceDePiezas::listaDePiezas* _v;
  IndiceDePiezas::listaDePiezas::iterator _v_it;
  IndiceDePiezas& _ip;
  uint32_t _posicion;
public:
  IteradorIndiceDePiezas( IndiceDePiezas&, uint32_t );
  virtual ~IteradorIndiceDePiezas() = 0;
  virtual bool hayPiezasPosibles() = 0;
  virtual IteradorIndiceDePiezas& operator++( int );
  virtual uint32_t operator*();
  void utilizarPiezaTransparente();
};

#include "IteradorSecuencial.h"
#include "IteradorColores.h"
#endif




