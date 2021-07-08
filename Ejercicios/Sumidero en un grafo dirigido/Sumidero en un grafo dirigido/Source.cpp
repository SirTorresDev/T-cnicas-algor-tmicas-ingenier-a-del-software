
// Roberto Torres Prensa

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>

#include "Digrafo.h"  // propios o los de las estructuras de datos de clase
using namespace std;
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

class Sumidero {
public:
    Sumidero(Digrafo const& grafo, int origen) : visitados(grafo.V(), false), numAristasEntrantes(grafo.V(),0) {
        for (int v = 0; v < grafo.V(); v++) {
            visitados[v] = true;
            if (!visitados[v]) {
                dfs(grafo, v);
            }
        }
    }

    int verticeSumidero(int vertice) {
        int numero = 0;
        for (int i = 0; i < grafo.V(); i++) {
            numero += numAristasEntrantes[i][vertice]; //Solo recorres las filas del vertice y si el grado es 0 es que es un sumidero.
        }
        return numero;
    }

private:
    vector<bool> visitados;
    vector<vector<bool>> numAristasEntrantes;

    int dfs(Digrafo const& g, int v) {
        int numAristas = 0;
        visitados[v] = true;
        for (int w : g.ady(v)) {
            if (!visitados[w]) {
                visitados[w] = true;
                numAristasEntrantes[w] += dfs(g, w);
            }
        }
        return numAristas++;
    }

};

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int numVertices, numAriastas;
    // leer los datos de la entrada

    if (cin >> numVertices >> numAriastas)  // fin de la entrada
        return false;

    Digrafo grafo(numVertices);
    for (int i = 0; i < numAriastas; i++) {
        int a, b;
        cin >> a >> b;
        grafo.ponArista(a - 1, b - 1);
    }

    Sumidero sumi(grafo, 0);
    for (int i = 0; i < grafo.V(); i++) {
        if (sumi.verticeSumidero(i) == grafo.V() - 1) {
            cout << "SI " << i << "\n";
        }
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
