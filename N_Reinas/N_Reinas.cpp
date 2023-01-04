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
#include <windows.h>

using namespace std;
int cantSoluciones = 1;
HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE);//Obtenemos la salida estandar (CONSOLA)

void GoToXY(int x, int y)
{//La función coloca el cursor para imprimir en el lugar que queramos.
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hconsole, dwPos);
}

void disenoMenu() {
	GoToXY(32, 6);
	SetConsoleTextAttribute(hconsole, 13);
	cout << "*------------------------------------------------*";
	GoToXY(32, 7);
	cout << "|";
	SetConsoleTextAttribute(hconsole, 11);
	cout << "            Problema de las N REINAS            ";
	SetConsoleTextAttribute(hconsole, 13);
	cout << "|";
	GoToXY(32, 8);
	cout << "*------------------------------------------------*";
	
	SetConsoleTextAttribute(hconsole, 6);
	GoToXY(30, 10);
	cout << "Bienvenido al problema de las N reinas. Este problema";
	GoToXY(30, 11);
	cout << "consiste en encontrar una forma de acomodar N reinas";
	GoToXY(30, 12);
	cout << "en un tablero NxN, de forma tal que no se maten.";

	SetConsoleTextAttribute(hconsole, 7);
	GoToXY(35, 14);
	cout << "Las opciones del menu sin las siguientes:";
	SetConsoleTextAttribute(hconsole, 2);
	GoToXY(42, 16);
	cout << "1) ";
	SetConsoleTextAttribute(hconsole, 7);
	cout << "Calcular las Soluciones.";
	SetConsoleTextAttribute(hconsole, 12);
	GoToXY(50, 17);
	cout << "0) ";
	SetConsoleTextAttribute(hconsole, 7);
	cout << "Salir";
	GoToXY(40, 19);
	SetConsoleTextAttribute(hconsole, 11);
	cout << "*--------------------------*";
	GoToXY(40, 20);
	cout << "|";
	SetConsoleTextAttribute(hconsole, 7);
	cout << "     Opcion Elegida:      ";
	SetConsoleTextAttribute(hconsole, 11);
	cout << "|";
	GoToXY(40, 21);
	cout << "*--------------------------*";
	GoToXY(62, 20);
	SetConsoleTextAttribute(hconsole, 7);
}
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

bool validarEntrada(string entrada) {
	for (int i = 0;i < entrada.length();i++){
		if (!isdigit(entrada[i]))
		{
			return false;
		}
}
	return true;
}

int main() {
	int nivelArbol = 0;
	int cantReinas;
	string numReinas;
	bool cerrar = false;
	string opcion;

	do {
		system("CLS");
		disenoMenu();
		cin >> opcion;

		if (validarEntrada(opcion))
		{
			switch (stoi(opcion)) {
			case 1:
				system("CLS");
				GoToXY(30, 10);
				SetConsoleTextAttribute(hconsole, 11);
				cout << "*---------------------------------------------*";
				GoToXY(30, 11);
				cout << "|";
				SetConsoleTextAttribute(hconsole, 7);
				cout << "      Ingrese la cantidad de Reinas:         ";
				SetConsoleTextAttribute(hconsole, 11);
				cout << "|";
				GoToXY(30, 12);
				cout << "*---------------------------------------------*";
				GoToXY(68, 11);
				SetConsoleTextAttribute(hconsole, 7);
				cin >> numReinas;

				if (validarEntrada(numReinas))
				{
					system("CLS");
					cantReinas = stoi(numReinas);
					int* reinas = new int[cantReinas];
					LlenarArray(reinas, cantReinas);
					Nreinas(reinas, cantReinas, nivelArbol);
					_getch();
				}
				else
				{
					GoToXY(30, 14);
					SetConsoleTextAttribute(hconsole, 12);
					cout << "El valor ingresado no es valido. Reintente";
					SetConsoleTextAttribute(hconsole, 7);
					_getch();
				}
				break;
			case 0:
				cerrar = true;
				system("CLS");
				GoToXY(40, 10);
				SetConsoleTextAttribute(hconsole, 11);
				cout << "*-----------------------*";
				GoToXY(40, 11);
				cout << "|";
				SetConsoleTextAttribute(hconsole, 12);
				cout << "        Cerrando       ";
				SetConsoleTextAttribute(hconsole, 11);
				cout << "|";
				GoToXY(40, 12);
				cout << "*-----------------------*";
				SetConsoleTextAttribute(hconsole, 7);
				break;
			}
		}

	} while (!cerrar);

}