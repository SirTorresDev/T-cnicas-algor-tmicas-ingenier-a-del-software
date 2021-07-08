
// Roberto Torres Prensa
// TAIS84

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

#include "ConjuntosDisjuntos.h"  // propios o los de las estructuras de datos de clase
const vector<pair<int, int>> direcciones = { {1,0} , {0,1}, {-1,0}, {0,-1}, {1,1} , {1,-1}, {-1,1}, {-1,-1} };
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

class Petrolero {
private:
    vector<vector<bool>> marcas;
    ConjuntosDisjuntos conjunto;
    int hundidos;
    int filas, columnas;

    bool posicionCorrecta(int i, int j) {
        return (i >= 0 && i < filas && j >= 0 && j < columnas);
    }

    void dfs(vector<string>& tablero, int i, int j, int& aux) { //O(N + M + logN)
        marcas[i][j] = true;
        aux++;
        for (auto dir : direcciones) {
            int v = i * columnas + j;
            int ni = i + dir.first;
            int nj = j + dir.second;
            if (posicionCorrecta(ni, nj) && tablero[ni][nj] == '#' && !marcas[ni][nj]) {
                int w = ni * columnas + nj;
                conjunto.unir(v,w);
                dfs(tablero, ni, nj, aux);
            }
        }
       
    }

public:
    Petrolero(vector<string> tablero, int numFilas, int numColumnas) : filas(numFilas), columnas(numColumnas), hundidos(0), conjunto(numFilas * numColumnas), marcas(numFilas, vector<bool>(numColumnas,false)) {
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                if (tablero[i][j] == '#' && !marcas[i][j]) {
                    int aux = 0;
                    dfs(tablero, i, j, aux);
                    hundidos = max(hundidos, aux);
                }
            }
        }
    }

    int getHundidos() const {
        return hundidos;
    }

    void nuevasUniones(vector<string> const & tablero, int a, int b) {
        int v = a * columnas + b;
        bool exist = false;
        for (auto dir : direcciones) {
            int ni = a + dir.first;
            int nj = b + dir.second;
            if (posicionCorrecta(ni, nj)) {
                if (tablero[ni][nj] == '#') {
                    int w = ni * columnas + nj;
                    conjunto.unir(v, w);
                    hundidos = max(conjunto.cardinal(v), hundidos);
                    exist = true;
                }
            }
        }
                
        
        if (!exist) hundidos = max(conjunto.cardinal(v), hundidos);
        
    }



};

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int numFilas, numColumnas;
    cin >> numFilas >> numColumnas;
    // leer los datos de la entrada

    if (!std::cin)  // fin de la entrada
        return false;
    vector<string> tablero(numFilas);
    cin.ignore();
    for (int i = 0; i < numFilas; i++) {
        getline(cin, tablero[i]);
    }
    Petrolero petroleroHundido(tablero, numFilas, numColumnas);
    int hundidos = petroleroHundido.getHundidos();
    std::cout << hundidos << " ";
    int numImagenesAdiccionales;
    cin >> numImagenesAdiccionales;
    for (int i = 0; i < numImagenesAdiccionales; i++) {
        int a, b;
        cin >> a >> b;
        tablero[a - 1][b - 1] = '#';
        petroleroHundido.nuevasUniones(tablero,a-1, b-1);
        hundidos = petroleroHundido.getHundidos();
        cout << hundidos << " ";
    }
    cout << "\n";
  
  

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
