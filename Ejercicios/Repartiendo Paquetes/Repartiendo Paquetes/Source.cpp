
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
    IndexPQ<int> pq;

    void relajar(AristaDirigida<int> a) {
        int v = a.desde(), w = a.hasta();
        if (dist[w] > dist[v] + a.valor()) {
            dist[w] = dist[v] + a.valor();
            pq.update(w, dist[w]); //Si no esta lo mete en la cola, como si fuera un push, y cambia su prioridad en caso de que fuera necesario.

        }
    }


    //Dijkstra
public:
    Navegacion(DigrafoValorado<int> const& grafo, int orig) : g(grafo), origen(orig), dist(grafo.V(), INF), pq(grafo.V()) {
        dist[origen] = 0;  //O(A logV) con espacio adiccional O(V)
        pq.push(origen, 0);
        while (!pq.empty()) {
            int v = pq.top().elem;
            pq.pop();
            for (auto a : grafo.ady(v)) {
                relajar(a);
            }
        }
    }

    int minCoste(int destino) {
        if (dist[destino] == INF) return -1;
        else return dist[destino];
    }




};


// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int numCasas, numEnlaces, a, b, esfuerzo, total = 0;
    // leer los datos de la entrada
    cin >> numCasas;
    if (!std::cin)  // fin de la entrada
        return false;
    DigrafoValorado<int> grafo(numCasas);
    cin >> numEnlaces;
    for (int i = 0; i < numEnlaces; i++) {
        cin >> a >> b >> esfuerzo;
        grafo.ponArista({ a - 1, b - 1, esfuerzo });
    }
    int origenDest, numPaquetes, destino;
    cin >> origenDest >> numPaquetes;
    Navegacion n(grafo, origenDest - 1);  
    Navegacion vuelta(grafo.inverso(), origenDest - 1); 
    for (int i = 0; i < numPaquetes; i++) {
        cin >> destino;
        int solIda = n.minCoste(destino-1);
        int solVuelta = vuelta.minCoste(destino-1);
        if (solIda == -1 || solVuelta == -1) {
            total = -1;
        }
        else if(total != -1) {
            total += solIda + solVuelta;
        }
    }
    if (total == -1) cout << "IMPOSIBLE" << "\n";
    else cout << total << "\n";
    
  



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
