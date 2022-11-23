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

int main() {
	
	for (int i = 1; i < 100; i++)
	{
		int x = (100 - i);
		if (x % 6 ==0)
		{
			int floreros = x - 8;
			if (floreros%11 == 0)
			{
				cout << "Vendio: " << i << endl;
				cout << "Quedan: " << floreros << endl;
			}
		}
	}
	return 0;
}

