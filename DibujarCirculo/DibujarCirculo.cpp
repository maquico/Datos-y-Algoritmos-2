
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

int main() {
	//Imprime lindo hasta radio 19
	int radio;
	cout << "Inserte el radio del circulo:\n";
	cin >> radio;
	system("cls");
	DibujarCirculo(radio);
	_getch();
	return 0;
}