#include "../common/TestCase.h"

class TestCaseEj1 : TestCase { //: public TestCase {
public:
	TestCaseEj1( std::istream & );
	~TestCaseEj1();
	bool tomarDatos();
	// Getters
	int dameIntervaloInspector(void);
	int* dameFechasCamiones(void);
	int dameCantidadCamiones(void);
private:
	int _intervaloInspector;
	int _cantidadCamiones;
	int* _fechasCamiones;
};

