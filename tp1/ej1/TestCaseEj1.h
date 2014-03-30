#include "../common/TestCase.h"

class TestCaseEj1 : TestCase {
public:
  TestCaseEj1( std::istream & );
  ~TestCaseEj1();
  bool tomarDatos();
private:
  uint32_t _intervaloInspector;
  uint32_t _cantidadDeCamiones;
  uint32_t* _fechasCamiones;
public:
  /**
   * Devuelve la cantidad de días que trabaja el inspector
   */
  inline const uint32_t& dameIntervaloInspector(void) const{ return this->_intervaloInspector; };
  /**
   * Devuelve un puntero a un vector con las fechas de los camiones
   */
  inline uint32_t* dameFechasCamiones(void) { return this->_fechasCamiones; };
  /**
   * Devuelve la cantidad de camiones
   */
  inline const uint32_t& dameCantidadDeCamiones(void) const{ return this->_cantidadDeCamiones; };
};

