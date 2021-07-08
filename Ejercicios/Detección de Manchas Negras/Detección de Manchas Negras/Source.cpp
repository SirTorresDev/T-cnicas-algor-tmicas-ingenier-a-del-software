
// Roberto Torres Prensa
// TAIS84

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

using Mapa = vector<string>;
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

class ManchasNegras {

public:
    ManchasNegras(Mapa const & m) : F(m.size()) ,C(m[0].size()), visitados(F, vector<bool>(C,false)), num(0), maxim(0)  { //O(F * C) 
        for (int i = 0; i < F; i++) {
            for (int j = 0; j < C; j++) {
                if (!visitados[i][j] && m[i][j] == '#') {
                    num++;
                    int nuevoTam = dfs(m, i, j);
                    maxim = max(maxim, nuevoTam);
                }
            }
        }

    }

    int numero() const {
        return num;
    }

    int maximo() const {
        return maxim;
    }
    
private:
    int F, C;
    vector<vector<bool>> visitados; //Se ha visitado el pixel <i,j>
    int num;
    int maxim;

    bool correcta(int i, int j) const {
        return 0 <= i && i < F && 0 <= j && j < C;
    }

    const vector<pair<int, int>> dirs = { {1,0}, {0,1}, {-1,0}, {0, -1} };

    int dfs(Mapa const& m, int fila, int columna) { //O(F * C) 
        visitados[fila][columna] = true;
        int tam = 1;
        for (auto t : dirs) {
            int ni = fila + t.first, nj = columna + t.second;
            if (correcta(ni, nj) && m[ni][nj] == '#' && !visitados[ni][nj]) {
                tam += dfs(m, ni, nj);
            }
        }
        return tam;
    }

  
};

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() { //O(F * C)
    int F, C;
    cin >> F >> C;
    if (!std::cin)  // fin de la entrada
        return false;
    Mapa mapa(F);
    for (string& linea : mapa) {
        cin >> linea;
    }

    ManchasNegras manchas(mapa);
    cout << manchas.numero() << " " << manchas.maximo() << "\n";

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

