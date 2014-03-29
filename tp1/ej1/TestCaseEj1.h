#include "../common/TestCase.h"

class TestCaseEj1 : TestCase { //: public TestCase {
	public:
	TestCaseEj1( std::istream & );
	~TestCaseEj1();
	void imprimir(){
        if(_input!=NULL){
            cout << "El input era: ";
            int in;
            _input >> in;
            cout << in << endl;
    bool tomarDatos ();
        }
	}
};

