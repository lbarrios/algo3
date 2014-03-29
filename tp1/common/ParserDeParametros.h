#ifndef __PARSERDEPARAMETROS_H__
#define __PARSERDEPARAMETROS_H__
#include <getopt.h>
#include "headers.h"
/**
 * Parsea los parámetros con que fue llamado el ejecutable
 */
struct ParserDeParametros{
private:
  istream *_input; ///< Puntero a stream para input
  ostream *_output; ///< Puntero a stream para output
  ostream *_debug; ///< Puntero a stream para debug
  ostream *_time; ///< Puntero a stream para time
  fstream _finput; ///< Descriptor de archivo para input
  fstream _foutput; ///< Descriptor de archivo para output
  fstream _fdebug; ///< Descriptor de archivo para debug
  fstream _ftime; ///< Descriptor de archivo para time
  char* _nombrePrograma; ///< Guarda el nombre del ejecutable
  bool _sonValidos;
  /** 
   * Imprime los parámetros del programa.
   */
  void _imprimirAyuda( void );
  /**
   * Imprime un mensaje de error muy corto.
   */
  void _imprimirAyudaError( void );
  /**
   * Indica que hubo un error al acceder al archivo de input.
   * @param string Nombre del archivo que dio error.
   */
  void _imprimirErrorInput ( string );
  /**
   * Indica que hubo un error al acceder al archivo de output.
   * @param string Nombre del archivo que dio error
   */
  void _imprimirErrorOutput( string );
  /**
   * Indica que hubo un error al reconocer el tipo de algoritmo.
   * @param string Nombre de solución que se quería ejecutar.
   */
  void _imprimirErrorSolucion ( string );
  /**
   * Indica que hubo un error al acceder al archivo debug,
   * o que el ejecutable no es el correcto.
   * @param string Nombre del archivo pasado como parámetro.
   */
  void _imprimirErrorDebug( string );
  /**
   * Indica que hubo un error al acceder al archivo de time,
   * o que el ejecutable no es el correcto.
   * @param string Nombre del archivo pasado como parámetro.
   */
  void _imprimirErrorTime( string );
  /**
   * Indica que hubo un error, se reconoció un parámetro,
   * pero el valor indicado es inválido.
   * @param string Parámetro indicado
   * @param string Valor del parámetro
   */
  void _imprimirErrorParametro( string, string );

public:
  istream &tipoInput( void );
  ostream &tipoOutput( void );
  ostream &tipoDebug( void );
  ostream &tipoTime( void );
  bool parametrosSonValidos( void );
  ParserDeParametros(int argc, char** argv);
  ~ParserDeParametros( void );
  
};
#endif
