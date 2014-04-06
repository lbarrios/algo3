#include "TestCaseEj3.h"

/**
 * Constructor
 */
TestCaseEj3::TestCaseEj3( std::istream &pinput ) : TestCase(pinput)
{
    this->_cantidadDeFilas = 0;
    this->_cantidadDeColumnas = 0;
    this->_cantidadDeColores = 0;
    this->_listaDePiezas = NULL;
    this->_yaSeEjecuto = false;
}

/**
 * Realiza la lectura de datos para el ejercicio
 */
/**
 * descripcion
 * @return aaaa
 */
bool TestCaseEj3::tomarDatos()
{
  // Libero memoria de la toma de datos anterior
  if (this->_listaDePiezas!=NULL){
    delete this->_listaDePiezas;
    this->_listaDePiezas = NULL;
  }
  if( !this->_yaSeEjecuto ){
    return false;
  }
  // Tomo las cantidades de filas, columnas y colores respectivamente
  this->_input 
    >> this->_cantidadDeFilas
    >> this->_cantidadDeColumnas
    >> this->_cantidadDeColores;
  // Tomo las piezas
  uint32_t cantidadDePiezas = this->_cantidadDeFilas*this->_cantidadDeColumnas;
  this->_listaDePiezas = new vector<Pieza>;
  this->_listaDePiezas->reserve(cantidadDePiezas+1);
  // Agrego una pieza vacia en la posicion 0
  Pieza piezaVacia;
  this->_listaDePiezas->push_back(piezaVacia);
  // Agrego el resto de las piezas
  for(uint32_t i=0; i<cantidadDePiezas; i++){
    Pieza pieza;
    this->_input 
      >> pieza.colorArriba
      >> pieza.colorIzquierda
      >> pieza.colorDerecha
      >> pieza.colorAbajo;
    this->_listaDePiezas->push_back(pieza);
  }
  this->_yaSeEjecuto = true;
  return true;
}

/**
 * Destructor
 */
TestCaseEj3::~TestCaseEj3(void){
  // Libero la memoria dinámica
  if (this->_listaDePiezas!=NULL){
    delete this->_listaDePiezas;
    this->_listaDePiezas = NULL;
  }
}

// Getters
uint32_t TestCaseEj3::dameCantidadDeFilas(void){
  return this->_cantidadDeFilas;
}
uint32_t TestCaseEj3::dameCantidadDeColumnas(void){
  return this->_cantidadDeColumnas;
}
uint32_t TestCaseEj3::dameCantidadDeColores(void){
  return this->_cantidadDeColores;
}
vector<TestCaseEj3::Pieza>& TestCaseEj3::dameListaDePiezas(void){
  return (*this->_listaDePiezas);
}
