
// Roberto Torres Prensa

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>

#include "PriorityQueue.h"  // propios o los de las estructuras de datos de clase
using namespace std;


struct registro {
    long long int momento;
    long long int id;
    long long int periodo;
};

bool operator<(registro const& a, registro const& b) {
    return a.momento < b.momento || (a.momento == b.momento && a.id < b.id);
}
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
int resolver(PriorityQueue<registro> cola) {
    int envios;
    cin >> envios;
    while (envios--) { //El tamaño del bucles de 0(N logN + KlogN) siendo k el numero de envios
        auto e = cola.top(); //O(1)
        cola.pop(); //O(logN)
        cout << e.id << '\n';
        e.momento += e.periodo;
        cola.push(e);//O(logN)
    }
    cout << "---\n";
    return true;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int N;
    cin >> N;
    if (N == 0) return false;
    PriorityQueue<registro> cola;
    for (int i = 0; i < N; i++) { //Todo el bucle tiene un coste de O(N logN)
        long long int id_usu, periodo;
        cin >> id_usu >> periodo;
        cola.push({ periodo, id_usu, periodo }); //O(logN)
    }
    resolver(cola);
    // leer los datos de la entrada

   
    return true;
    // escribir solución
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
