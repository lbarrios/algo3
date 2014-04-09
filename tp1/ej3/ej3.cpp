#include <iostream>
#include <list>
#include <vector>
using namespace std;

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
//por ahora asi es mas facil
vector<int> piezasPorColores[1024][1024];
int t[1024][1024];

int main() {
    cin >> n >> m >> c;
    Pieza blanco;
    blanco.sup = 0;
    blanco.izq = 0;
    blanco.der = 0;
    blanco.inf = 0;
    //de esta forma la pieza blanca queda con el id 0
    listaDePiezas.push_back(blanco);
    for (int i=1; i <= n*m; i++) {
        int sup, izq, der, inf;
        cin >> sup >> izq >> der >> inf;
        Pieza pongo;
        //hacerlo mas eficiente
        pongo.sup = sup;
        pongo.izq = izq;
        pongo.der = der;
        pongo.inf = inf;
        listaDePiezas.push_back(pongo);
        //cada pieza queda con su id correspondiente
        piezasPorColores[sup][izq].push_back(i);
    }

    max_global = (n*m)/2;
    max_local = 0;
    huecos = 0;
    backtrack(0, 0);
    cout << "orden de las piezas: ";
    for(list<int>::iterator it = orden_global.begin(); it != orden_global.end(); it++)
        cout << *it << " ";
    cout << endl;
    cout << "max_global: " << max_global << endl;
    return 0;
}

void probaConTodasLasFichas(int x, int y, vector<int> &listaPosibles) {
        for(int i=listaPosibles.size() - 1; i >= 0; i--) {
            int fichaQueVoyAPoner = listaPosibles[i];
            listaPosibles[i] = listaPosibles.back();
            listaPosibles.pop_back();
            max_local++;
            t[x][y] = fichaQueVoyAPoner;
            orden_local.push_back(fichaQueVoyAPoner);
            
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
            
            //deshago todo lo que hice
            orden_local.pop_back();
            max_local--;
            listaPosibles.push_back(fichaQueVoyAPoner);
        }
}

void backtrack(int x, int y) {
    //primero veo que fichas puedo poner aca
    int color_sup = x>0 ? listaDePiezas[t[x-1][y]].inf : 0;
    int color_izq = y>0 ? listaDePiezas[t[x][y-1]].der : 0;
    if (color_sup > 0 && color_izq > 0) {
        probaConTodasLasFichas(x, y, piezasPorColores[color_sup][color_izq]);    
    } else if (color_sup > 0) {
        for(int r=1; r<=c; r++) {
            probaConTodasLasFichas(x, y, piezasPorColores[color_sup][r]);
        }
    } else if (color_izq > 0) {
        for(int r=1; r<=c; r++) {
            probaConTodasLasFichas(x, y, piezasPorColores[r][color_izq]);
        }
    } else {
        for (int r1=1; r1<=c; r1++) {
            for(int r2=1; r2<=c; r2++) {
                probaConTodasLasFichas(x, y, piezasPorColores[r1][r2]);
            }
        }
    }
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
