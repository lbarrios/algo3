#include "TestCase.h"

/**
 * Constructor
 */
TestCase::TestCase(std::istream &pinput) : _input(pinput)
{
  if (!this->_input){
    cout << "Error en el programa: No se puede leer el input." << endl 
    << "El programa se cerrará!" << endl;
    exit(-1);
  }
}
/**
 * Destructor
 */
TestCase::~TestCase(){
}
