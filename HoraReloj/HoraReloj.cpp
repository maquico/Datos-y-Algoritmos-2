
#include "iostream"
#include "math.h"

using namespace std;

void Hora(int limite) {
	int hora, cuadrado;
	for (int i = 0; i < limite; i++)
	{
		int j = 0;
		for (j = 0; j < limite; j++)
		{
			hora = (i * 100) + j;
			cuadrado = i * i + j * j;
			if(hora==cuadrado) cout << hora << endl;
		}
	}
}

int main() {

	Hora(100);
	return 0;
}
