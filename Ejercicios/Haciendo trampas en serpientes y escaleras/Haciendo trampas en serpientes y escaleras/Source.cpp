
// Roberto Torres Prensa

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

/*
Para resolver este problema he usado un vector en que almaceno el numero de tiradas para llegar a la posicion i del tablero, por lo demas
sigue la estructura de una busqueda en anchura normal, ya que queremos encontrar el camino mas corto para llegar lo antes posible a la ultima casilla.
Para ello usamos una cola en la que vamos almacenando cada uno de los vertices para ir mirando sus adyacentes(serpiente o escalera) en caso de que los tenga.
y un vector de booleanos en los que marco a true cada vertice que visito.

*/


#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;


#include "Digrafo.h"  // propios o los de las estructuras de datos de clase

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
class Juego {
private:
    int n, k;
    vector<bool> visitados;
    vector<int> distancia;
    queue<int> cola;

    int bfs(Digrafo const& grafo, int origen, int destino) { //O(V+A)
        if (origen == destino) return 0;
        visitados[origen] = true;
        distancia[origen] = 0;
        cola.push(origen);
        while (!cola.empty()) {
            int v = cola.front();
            cola.pop();
            for (int i = 1; i <= k; i++) { //Tiras k veces el dado
                int w = v + i; // El proximo vertice a considerar
                if (w >= destino) w = destino - 1;
                if (!grafo.ady(w).empty()) {
                    w = grafo.ady(w)[0];
                }//si tiene escalera o serpiente
                if (!visitados[w]) {
                    visitados[w] = true;
                    distancia[w] = distancia[v] + 1;
                    if (w == destino - 1) return distancia[w]; //Si llego al final
                    else cola.push(w);
                }

            }
        }
    }

public:
    Juego(Digrafo const& grafo, int n, int k) : visitados(n*n, false), distancia(n * n, -1), n(n), k(k) {

    }


    int minimo(Digrafo const& grafo){
        return bfs(grafo , 0, n * n);
    }


};

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int dimension, numCaras, numSerpientes, numEscaleras;
    // leer los datos de la entrada
    cin >> dimension >> numCaras >> numSerpientes >> numEscaleras;

    if (dimension == 0 && numCaras == 0 && numSerpientes == 0 && numEscaleras == 0)
        return false;

    Digrafo grafo(dimension * dimension);
    for (int s = 0; s < numSerpientes; s++) {
        int a, b;
        cin >> a >> b;
        grafo.ponArista(a - 1, b - 1);
    }

    for (int e = 0; e < numEscaleras; e++) {
        int a, b;
        cin >> a >> b;
        grafo.ponArista(a - 1, b - 1);
    }

    Juego j(grafo, dimension, numCaras);
    cout << j.minimo(grafo) << "\n";

    

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
