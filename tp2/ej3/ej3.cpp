#include <iostream>
using namespace std;

struct Posicion {
    int fila;
    int columna;
};

struct Nodo {
    Posicion posicion;
    int pot_extra;
    Posicion padre;
    int distancia;
};

struct Resultado {
    int distancia;
    Posicion padre_pos;
    int padre_unidadesextra;
    int unidades_extra_usadas_recien;
};

int n, k;
Posicion origen;
Posicion destino;
int potencias[1024][1024];
Resultado distancias[1024][1024][1024];
int potenciaDeLlegada;

int main() {
    inicializar();
    BFS();
    imprimir();
    return 0;
}

void inicializar() {
    cin >> n >> origen.fila >> origen.columna >> destino.fila >> destino.columna >> k;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> potencias[i][j];
            for(int l=0; l<k; k++){
                //seria INF
                distancias[i][j][l].distancia = n * n;
            }  
        }
    }
}

void imprimir() {
    Resultado fin = distancias[destino.columna][destino.fila][potenciaDeLlegada];
    cout << fin.distancia << endl; 
    //fijate +- indice
    list<Resultado> camino;
    Resultado recorro = fin;
    for (int i=0; i<fin.distancia; i++) {
        camino.push_back(recorro);
        Posicion delPadre = recorro.padre;
        
    }
}
