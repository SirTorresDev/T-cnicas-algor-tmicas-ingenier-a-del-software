
// Roberto Torres Prensa
// TAIS84

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>

#include "Grafo.h"  // propios o los de las estructuras de datos de clase
using namespace std;
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

class MaximaCompConexa {
private:
    vector<bool> visitados;
    int maxi;

    int dfs(Grafo const& g, int v) { //O(N + M)
        visitados[v] = true;
        int tam = 1;
        for (int w : g.ady(v)) {
            if (!visitados[w]) 
                tam += dfs(g, w);
            
        }
        return tam;
    }

public:
    MaximaCompConexa(Grafo const& g) : visitados(g.V(), false), maxi(0) {
        for (int v = 0; v < g.V(); v++) {
            if (!visitados[v]) {
                int tam = dfs(g, v);
                maxi = max(tam, maxi);
            }
        }
    }

    int maximo() const {
        return maxi;
    }

};
// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() { //O(N + M)
    int numPersonas, numAmistades;
    cin >> numPersonas >> numAmistades;
    Grafo grafo(numPersonas);
    for (int i = 0; i < numAmistades; i++) {
        int v, w;
        cin >> v >> w;
        grafo.ponArista(v - 1, w - 1);
    }

    MaximaCompConexa mcc(grafo);
    cout << mcc.maximo() << "\n";
    // leer los datos de la entrada



    // escribir solución
}

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
