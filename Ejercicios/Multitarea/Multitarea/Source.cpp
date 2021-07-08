
// Roberto Torres Prensa

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

/*
Para resolver este problema he usado un struct que contiene el inicio de mi tarea, el final, y el valor del periodo,
el cual sera 0 si me dicen que no se repite nunca.
Leo todos los datos, y los inserto en mi cola de Prioridad, y despues cuando los voy procesando, me declaro una variable procesamiento
en la que almaceno el instante del final de mi tarea, y desapilo el primer elemento de la cola y comparo esta varible con el instante de inicio de mi
siguiente tarea, si este es menor que el de mi variable procesamiento el resultado sera NO y si no sera Si.
Para ello he redefinido la operacion < para que puede insertar de forma ordenada las diferentes tareas.

*/

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "PriorityQueue.h"  // propios o los de las estructuras de datos de clase

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

struct tSolucion {
    int inicio;
    int fin;
    int periodo;
};
bool operator<(tSolucion a, tSolucion b) {
    return (a.inicio < b.inicio || (a.inicio == b.inicio && a.fin < b.fin));
}
// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
/*
El coste de este algoritmo es del orden O(N logN + KlogN) siendo k el numero de instantes que quiero averiguar si hay conflictos o no.
*/
bool resuelveCaso() {
    bool ok = true;
    PriorityQueue<tSolucion> cola;
    int N, M, T, inicio, fin, periodo, procesado = 0, i = 0;
    cin >> N >> M >> T;
    if (!std::cin)  // fin de la entrada
        return false;
    for (int i = 0; i < N; i++) {
        cin >> inicio >> fin;
        cola.push({ inicio, fin,0 });

    }
    for (int i = 0; i < M; i++) {
        cin >> inicio >> fin >> periodo;
        cola.push({ inicio,fin,periodo });
    }
    // leer los datos de la entrada
    while (!cola.empty() && cola.top().inicio < T) { //El coste de este bucle es del orden O(N logN + KlogN) siendo k el numero de instantes que quiero averiguar si hay conflictos o no.
        if (i <= cola.top().inicio && ok == true) { //O(1)
            ok = true;
        }
        else if (i > cola.top().inicio) { //O(1)
            ok = false;
            break;
        }
        if (cola.top().periodo != 0) { //O(1)
            cola.push({ cola.top().inicio + cola.top().periodo, cola.top().fin + cola.top().periodo,cola.top().periodo }); //O(logN)
        }
        if (!cola.empty()) {
            i = cola.top().fin; //O(1)
        }
        cola.pop(); //O(logN)


    }

    if (!ok) cout << "SI" << "\n";
    else cout << "NO" << "\n";



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
