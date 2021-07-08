
// Roberto Torres Prensa
// TAIS84

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
#include <deque>

#include "Digrafo.h"  // propios o los de las estructuras de datos de clase
using namespace std;
using Camino = deque<int>;
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...


class OrdenTopologico {
public:
    //g es DAG
    OrdenTopologico(Digrafo const& g) : visitados(g.V(), false), anterior(g.V()), apilado(g.V(), false), hayciclo(false) {
        for (int v = 0; v < g.V(); v++) {
            if (!visitados[v]) {
                dfs(g, v);
            }
        }
    }

    bool hayCiclo() const { return hayciclo; }

    Camino const& ciclo() const { return _ciclo; }

    deque<int> const& orden() const {
        return _orden;
    }


private:
    vector<bool> visitados;
    vector<int> anterior;
    vector<bool> apilado;
    Camino _ciclo;
    bool hayciclo;
    deque<int> _orden;

    void dfs(Digrafo const& g, int v) { //Coste O(V+A)
        apilado[v] = true;
        visitados[v] = true;
        for (int w : g.ady(v)) {
            if (hayciclo) {
                return;
            }
            if (!visitados[w]) {
                anterior[w] = v;
                dfs(g, w);
               
            }
            else if (apilado[w]) {
                hayciclo = true;
                for (int x = v; x != w; x = anterior[x]) {
                    _ciclo.push_front(x);
                }
                _ciclo.push_front(w); _ciclo.push_front(v);
            }
            
        }
        _orden.push_front(v + 1);
        apilado[v] = false; 
    }
};

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int numTareas, numRelaciones;
    // leer los datos de la entrada
    cin >> numTareas;
    if (!std::cin)  // fin de la entrada
        return false;
    cin >> numRelaciones;
    Digrafo grafo(numTareas);
    for (int i = 0; i < numRelaciones; i++) {
        int a, b;
        cin >> a >> b;
        grafo.ponArista(a - 1, b - 1);
    }

    OrdenTopologico orden(grafo);
    if (orden.hayCiclo()) {
        cout << "Imposible";
    }
    else {
        for (int i = 0; i < orden.orden().size(); i++) {
            cout << orden.orden()[i] << " ";
        }
    }
    cout << "\n";

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
