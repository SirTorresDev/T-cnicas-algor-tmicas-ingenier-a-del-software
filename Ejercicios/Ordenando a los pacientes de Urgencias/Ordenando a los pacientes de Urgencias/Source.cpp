
// Roberto Torres Prensa

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
using namespace std;

#include "PriorityQueue.h"  // propios o los de las estructuras de datos de clase

struct tSolucion {
    string nombre;
    int gravedad;
    int espera;
};
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
/*
    Para resolver este ejercicio he usado una PriorityQueue en la cual los elementos son structs que contiene el nombre del paciente,
    la gravedad y el tiempo de espera que lleva este paciente, el cual se va encremetar en cada caso ya sea de un nuevo Ingreso o una baja.
    Para ello he redefinido la operacion < para que compare los elementos de la cola segun la gravedad, de forma que me queden los de mas gravedad al principio.
*/

bool operator<(tSolucion const &a, tSolucion const &b) {
    return a.gravedad > b.gravedad || (a.gravedad == b.gravedad && a.espera < b.espera);
}


// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int numCasos, gravedad, tiempo = 0;
    string nombre;
    char evento;
    PriorityQueue<tSolucion> cola;
    cin >> numCasos;
    if (numCasos == 0)
        return false;
    for (int i = 0; i < numCasos; i++) { //El tamaño del bucles de 0(N logN + KlogN) siendo k el numero de casos.
        cin >> evento;
        if (evento == 'I') {
            cin >> nombre >> gravedad;
            cola.push({ nombre,gravedad,tiempo });
        }
        else if (evento == 'A') {
            if (cola.empty()) {

            }
            else {
                cout << cola.top().nombre << '\n'; //O(1)
                cola.pop(); //O(logN)
            }
        }
        tiempo++;
    }
    cout << "---" << '\n';

    // leer los datos de la entrada

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
