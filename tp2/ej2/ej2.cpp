#include <iostream>
#include <list>
#include <math.h>
using namespace std;

typedef pair<int, int> arista ;
// habia puesto 1<<31 y me daba todo mal porque habia overflow jaja
#define INF 1<<30;

struct ComponenteConexa {
    bool esComponente;
    float distancias[1024]; //dejarlo fijo, o vector, u otra cosa
    arista aristaMasCortaTotalHacia[1024];
    float menorDistancia;
    arista aristaMasCortaTotalGeneral;
    int ccMasCercana;
    list<arista> aristas;
};

void tomarInput();
void inicializarComponentes();
void kruskal_parcial();
void imprimir();
float distancia(int, int);

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
    for (int i = 1; i <= n; i++) {
        ComponenteConexa c;
        c.esComponente = true;
        list<arista> inicial; 
        c.aristas = inicial;
        c.menorDistancia = INF;
        for (int j = 1; j <= n; j++) {
            if (j == i) continue;
            c.distancias[j] = distancia(i, j);
            c.aristaMasCortaTotalHacia[j] = make_pair(i, j);
            if (c.distancias[j] < c.menorDistancia) {
                c.menorDistancia = c.distancias[j];
                c.aristaMasCortaTotalGeneral = c.aristaMasCortaTotalHacia[j];
                c.ccMasCercana = j;
            }
        }
        componentes[i] = c;
    }    
}

float distancia(int i, int j) {
    float x_i = posiciones[i].first;
    float y_i = posiciones[i].second;
    float x_j = posiciones[j].first;
    float y_j = posiciones[j].second;
    return sqrt((x_i - x_j) * (x_i - x_j) + (y_i - y_j) * (y_i - y_j));
}

void kruskal_parcial() {
    for (int i = 1; i <= n - k; i++) {
        float disMin = INF;
        int ind_cc1, ind_cc2;
        // enncuentro las cc mas cercanas
        for (int j = 1; j <= n; j++) {
            ComponenteConexa &actual = componentes[j];
            if (actual.esComponente == false) continue;
            if (actual.menorDistancia < disMin) {
                disMin = actual.menorDistancia;
                ind_cc1 = j;
                ind_cc2 = actual.ccMasCercana;
            }
        }
        // uno cc1 y cc2
        ComponenteConexa &cc1 = componentes[ind_cc1]; 
        ComponenteConexa &cc2 = componentes[ind_cc2]; 
        // me olvido de cc2
        cc2.esComponente = false;
        // concateno las listas de aristas
        cc1.aristas.push_back(cc1.aristaMasCortaTotalGeneral);
        cc1.aristas.insert(cc1.aristas.end(), cc2.aristas.begin(), cc2.aristas.end());
        cc1.menorDistancia = INF;
        for (int j = 1; j <= n; j++) {
            ComponenteConexa &actual = componentes[j];
            if (j == ind_cc1 || j == ind_cc2) continue;
            if (actual.esComponente == false) continue;
            if (actual.distancias[ind_cc2] < actual.distancias[ind_cc1]) {
                actual.distancias[ind_cc1] = actual.distancias[ind_cc2];
                actual.aristaMasCortaTotalHacia[ind_cc1] = actual.aristaMasCortaTotalHacia[ind_cc2];
            }
            // notar que uso <=, es para que si quedaba apuntando a cc2 que ya no existe, cambie a cc1
            if (actual.distancias[ind_cc1] <= actual.menorDistancia) {
                actual.menorDistancia = actual.distancias[ind_cc1];
                actual.ccMasCercana = ind_cc1;
                actual.aristaMasCortaTotalGeneral = actual.aristaMasCortaTotalHacia[ind_cc1];
            }
            cc1.distancias[j] = actual.distancias[ind_cc1];
            cc1.aristaMasCortaTotalHacia[j] = actual.aristaMasCortaTotalHacia[ind_cc1];
            if (cc1.distancias[j] < cc1.menorDistancia) {
                cc1.menorDistancia = cc1.distancias[j];
                cc1.ccMasCercana = j;
                cc1.aristaMasCortaTotalGeneral = cc1.aristaMasCortaTotalHacia[j];
            }
        }
        
    }
}

void imprimir() {
    int q = 0, m = 0;
    list<int> compFinales;
    for (int i = 1; i <= n; i++) {
        ComponenteConexa &actual = componentes[i];
        if (actual.esComponente) {
            q++;
            compFinales.push_back(i);
            m += actual.aristas.size();
        }
    }
    cout << q << " " << m << endl;
    for (list<int>::iterator it = compFinales.begin(); it != compFinales.end(); it++)
        cout << *it << endl;
    for (list<int>::iterator it = compFinales.begin(); it != compFinales.end(); it++) {
        ComponenteConexa &actual = componentes[*it];
        for (list<arista>::iterator it_arista = actual.aristas.begin(); it_arista != actual.aristas.end(); it_arista++) {
            cout << it_arista->first << " " << it_arista->second << endl;
        }
    }
}
