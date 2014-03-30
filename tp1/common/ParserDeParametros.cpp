#include "ParserDeParametros.h"

#define LINEA_PUNTEADA "--------------------------------------------------------------------------------"
#define TITULO_ERROR LINEA_PUNTEADA << endl << "----------------------------------   ERROR   -----------------------------------" << endl << LINEA_PUNTEADA << endl
#define TITULO_AYUDA LINEA_PUNTEADA << endl << "----------------------------------   AYUDA   -----------------------------------" << endl << LINEA_PUNTEADA << endl

ParserDeParametros::ParserDeParametros(int argc, char** argv){
  if ( argc < 1 ) exit(EXIT_FAILURE);
  _nombrePrograma = argv[0];
  _input=NULL, _output=NULL, _debug=NULL, _time=NULL;
  int tipoDeSolucion=-1;
  static struct option l_opts[] = {
    {"input",            required_argument,    NULL,   'i' },
    {"output",           required_argument,    NULL,   'o' },
    {"debug",            required_argument,    NULL,   'd' },
    {"time",             required_argument,    NULL,   't' },
    {"help",             no_argument,          NULL,   'h' },
    {NULL,               0,                    NULL,    0  }
  };
  //-max_itr <numero> -max_tabu_size <numero> -si <GREEDY|RANDOM>
  int opt=0, long_opt;
  opterr=0; //< Deshabilito el manejo de errores por defecto.
  while ( (opt=getopt_long(argc, argv,"i:o:d:t:h", l_opts, &long_opt )) !=-1 ) {
    switch (opt) {
      case 'i' : //< --input
        if( strcmp(optarg,"stdin") ){
          _finput.open( optarg, fstream::in );
          if( !_finput ) _imprimirErrorInput( optarg );
          else _input = (istream*) &_finput;
        } else _input = (istream*) &cin;
        break;
      case 'o' : //< --output
        if( strcmp(optarg,"stdout") ) {
          _foutput.open( optarg, fstream::out );
          if( !_foutput ) _imprimirErrorOutput( optarg );
          else _output = (ostream*) &_foutput;
        } else _output = (ostream*) &cout;
        break;
      case 'd' : //< --debug
        #ifndef DEBUG
          _imprimirErrorDebug( optarg );
        #else
          if( strcmp(optarg,"stderr") ) {
            _fdebug.open( optarg, fstream::out );
            if( !_fdebug ) _imprimirErrorDebug( optarg );
            else _debug = (ostream*) &_fdebug;
          } else _debug = (ostream*) &cerr;
        #endif
        break;
      case 't' : //< --time
        #ifndef TIME
          _imprimirErrorTime( optarg );
        #else
          if( strcmp(optarg,"stderr") && strcmp(optarg, "stdout") )
          {
            _ftime.open( optarg, fstream::out );
            if( !_ftime )
            {
            	_imprimirErrorTime( optarg );
            }
            else
            {
            	_time = (ostream*) &_ftime;
            }
          }
          else
          {
          	if( strcmp(optarg,"stderr") )
          	{
          	  _time = (ostream*) &cout;
          	}
          	else
          	{
          	  _time = (ostream*) &cerr;
          	}
          }
        #endif
        break;
      case 'h' : //< --help
        _imprimirAyuda();
        exit(EXIT_SUCCESS);
        break;
      case '?' : //< ¡¡Opción no reconocida!!
        if(argc <= optind)
          cerr << "No se reconoce la opción " << argv[argc-1] << "." << endl;
        else
          cerr << "No se reconoce la opción " << argv[optind] << "." << endl;
      default :
        _imprimirAyudaError();
    }
  }

  // Me fijo si el input es válido.
  if(!_input)
    cerr << "Error: No se ha indicado el input (-i [stdin|RUTA_ARCHIVO])" << endl;
  // Me fijo si el output es válido.
  if(!_output)
    cerr << "Error: No se ha indicado el output (-o [stdout|RUTA_ARCHIVO])" << endl;
  #ifdef DEBUG
  if(!_debug)
    cerr << "Error: No se ha indicado el debug (-d [stderr|RUTA_ARCHIVO])" << endl;
  #endif
  #ifdef TIME
  if(!_time)
  	cerr << "Error: No se ha indicado el output de time (-t [stdout|stderr|RUTA_ARCHIVO)" << endl;
  #endif
  /**
   * Analizo los parámetros, si hay errores detengo la ejecución
   */
#ifdef DEBUG
  if(!_input || !_output || !_debug)
#else
  #ifdef TIME
    if(!_input || !_output || !_time)
  #else
    if(!_input || !_output)
  #endif
#endif
    _imprimirAyudaError();
}
ParserDeParametros::~ParserDeParametros( void ){
  /* Destructor */
}
void ParserDeParametros::_imprimirAyudaError( void ){
#ifdef DEBUG
  cerr << endl << " --- VERSION DE DEBUG --- " << endl << endl <<
    "Uso: Ejecute " << endl <<
    "\t" << _nombrePrograma << " -i INPUT -o OUPUT -d DEBUG" << endl;
#else
	#ifdef TIME
  	cerr << endl << " --- VERSION DE MEDICION DE TIEMPO --- " << endl << endl <<
	    "Uso: Ejecute " << endl <<
	    "\t" << _nombrePrograma << " -i INPUT -o OUPUT -t TIME" << endl;
	#else
 		cerr << "Uso: Ejecute " << endl <<
	    "\t" << _nombrePrograma << " -i INPUT -o OUPUT" << endl;
  #endif
#endif
  cerr << "Ejecute el parámetro [-h | --help] si desea obtener ayuda" << endl;
  exit(EXIT_FAILURE);
}
void ParserDeParametros::_imprimirAyuda( void ){
  cout << TITULO_AYUDA << endl;

  cout << "Para correr este programa debe respetar la siguiente sintaxis:" << endl;
  #ifdef DEBUG
  cout << _nombrePrograma << " --input=INPUT --output=OUTPUT --debug=DEBUG" << endl;
  #else
  	#ifdef TIME
  	cout << _nombrePrograma << " --input=INPUT --output=OUTPUT --time=TIME" << endl;
  	#else
  	cout << _nombrePrograma << " --input=INPUT --output=OUTPUT" << endl;
  	#endif
  #endif
  cout << "\t" << "•) INPUT = [stdin|RUTA_ARCHIVO]" << endl
           << "\t\t" << "utilizar entrada estándar ó un archivo" << endl
       << "\t" << "•) OUTPUT = [stdout|RUTA_ARCHIVO]" << endl
           << "\t\t" << "utilizar salida estándar ó un archivo" << endl
    #ifdef DEBUG
       << "\t" << "•) DEBUG = [stderr|RUTA_ARCHIVO]" << endl
           << "\t\t" << "utilizar salida error ó un archivo" << endl
    #endif
    #ifdef TIME
       << "\t" << "•) TIME = [stdout|stderr|RUTA_ARCHIVO]" << endl
           << "\t\t" << "utilizar salida estándar, error ó un archivo" << endl
    #endif
       << endl;
  cout
  << "Parámetros extra:" << endl
  << "\t" << "Ninguno (por ahora)" << endl;

  cout << endl << "Se pueden reemplazar todos los parámetros no opcionales de la forma" << endl
       << "\"--parametro=VALOR\" por su versión corta \"-p VALOR\", ejemplo:" << endl
       #ifdef DEBUG
       << "\t" << _nombrePrograma << " -i stdin -o stdout -d stderr" << endl;
       #else
       	#ifdef TIME
       	<< "\t" << _nombrePrograma << " -i stdin -o stdout -t stderr" << endl;
       	#else
       	<< "\t" << _nombrePrograma << " -i stdin -o stdout" << endl;
       	#endif
       #endif
  cout << endl << LINEA_PUNTEADA << endl;
}
void ParserDeParametros::_imprimirErrorInput( string nombreArchivo ){
  cerr << TITULO_ERROR <<
"No se puede abrir el archivo de input indicado ("<< nombreArchivo <<")."
  << endl;
  exit(EXIT_FAILURE);
}
void ParserDeParametros::_imprimirErrorOutput( string nombreArchivo ){
  cerr << TITULO_ERROR <<
"No se puede abrir el archivo de output indicado ("<< nombreArchivo <<")."
  << endl;
  exit(EXIT_FAILURE);
}
void ParserDeParametros::_imprimirErrorDebug( string nombreArchivo ){
#ifndef DEBUG
  cerr << TITULO_ERROR <<
  "Para realizar debug debe correr el ejecutable para debug." << endl <<
  "Probablemente ud. desee correr " << _nombrePrograma << ".debug" <<
  " o " << _nombrePrograma << ".debug2"
  << endl;
#else
  cerr << TITULO_ERROR <<
  "No se puede abrir el archivo de debug indicado ("<< nombreArchivo <<")."
  << endl;
#endif
  exit(EXIT_FAILURE);
}
void ParserDeParametros::_imprimirErrorTime( string nombreArchivo ){
#ifndef DEBUG
  cerr << TITULO_ERROR <<
  "Para medir tiempo debe correr el ejecutable correcto." << endl <<
  "Probablemente ud. desee correr " << _nombrePrograma << ".time" <<
  endl;
#else
  cerr << TITULO_ERROR <<
  "No se puede abrir el archivo de time indicado ("<< nombreArchivo <<")."
  << endl;
#endif
  exit(EXIT_FAILURE);
}
void ParserDeParametros::_imprimirErrorParametro( string parametro, string value ){
  cerr << TITULO_ERROR <<
"Se reconoció el parámetro: " << parametro <<"."
  << endl <<
"Sin embargo, no se reconoce el valor indicado (" << value << ")" << endl;
  exit(EXIT_FAILURE);
}
istream &ParserDeParametros::dameInput ( void )
{
  return *_input;
}
ostream &ParserDeParametros::dameOutput ( void )
{
  return *_output;
}
ostream &ParserDeParametros::dameDebug ( void )
{
  return *_debug;
}
ostream &ParserDeParametros::dameTime ( void )
{
  return *_time;
}
