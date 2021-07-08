
// Roberto Torres Prensa

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

#include "Matriz.h"  // propios o los de las estructuras de datos de clase

//==========================>   EJERCICIO 35 (Roberto) <==========================//

/*

 maneras(i, j) = Maneras de formar una cuerda de longitud j con los cordeles del 1 al i.

 CASOS BASE:

     maneras(0, j) = 0
     maneras(i, 0) = 1


 ECUACION RECURSIVA:

   maneras(i, j) = maneras(i - 1, j)   si cordeles[i].first > j

 maneras(i - 1, j - cordeles[i].first) || maneras(i - 1, j) si cordeles[i].first <= j

 COSTE:

 - En tiempo: O(n*m) siendo n el numero de filas y m el numero de columnas de la matriz.

 - En espacio adicional: O(n*m) siendo n el numero de filas y m el numero de columnas de la matriz

 */

int INF = 1000000000;
long long int maneras(const vector<pair<int, int>>&cordeles, const int l) {
    int n = cordeles.size();
    vector<vector<long long int>> matriz(n + 1, vector<long long int>(l + 1, 0));
    matriz[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        matriz[i][0] = 1;
        for (int j = 1; j <= l; j++) {
            if (cordeles[i - 1].first > j) {
                matriz[i][j] = matriz[i - 1][j];
            }
            else {
                matriz[i][j] = matriz[i - 1][j] + matriz[i - 1][j - cordeles[i-1].first];
            }
        }
    }
    return matriz[n][l];


}

int minimoNumero(const vector<pair<int, int>>& cordeles, const int l) {
    int n = cordeles.size();
    vector<vector<int>> matriz(n + 1, vector<int>(l + 1, INF));
    matriz[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        matriz[i][0] = 0;
        for (int j = 1; j <= l; j++) {
            if (cordeles[i - 1].first > j) {
                matriz[i][j] = matriz[i - 1][j];
            }
            else {
                matriz[i][j] = min(matriz[i - 1][j], matriz[i - 1][j - cordeles[i-1].first] + 1);
            }
        }
    }
    return matriz[n][l];
}

int minimoCoste(const vector<pair<int, int>>& cordeles, const int l) {
    int n = cordeles.size();
    vector<vector<int>> matriz(n + 1, vector<int>(l + 1, INF));
    matriz[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        matriz[i][0] = 0;
        for (int j = 1; j <= l; j++) {
            if (cordeles[i - 1].first > j) {
                matriz[i][j] = matriz[i - 1][j];
            }
            else {
                matriz[i][j] = min(matriz[i - 1][j], matriz[i - 1][j - cordeles[i-1].first] + cordeles[i-1].second);
            }
        }
    }
    return matriz[n][l];
}
bool resuelveCaso() {
    int n, l;
    cin >> n >> l;
    if (!cin) return false;
    vector<pair<int, int>> cordeles;
    for (int i = 0; i < n; i++) {
        int l, c;
        cin >> l >> c;
        cordeles.push_back({ l, c });
    }
    long long int m = maneras(cordeles, l);
    if (m != 0)
        cout << "SI " << m << " "
        << minimoNumero(cordeles, l) << " "
        << minimoCoste(cordeles, l) << "\n";
    else
        cout << "NO" << "\n";
    return true;
}
int main() {
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
    while (resuelveCaso());
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
