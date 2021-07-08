
// Roberto Torres Prensa

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "GrafoValorado.h"  // propios o los de las estructuras de datos de clase
#include  "IndexPQ.h"

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

const int INF = 10000000000;

class Camino {
private:
    GrafoValorado<int> grafo;
    vector<int> dist;
    vector<int> cambios; //Guardamos en un vector los cambios, asi cada vez que avazamos de vertice llevamos las posibilidades del anterior mas las nuevas.
    int origen;
    IndexPQ<int> pq;

    void relajar(Arista<int> a ,int v) {
        int w = a.otro(v);
        if (dist[w] > dist[v] + a.valor()) {
            dist[w] = dist[v] + a.valor();
            cambios[w] = cambios[v];
            pq.update(w, dist[w]); //Si no esta lo mete en la cola, como si fuera un push, y cambia su prioridad en caso de que fuera necesario
        }
        else if (dist[w] == dist[v] + a.valor()) {
            cambios[w] += cambios[v];
        }
    }


public:
    //Dijkstra
    Camino(GrafoValorado<int> g, int ori) : grafo(g), dist(g.V(), INF), cambios(g.V(),INF), origen(ori), pq(g.V()){
        dist[ori] = 0;
        cambios[ori] = 1;
        pq.push(ori, 0);
        while (!pq.empty()) {
            int v = pq.top().elem;
            pq.pop();
            for (auto a : g.ady(v)) {
                relajar(a,v);                   //O(A logV) con espacio adiccional O(V)
            }
        }
    }

    int numFormas() {
        if (dist[grafo.V() - 1] == INF) {
            return 0;
        }
        else return cambios[grafo.V() - 1];
       
    }





};

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int numIntersecciones, numCalles;
    // leer los datos de la entrada
    cin >> numIntersecciones;
    if (!std::cin)  // fin de la entrada
        return false;
    GrafoValorado<int> grafo(numIntersecciones);
    cin >> numCalles;
    int a, b, longitud;
    for (int i = 0; i < numCalles; i++) {
        cin >> a >> b >> longitud;
        grafo.ponArista({ a - 1, b - 1, longitud });
    }
    Camino c(grafo, 0);
  
    cout << c.numFormas() << "\n";

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
