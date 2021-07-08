
// Roberto Torres Prensa
// TAI84

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
#include "PriorityQueue.h"
#include "GrafoValorado.h"  // propios o los de las estructuras de datos de clase
#include "ConjuntosDisjuntos.h"
using namespace std;




//Para resolver este problema usamos un vector para ver si podemos visitar todos los vertices, es decir si existe puentes a todas las islas, y vamos acumulando en una variable
// en caso de que no hayamos visitados ese vector el coste de construir ese puente.

class Archipielago {
private:
    GrafoValorado<int> g;
    int minimoCoste, numVisitados;

    int kruskal() {
        PriorityQueue<Arista<int>> pq(g.aristas());
        ConjuntosDisjuntos cjtos(g.V());
        while (!pq.empty()) {
            auto a = pq.top();
            pq.pop();
            int v = a.uno();
            int w = a.otro(v);
            if (!cjtos.unidos(v, w)) {
                cjtos.unir(v, w);
                numVisitados++;
                minimoCoste += a.valor();
                if (numVisitados == g.V() - 1) return minimoCoste;
            }
        }
        return -1;
    }

public:

    int coste() {
        if (g.V() == 1) return 0;
        return kruskal();
    }




    Archipielago(GrafoValorado<int> const &grafo) : minimoCoste(0), numVisitados(0), g(grafo)  {
        

    }

};
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...


// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int numIslas, numPuentes;

    // leer los datos de la entrada
    cin >> numIslas;
    if (!std::cin)  // fin de la entrada
        return false;

    cin >> numPuentes;
    int a, b, coste;
    GrafoValorado<int> g(numIslas);
    for (int i = 0; i < numPuentes; i++) {
        cin >> a >> b >> coste;
        g.ponArista({ a-1, b-1, coste });
    }

    Archipielago archi(g);
    
    int sol = archi.coste();
    if (sol == -1) {
        cout << "No hay puentes suficientes" << "\n";
    }
    else cout << sol << "\n";
    

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
