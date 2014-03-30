void backtrack(int x, int y) {
    //primero veo que fichas puedo poner aca
    color_izq = x>0 ? fichas[x][y-1].der() : 0;
    color_arr = y>0 ? fichas[x-1][y].abj() : 0;
    vector<ficha> listaPosibles = fichas.izq(color_izq).arr(color_arr); //hagamoslo por referencia

    //veo adonde voy a ir despues
    int sig_x = n, sig_y = m;
    if (x < n-1) {
        sig_x = x;
        sig_y = y + 1;
    } else if (y < m - 1) {
        sig_x = x + 1;
        sig_y = 0;
    }

    //lo recorro al reves. es medio raro, voy swapeando, es la forma que se me ocurrio
    //para que sea O(1) (amortizado) pasarle el vector sin la pieza que acabas de usar.
    //La idea que el vector tenga la ficha vacia en la primer posicion.
    for(int i=listaPosibles.size(); i>0; i--) {
        fichaQueVoyAPoner = listaPosibles[i];
        //si no es la ficha blanca
        if (i > 1) {   
            listaPosibles.swap(listaPosibles.size(), i);
            listaPosibles.pop_back();
            max_local++;
        } else {
            huecos++;
            //esto es una poda
            if (max_local + m*n - huecos <= max_global) continue;   //funciona continue?
        }
        
        t[x][y] = fichaQueVoyAPoner;
        orden_piezas_local.push_back(fichaQueVoyAPoner.id);

        if (sig_x != n || sig_y != m) {
            backtrack(sig_x, sig_y);
        } else if (max_local > max_global) {
            max_global = max_local;
            orden_piezas_global = orden_piezas_local;
        }

        orden_piezas_local.pop_back();
        if (i > 1) {
            listaPosibles.push_back(fichaQueVoyAPoner);
            max_local--;
        } else {
            huecos--;
        }
    }
}    

int main() {
    global n, m;    //no se si existe 'global'
    global int t[n][m];
    global vector<ficha> fichas[c+1][c+1];
    /* La idea es que se guarde en la pos 0 0 todas las fichas(como para poner en la 
     * primera posicion del tablero), estaria bueno que sea una clase o struct, en
     * la que le decis fichas.arriba('azul'), o 
     * fichas.izq('amarillo').arriba('azul'). En vez de colores numeros. */
    global max_global = (n * m) /2;
    global max_local = 0;
    global list<int> orden_piezas_global;
    global list<int> orden_piezas_local;
    global huecos = 0;
    backtrack(0, 0);
    cout << max_global << orden_piezas_global << endl;    //hay que poner bien el formato
    return 0;
}
