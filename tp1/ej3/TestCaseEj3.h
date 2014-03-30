#include "../common/TestCase.h"

class TestCaseEj3 : TestCase {
public:
  typedef struct Pieza{
    uint32_t colorIzquierda;
    uint32_t colorDerecha;
    uint32_t colorArriba;
    uint32_t colorAbajo;
  };
  TestCaseEj3( std::istream & );
  ~TestCaseEj3();
  bool tomarDatos();
  // Getters
  uint32_t dameCantidadDeFilas(void);
  uint32_t dameCantidadDeColumnas(void);
  uint32_t dameCantidadDeColores(void);
  vector<Pieza> *dameListaDePiezas(void);
private:
  uint32_t _cantidadDeFilas;
  uint32_t _cantidadDeColumnas;
  uint32_t _cantidadDeColores;
  vector<Pieza> *_listaDePiezas;
  bool _yaSeEjecuto;
};

