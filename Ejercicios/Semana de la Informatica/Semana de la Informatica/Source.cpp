
// Roberto Torres Prensa
// TAIS84

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include "PriorityQueue.h"

using namespace std;

struct actividades {
	int ini;
	int fin;	
};

bool operator<(actividades op1, actividades op2) {
	return op1.ini < op2.ini || (op1.ini == op2.ini && op1.fin < op2.fin);
}

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
int resolver(vector<actividades> &lista) {
	sort(lista.begin(), lista.end());
	int compis = 0, i = 1, j = 0;
	PriorityQueue<int> finales;
	actividades a = lista[0];
	finales.push(a.fin);

	for (int i = 1; i < lista.size(); i++) {
		a = lista[i];

		if (finales.top() > a.ini) {
			compis++;
			finales.push(a.fin);
		}
		else {
			finales.pop();
			finales.push(a.fin);
		}
	}
	return compis;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

	// leer los datos de la entrada
	int numActividades;
	cin >> numActividades;
	if (numActividades == 0) {
		return false;
	}


	vector<actividades> lista(numActividades);

	for (int i = 0; i < numActividades; i++) {
		cin >> lista[i].ini >> lista[i].fin;
	}

	

	int sol = resolver(lista);

	cout << sol << "\n";

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
