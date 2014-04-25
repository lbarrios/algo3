#include <iostream>
#include <list>
using namespace std;

struct ComponenteConexa {
    bool esComponente;
    float distancias[1024]; //dejarlo fijo, o vector, u otra cosa
    float menorDistancia;
    int compConexMasCerca;
    list<int> nodos;
};


void tomarInput();
void inicializarComponentes();
void kruskal_parcial();
void imprimir();

int n, k;
pair<int, int> posiciones[1024];
ComponenteConexa componentes[1024];

int main() {
    tomarInput();
    inicializarComponentes();
    kruskal_parcial();
    imprimir();
    return 0;
}

void tomarInput() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        pair<int, int> agrego;
        cin >> agrego.first >> agrego.second;
        posiciones[i] = agrego;
    }
}

void inicializarComponentes() {
    
}

void kruskal_parcial() {

}

void imprimir() {

}
