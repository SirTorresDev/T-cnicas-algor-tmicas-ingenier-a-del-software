
// Roberto Torres Prensa

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

/*
Para resolver este problema he usado un struct que contiene el numero de Instrumentos, el numero de Partituras, y el numero de Personas,
Leo todos los datos, y los inserto en mi cola de Prioridad, y despues si hay mas partituras que instrumentos divides a la mitad el mayor grupo de
instrumentos, si no es una divison exacta le sumas 1 al grupo.
Para ello he redefinido la operacion < para que puede insertar de forma ordenada las diferentes tareas.

*/

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "PriorityQueue.h"  // propios o los de las estructuras de datos de clase

struct tSolucion {
    int numInstrumentos;
    int numPartituras;
    int numPersonas;
};
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

bool operator<(tSolucion a, tSolucion b) {
    return (a.numPersonas > b.numPersonas);
}
// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
/*
El coste de este algoritmo es del orden O(N logN + KlogN) siendo k el numero de instantes que quiero averiguar si hay conflictos o no.
*/
bool resuelveCaso() {
    bool ok = true;
    PriorityQueue<tSolucion> cola;
    int numeroPartituras, numInstrumentos, numPersonas, mayor;
    cin >> numeroPartituras >> numInstrumentos;
    if (!std::cin)  // fin de la entrada
        return false;
    for (int i = 0; i < numInstrumentos; i++) {
        cin >> numPersonas;
        cola.push({ numPersonas,1,numPersonas});

    }
    int partiturasSobrantes = numeroPartituras - numInstrumentos;
    if (partiturasSobrantes == 0) {
        mayor = cola.top().numPersonas;
        cola.pop();
    }
    else {
        while (partiturasSobrantes > 0) {
            tSolucion aux = cola.top();
            cola.pop();
            aux.numPartituras++;
            aux.numPersonas = aux.numInstrumentos / aux.numPartituras;
            if (aux.numInstrumentos % aux.numPartituras != 0)//si al dividirlo no es igual le sumo 1 al grupo
                aux.numPersonas++;

            cola.push(aux);//O(logN)
            partiturasSobrantes--;
        }
        mayor = cola.top().numPersonas;
    }

    cout << mayor << " " << "\n";


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
