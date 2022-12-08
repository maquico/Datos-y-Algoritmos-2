/* ESTRUCTURAS DE DATOS Y ALGORITMOS II
* ENUNCIADO: CADENA MAS LARGA
* ASUNTO: ESTE PROGRAMA RESUELVE EL PROBLEMA DE LA CADENA MAS LARGA DE ENTRE 1 Y 99
AUTORES: ANGEL MORENO ID:1104666
*        GLEIDY ESPINAL ID:1104225
*        ALLEN SILVERIO ID:1104220
*        CRISTIAN JIMÉNEZ ID:1106166
*        WILLIAM FERREIRA ID:1104228
* FECHA: 24/11/2022
*/
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
	cout << "El numero de pasos es:" << CadenaMasLarga(97, 0);

	return 0;

}
