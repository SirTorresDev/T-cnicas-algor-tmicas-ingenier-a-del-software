
// Roberto Torres Prensa
// TAIS84

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int resolver(vector<int>& efectivosEnimigos, vector<int> &unidadesDefensa) {
    int contador = 0, j = 0;
    sort(efectivosEnimigos.begin(), efectivosEnimigos.end());
    sort(unidadesDefensa.begin(), unidadesDefensa.end());
    for (int i = 0; i < unidadesDefensa.size(); i++) {
        if (efectivosEnimigos[j] <= unidadesDefensa[i]) {
            contador++;
            j++;
        }
    }
    return contador;
}

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int ciudadesInvadidas;
    // leer los datos de la entrada
    cin >> ciudadesInvadidas;
    if (!std::cin)  // fin de la entrada
        return false;

    vector<int> efectivosEnemigos(ciudadesInvadidas);
    vector<int> unidadesDefensa(ciudadesInvadidas);
    for (int i = 0; i < ciudadesInvadidas; i++) {
        cin >> efectivosEnemigos[i];
    }
    for (int j = 0; j < ciudadesInvadidas; j++) {
        cin >> unidadesDefensa[j];
    }

    cout << resolver(efectivosEnemigos, unidadesDefensa) << "\n";


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
