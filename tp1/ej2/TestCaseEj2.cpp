#include "TestCaseEj2.h"

/**
 * Constructor
 */
TestCaseEj2::TestCaseEj2( std::istream &pinput ) : TestCase(pinput)
{
  this->_listadoDePiezas=NULL;
  this->_numeroDePiezasAFabricar=0;
}

/**
 * Realiza la lectura de datos para el ejercicio
 */
bool TestCaseEj2::tomarDatos()
{
  // Libero memoria de la toma de datos anterior
  if (this->_listadoDePiezas!=NULL){
    delete this->_listadoDePiezas;
    this->_listadoDePiezas = NULL;
  }
  // Tomo la cantidad de piezas a fabricar
  this->_input >> this->_numeroDePiezasAFabricar;
  if(this->_numeroDePiezasAFabricar == 0){
    return false;
  }
  // Tomo el listado de piezas (pérdida y tiempo)
  this->_listadoDePiezas = new vector<Pieza>;
  this->_listadoDePiezas->reserve(this->_numeroDePiezasAFabricar);
  for(uint32_t i=0; i<this->_numeroDePiezasAFabricar; i++){
    Pieza pieza;
    this->_input >> pieza.perdidaDiariaDeGanancia >> pieza.tiempoDeFabricacion;
    this->_listadoDePiezas->push_back(pieza);
  }
  return true;
}
/**
 * Devuelve la cantidad de piezas que se necesitan fabricar
 */
uint32_t TestCaseEj2::dameNumeroDePiezasAFabricar(void)
{
  return this->_numeroDePiezasAFabricar;
}
/**
 * Devuelve el listado de piezas
 */
vector<TestCaseEj2::Pieza> *TestCaseEj2::dameListadoDePiezas(void)
{
  return this->_listadoDePiezas;
}
/**
 * Destructor
 */
TestCaseEj2::~TestCaseEj2(void)
{
  // Libero la memoria
  if (this->_listadoDePiezas!=NULL){
    delete[] this->_listadoDePiezas;
    this->_listadoDePiezas = NULL;
  }
}
