#include <iostream>
#include <queue>
#include <list>
#include "../common/Timer.h"
using namespace std;

struct Posicion {
    int fila;
    int columna;
    bool operator==(const Posicion &p1) {
        return fila == p1.fila && columna == p1.columna;
    }
};

struct Nodo {
    Posicion posicion;
    int pot_extra;
    Posicion pos_padre;
    int padre_pot_extra_uso;
    int distancia;
};

enum Direccion {arriba, abajo, izquierda, derecha};

bool inicializar();
void BFS();
void hace_la_cruz(Nodo, queue<Nodo>&);
void pushea_hijo (Nodo &hijo, int &fila_hijo, int &columna_hijo, int &distancia_hijo, int pot_extra_hijo, int padre_pot_extra_uso, Posicion &pos_actual, queue<Nodo> &cola);
void imprimir();

int n, k;
Posicion origen;
Posicion destino;
int potencias[256][256];
Nodo distancias[256][256][256];
int potenciaDeLlegada;


Timer timer(cout);


int main() {
    while ( inicializar() ){
      BFS();
      timer.setFinalTime("cicloEntero");
      imprimir();
    }
    return 0;
}

bool inicializar() {
		timer.setInitialTime("cicloEntero");
    cin >> n;
    if (!n) return false;
    cin >> origen.fila >> origen.columna >> destino.fila >> destino.columna >> k;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cin >> potencias[i][j];
            for(int l=0; l<=k; l++){
                //seria INF
                distancias[i][j][l].distancia = n * n;
            }
        }
    }
}

void BFS() {
    Nodo inicial;
    inicial.posicion = origen;
    inicial.pot_extra = k;
    inicial.distancia = 0;
    distancias[origen.fila][origen.columna][k] = inicial;
    queue<Nodo> cola;
    cola.push(inicial);
    while (! cola.empty()) {
        Nodo expando = cola.front();
        cola.pop();
        Posicion pos_actual = expando.posicion;
        if (pos_actual == destino) {
            potenciaDeLlegada = expando.pot_extra;
            break;
        }
        hace_la_cruz(expando, cola);
    }
}

void hace_la_cruz (Nodo expando, queue<Nodo> &cola) {
    Posicion pos_actual = expando.posicion;
    int pot = potencias[pos_actual.fila][pos_actual.columna];
    int pot_extra = expando.pot_extra;
    int fila_hijo, columna_hijo, padre_pot_extra_uso, pot_extra_hijo, distancia_hijo;
    Nodo hijo;
    //cruz para arriba
    for (int i=1; pos_actual.fila - i >= 1 && i <= pot + pot_extra; i++) {
        fila_hijo =  pos_actual.fila - i;
        columna_hijo = pos_actual.columna;
        padre_pot_extra_uso = max(0, i - pot);
        pot_extra_hijo = pot_extra - padre_pot_extra_uso;
        distancia_hijo = expando.distancia + 1;
        if (distancias[fila_hijo][columna_hijo][pot_extra_hijo].distancia == n * n) {
            pushea_hijo(hijo, fila_hijo, columna_hijo, distancia_hijo, pot_extra_hijo, padre_pot_extra_uso, pos_actual, cola);
        }
    }
    //cruz para abajo
    for (int i=1; pos_actual.fila + i <= n && i <= pot + pot_extra; i++) {
        fila_hijo =  pos_actual.fila + i ;
        columna_hijo = pos_actual.columna;
        padre_pot_extra_uso = max(0, i - pot);
        pot_extra_hijo = pot_extra - padre_pot_extra_uso;
        distancia_hijo = expando.distancia + 1;
        if (distancias[fila_hijo][columna_hijo][pot_extra_hijo].distancia == n * n) {
            pushea_hijo(hijo, fila_hijo, columna_hijo, distancia_hijo, pot_extra_hijo, padre_pot_extra_uso, pos_actual, cola);
        }
    }
    //cruz para izquierda
    for (int i=1; pos_actual.columna - i >= 1 && i <= pot + pot_extra; i++) {
        fila_hijo =  pos_actual.fila;
        columna_hijo = pos_actual.columna - i;
        padre_pot_extra_uso = max(0, i - pot);
        pot_extra_hijo = pot_extra - padre_pot_extra_uso;
        distancia_hijo = expando.distancia + 1;
        if (distancias[fila_hijo][columna_hijo][pot_extra_hijo].distancia == n * n) {
            pushea_hijo(hijo, fila_hijo, columna_hijo, distancia_hijo, pot_extra_hijo, padre_pot_extra_uso, pos_actual, cola);
        }
    }
    //cruz para derecha
    for (int i=1; pos_actual.columna + i <= n && i <= pot + pot_extra; i++) {
        fila_hijo =  pos_actual.fila;
        columna_hijo = pos_actual.columna + i;
        padre_pot_extra_uso = max(0, i - pot);
        pot_extra_hijo = pot_extra - padre_pot_extra_uso;
        distancia_hijo = expando.distancia + 1;
        if (distancias[fila_hijo][columna_hijo][pot_extra_hijo].distancia == n * n) {
            pushea_hijo(hijo, fila_hijo, columna_hijo, distancia_hijo, pot_extra_hijo, padre_pot_extra_uso, pos_actual, cola);
        }
    }
}

void pushea_hijo (Nodo &hijo, int &fila_hijo, int &columna_hijo, int &distancia_hijo, int pot_extra_hijo, int padre_pot_extra_uso, Posicion &pos_actual, queue<Nodo> &cola) {
    hijo.posicion.fila = fila_hijo;
    hijo.posicion.columna = columna_hijo;
    hijo.distancia = distancia_hijo;
    hijo.pot_extra = pot_extra_hijo;
    hijo.padre_pot_extra_uso = padre_pot_extra_uso;
    hijo.pos_padre = pos_actual;
    distancias[fila_hijo][columna_hijo][pot_extra_hijo] = hijo;
    cola.push(hijo);
}

void imprimir() {
#ifdef GRAF
    Nodo fin = distancias[destino.fila][destino.columna][potenciaDeLlegada];
    cout << fin.distancia << endl;
#endif
#ifdef RESULTS
    Nodo fin = distancias[destino.fila][destino.columna][potenciaDeLlegada];
    cout << fin.distancia << endl;
    list<Nodo> camino;
    Nodo recorro = fin;
    //fijate +- indice
    for (int i=0; i<fin.distancia; i++) {
        camino.push_front(recorro);
        int fila_padre = recorro.pos_padre.fila;
        int col_padre = recorro.pos_padre.columna;
        int pot_padre = recorro.pot_extra + recorro.padre_pot_extra_uso;
        recorro = distancias[fila_padre][col_padre][pot_padre];
    }
    for (list<Nodo>::iterator it=camino.begin(); it != camino.end(); it++) {
        cout << it->posicion.fila << " " << it->posicion.columna << " " << it->padre_pot_extra_uso << endl;
    }
#endif
#ifdef TIME
    timer.saveAllTimes();
#endif
    /* debug. solo tiene sentido cuando k == 0 */
    /*
    cout << "tablero de distancias: " << endl;
    for (int i=1; i <= n; i++) {
        for (int j=1; j <= n; j++) {
            cout << distancias[i][j][0].distancia << " ";
        }
        cout << endl;
    }
    */
}
