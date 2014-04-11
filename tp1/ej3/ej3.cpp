#include "ej3.h"

struct Pieza{
  int sup;
  int izq;
  int der;
  int inf;
};

void backtrack(int, int);
int n, m, c, max_global, max_local, huecos;
list<int> orden_global, orden_local;
vector<Pieza> listaDePiezas;
vector<Pieza> piezasQueQuedan;
//por ahora asi es mas facil
vector<int> piezasPorColores[1024][1024];
int t[1024][1024];
bool yaLlegueAlMaximoAbsoluto;


int main(int argc, char** argv) {
  //Parseo el input.
  ParserDeParametros parser(argc, argv);
  //Consigo el input.
  istream& input = parser.dameInput();

  //Genero el timer
  Timer timer( parser.dameTime());
  timer.setInitialTime("todoElEjercicio");

  Pieza blanco = {0, 0, 0, 0};
  //de esta forma la pieza blanca queda con el id 0
  listaDePiezas.push_back(blanco);


  //Pongos los datos en variables
  input >> n >> m >> c;
  for (int i=1; i <= n*m; i++) {
    int sup, izq, der, inf;
    //Entran una ficha;
    input >> sup >> izq >> der >> inf;
    //hacerlo mas eficiente
    Pieza pongo = {sup, izq, der, inf};
    listaDePiezas.push_back(pongo);
    piezasQueQuedan.push_back(i);
    //cada pieza queda con su id correspondiente
    piezasPorColores[sup][izq].push_back(i);
  }
  yaLlegueAlMaximoAbsoluto = false;
  max_global = (n*m)/2;
  //inicializo orden_global (mas eficiente es hacerlo en el ciclo de arriba, pero por claridad)
  for (int i=1; i <= n*m; i++) {
    if (i % 2 == 1)
        max_global.push_back(i);
    else
        max_global.push_back(0);
  } 
  max_local = 0;
  huecos = 0;
  backtrack(0, 0);
  timer.setFinalTime("todoElEjercicio");
  // A partir de acá el ejercicio ya está resuelto.
  

  #ifndef TIME
  ostream& output = parser.dameOutput();
  list<int>::iterator it = orden_global.begin();
  for(int i=0; i<n; i++) {
    for (int j=0; j<m; j++) {
       output << *it << " ";
       it++;
    }
    output << endl;
  }
  
  #else
  timer.saveAllTimes();
  #endif
  return 0;
}

  void probaConTodasLasFichas(int x, int y, vector<int> &listaPosibles, bool estoyEnPiezasPorColores) {
    if (!yaLlegueAlMaximoAbsoluto) {
    for(int i=listaPosibles.size() - 1; i >= 0; i--) {
      int fichaQueVoyAPoner = listaPosibles[i];
      
      vector<int> laOtraLista;
      if (estoyEnPiezasPorColores) {
        laOtraLista = &piezasQueQuedan;
      } else {
        int color_sup = listaDePiezas[fichaQueVoyAPoner].sup;
        int color_izq = listaDePiezas[fichaQueVoyAPoner].izq;
        laOtraLista = &piezasPorColores[color_sup][color_izq];
      }
      // O(n)
      listaPosibles.erase(@listaPosibles[i]); 
      
      //listaPosibles[i] = listaPosibles.back();
      //listaPosibles.pop_back();
      // atencion: O(n)
      vector<int>::iterator indiceParaGuardar = laOtraLista.begin();
      // nunca deberia pasarse de rango, digo por si da SEGFAULT
      while (*it != fichaQueVoyAPoner)
          indiceParaGuardar++;
      laOtraLista.erase(indiceParaGuardar);
      max_local++;
      t[x][y] = fichaQueVoyAPoner;
      orden_local.push_back(fichaQueVoyAPoner);
      bool yaLlegueAlMaximoAbsoluto = false;
      if (x == n-1 && y == m-1) {
        if (max_local > max_global) {
          max_global = max_local;
          orden_global = orden_local;
          if (max_global == n * m) yaLlegueAlMaximoAbsoluto = true;
        }
      } else {
        //veo adonde voy a ir despues
        int sig_x, sig_y;
        if (y < m-1) {
          sig_x = x;
          sig_y = y + 1;
        } else { 
          sig_x = x + 1;
          sig_y = 0;
        }

        backtrack(sig_x, sig_y);
      }
      
      //deshago todo lo que hice
      orden_local.pop_back();
      max_local--;
      listaPosibles.insert(&listaPosibles[i], fichaQueVoyAPoner);
      laOtraLista.insert(indiceParaGuardar, fichaQueVoyAPoner);
    }
  }
 }

  void backtrack(int x, int y) {
    if (!yaLlegueAlMaximoAbsoluto) {
    //primero veo que fichas puedo poner aca
    int color_sup = x>0 ? listaDePiezas[t[x-1][y]].inf : 0;
    int color_izq = y>0 ? listaDePiezas[t[x][y-1]].der : 0;
    if (color_sup > 0 && color_izq > 0) {
      probaConTodasLasFichas(x, y, piezasPorColores[color_sup][color_izq]);  
    } else if (color_sup > 0) {
      if (max_local + huecos < c) {
        probaConTodasLasFichas(x, y, piezasQueQuedan); 
      } else {
          for(int r=1; r<=c; r++) {
            if (yaLlegueAlMaximoAbsoluto) break;
            probaConTodasLasFichas(x, y, piezasPorColores[color_sup][r]);
          }
      }
    } else if (color_izq > 0) {
      if (max_local + huecos < c) {
        probaConTodasLasFichas(x, y, piezasQueQuedan); 
      } else {
      for(int r=1; r<=c; r++) {
        if (yaLlegueAlMaximoAbsoluto) break;
        probaConTodasLasFichas(x, y, piezasPorColores[r][color_izq]);
      }}
    } else {
      if (max_local + huecos < c*c) {
        probaConTodasLasFichas(x, y, piezasQueQuedan); 
      } else {
      for (int r1=1; r1<=c; r1++) {
        if (yaLlegueAlMaximoAbsoluto) break;
        for(int r2=1; r2<=c; r2++) {
          if (yaLlegueAlMaximoAbsoluto) break;
          probaConTodasLasFichas(x, y, piezasPorColores[r1][r2]);
        }
      }}
    }
    if (!yaLlegueAlMaximoAbsoluto) {
    //ahora hay que probar metiendo la casilla vacia
    int piezaBlanca = 0;
    t[x][y] = piezaBlanca;
    huecos++;
    //esto es una poda
    bool continua = true;
    if (max_local + m*n - huecos <= max_global) bool continua = false;
    if (continua) {
    orden_local.push_back(piezaBlanca);
    if (x == n-1 && y == m-1) {
      if (max_local > max_global) {
        max_global = max_local;
        orden_global = orden_local;
      }
    } else {
      //veo adonde voy a ir despues
      int sig_x, sig_y;
      if (y < m-1) {
        sig_x = x;
        sig_y = y + 1;
      } else { 
        sig_x = x + 1;
        sig_y = 0;
      }

      backtrack(sig_x, sig_y);
     }
     //desarmo lo que hice
     huecos--;
     orden_local.pop_back();
    }
    }
    }
}  
