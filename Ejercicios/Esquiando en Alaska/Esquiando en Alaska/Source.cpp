
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

//coste O(N log n)

int resolver(vector<int> &alturas, vector<int> &esquis) {
    sort(alturas.begin(), alturas.end()); //Ordenamos los dos de menor a mayor y asi tendra asignado el que tenga menor altura con menor longitud, y asi sucesivamente
    sort(esquis.begin(), esquis.end());
    int minimo = 0;
    for (int i = 0; i < alturas.size(); i++) {
        minimo += abs(alturas[i] - esquis[i]);
    }
    
    return minimo;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta

bool resuelveCaso() {
    int numEsquiadores;
    cin >> numEsquiadores;
    
    // leer los datos de la entrada

    if (numEsquiadores == 0) {
        return false;
    }
    vector<int>alturas(numEsquiadores);
    vector<int>longitudes(numEsquiadores);

    for (int i = 0; i < numEsquiadores; i++) {
        cin >> alturas[i];
    }

    for (int i = 0; i < numEsquiadores; i++) {
        cin >> longitudes[i];
    }

    cout << resolver(alturas,longitudes) << "\n";

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
