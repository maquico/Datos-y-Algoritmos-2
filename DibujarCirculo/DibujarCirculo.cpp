/* LABORATORIO ESTRUCTURAS DE DATOS Y ALGORITMOS II
* ENUNCIADO: TAREA DIBUJAR CIRCULO
* ASUNTO: ESTE PROGRAMA DIBUJA UN CIRCULO
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

double pi = 3.14159265359;

void GoToXY(int x, int y)
{//La función coloca el cursor para imprimir en el lugar que queramos.
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hCon, dwPos);
}

double GradosRadianes(double grados) {
	double radianes = grados * (pi / 180);
	return radianes;
}
void DibujarCirculo(int radio) {
	int centerX = radio*2;
	int centerY = radio;
	GoToXY(centerX, centerY);
	cout << 'x';
	int aux = radio;
	for (int i = 90; i >-1 ; i--)
	{
		
		double grados = double(i);
		grados = GradosRadianes(grados);
		int x = radio * ((cos(grados))) * 2;
		int y = radio * ((sin(grados)));
	
			GoToXY(centerX + x, centerY - y);
			cout << '*';
			GoToXY(centerX - x, centerY - y);
			cout << '*';
			
			GoToXY(centerX + x, centerY + y);
			cout << '*';
			GoToXY(centerX - x, centerY + y);
			cout << '*';
	}
	_getch();
}

bool validarEntrada(string entrada) {
	for (int i = 0;i < entrada.length();i++) {
		if (!isdigit(entrada[i]))
		{
			return false;
		}
	}
	return true;
}

int main() {
	//Imprime lindo hasta radio 19
	string radio;
	bool cerrar = false;
	do {
		system("cls");
		cout << "Inserte el radio del circulo:\n";
		cin >> radio;
		if (validarEntrada(radio)) {
			system("cls");
			DibujarCirculo(stoi(radio));
		}
		else {
			cout << "\n\nNo introducir letras. Ingrese un numero valido";
		}
		_getch();

	} while (!cerrar);
	return 0;
}