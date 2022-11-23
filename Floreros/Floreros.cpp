/* ESTRUCTURAS DE DATOS Y ALGORITMOS II
* ENUNCIADO: LOS FLOREROS DE SALVADOR
* ASUNTO: ESTE PROGRAMA RESUELVE EL PROBLEMA DE LOS FLOREROS DE SALVADOR
AUTORES: ANGEL MORENO ID:1104666
*        GLEIDY ESPINAL ID:1104225
*        ALLEN SILVERIO ID:1104220
*        CRISTIAN JIMÉNEZ ID:1106166
*        WILLIAM FERREIRA ID:1104228
* FECHA: 24/11/2022
*/
#include "iostream"
#include "math.h"

using namespace std;

int floreros(int i, int limite) {
	if (i == limite)
	{
		return 0;
	}
	else
	{
		int x = 100 - i;
		if (x%6 == 0)
		{
			int floreros = x - 8;
			if (floreros%11==0)
			{
				cout << "Vendio: " << i << endl;
				cout << "Quedan: " << floreros << endl;
			}
		}
		floreros(i + 1, limite);
	}
}

int main() {

	floreros(1, 100);
	return 0;
}

