#include "../common/TestCase.h"

class TestCaseEj2 : TestCase {
public:
  typedef struct Pieza
  {
    uint32_t perdidaDiariaDeGanancia;
    uint32_t tiempoDeFabricacion;
  };
  TestCaseEj2( std::istream & );
  ~TestCaseEj2();
  bool tomarDatos();
  // Getters
  uint32_t dameNumeroDePiezasAFabricar(void);
  vector<Pieza> *dameListadoDePiezas(void);
private:
  uint32_t _numeroDePiezasAFabricar;
  vector<Pieza> *_listadoDePiezas;
};

