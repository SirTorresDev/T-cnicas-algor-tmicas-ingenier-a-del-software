
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

class ArbolLibre {

private:
    vector<bool> visitados;
    vector<int> anterior;
    int origen;
    int contador;
public:

    ArbolLibre(Grafo const& g, int s) : visitados(g.V(), false), anterior(g.V()), origen(s),contador(1) {
        dfs(g, s);
        
    }
    bool hayCamino(int v) const {
        return visitados[v];
    }

  
    bool grafoLibre(Grafo const& g) { 
        return (g.V() == contador && g.A() == g.V() - 1);
    }

private:

    void dfs(Grafo const& g, int v) { //O(V + A) Ya que por cada vertice recorro todos sus adyacentes.
        visitados[v] = true;
        for (int w : g.ady(v)) {
            if (!visitados[w]) {
                contador++;
                anterior[w] = v;
                dfs(g, w);
            }
        }
    }
};

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() { //O(V + A)
    int numVertices, numAristas;
    cin >> numVertices;
    if (!std::cin)  // fin de la entrada
        return false;
    cin >> numAristas;
   
	
	// leer los datos de la entrada
	Grafo grafo(numVertices);
    for (int i = 0; i < numAristas; i++) {
        int v, w;
        cin >> v >> w;
        grafo.ponArista(v, w);
    }
	

    ArbolLibre arbol(grafo,0);
	if (arbol.grafoLibre(grafo)) cout << "SI" << "\n";
	else cout << "NO" << "\n";
	

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
