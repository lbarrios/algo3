#include "TestCaseEj1.h"
#include <iostream>

/**
 * Constructor
 */
TestCaseEj1::TestCaseEj1( std::istream &pinput ) : TestCase(pinput)
{
    if (!this->_input){
        cout << "Error: No se puede leer el input.";
        exit(-1);
    }
    this->_cantidadCamiones = -1;
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
    this->_input >> this->_cantidadCamiones;

    // Tomo las fechas en que pasan los camiones
    this->_fechasCamiones = new int[this->_cantidadCamiones];
    for(int i = 0; i< this->_cantidadCamiones; i++){
        this->_input >> this->_fechasCamiones[i];
    }

    return true;
}

int TestCaseEj1::dameIntervaloInspector()
{
    return this->_intervaloInspector;
}
int *TestCaseEj1::dameFechasCamiones()
{
    return this->_fechasCamiones;
}
int TestCaseEj1::dameCantidadCamiones()
{
    return this->_cantidadCamiones;
}

/**
 * Destructor
 */
TestCaseEj1::~TestCaseEj1(void){
    if (this->_fechasCamiones!=NULL){
        delete[] this->_fechasCamiones;
        this->_fechasCamiones = NULL;
    }
}
