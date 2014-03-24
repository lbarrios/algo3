/*
	Si se modifica este .h, hacer make clean en cada directorio de ejercicio
*/
struct ParserDeParametros{
private:
	istream *_input;
	ostream *_output;
	fstream finput, foutput;
	bool _sonValidos;
	char* _nombrePrograma;
public:
	istream &input(){ return *_input; };
	ostream &output(){ return *_output; };
	bool parametrosSonValidos( void ) { return _sonValidos; };
	ParserDeParametros(int argc, char** argv){
		_input=NULL;
		_output=NULL;
		if ( argc >= 1 ){
			_nombrePrograma = argv[0];
			_sonValidos = true;
			if ( argc > 1 ){
				for(int i=1; i<argc; i++){
					string str(argv[i]);
					if ( str.find("--input=")==0 ){
						if ( !_input ){
							finput.open( &argv[i][8], fstream::in );
							if( !finput ){
								cerr << "ERROR: No se puede abrir el archivo de input solicitado ( " << &argv[i][8] << " )." << endl;
								_sonValidos = false;
							}else _input = ( istream* ) &finput;
						}else{
							cerr << "ERROR: ¿Cuántos inputs desea ingresar? ( " << &argv[i][8] << " )." << endl;
							_sonValidos = false;
						}
					}else
					if(str.find("--output=")==0){
						if( !_output ){
							foutput.open( &argv[i][9], fstream::out );
							if( !foutput ){
								cerr << "ERROR: No se puede abrir el archivo de output solicitado ( " << &argv[i][9] << " )." << endl;
								_sonValidos = false;
							} else _output = ( ostream* ) &foutput;
						}else{
							cerr << "ERROR: No voy a hacer output a muchos archivos a la vez ( " << &argv[i][8] << " )." << endl;
							_sonValidos = false;
						}
					}else{
						cerr << "ERROR: No se reconoce/n el/los parámetros ingresados ( " << argv[i] << " )." << endl;
						_sonValidos = false;
					}
				}
			}
		}else{
			cerr << "????? WTF :(" << endl;
			_sonValidos = false;
		}
		if(_sonValidos){
			if(!_input) _input = &cin;
			if(!_output) _output = &cout;
		}
	};
	void imprimirAyuda( void ){
		cout << "Para correr este programa debe respetar la siguiente sintaxis:" << endl;
		cout << _nombrePrograma << endl;
		cout << 	"\t" << " para correr el programa usando stdin/stdout" << endl;
		if(!_input){
			cout << endl;
			cout << _nombrePrograma << " --input=in.txt" << endl;
			cout << 	"\t" << " para correr el programa usando in.txt como input" << endl;
		}
		if(!_output){
			cout << endl;
			cout << _nombrePrograma << " --output=out.txt" << endl;
			cout << 	"\t" << " para correr el programa usando out.txt como output" << endl;
		}
	}
};
