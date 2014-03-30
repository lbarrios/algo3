#include "../common/TestCase.h"

class TestCaseEj1 : TestCase {
public:
	TestCaseEj1( std::istream & );
	~TestCaseEj1();
	bool tomarDatos();
	// Getters
	uint32_t dameIntervaloInspector(void);
	uint32_t* dameFechasCamiones(void);
	uint32_t dameCantidadDeCamiones(void);
private:
	uint32_t _intervaloInspector;
	uint32_t _cantidadDeCamiones;
	uint32_t* _fechasCamiones;
};

