
// Roberto Torres Prensa

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "PriorityQueue.h"
using namespace std;

struct Tarea {
    int inicio;
    int fin;
};

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

bool operator<(Tarea a, Tarea b) {
    return a.fin < b.fin;
}

int resolver(PriorityQueue<Tarea> tareas) {
    int contador = 1, n = tareas.size() -1;
    auto t = tareas.top();
    tareas.pop();

    while (n > 0) {
        if (t.fin <= tareas.top().inicio) {
            contador++;
            t = tareas.top();
        }
        tareas.pop();
        n--;
    
    }
    return contador;
   
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta

    bool resuelveCaso() {
        int numEdificios, numOcci, numOri;
        cin >> numEdificios;
        
        // leer los datos de la entrada

        if (numEdificios == 0) {
            return false;
        }
        PriorityQueue<Tarea> tareas;
            
        for (int i = 0; i < numEdificios; i++) {
            cin >> numOcci >> numOri;
            tareas.push({ numOcci, numOri });
        }
      
        cout << resolver(tareas) << "\n";

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
