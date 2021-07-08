
// Roberto Torres Prensa

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <string>
#include "bintree_eda.h"
using namespace std;

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
bool esAVL(bintree<int> const tree, int &altura,  int maximo, int minimo) {
	bool left, right;
	if (tree.empty())
		return true;
	
	altura++;

	if (tree.root() < minimo || tree.root() > maximo) {
		return false;
	}
	
	int alturaIzq = altura;
	left = esAVL(tree.left(), alturaIzq, tree.root() - 1, minimo);
	int alturaDer = altura;
	right = esAVL(tree.right(), alturaDer, maximo, tree.root() + 1);

	if (abs(alturaDer - alturaIzq) <= 1 && left && right) {
		altura = max(alturaDer, alturaIzq);
		return true;
	}

	return false;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	bintree<int> tree = leerArbol(-1);
	// leer los datos de la entrada
	int altura = 0, minimo = -1, maximo = 10000;

	bool sol = esAVL(tree,altura,maximo,minimo);

	// escribir solución

	if (sol)
		cout << "SI" << endl;
	else
	{
		cout << "NO" << endl;
	}
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
