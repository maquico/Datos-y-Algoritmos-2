/* LABORATORIO ESTRUCTURAS DE DATOS Y ALGORITMOS II
* ENUNCIADO: TAREA TRIANGULO
* ASUNTO: ESTE PROGRAMA GENERA UN FRACTAL
AUTORES: ANGEL MORENO ID:1104666
*        GLEIDY ESPINAL ID:1104225
*        ALLEN SILVERIO ID:1104220
*        CRISTIAN JIMÉNEZ ID:1106166
*        WILLIAM FERREIRA ID:1104228
* FECHA: 22/12/2022
*/
#include <iostream> 
#include <string>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <graphics.h>
using namespace std;

COORD punto1, punto2, punto3;

void MoverPuntoExterior(int opcion, COORD& puntoExterior) {

	switch (opcion)
	{
	case 1:
		puntoExterior.X = (puntoExterior.X + punto1.X) / 2;
		puntoExterior.Y = (puntoExterior.Y + punto1.Y) / 2;
		break;
	case 2:
		puntoExterior.X = (puntoExterior.X + punto2.X) / 2;
		puntoExterior.Y = (puntoExterior.Y + punto2.Y) / 2;
		break;
	case 3:
		puntoExterior.X = (puntoExterior.X + punto3.X) / 2;
		puntoExterior.Y = (puntoExterior.Y + punto3.Y) / 2;
		break;
	}
}

int main() {
	srand(time(NULL));

	punto1.X = 400;
	punto1.Y = 200;
	punto2.X = 200;
	punto2.Y = 400;
	punto3.X = 600;
	punto3.Y = 400;

	int gd = DETECT, gm;
	initwindow(1300, 700);

	putpixel(punto1.X, punto1.Y, YELLOW);
	putpixel(punto2.X, punto2.Y, YELLOW);
	putpixel(punto3.X, punto3.Y, YELLOW);


	COORD puntoExterior;
	puntoExterior.X = 500;
	puntoExterior.Y = 500;

	for (int i = 0; i < 3000; i++)
	{
		int random = (rand() % 3) + 1;
		putpixel(puntoExterior.X, puntoExterior.Y, YELLOW);
		MoverPuntoExterior(random, puntoExterior);
	}
	_getch();
	closegraph();
	return 0;
}