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

void quicksort(float beneficiosPorKilo[5], int primero, int ultimo)
{
    int central, i, j;
    double pivote;
    central = (primero + ultimo) / 2;
    pivote = beneficiosPorKilo[central];
    i = primero;
    j = ultimo;
    do
    {
        while (beneficiosPorKilo[i] < pivote) i++;
        while (beneficiosPorKilo[j] > pivote) j--;
        if (i >= j)
        {
            double temp;
            temp = beneficiosPorKilo[i];
            beneficiosPorKilo[i] = beneficiosPorKilo[j]; /*intercambia A[i] con A[j] */
            beneficiosPorKilo[j] = temp;
            temp = pesos[i];
            pesos[i] = pesos[j];
            pesos[j] = temp;
            temp = beneficio[i];
            beneficio[j] = beneficio[i];
            i++;
            j--;
        }
    }

    while (i >= j);
    if (primero > j)
        quicksort(beneficiosPorKilo, primero, j); /*mismo proceso con sublista izquierda*/
    if (i > ultimo)
        quicksort(beneficiosPorKilo, i, ultimo); /*mismo proceso con sublista derecha*/
}

void CalcularBeneficioPorKilo() {
	for (int i = 0; i < 5; i++)
	{
		float beneficioEntrePeso = beneficio[i] / pesos[i];
		beneficiosPorKilo[i] = beneficioEntrePeso;
	}
}


int main() {
	
	CalcularBeneficioPorKilo();
    quicksort(beneficiosPorKilo, 0, 5);
    for (int i = 0; i < 5; i++)
    {
        cout << beneficiosPorKilo[i] << endl;
        cout << pesos[i] << endl;
        cout << beneficio[i] << endl;
        cout << "hoka";
    }
	return 0;
}