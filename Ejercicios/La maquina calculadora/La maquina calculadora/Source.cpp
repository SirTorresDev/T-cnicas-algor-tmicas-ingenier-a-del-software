
// Roberto Torres Prensa
// TAIS84

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

/*
Para resolver este problema hemos usado un recorrido en anchura, ya que buscamos el camino minimo para llegar al resultado, para ello 
he creado una funcion adyacente con las propiedaes que puede cumplir los adyacentes de cada vertice y la funcion bfs para realizar la busqueda en anchura con la cola.
Tambien he declarado 2 varibales que son MAX ya que la calculadora solo puede mostrar 4 digitos y en algunos casos se puede salir del limite
y la variable INF para marcar al recorrido que ese vertice no ha sido alcanzado.
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 10000;
const int INF = 1000000000;




// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...


// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta

int adyacente(int v, int i) {
    switch (i) {
    case 0: return (v + 1) % MAX; // + 1;
    case 1: return (v * 2) % MAX; // * 2;
    case 2: return (v / 3); // / 3
    }
}



int bfs(int origen, int destino) { //O(V+A)
    if (origen == destino) return 0;
    vector<int> distancia(MAX, INF);
    distancia[origen] = 0;
    queue<int> cola; cola.push(origen);
    while (!cola.empty()) {
        int v = cola.front(); cola.pop();
        for (int i = 0; i < 3; i++) {
            int w = adyacente(v, i);
            if (distancia[w] == INF) {
                distancia[w] = distancia[v] + 1;
                if (w == destino) return distancia[w];
                else cola.push(w);
            }
        }
    }

}

bool resuelveCaso() {

    // leer los datos de la entrada
    int inicio, fin;
    cin >> inicio;
    if (!std::cin)  // fin de la entrada
        return false;
    cin >> fin;

    cout << bfs(inicio, fin) << "\n";

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
