#include "TestCaseEj1.h"
/**
 * Constructor
 */
TestCaseEj1::TestCaseEj1( std::istream &pinput ) : TestCase(pinput)
{
  this->_intervaloInspector = 0;
  this->_cantidadDeCamiones = 0;
  this->_fechasCamiones = NULL;
}
/**
 * Realiza la lectura de datos para el ejercicio
 */
bool TestCaseEj1::tomarDatos()
{
  // Libero memoria de la toma de datos anterior
  if (this->_fechasCamiones!=NULL){
    delete[] this->_fechasCamiones;
    this->_fechasCamiones = NULL;
  }

  // Tomo el intervalo del inspector
  this->_input >> this->_intervaloInspector;
  if(this->_intervaloInspector == 0){
    return false;
  }

  // Tomo la cantidad de camiones
  this->_input >> this->_cantidadDeCamiones;

  // Tomo las fechas en que pasan los camiones
  this->_fechasCamiones = new uint32_t[this->_cantidadDeCamiones];
  for(uint32_t i=0; i<this->_cantidadDeCamiones; i++){
    this->_input >> this->_fechasCamiones[i];
  }

  return true;
}
/**
 * Destructor
 */
TestCaseEj1::~TestCaseEj1(void)
{
  // Libero la memoria dinámica
  if (this->_fechasCamiones!=NULL){
    delete[] this->_fechasCamiones;
    this->_fechasCamiones = NULL;
  }
}
