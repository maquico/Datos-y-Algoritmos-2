/* ESTRUCTURAS DE DATOS Y ALGORITMOS II
* ENUNCIADO: TAREA 3 MOCHILA CARGADA
* ASUNTO: ESTE PROGRAMA CALCULA EL MAXIMO DE BENEFICIO SIN PASAR EL LIMITE DE PESO DE UNA MOCHILA
AUTORES: ANGEL MORENO ID:1104666
*        GLEIDY ESPINAL ID:1104225
*        ALLEN SILVERIO ID:1104220
*        CRISTIAN JIMÉNEZ ID:1106166
*        WILLIAM FERREIRA ID:1104228
* FECHA: 15/12/2022
*/
#include <iostream> 
#include <string>
#include <conio.h>
#include <math.h>
#include <windows.h>
#include <cmath>

using namespace std;


float pesos[5] = {10, 20, 30, 40, 50};
float beneficio[5] = { 20, 30, 65, 40, 60 };
float beneficiosPorKilo[5] = { 0,0,0,0,0 };

void CalcularBeneficioPorKilo() {
	for (int i = 0; i < 5; i++)
	{
		float beneficioEntrePeso = beneficio[i] / pesos[i];
		beneficiosPorKilo[i] = beneficioEntrePeso;
}



int main() {
	
	CalcularBeneficioPorKilo();
	return 0;
}