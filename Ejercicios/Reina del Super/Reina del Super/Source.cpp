
// Roberto Torres Prensa

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

/*
Para resolver este problema, he usado un struct que contiene el identificador, y el tiempo que esta ocupada la caja.
Entonces las inicializo todas las cajas a 0 y voy leyendo en numero del tiempo que va a estar ocupada cada caja, y las introduzco en mi cola de prioridad
de minimos ya que esta ordenada de forma que tengo la que menos tiempo va a tardar la primera.
*/

#include <iostream>
#include <fstream>
#include <vector>

#include "PriorityQueue.h"  // propios o los de las estructuras de datos de clase
using namespace std;


struct tCaja {
    int id;
    int tiempo;
};
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

bool operator<(tCaja const& caja1, tCaja const &caja2) {
    if (caja1.tiempo < caja2.tiempo) {
        return true;
    }
    else if (caja1.tiempo > caja2.tiempo) {
        return false;
    }
    else {
        if (caja1.id < caja2.id) {
            return true;
        }
        else return false;
    }

}

void resolver(PriorityQueue<tCaja> cola, int numeroClientes) {
    int tiempo;

    while (numeroClientes != 0) { //O(N logN) ya que realizo N operaciones de coste logN
        cin >> tiempo;
        tCaja caja = cola.top(); //O(1)
        cola.pop(); //O(1)
        caja.tiempo += tiempo;
        cola.push(caja); //O(logN)
        numeroClientes--;

       
    }
    cout << cola.top().id << "\n";

}
// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta

bool resuelveCaso() {
    PriorityQueue<tCaja> cola;
    int numeroCajas, numeroClientes;
    cin >> numeroCajas >> numeroClientes;

    // leer los datos de la entrada

    if (numeroCajas == 0 && numeroClientes == 0)
        return false;
    for (int i = 1; i <= numeroCajas; i++) { //O(N logN) ya que realizo N operaciones de coste logN
        cola.push({i,0});  //O(logN)
    }

    resolver(cola, numeroClientes);
    

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
