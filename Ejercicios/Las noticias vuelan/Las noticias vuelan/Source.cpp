
// Roberto Torres Prensa

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

#include "Grafo.h"  // propios o los de las estructuras de datos de clase

class NoticiasVuelan {
public: 
    NoticiasVuelan(Grafo const& grafo) : visitados(grafo.V(), false), usuarios(grafo.V()), numGrupo(0) { //Coste de O(V+A)
        for (int i = 0; i < grafo.V(); i++) {
            if (!visitados[i]) {
                visitados[i] = true;
                grupos.push_back(dfs(grafo, i));
                numGrupo++;
            }
        }
    }

    int conocenNoticia(int n) {
        return grupos[usuarios[n]];
    }


private:
    vector<bool> visitados;
    vector<int> usuarios;
    vector<int> grupos;
    int numGrupo;

    int dfs(Grafo const& grafo, int origen) {
        int result = 1;
        usuarios[origen] = numGrupo;
        for (int w : grafo.ady(origen)) {
            if (!visitados[w]) {
                visitados[w] = true;
                usuarios[w] = numGrupo;
                result += dfs(grafo, w);
            }
        }
        return result;
    }


};

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...


// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    long int numUsuarios, numGrupos;
    cin >> numUsuarios;
    // leer los datos de la entrada
    if (!std::cin)  // fin de la entrada
        return false;
    Grafo grafo(numUsuarios);
    cin >> numGrupos;
    for (int i = 0; i < numGrupos; i++) {
        long int numUsuarios, a, b;
        cin >> numUsuarios;
        if (numUsuarios != 0) {
            cin >> a;
            for (int j = 1; j < numUsuarios; j++) {
                cin >> b;
                grafo.ponArista(a - 1, b - 1);
                a = b;
            }
        }
    }

    NoticiasVuelan resultado(grafo);
    for (int i = 0; i < grafo.V(); i++) {
        cout << resultado.conocenNoticia(i) << " ";
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