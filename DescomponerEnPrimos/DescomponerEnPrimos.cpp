#include <iostream>
#include <string>
#include <conio.h>
#include <math.h>
#include <windows.h>
#include <cmath>


using namespace std;

bool EsPrimo(float n) {
	//int raiz = pow(0.5, n);
	int contador=0;
	int num = int(n);
	for (int i = 1; i <= n && contador < 3; i++)
	{
		if (num%i==0)
		{
			contador++;
		}
	}
	if (contador > 2)
	{
		return false;
	}
	else
	{
		return true;
	}
}

int SiguientePrimo(int n) {

	int p = n + 1, d = 2;

	while (d < p)
	{
		if (p%d == 0)
		{
			return SiguientePrimo(n + 1);
			d++;
		}
	}
	return p;
}

void DescomponerEnPrimos(int n) {
	int divisor = 2;
	while (divisor < n)
	{
		if (n%divisor == 0)
		{
			cout << divisor << "x";
			n = n / divisor;
		}
		else
		{
			divisor = SiguientePrimo(divisor); // siguiente primo
		}
	}
	cout << divisor;
}




int main()
{
	DescomponerEnPrimos(52);
	return 0;
}

