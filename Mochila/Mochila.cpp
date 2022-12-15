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

float pesoMochila = 0;
float beneficioMochila = 0;
float pesos[5] = {10, 20, 30, 40, 50};
float beneficio[5] = { 20, 30, 65, 40, 60 };
float beneficiosPorKilo[5] = { 0,0,0,0,0 };

// Bubble sort in C++

#include <iostream>
using namespace std;

// perform bubble sort
void BubbleSort(float array[5], int n) {

    // 5, 6, 3, 4 -> 6, 5, 3, 4 -> 6, 5, 3, 4 -> 6, 5, 4, 3
    // loop to access each array element
    for (int i = 0; i < n; i++) {

        // loop to compare array elements
        for (int j = 0; i < n - j; j++) {

            // compare two adjacent elements
            // change > to < to sort in descending order
            if (array[j] < array[j + 1]) {

                // swapping elements if elements
                // are not in the intended order
                
                float temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                temp = pesos[j];
                pesos[j] = pesos[j + 1];
                pesos[j + 1] = temp;
                temp = beneficio[j];
                beneficio[j] = beneficio[j + 1];
                beneficio[j + 1] = temp;
            }
        }
    }
}
//void quicksort(float beneficiosPorKilo[5], int primero, int ultimo)
//{
//    int central, i, j;
//    double pivote;
//    central = (primero + ultimo) / 2;
//    pivote = beneficiosPorKilo[central];
//    i = primero;
//    j = ultimo;
//    do
//    {
//        while (beneficiosPorKilo[i] < pivote) i++;
//        while (beneficiosPorKilo[j] > pivote) j--;
//        if (i >= j)
//        {
//            double temp;
//            temp = beneficiosPorKilo[i];
//            beneficiosPorKilo[i] = beneficiosPorKilo[j]; /*intercambia A[i] con A[j] */
//            beneficiosPorKilo[j] = temp;
//            temp = pesos[i];
//            pesos[i] = pesos[j];
//            pesos[j] = temp;
//            temp = beneficio[i];
//            beneficio[j] = beneficio[i];
//            i++;
//            j--;
//        }
//    }
//
//    while (i >= j);
//    if (primero > j)
//        quicksort(beneficiosPorKilo, primero, j); /*mismo proceso con sublista izquierda*/
//    if (i > ultimo)
//        quicksort(beneficiosPorKilo, i, ultimo); /*mismo proceso con sublista derecha*/
//}

void CalcularBeneficioPorKilo() {

	for (int i = 0; i < 5; i++)
	{
		float beneficioEntrePeso = beneficio[i] / pesos[i];
		beneficiosPorKilo[i] = beneficioEntrePeso;
	}
    
}

void Mochila() 
{
    for (int i = 0; pesoMochila < 100; i++) 
    {
        if (pesoMochila + pesos[i] < 100) 
        {
            beneficioMochila += beneficio[i];
            pesoMochila += pesos[i];
            cout << "Se agrega el paquete que pesa " << pesos[i] << " Kilogramos, con un beneficio de " << beneficio[i] << endl;
        }
        else 
        {
            float beneficioRestante = 0;
            float pesoRestante = 0;

            pesoRestante = (100 - pesoMochila);
            beneficioRestante = pesoRestante / pesos[i];
            cout << "Se agrega el " << beneficioRestante * 100 << " porciento, del objeto que pesa " << pesos[i] << " kilogramos, ";
            beneficioRestante *= beneficio[i];
            cout<<" con un beneficio de " << beneficioRestante <<endl;
            beneficioMochila += beneficioRestante;
            pesoMochila += pesoRestante;
        }
      
    }
}


int main() {
	
	CalcularBeneficioPorKilo();
    BubbleSort(beneficiosPorKilo, 5);
    Mochila();
    cout << "\n\nEl peso total es " << pesoMochila<< endl;
    cout << "El beneficio total es " << beneficioMochila << endl;
	return 0;
}