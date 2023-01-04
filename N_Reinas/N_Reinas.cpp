/* ESTRUCTURAS DE DATOS Y ALGORITMOS II
* ENUNCIADO: PROBLEMA N REINAS
* ASUNTO: ESTE PROGRAMA ENCUENTRA LAS POSIBLES SOLUCIONES PARA EL PROBLEMA DE LAS N REINAS
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
#include <math.h>

using namespace std;

int cantSoluciones = 1;
int ValorAbsoluto (int n){
	if(n < 0){
		n = n * -1;
	}
	return n;
}

bool ValidarPosicion(int reinas[], int cantReinas, int nivel){
	int i;
	for(i=0; i<nivel; i++ ){
		if((reinas[i] == reinas[nivel]) || ( ValorAbsoluto(nivel-i) == ValorAbsoluto(reinas[nivel]-reinas[i]) )){
			return false;
		}
	}
	return true;
}

void LlenarArray (int reinas[], int cantReinas){
	for(int i =0 ;i < cantReinas; i++ ){
		reinas[i] = -1;
	}
}

void Nreinas(int reinas[], int cantReinas, int nivel){
	
	if(cantReinas == nivel){
		cout << "Solucion #" << cantSoluciones << " es: ";
		for(int i=0;i <cantReinas; i++ ){
			(i == cantReinas-1) ? cout << reinas[i] << "." : cout << reinas[i] << " , ";
		}
		cout << endl;
		cantSoluciones++;
	}
	else{
		for(reinas[nivel]=0; reinas[nivel]<cantReinas; reinas[nivel]++){
			if(ValidarPosicion(reinas,cantReinas, nivel)){
				Nreinas(reinas, cantReinas, nivel + 1);
			}
		}
	}

}

int main() {
	int nivelArbol = 0;
	int cantReinas = 0;
	
	cout << "Cuantas reinas?? \n";
	cin >> cantReinas;

	int* reinas = new int[cantReinas];
	LlenarArray(reinas, cantReinas);
	Nreinas(reinas, cantReinas, nivelArbol);

}