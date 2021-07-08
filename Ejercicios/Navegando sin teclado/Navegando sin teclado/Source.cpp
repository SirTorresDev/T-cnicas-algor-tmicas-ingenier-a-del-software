
// Roberto Torres Prensa

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "DigrafoValorado.h"
#include "IndexPQ.h"
// propios o los de las estructuras de datos de clase
const int INF = 10000000000;

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

class Navegacion {
private: 
    DigrafoValorado<int> g;
    int origen;
    vector<int> dist;
    vector<int> costes;
    IndexPQ<int> pq;

    void relajar(AristaDirigida<int> a) {
        int v = a.desde(), w = a.hasta();
        if (dist[w] > dist[v] + a.valor() + costes[w]) { 
            dist[w] = dist[v] + a.valor() + costes[w];
            pq.update(w, dist[w]); //Si no esta lo mete en la cola, como si fuera un push, y cambia su prioridad en caso de que fuera necesario
        }
    }
    

    //Dijkstra
public:
    Navegacion(DigrafoValorado<int> const& grafo, int orig, vector<int> tiempos) : g(grafo), origen(orig), dist(grafo.V(), INF), costes(tiempos), pq(grafo.V()) {
        dist[origen] = costes[origen];  //O(A logV) con espacio adiccional O(V)
        pq.push(origen, 0);  
        while (!pq.empty()) {
            int v = pq.top().elem;
            pq.pop();
            for (auto a : grafo.ady(v)) {
                relajar(a);
            }
        }
    }

    int minCoste() {
        if (dist[g.V() - 1] == INF) return -1;
        return dist[g.V() - 1];
    }

    


};


// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int numPaginas, numEnlaces, a, b, tiempo;
    // leer los datos de la entrada
    cin >> numPaginas;
    if (numPaginas == 0) {
        return false;
    }
    vector<int> tiempoPaginas(numPaginas);
    for (int i = 0; i < numPaginas; i++) {
        cin >> tiempoPaginas[i];
    }
    DigrafoValorado<int> grafo(numPaginas);
    cin >> numEnlaces;
    for (int i = 0; i < numEnlaces; i++) {
        cin >> a >> b >> tiempo;
        grafo.ponArista({ a - 1, b - 1, tiempo });
    }
    Navegacion n(grafo, 0, tiempoPaginas);
    int sol = n.minCoste();
    if (sol == -1) {
        cout << "IMPOSIBLE" << "\n";
    }
    else {
        cout << sol << "\n";
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
