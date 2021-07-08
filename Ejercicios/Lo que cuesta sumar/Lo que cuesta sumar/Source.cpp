
// Roberto Torres Prensa

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
/*
Nos creamos una cola de priorida de tipo int en la que almacenamos todos los valores, 
luego obtenemos el primero con top y lo desapilamos con pop y tambien el segundo elemento, sumamos estos dos elementos
y lo gurdamos en la pila con push, y nos creamos una variable auxiliar para acumular el valor del esfuerzo de cada suma,
en la que vamos incrementando el valor en cada iteracion(suma) que hacemos.



*/



#include <iostream>
#include <fstream>
#include "PriorityQueue.h"
using namespace std;

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
long long int resolver(PriorityQueue<long long int> &cola) {
    long int a, b, c, aux = 0;
    if (cola.size() > 0) {
        while(cola.size() > 1) {  //Coste de O(N logN);
            a = cola.top(); //Coste O(1)
            cola.pop();     //Coste O(logN)
            b = cola.top();
            cola.pop();
            c = a + b;
            aux += c;

            cola.push(c);
        }
        
    }
    return aux;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int n;
    long long int elemento;
    // leer los datos de la entrada
    cin >> n;
    if (n == 0)
        return false;
    PriorityQueue<long long int> cola;
    for (int i = 0; i < n; i++) {  //Todo el bucle tiene coste O(N logN)
        cin >> elemento;
        cola.push(elemento);  //O(log N)
    }

    cout << resolver(cola) << endl;

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
