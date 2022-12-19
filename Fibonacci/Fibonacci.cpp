#include "iostream"
#include "math.h"

using namespace std;

int Fibonacci(int serieAnterior, int serie, int n) {
	int aux = 0;
		if (n == 0)
		{
			return serieAnterior;
		}
		else {
			aux = serie;
			serie = serieAnterior + serie;
			Fibonacci(aux, serie, n - 1);
		}
}
int EsFibonacci(int serieAnt, int serie, int n) {
	int aux = 0;
	if (n >= serieAnt)
	{
		if (serie == n || serieAnt==n) {
			cout << "Exito " << n << " forma parte de la serie de fibonacci\n";
			return serie;
		}
		else
		{
			aux = serie;
			serie = serieAnt + serie;
			EsFibonacci(aux, serie, n);
		}
	}
	else {
		cout << "No aparecio broki\n";
		return serie;
	}
}
int main() {

	cout << "\n\n *--* Funcion que dice si un numero pertenece a la serie y el ultimo elemento de la serie que calculo *--* \n\n";
	EsFibonacci(0, 1, 8);
	EsFibonacci(0, 1, 1597);
	EsFibonacci(0, 1, 6);
	/*cout << "\n\n *--* Funcion que devuelve el numero de la serie de fibonacci en la posicion solicitada *--* \n\n";
	int posicion = 0;
	cout << "El numero en la posicion " << posicion << " es: " << Fibonacci(0, 1, posicion);
	cout << "El numero en la posicion " << posicion + 8 << " es: " << Fibonacci(0, 1, posicion + 8);*/
	return 0;
}

