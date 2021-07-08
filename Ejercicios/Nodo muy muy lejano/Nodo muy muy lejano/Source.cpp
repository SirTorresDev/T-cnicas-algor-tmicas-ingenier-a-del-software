
// Roberto Torres Prensa
// TAIS84

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>


#include "Grafo.h"  // propios o los de las estructuras de datos de clase
#include "PriorityQueue.h"
using namespace std;
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...


struct tNodo {
    int nodo;
    int distancia;
};

bool operator<(tNodo nodo1, tNodo nodo2) {
    return nodo1.distancia < nodo2.distancia;
}

class NodoLejano {
private:
    vector<bool> visitados;
    vector<int> distancias;
    int numNodos;


public:
    NodoLejano(Grafo const& grafo, int& origen, int &ttl) : visitados(grafo.V(), false), distancias(grafo.V()), numNodos(0) {
        visitados[origen] = true;
        numNodos++;
        tNodo inicial = { origen,0 };
        bfs(grafo, inicial, ttl);
    }

    int inalcanzables() const {
        return visitados.size() - numNodos;
    }

    void bfs(Grafo const &grafo, tNodo inicio, int &ttl){
        PriorityQueue<tNodo> cola;
        tNodo nodo;
        cola.push(inicio);

        while (!cola.empty()) {
            nodo = cola.top();
            cola.pop();
            for (int u : grafo.ady(nodo.nodo)) {
                if (!visitados[u] && nodo.distancia < ttl) { //Si no lo he visitado y no he agotado el ttl
                    visitados[u] = true;
                    numNodos++;
                    cola.push({ u,nodo.distancia + 1 }); //Cola con los nodos no visitados
                }
            }
        }

    }



};

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int numVertices, numAristas, numConsultas, origen, ttl;
    // leer los datos de la entrada
    cin >> numVertices;
    if (!std::cin)  // fin de la entrada
        return false;
    Grafo grafo(numVertices);
    cin >> numAristas;
    for (int i = 0; i < numAristas; i++) {
        int u, w;
        cin >> u >> w;
        grafo.ponArista(u - 1, w - 1);
    }
    cin >> numConsultas;
    while (numConsultas--) {
        cin >> origen >> ttl;
        origen--;
        NodoLejano sol(grafo, origen, ttl);
        cout << sol.inalcanzables() << "\n";
    }
    cout << "---" << "\n";

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
