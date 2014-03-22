#include <list>
#include <utility>
#include <vector>
#include <iostream>
using namespace std;

//juez online http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=11&page=show_problem&problem=930

// Varios typedefs
typedef vector<int> Vec;
typedef vector<Vec> Tablero;
typedef pair<int, int> Coord;
typedef list<Coord> LCoord;

// Prototipado de funciones
bool resolver(Tablero& p, int nsubs);
void mostrar(const Tablero& m);
int check(const Tablero& c, int n);
bool algunRepetido(const Vec &v);
bool backtrack(Tablero&, int, LCoord&);

unsigned long long int llamadas;
/**
 * La función main toma el tablero por std input:
 * recibe primero el tamaño de bloque (si se le pasa n se
 * asume un bloque de n*n, con lo cual la matriz final será
 * de (n*n)*(n*n)). Luego recibe un numero por cada casillero
 * del tablero. Un cero indica casilla vacia.
 * Finalmente, llama al método resolver(...) y al finalizar éste
 * se muestra el resultado (de haberlo).
 */
int main()
{
	int n;
	llamadas = 0;

	while(true) {
		cin >> n;
		if(cin.eof()){
			break;
		}
		int n2 = n*n;
		Tablero p(n2, Vec(n2, 0));
		for(int i = 0; i < n2; ++i)
			for(int j = 0; j < n2; ++j)
				cin >> p[i][j];

		bool sol = resolver(p,n);
		if(!sol){
			cout << "El tablero no tene solucion...";
		} else {
			mostrar(p);
		}
		cout << endl;
	}

	cout << "DBG: Cantidad de llamadas: " << llamadas << endl;

	return 0;
}

/**
 * Recibe el tablero inicial y el tamaño de bloque y fabrica
 * una lista con las casillas vacias del tablero.
 * Luego llama a la función backtrack(...) e informa e resultado.
 */
bool resolver(Tablero& p, int n)
{
	int a,b;
	LCoord listaVacios;

	for(a=0;a<(n*n);a++) for(b=0;b<(n*n);b++)
		if(p[a][b] == 0)
			// Si el casillero esta vacio
			listaVacios.push_back( Coord(a,b) );

	return backtrack(p,n,listaVacios);
}

bool backtrack(Tablero& p, int n, LCoord& listaCoordenadas){
	//DEBUG
	//mostrar(p);
	llamadas++;
	if((llamadas%10000)==0){
		cout << "DBG: Llamadas: " << llamadas << endl;
	}

	//Chequeo si el tablero estÃ¡ resuelto
	int resultado = check(p,n);
	if(resultado==1){
		// Si estÃ¡ resuelto retorno true
		//cout << "DBG: El tablero esta resuelto" << endl;
		return true;
	}
	if(resultado==2){
		// Si el tablero estÃ¡ mal retorno false
		//cout << "DBG: El tablero esta mal" << endl;
		return false;
	}
	else{
		//cout << "DBG: El tablero esta bien" << endl;
	}

	// Si el tablero tiene casilleros en blanco hago recursion
	Coord coordenada = listaCoordenadas.front();
	listaCoordenadas.pop_front();
	for(int i=1;i<=(n*n);i++){
		p[coordenada.first][coordenada.second] = i;
		if ( backtrack(p,n,listaCoordenadas) )
			return true;
	}
	p[coordenada.first][coordenada.second] = 0;
	listaCoordenadas.push_front(coordenada);
	return false;
}

/**
 * Recibe un tablero y lo muestra por pantalla
 */
void mostrar(const Tablero& m)
{
	cout << endl;
	int n = m.size();
	for(int i = 0; i < n; ++i)
	{
		cout << m[i][0];
		for (int j = 1; j < n; j++)
		{
			cout << " " << m[i][j];
		}
		cout << endl;
	}
}


/**
 * La siguiente función devuelve:
 *    2 --> Si el tablero tiene repetidos en alguna fila, columna o cuadrante
 *    1 --> Si no tiene repetidos y es una solucion de Sudoku
 *    0 --> Si no tiene repetidos pero le faltan casillas por llenar
 */
int check(const Tablero& p, int n)
{
	int n2 = p.size();
	bool ceros = false;
	for (int i = 0; i < n2; i++)
	{
		// verifico la fila i
		Vec flag_fila (n2, 0);
		for (int j = 0; j < n2; j++)
		{
			if (p[i][j] == 0)
				ceros = true;
			else
				flag_fila[p[i][j]-1]++;
		}

		if (algunRepetido(flag_fila))
			return 2;

		// verifico la columna i
		Vec flag_col (n2, 0);
		for (int j = 0; j < n2; j++)
		{
			if (p[j][i] == 0)
				ceros = true;
			else
				flag_col[p[j][i]-1]++;
		}

		if (algunRepetido(flag_col))
			return 2;

		// verifico el cuadrante i
		Vec flag_cuad(n2, 0);
		int f = (i/n)*n; // fila donde empieza el cuadrante
		int c = (i % n)*n; // col donde empieza el cuadrante
		for (int j = 0; j < n; j++)
		for (int k = 0; k < n; k++)
		{
			if (p[f+j][c+k] == 0)
				ceros = true;
			else
				flag_cuad[p[f+j][c+k]-1]++;
		}

		if (algunRepetido(flag_cuad))
			return 2;
	}

	return ceros? 0 : 1;
}

/**
 * Método auxiliar del método check
 */
bool algunRepetido(const Vec& v)
{
	int k = v.size();
	for (int i = 0; i < k; i++)
		if (v[i] > 1)
			return true;

	return false;
}

