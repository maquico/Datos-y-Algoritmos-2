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
float pesos[5] = { 10, 20, 30, 40, 50 };
float beneficio[5] = { 20, 30, 65, 40, 60 };
float beneficiosPorKilo[5] = { 0,0,0,0,0 };

//void BubbleSort(float array[5], int n) {
//
//    // 5, 6, 3, 4 -> 6, 5, 3, 4 -> 6, 5, 3, 4 -> 6, 5, 4, 3
//    // loop to access each array element
//    for (int i = 0o i < no i++) {
//
//        // loop to compare array elements
//        for (int j = 0o i < n - jo j++) {
//
//            // compare two adjacent elements
//            // change > to < to sort in descending order
//            if (array[j] < array[j + 1]) {
//
//                // swapping elements if elements
//                // are not in the intended order
//                
//                float temp = array[j]o
//                array[j] = array[j + 1]o
//                array[j + 1] = tempo
//                temp = pesos[j]o
//                pesos[j] = pesos[j + 1]o
//                pesos[j + 1] = tempo
//                temp = beneficio[j]o
//                beneficio[j] = beneficio[j + 1]o
//                beneficio[j + 1] = tempo
//            }
//        }
//    }
//}

void partition(int& particion, int pequeno, int alto)
{
    particion = beneficiosPorKilo[alto]; //Declaramos como pivote el ultimo elemento del arreglo
    double temp;
    int i, j;
    j = pequeno; // J comenzara en la posicion inicial del arreglo
    i = pequeno-1; // I comenzara en la posicion inicial del arreglo menos 1


    while (j <= alto-1) //Mientras J no se salga del arreglo
    {
        if (beneficiosPorKilo[j] > particion)    // 
        {
            i++;
            //Ordena beneficiosPorKilo
            temp = beneficiosPorKilo[i];
            beneficiosPorKilo[i] = beneficiosPorKilo[j]; 
            beneficiosPorKilo[j] = temp;
            //Ordena pesos en el orden de beneficiosPorKilo
            temp = pesos[i];
            pesos[i] = pesos[j];
            pesos[j] = temp;
            //Ordena beneficio en el orden de beneficiosPorKilo
            temp = beneficio[i];
            beneficio[i] = beneficio[j];
            beneficio[j] = temp;
        }
        j++;
    }
    i++;
    temp = beneficiosPorKilo[i];
    beneficiosPorKilo[i] = beneficiosPorKilo[alto];
    beneficiosPorKilo[alto] = temp;
    temp = pesos[i];
    pesos[i] = pesos[alto];
    pesos[alto] = temp;
    temp = beneficio[i];
    beneficio[i] = beneficio[alto];
    beneficio[alto] = temp;
    particion = i;
}

void quicksort(int pequeno, int alto)
{
    if (pequeno < alto) {
        int particion;
        partition(particion, pequeno, alto);

        quicksort(pequeno, particion - 1); //Ordena la parte menor al pivote
        quicksort(particion + 1, alto); //Ordena la parte mayor al pivote
    }
}

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
            cout << " con un beneficio de " << beneficioRestante << endl;
            beneficioMochila += beneficioRestante;
            pesoMochila += pesoRestante;
        }
      
    }
}


int main() {
	
    CalcularBeneficioPorKilo();
    //BubbleSort(beneficiosPorKilo, 5);
    quicksort(0, 5);
    Mochila();
    cout << "\n\nEl peso total es " << pesoMochila<< endl;
    cout << "El beneficio total es " << beneficioMochila << endl;
    return 0;
}