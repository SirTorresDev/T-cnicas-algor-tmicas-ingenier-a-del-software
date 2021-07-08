
// Roberto Torres Prensa
// TAIS84

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int resolver(const vector<int>& posiciones, const int& longitudParches) {
    int contador = 0;
    int i = 0, elemento = posiciones[0];
    elemento = elemento + longitudParches;
    contador++;
    while(i < posiciones.size() && elemento < posiciones[posiciones.size()-1]) {
       
        if (elemento < posiciones[i + 1]) {
            i++;
            elemento = posiciones[i];
            elemento = elemento + longitudParches;
            contador++;
           
        }
        else {
            i++;
        }
       

       
        
    }
    return contador;
}

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int numAgujeros, longitudParches;
    // leer los datos de la entrada
    cin >> numAgujeros;
    if (!std::cin)  // fin de la entrada
        return false;
    cin >> longitudParches;
    vector<int> posiciones(numAgujeros);
    for (int i = 0; i < numAgujeros; i++) {
        cin >> posiciones[i];
    }

    cout << resolver(posiciones, longitudParches) << "\n";
    

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
