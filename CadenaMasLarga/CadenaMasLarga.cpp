#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

int CadenaMasLarga(int n, int pasos) {
	if (n == 4) return pasos;
	else if (n % 2 == 0) n = n / 2;
	else  n = (n * 3) + 1;
	return CadenaMasLarga(n, pasos + 1);
}

int main() {
	int mayorCadena = 0;
	for (int i = 1; i < 100; i++)
	{
		if (CadenaMasLarga(i, 0) > mayorCadena) mayorCadena = i;
	}
	cout << "El numero con la mayor cadena es: " << mayorCadena;

	return 0;
}
