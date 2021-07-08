
/*@ <answer>
 *
 * Nombre y Apellidos: Roberto Torres Prensa
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "Matriz.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>


    mochila(i,j) = Maxima cantidad de oro que puedo coger con un tiempo j considerando los cofres del 1 al i

    CASOS BASE:

    mochila(i,0) = 0
    mochila(0,j) = 0

    CASOS RECURSIVOS:

    mochila(i,j) = mochila(i - 1,j) si datos[i].profundidad > j

    mochila(i,j) = max(mochila(i-1,j), mochila(i, j - datos[i].profundidad) + datos[i].cantidad si datos[i].profundidad <= j



 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>



struct tSol{
    int profundidad;
    int cantidad;
};


void mochila(const vector<tSol>& datos, int numSegundos, int numCofres, vector<bool> &sol, int &oroMax, int &cofres) {
    int n = datos.size() - 1;
    Matriz<int> matriz(n + 1, numSegundos + 1, 0);
    matriz[0][0] = 0;
    //Calculo de los objetos
    for (int i = 1; i <= n; i++) {
        matriz[i][0] = 0;
        for (int j = 1; j <= numSegundos; j++) {
            if (datos[i].profundidad > j) {
                matriz[i][j] = matriz[i-1][j];
            }
            else {
                matriz[i][j] = max(matriz[i - 1][j], matriz[i-1][j - datos[i].profundidad] + datos[i].cantidad);
            }
        }
    }
    oroMax = matriz[n][numSegundos];
    int i = n, j = numSegundos;
    while (i > 0 && j > 0) {
        if (matriz[i][j] == matriz[i - 1][j]) {
            sol[i] = false;
        }
        else{
            sol[i] = true;
            j = j - datos[i].profundidad;
            cofres++;
        }
        --i;
    }


}

bool resuelveCaso() {
    int numSegundos, numCofres, oroMax = 0, cofres = 0;
    cin >> numSegundos >> numCofres;
    // leer los datos de la entrada

    if (!std::cin)  // fin de la entrada
        return false;
    vector<tSol> datos;
    vector<bool> sol(numCofres + 1,false);
    datos.push_back({ 0,0 });
    int p, o;
    for (int i = 1; i <= numCofres; i++) {
        cin >> p >> o;
        datos.push_back({ 3*p, o });
    }

    mochila(datos, numSegundos, numCofres,sol, oroMax,cofres);
    if (oroMax == 0) {
        cout << "0" << "\n";
        cout << "0" << "\n";
        cout << "----" << "\n";
    }
    else {
        cout << oroMax << "\n";
        cout << cofres << "\n";
        for (int i = 0; i < sol.size(); i++) {
            if (sol[i]) {
                cout << datos[i].profundidad / 3 << " " << datos[i].cantidad << "\n";
            }
        }
        cout << "----\n";
    }
   

    // resolver el caso posiblemente llamando a otras funciones

    // escribir la solución

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

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
