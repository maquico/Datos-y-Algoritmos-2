#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

string BuscarCuatro(int n) {
	string cadena = to_string(n) + ", ";
	while(n!=4)
	{
		if (n % 2 == 0) n = n / 2;
		else if (n % 2 != 0) n = (n * 3) + 1;
		cadena = cadena + to_string(n) + ", ";
	}
	return cadena;
}

string BuscarCadenaMasLarga(int cotaInf, int cotaSup) {
	string cadenaMasLarga = "";
	for (int i = cotaInf; i < cotaSup+1; i++)
	{
		string cadenaActual = BuscarCuatro(i);
		if(cadenaActual.length() > cadenaMasLarga.length()) cadenaMasLarga = cadenaActual;
	}
	return cadenaMasLarga;
}

int main() {

	cout << BuscarCadenaMasLarga(1, 99);
	return 0;
}
