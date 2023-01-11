#include <iostream>
#include <string>
#include <conio.h>
#include <math.h>
#include <windows.h>
#include <cmath>


using namespace std;

void DescomponerEnPrimos(int n) {
	int divisor = 2;
	while (n > 1)
	{
		while (n%divisor == 0)
		{
			n = n / divisor;
			(n > 1) ? cout << divisor << "x" : cout << divisor;
			
		}
			divisor++; // siguiente primo
	}
}

int main()
{
	int numero;
	cout << "Introduzca su numero a descomponer:\n";
	cin >> numero;
	DescomponerEnPrimos(numero);
	return 0;
}

