
// Roberto Torres Prensa

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>

#include "Matriz.h"  // propios o los de las estructuras de datos de clase
using namespace std;

const int INF = 1000000000;

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
void resolver(Matriz<int> &tabla) {
    for (int k = 1; k <= tabla.numfils()-1; k++) {
        for (int i = 1; i <= tabla.numfils()-1; i++) {
            for (int j = 1; j <= tabla.numcols()-1; j++) {
                int sol = tabla[i][k] + tabla[k][j];
                if (sol < tabla[i][j]) {
                    tabla[i][j] = sol;
                }
            }

        }
    }
    
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int numPersonas, relaciones, contador = 1;
    string persona1, persona2;
    // leer los datos de la entrada
    cin >> numPersonas >> relaciones;
    if (!std::cin)  // fin de la entrada
        return false;
    Matriz<int> tabla(numPersonas + 1, numPersonas + 1, INF);

    for (int d = 1; d <= numPersonas; d++) {
        tabla[d][d] = 0;
    }
    unordered_map<string, int> nombres;
    //vector<string> nombres(numPersonas + 1, "vacio");
    for (int i = 0; i < relaciones; i++) {
        cin >> persona1 >> persona2;
        if (nombres.count(persona1) == 0) {
            nombres.insert({ persona1,contador});
            contador++;
        }
        if (nombres.count(persona2) == 0) {
            nombres.insert({ persona2,contador});
            contador++;
        }
        

        tabla[nombres[persona1]][nombres[persona2]] = 1;
        tabla[nombres[persona2]][nombres[persona1]] = 1;
    }
    // Floyd -> Coste O(n^3) en tiempo y O(1) en espacio adicional
    resolver(tabla);
    int maxi = 0;
    for (int i = 1; i <= numPersonas; i++) {
        for (int j = 1; j <= numPersonas; j++) {
            maxi = max(tabla[i][j], maxi);    
        }
    }
    if (maxi != INF) {
        cout << maxi << "\n";
    }
    else {
        cout << "DESCONECTADA" << "\n";
    }
    // escribir sol

    return true;
}

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
