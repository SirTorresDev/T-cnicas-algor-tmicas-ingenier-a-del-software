
/*@ <answer>
 *
 * Nombre y Apellidos: Roberto Torres Prensa
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "Matriz.h"  // propios o los de las estructuras de datos de clase

const int INF = 1000000000;

/*@ <answer>

costeMin(i,j) = Coste m�nimo de la instalci�n para obtener la potencia j con bombillas de 1 a i

//Casos Base
     costeMin(0, j) = INF
     costeMin(i, 0) = 0

     ECUACION RECURSIVA:

     costeMin(i,j) = costeMin(i - 1,j) si j < potencias[i - 1]

     costeMin(i,j) = min(costeMin(i - 1,j), costeMin(i,j-potencias[i - 1]) + costes[i-1])


 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 Costes:
 - En tiempo: O(n*m) siendo n el numero de filas y m el numero de Columnas de la Matriz.

 - En espacio adicional: O(n*m) siendo n el numero de filas y m el numero de columnas de la matriz

 @ </answer> */


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
 // ================================================================
 //@ <answer>

int costeMin(const vector<int>& potencias, const vector<int>& costes, const int numBombillas, const int potenciaMax, const int potenciaMin, int &coste) {
    int n = potencias.size();
    Matriz<int> matriz(n + 1, potenciaMax + 1, INF);
    matriz[0][0] = 0;
    for (int i = 1; i <= numBombillas; i++) {
        matriz[i][0] = 0;
        for (int j = 1; j <= potenciaMax; j++) {
            if (potencias[i - 1] > j) {
                matriz[i][j] = matriz[i - 1][j];
            }
            else {
                matriz[i][j] = min(matriz[i - 1][j], matriz[i][j - potencias[i - 1]] + costes[i-1]);
            }
        }
    }
    int minPot = potenciaMin;
    coste = matriz[n][potenciaMin];
    int aux = coste;
    for (int i = potenciaMin + 1; i <= potenciaMax; i++) {
        coste = min(coste, matriz[n][i]);

        if (aux != coste) {
            aux = coste;
            minPot = i;
        }
    }
    
    return minPot;

}

bool resuelveCaso() {
    int numBombillas, potenciaMax, potenciaMin, coste = 0;
    cin >> numBombillas >> potenciaMax >> potenciaMin;
    // leer los datos de la entrada

    if (!std::cin)  // fin de la entrada
        return false;
    vector<int> potencias(numBombillas);
    vector<int> costes(numBombillas);
    for (int i = 0; i < numBombillas; i++) {
        cin >> potencias[i];
    }
    for (int i = 0; i < numBombillas; i++) {
        cin >> costes[i];
    }

    int sol = costeMin(potencias, costes, numBombillas, potenciaMax, potenciaMin, coste);
    if (coste != INF) {
        cout << coste << " " << sol << "\n";
    }
    else cout << "IMPOSIBLE " << "\n";

        
        

    // resolver el caso posiblemente llamando a otras funciones

    // escribir la soluci�n

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
