#ifndef TESTCASE_EJ2_H
#define TESTCASE_EJ2_H

#include "../common/TestCase.h"

class TestCaseEj2 : TestCase {
public:
  typedef struct Pieza
  {
    uint32_t perdidaDiariaDeGanancia;
    uint32_t tiempoDeFabricacion;
    uint32_t numeroDeOrden;
    inline bool operator<(const Pieza& a) const
    {
        return (
          perdidaDiariaDeGanancia/tiempoDeFabricacion < 
          a.perdidaDiariaDeGanancia/a.tiempoDeFabricacion);
    }
  };
  TestCaseEj2( std::istream & );
  ~TestCaseEj2();
  bool tomarDatos();
  /*
  // Getters
  uint32_t dameNumeroDePiezasAFabricar(void);
  vector<Pieza> *dameListadoDePiezas(void);
  */
private:
  uint32_t _numeroDePiezasAFabricar;
  vector<Pieza> *_listaDePiezas;
public:
  /**
   * Devuelve la cantidad de piezas que se necesitan fabricar
   */
  inline const uint32_t& dameNumeroDePiezasAFabricar(void) const { return this->_numeroDePiezasAFabricar; }
  /**
   * Devuelve el listado de piezas
   */
  inline vector<TestCaseEj2::Pieza>* dameListadoDePiezas(void) { return this->_listaDePiezas; }
};

#endif
