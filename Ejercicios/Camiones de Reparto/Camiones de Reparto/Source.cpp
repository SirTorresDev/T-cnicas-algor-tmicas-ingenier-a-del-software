
// Roberto Torres Prensa

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

//Nos creamos un vector de booleanos en el que vamos a ir guardando el valor de visitados de cada vertice, por lo que dado un vertice inicial podemos saber recorriendo todas su
// aristas, ver a que vertices llega con la restriccion de la anchura y si finalmente llega a su destino en el vector en esa posicion estará a true.

#include <iostream>
#include <fstream>
#include <vector>
#include "GrafoValorado.h"
using namespace std;

class Reparto {
private:
    GrafoValorado<int> g;
    vector<bool> visitados;

    void dfs(int origen, int destino, int anchura) {   //O(V+A)
        visitados[origen] = true;
        for (auto a : g.ady(origen)) {
            if (a.valor() >= anchura) {
                int w = a.otro(origen);
                if (!visitados[w]) {
                    dfs(w, destino, anchura);
                }
            }
        }
    }

public:
    bool haLlegado(int origen, int destino, int anchura) {
        dfs(origen, destino, anchura);
        return visitados[destino];
    }

    Reparto(GrafoValorado<int>grafo, int v, int e) : g(grafo), visitados(grafo.V(), false) {
        g = grafo;
    }



};

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...



// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int numIntersecciones, numCalles, a, b, anchuraMaxima, numConsultas;
    cin >> numIntersecciones;
   


    // leer los datos de la entrada

    if (!std::cin)  // fin de la entrada
        return false;

    cin >> numCalles;
    GrafoValorado<int> grafo(numIntersecciones);

    for (int i = 0; i < numCalles; i++) {
        cin >> a >> b >> anchuraMaxima;
        grafo.ponArista({ a-1,b-1,anchuraMaxima });
    }

    cin >> numConsultas;
    int origen, destino, anchuraCamion;
    for (int i = 0; i < numConsultas; i++) {
        Reparto r(grafo, numIntersecciones, numCalles);
        cin >> origen >> destino >> anchuraCamion;
        if(r.haLlegado(origen-1,destino-1,anchuraCamion)) cout <<"SI" << "\n";
        else cout << "NO" << "\n";
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
