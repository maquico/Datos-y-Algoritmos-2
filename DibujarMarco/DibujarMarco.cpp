/* LABORATORIO ESTRUCTURAS DE DATOS Y ALGORITMOS II
* ENUNCIADO: TAREA DIBUJAR MARCO
* ASUNTO: ESTE PROGRAMA DIBUJA UN MARCO
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

int figuras[6] = { 201, 205, 187, 186, 188, 200 };
char figura;

void GoToXY(int x, int y)
{//La función coloca el cursor para imprimir en el lugar que queramos.
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hCon, dwPos);
}

void DibujarLinea1(int nVueltas, int posicionX, int posicionY) {
	for (int i = 0; i < nVueltas; i++)
	{
		GoToXY(posicionX, posicionY);
		figura = (char)figuras[1];
		cout << figura;
		Sleep(5);
		posicionX += 1;
	}
}

void DibujarLinea2(int nVueltas, int posicionX, int posicionY) {
	for (int i = 0; i < nVueltas; i++)
	{
		GoToXY(posicionX, posicionY);
		figura = (char)figuras[1];
		cout << figura;
		Sleep(5);
		posicionX -= 1;
	}
}

void DibujarLineaVert(int nVueltas, int posicionX, int posicionY) {
	for (int i = 0; i < nVueltas; i++)
	{
		GoToXY(posicionX, posicionY);
		figura = (char)figuras[3];
		cout << figura;
		Sleep(5);
		posicionY += 1;
	}
}

void DibujarLineaVert2(int nVueltas, int posicionX, int posicionY) {
	for (int i = 0; i < nVueltas; i++)
	{
		GoToXY(posicionX, posicionY);
		figura = (char)figuras[3];
		cout << figura;
		Sleep(5);
		posicionY -= 1;
	}
}

int main() {
	
	int posicionX = 1;
	int posicionY = 0;
	string titulo = "Estructuras de Datos y Algoritmos II";
	

	figura = (char)figuras[0];
	cout << figura;
	DibujarLinea1(78, 1, 0);
	
	figura = (char)figuras[2];
	cout << figura;
	DibujarLineaVert(23, 79, 1);

	GoToXY(79, 24);
	figura = (char)figuras[4];
	cout << figura;
	DibujarLinea2(78, 78, 24);

	GoToXY(0, 24);
	figura = (char)figuras[5];
	cout << figura;

	DibujarLineaVert2(23, 0, 23);

	GoToXY((80 - titulo.length())/2, 24/2);
	cout << titulo;
	GoToXY(0, 31);

	
}