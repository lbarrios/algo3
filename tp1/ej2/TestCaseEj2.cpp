#include "TestCaseEj2.h"

/**
 * Constructor
 */
TestCaseEj2::TestCaseEj2( std::istream &pinput ) : TestCase(pinput)
{
  this->_listaDePiezas=NULL;
  this->_numeroDePiezasAFabricar=0;
}

/**
 * Realiza la lectura de datos para el ejercicio
 */
bool TestCaseEj2::tomarDatos()
{
  // Libero memoria de la toma de datos anterior
  if (this->_listaDePiezas!=NULL){
    delete this->_listaDePiezas;
    this->_listaDePiezas = NULL;
  }
  // Tomo la cantidad de piezas a fabricar
  this->_input >> this->_numeroDePiezasAFabricar;
  if(this->_numeroDePiezasAFabricar == 0){
    return false;
  }
  // Tomo el listado de piezas (pérdida y tiempo)
  this->_listaDePiezas = new vector<Pieza>;
  this->_listaDePiezas->reserve(this->_numeroDePiezasAFabricar);
  for(uint32_t i=0; i<this->_numeroDePiezasAFabricar; i++){
    Pieza pieza;
    pieza.numeroDeOrden = i+1;
    this->_input >> pieza.perdidaDiariaDeGanancia >> pieza.tiempoDeFabricacion;
    this->_listaDePiezas->push_back(pieza);
  }
  return true;
}
/**
 * Destructor
 */
TestCaseEj2::~TestCaseEj2(void)
{
  // Libero la memoria
  if (this->_listaDePiezas!=NULL){
    delete[] this->_listaDePiezas;
    this->_listaDePiezas = NULL;
  }
}
