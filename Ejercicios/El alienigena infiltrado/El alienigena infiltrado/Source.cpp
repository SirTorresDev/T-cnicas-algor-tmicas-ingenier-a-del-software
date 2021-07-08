
// Roberto Torres Prensa

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

struct tSol {
    int inicio;
    int finalizacion;
};

bool operator<(tSol a, tSol b) {
    return a.inicio < b.inicio || (a.inicio == b.inicio && a.finalizacion < b.finalizacion);
}

int resolver(vector<tSol> datos, const int &inicio, const int &finalizacion) {
    sort(datos.begin(), datos.end());
    int contador = 0, i = 0, max, inicioS = inicio;
    if (datos.size() == 0 || datos[0].inicio > inicioS) {
        return -1;
    }
    while (inicioS < finalizacion) {
        max = -1;
        while (i < datos.size() && datos[i].inicio <= inicioS) {
            if (datos[i].finalizacion > max) {
                max = datos[i].finalizacion;
            }
            i++;
        }
        if (max == -1) {
            return -1;
        }
        contador++;
        inicioS = max;
    }

 
    return contador;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int inicio, finalizacion, numTrabajos;
    // leer los datos de la entrada
    cin >> inicio >> finalizacion >> numTrabajos;
    if (inicio == 0 && finalizacion == 0 && numTrabajos == 0) {
        return false;
    }
        
    vector<tSol> datos(numTrabajos);
    for (int i = 0; i < numTrabajos; i++) {
        cin >> datos[i].inicio >> datos[i].finalizacion;
    }
    int sol = resolver(datos, inicio, finalizacion);
    if (sol == -1) {
        cout << "IMPOSIBLE" << "\n";
    }
    else cout << sol << "\n";

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
