#include <iostream>
#include <queue>
#include <list>
#include <vector>
#include <cstdio>

using namespace std;

struct DirCant {
  bool direccion;
  int cantidad;
};


struct Jugada {
  int turnosHastaAhora;
  list<DirCant>* turnosQuePasaron;
  int mejorPuntaje;
  inline bool operator<(const Jugada& j) {
    return mejorPuntaje < j.mejorPuntaje;
  }
};


void imprimeTabla(Jugada* tabla) {

}



int main(int argc, const char *argv[]) {
    
  int cantCartas;
  vector<int> cartas;
  
  list<int>* bla = new list<int>();


  //Se reciben los datos.
  cin >> cantCartas;
  for (int i = 0; i < cantCartas; i++) {
    int nuevaCarta;
    cin >> nuevaCarta;
    cartas.push_back(nuevaCarta);
  }
 
  //Se calculan las sumas parciales para cada elemento.
  int sumasParciales[cantCartas+1]; // Necesito un espacio extra para poner 0 al principio.
  sumasParciales[0] = 0;
  for (int i = 1; i < cantCartas+1; i++)
  {
    sumasParciales[i] = sumasParciales[i-1] + cartas[i-1];

  }

  //Se crea la matriz para guardar los datos;
  Jugada mejoresJugadas[cantCartas][cantCartas];

  // Se inicializa la matriz en cero para simplificar código.
  for (int i = 0; i < cantCartas; i++)
  {
    for (int j = 0; j < cantCartas; j++)
    {
      mejoresJugadas[i][j].mejorPuntaje = 0;
      mejoresJugadas[i][j].turnosHastaAhora = 0;
      mejoresJugadas[i][j].turnosQuePasaron = NULL;
    }
  }

  /**
   *Se inicializa la matriz para guardar los datos.
   *Se toman subconjuntos de tamaño cada vez mas grande.
   */
  // Tengo que hacer un arreglo acá. El caso de tamaño 1 se tiene
  // que calcular a parte. A patín viejo, a patín.
  
  for (int i = 0; i < cantCartas; i++) {
    mejoresJugadas[i][i].mejorPuntaje = cartas[i];
    mejoresJugadas[i][i].turnosHastaAhora = 1;
  }
  for (int tamSubconjunto = 2; tamSubconjunto <= cantCartas; tamSubconjunto++) {
    int principio = 0;
    int final = tamSubconjunto;
    while (final <= cantCartas) {
      int sumaParcial = sumasParciales[final] - sumasParciales[principio];
      Jugada minActual;
      minActual.mejorPuntaje = 1 << 30;// Máximo número posible en int;
      bool direccion;
      int cuantosAgarro;
      for (int i = principio+1; i < final; i++) {
        Jugada jugadaEnemigo = mejoresJugadas[i][final-1];
        if ( jugadaEnemigo < minActual ) {
          direccion = 0; //Esto significa izquierda
          minActual = jugadaEnemigo;
          cuantosAgarro = i;
          
        }
      }
      for (int i = principio+1; i <= final; i++) {
        Jugada jugadaEnemigo = mejoresJugadas[principio][i-1];
        if ( jugadaEnemigo < minActual ) {
          direccion = 1; //Esto significa derecha.
          minActual = jugadaEnemigo;
          cuantosAgarro = tamSubconjunto - i;
        }
      }

      Jugada miJugada;
      miJugada.mejorPuntaje = sumaParcial - minActual.mejorPuntaje;
      miJugada.turnosHastaAhora = minActual.turnosHastaAhora +1;
      DirCant ultimoMovimiento;
      ultimoMovimiento.direccion = direccion;
      ultimoMovimiento.cantidad = cuantosAgarro;
      miJugada.turnosQuePasaron = minActual.turnosQuePasaron;
      if (miJugada.turnosQuePasaron == NULL) {
        miJugada.turnosQuePasaron = new list<DirCant>();
      }
      miJugada.turnosQuePasaron->push_front(ultimoMovimiento);
      
      mejoresJugadas[principio][final-1] = miJugada;

      principio++;
      final++;
    }
  }
  // En este momento ya se tiene toda la tabla calculada.
  for (int i = 0; i < cantCartas; i++) {
    for (int j = 0; j < cantCartas; j++) {
      Jugada p = mejoresJugadas[i][j];
      cout << p.mejorPuntaje << "  ";
    }
    cout << endl;
    
  }
  list<DirCant>* mylist = mejoresJugadas[0][cantCartas-1].turnosQuePasaron;
  for (list<DirCant>::iterator i = mylist -> begin() ; i != mylist->end() ; i++) {
    cout << (*i).cantidad << " " << (*i).direccion << endl;
  }
}
  






  
