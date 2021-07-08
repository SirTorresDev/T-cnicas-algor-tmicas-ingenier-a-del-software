// Roberto Torres Prensa


// Construye un árbol binario a partir de la entrada y después
// calcula de forma recursiva su altura
// O(N)

// versión con extensión de la clase bintree del TAD dado en clase (Alberto Verdejo)

#include <fstream>
#include <iostream>
#include <cmath>

#include "bintree_eda.h"
using namespace std;

struct tSolucion {
	int altura = 0;
	bool equilibrado = true;
};

tSolucion esAVL(bintree<int> arbol) {
	tSolucion solucion, der, izq;

	if (!arbol.empty()) {
		der.altura++;
		der = esAVL(arbol.right());
		izq.altura++;
		izq = esAVL(arbol.left());
		
	

		if (abs(der.altura - izq.altura) <= 1 && (der.equilibrado && izq.equilibrado)) {
			if (!arbol.left().empty()) {
				if (arbol.root() < arbol.left().root()) {
					solucion.equilibrado = false;
				}
				else {
					solucion.equilibrado = true;
				}
			}
			else if (!arbol.right().empty()) {
				if (arbol.root() > arbol.right().root()) {
					solucion.equilibrado = false;
				}
				else {
					solucion.equilibrado = true;
				}
			}
			else {
				solucion.equilibrado = true;
			}
		}
		else {
			solucion.equilibrado = false;
		}
		solucion.altura = 1 + max(der.altura, izq.altura);
	}

	return solucion;
	
}

void resuelveCaso() {
	tSolucion sol;
	int elemento = -1;
	bintree<int> arbol;
	arbol = leerArbol(elemento);
	sol = esAVL(arbol);
	if (sol.equilibrado) cout << "SI" << endl;
	else cout << "NO" << endl;
}



int main() {
	// Para la entrada por fichero.
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif


	unsigned int numCasos;
	std::cin >> numCasos;
	// Resolvemos
	for (int i = 0; i < numCasos; ++i) {
		resuelveCaso();
	}


#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}
