// TicTacToeConAlgoritmoEnConsola.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <windows.h>
#include <string>
#include <conio.h> 

using namespace std;
COORD posAmenazada;
int tablero[3][3] = { {0,0,0}, {0,0,0}, {0,0,0} };
bool partidaTerminada = false, botX=false;
int jugadas = 0;
char simboloOponente, simboloBot;

void GoToXY(int x, int y)
{//La función coloca el cursor para imprimir en el lugar que queramos.
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hCon, dwPos);
}

char ConvertirNumSimbolo(int num) {
	switch (num) {
	case 0:
		return ' ';
		break;
	case 1:
		return simboloOponente;
		break;
	case -1:
		return simboloBot;
		break;
	}
}

void TableroVisual() 
{
	system("cls");
	int posY = 2;
	int posX = 3;
	cout << " |-0-|-1-|-2-|\n";
	cout << "-|------------\n";
	cout << "0|   |   |   |\n";
	cout << "-|------------\n";
	cout << "1|   |   |   |\n";
	cout << "-|------------\n";
	cout << "2|   |   |   |\n";
		for (int i = 0; i < 3; i++){
			
			for(int j = 0; j<3; j++){
				
				GoToXY(posX, posY);
				posX += 4;
				cout << ConvertirNumSimbolo(tablero[i][j]);
			}
			posX = 3;
			posY = 2+((i + 1) * 2);
		}
}

void ColocarJugada (int posX, int posY, bool jugadaUsuario){
	(jugadaUsuario) ? tablero[posX][posY] = 1 : tablero[posX][posY] = -1;
	TableroVisual();
	jugadas++;
}

void JugadaBot() {
	if(jugadas == 0){
		ColocarJugada(1, 1, false);
	}
	else{
		HayAmenaza(1);
	}
}

int HayAmenaza(int n){
	
	
}

bool SumaFila(int n){
	int suma;
	for(int i = 0 ; i < 3 ;i++){
		suma = suma + tablero[n][i];
		if (tablero[n][i] == 0) {
			posAmenazada.X = n;
			posAmenazada.Y = i;
		}
	}
	if (suma == 2){
		return true;
		BuscarPosicionAmenazadaFila(n);
	}
	else {
		return false;
	}
}

void BuscarPosicionAmenazadaFila(int n){
	for (int i = 0; i < 3;i++) {
		if (tablero[n][i] == 0) {
			posAmenazada.X = n;
			posAmenazada.Y = i;
		}
	}
}

// fila1Amenazada = SumaFila(1); 
// for, 3 vulta, que  busque en la fila la posicion vacia

int main()
{
	int opcionSimbolo;
	cout << "Que simbolo quiere ser?:\n\n";
	cout << "1) X (Empieza)\n";
	cout << "2) O (Es Segundo)\n\n";
	cout << "Opcion Elegida: ";
	cin >> opcionSimbolo;

	if(opcionSimbolo == 1) {
		simboloBot = 'O';
		simboloOponente = 'X';
	}
	else 
	{
		botX = true;
		simboloBot = 'X';
		simboloOponente = 'O';
	}
	int posX, posY;
	do {

		TableroVisual();
		if (botX) {
			JugadaBot();
			botX = false;
		}
		else {
			cout << "\n\nIngrese la Posicion en X: ";
			cin >> posX;
			cout << "\nIngrese la Posicion en Y: ";
			cin >> posY;
			ColocarJugada(posX, posY, true);
			JugadaBot();
		}
	} while (jugadas != 9);
}

