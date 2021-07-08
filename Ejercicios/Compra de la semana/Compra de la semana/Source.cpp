
// Roberto Torres Prensa

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;



struct Nodo {
	vector<bool> sol;
	int k; //La ultima posicion del vector ocupada
	int precio;
	double coste_est;
	bool operator<(Nodo const& otro) const {
		return otro.coste_est > coste_est;
	}
};

double calculo_voraz(vector<vector<int>> const& precios, double M, Nodo const& X) {
	double hueco = M - 1, coste_est = X.precio;
	int i = 0, j = X.k + 1;
	while (j < M && i <  &&  <= hueco) {
		if (precios[i][j] <= hueco) {
			hueco -= 1;
			coste_est += precios[i][j];
			j++;
		}

	}
	if (i < precios.size()) {
		coste_est += (hueco / precios[i][j]);
	}
	return coste_est;
}

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
void compras(vector<vector<int>> const& precios, double M, vector<bool>& sol_mejor, double& beneficio_mejor) {
    int N = precios.size();
    //se genera la raiz
    Nodo Y;
    Y.sol = vector<bool>(N);
    Y.k = -1;
    Y.precio = 0;
    Y.coste_est = calculo_voraz(precios, M, Y);
    priority_queue<Nodo> cola;
    cola.push(Y);
    beneficio_mejor = -1;
    while (!cola.empty() && cola.top().coste_est > beneficio_mejor) {
        Y = cola.top(); cola.pop();
        Nodo X(Y);
        X.k++;
        //Probamos 1er hijo meterlo en la primera cara
        if (Y.tiempoC + [X.k].duracion <= M) {
            X.sol[X.k] = true;
            X.tiempoC = Y.tiempoC + canciones[X.k].duracion;
            X.puntuacion = Y.puntuacion + canciones[X.k].puntuacion;
            X.puntuacion_est = Y.puntuacion_est;
            if (X.k == N - 1) {
                sol_mejor = X.sol; beneficio_mejor = X.puntuacion;
            }
            else cola.push(X);


        }
        //No meterla
        X.sol[X.k] = false;
        X.precio = Y.precio;
        X.coste_est = calculo_voraz(precios, M, X);
        if (X.coste_est > beneficio_mejor) {
            if (X.k == N - 1) {
                sol_mejor = X.sol; beneficio_mejor = X.precio;
            }
            else {
                cola.push(X);
            }
        }
    }
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	int numSupermercados, numProductos;
	cin >> numSupermercados >> numProductos;
	vector<vector<int>> productos(numSupermercados * numProductos);
	for (int i = 0; i < numSupermercados; i++) {
		for (int j = 0; j < numProductos; j++) {
			cin >> productos[i][j];
		}
	}

	// leer los datos de la entrada

	Solucion sol = resolver(datos);

	// escribir solución
}

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
