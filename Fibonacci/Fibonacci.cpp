#include "iostream"
#include "math.h"

using namespace std;

int fibonacci(int serieAnterior, int serie, int n) {
	int aux = 0;
	if (n == 0)
	{
		return serieAnterior;
	}
	else {
		aux = serie;
		serie = serieAnterior + serie;
		fibonacci(aux, serie, n - 1);
	}
}

int main() {

	cout << fibonacci(0, 1, 5);
	return 0;
}

