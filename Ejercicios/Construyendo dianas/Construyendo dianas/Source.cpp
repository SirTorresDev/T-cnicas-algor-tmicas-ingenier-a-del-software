
/*@ <answer>
 *
 * Nombre y Apellidos: Roberto Torres Prensa
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

#include "Matriz.h"  
int INF = 1000000000;

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 minimoNumero(i,j) = Numero minimo de dardos que tengo que lanzar para conseguir la puntuación j con los sectores del 1 a i

 CASOS BASE:

     minimoNumero(0, j) = INF
     minimoNumero(i, 0) = 0    //No lanzar ninguno


 ECUACION RECURSIVA:

 minimoNumero(i, j) = minimoNumero(i - 1, j)   si sectores[i-1] > j

 min(minimoNumero(i-1, j),minimoNumero(i, j - sectores[i]) + 1) si sectores[i] <= j

 COSTE:

 - En tiempo: O(n*m) siendo n el numero de filas y m el numero de columnas de la matriz.

 - En espacio adicional: O(n*m) siendo n el numero de filas y m el numero de columnas de la matriz


 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

int minimoNumero(vector<int> const& sectores, int V, vector<int>& cuantas) {
    int n = sectores.size();
    Matriz<int> puntuaciones(n + 1, V + 1, INF);
    puntuaciones[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        puntuaciones[i][0] = 0;
        for (int j = 1; j <= V; ++j) {
            if (sectores[i-1] > j)
                puntuaciones[i][j] = puntuaciones[i - 1][j];
            else
                puntuaciones[i][j] = min(puntuaciones[i-1][j], puntuaciones[i][j - sectores[i-1]] + 1);
        }
            
    }
    int value = puntuaciones[n][V];
    if (value != INF) {
        cuantas.resize(value);
        int i = n, j = V, indice = 0;
        while (j > 0) {
            if (sectores[i-1] <= j && puntuaciones[i][j] == puntuaciones[i][j - sectores[i-1]] + 1) {
                cuantas[indice] = sectores[i-1];
                j -= sectores[i-1];
                indice++;
            }
            else {
                --i;
            }
        }
    }

        return puntuaciones[n][V];
}



bool resuelveCaso() {
    int resultado, numSectores;
    cin >> resultado >> numSectores;

    if (!std::cin)  // fin de la entrada
        return false;
    vector<int> sectores(numSectores);
    for (int i = 0; i < numSectores; i++) {
        cin >> sectores[i];
    }
    vector<int>cuantas(numSectores);
    int minDardos = minimoNumero(sectores, resultado, cuantas);
    if (minDardos != INF) {
        cout << minDardos << ": ";
        for (int j = 0; j < cuantas.size(); j++) {
            cout << cuantas[j] << " ";
        }
        cout << "\n";
    }
    else cout << "Imposible" << "\n";

    // resolver el caso sectoresosiblemente llamando a otras funciones

    // escribir la solución

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma sectoresarte de la solución.

int main() {
    // ajustes sectoresara que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

    // sectoresara dejar todo como estaba al sectoresrincisectoresio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
