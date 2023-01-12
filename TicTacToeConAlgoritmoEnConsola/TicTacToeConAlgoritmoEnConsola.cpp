// TicTacToeConAlgoritmoEnConsola.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <windows.h>
#include <string>
#include <conio.h> 

using namespace std;
COORD posAmenazada;
int dimension = 3;
int bot = 1;
int oponente = 0;
char tablero[3][3] = { {' ',' ',' '}, {' ',' ',' '}, {' ',' ',' '} };
bool partidaTerminada = false, botX=false;
int jugadas = 0;
char simboloOponente, simboloBot;
int posXbot, posYbot;

//#define DIMENSION 3;

void GoToXY(int x, int y)
{//La función coloca el cursor para imprimir en el lugar que queramos.
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hCon, dwPos);
}
//
//char ConvertirNumSimbolo(int num) {
//	switch (num) {
//	case 0:
//		return ' ';
//		break;
//	case 1:
//		return simboloOponente;
//		break;
//	case -1:
//		return simboloBot;
//		break;
//	}
//}

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
				cout << (tablero[i][j]);
			}
			posX = 3;
			posY = 2+((i + 1) * 2);
		}
}

//void ColocarJugada (int posX, int posY, bool jugadaUsuario){
//	(jugadaUsuario) ? tablero[posX][posY] = simboloOponente : tablero[posX][posY] = -1;
//	TableroVisual();
//	jugadas++;
//}

void Borrar(char tablero[3][3])
{
	// Initially the board is empty 
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < SIDE; j++)
			tablero[i][j] = ' ';
	}
}

bool RevisarFilas(char tablero[][3])
{
	for (int i = 0; i < 3; i++)
	{
		if (tablero[i][0] == tablero[i][1] && tablero[i][1] == tablero[i][2] && tablero[i][0] != ' ') return true;	
	}
	return false;
}

bool RevisarColumnas(char tablero[][3])
{
	for (int i = 0; i < 3; i++)
	{
		if (tablero[0][i] == tablero[1][i] && tablero[1][i] == tablero[2][i] && tablero[0][i] != ' ') return true;
	}
	return false;
}

bool RevisarDiagonales(char tablero[][3])
{
	if (tablero[0][0] == tablero[1][1] && tablero[1][1] == tablero[2][2] && tablero[0][0] != ' ') return true;

	if (tablero[0][2] == tablero[1][1] && tablero[1][1] == tablero[2][0] && tablero[0][2] != ' ') return true;

	return false;
}


bool HayVictoria(char tablero[3][3]) {
	return (RevisarDiagonales(tablero) || RevisarColumnas(tablero) || RevisarFilas(tablero));
}

void Ganador(int Turno)
{
	if (Turno == bot)
		printf("La COMPUTADORA ha ganado\n");
	else
		printf("El HUMANO ha ganado\n");
}


int minimax(char tablero[3][3], int profundidad, bool esBot)
{
	int puntuacion = 0;
	int mejorPuntuacion = 0;
	if (HayVictoria(tablero)) //CAMBIAR A GAME OVER(BOARD)
	{
		if (esBot == true)
			return -1;
		if (esBot == false)
			return +1;
	}
	else
	{
		if (profundidad < 9)
		{
			if (esBot == true)
			{
				mejorPuntuacion = -999;
				for (int i = 0; i < 3; i++)
				{
					for (int j = 0; j < 3; j++)
					{
						if (tablero[i][j] == ' ')
						{
							tablero[i][j] = simboloBot;
							puntuacion = minimax(tablero, profundidad + 1, false);
							tablero[i][j] = ' ';
							if (puntuacion > mejorPuntuacion)
							{
								mejorPuntuacion = puntuacion;
							}
						}
					}
				}
				return mejorPuntuacion;
			}
			else
			{
				mejorPuntuacion = 999;
				for (int i = 0; i < 3; i++)
				{
					for (int j = 0; j < 3; j++)
					{
						if (tablero[i][j] == ' ')
						{
							tablero[i][j] = simboloOponente;
							puntuacion = minimax(tablero, profundidad + 1, true);
							tablero[i][j] = ' ';
							if (puntuacion < mejorPuntuacion)
							{
								mejorPuntuacion = puntuacion;
							}
						}
					}
				}
				return mejorPuntuacion;
			}
		}
		else
		{
			return 0;
		}
	}
}

// Function to calculate best move
void MejorMovimiento(char tablero[3][3], int jugada)
{
	int x = -1, y = -1;
	int puntuacion = 0, mejorPuntuacion = -999;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (tablero[i][j] == ' ')
			{
				tablero[i][j] = simboloBot;
				puntuacion = minimax(tablero, jugada+1, false);
				tablero[i][j] = ' ';
				if(puntuacion > mejorPuntuacion)
				{
					mejorPuntuacion = puntuacion;
					x = i;
					y = j;
				}
			}
		}
	}
	posXbot = x;
	posYbot = y;
}

void jugar(int turno)
{
	int posX, posY;
	/*char tablero[3][3];*/
	int jugadas = 0; /*x = 0, y = 0;*/

	TableroVisual();

	while (HayVictoria(tablero) == false && jugadas != 9)
	{
		//int n;
		if (turno == bot)
		{
			//n = MejorMovimiento(tablero, jugadas);
			//x = n / 3;
			//y = n % 3;
			MejorMovimiento(tablero, jugadas);
			tablero[posXbot][posYbot] = simboloBot;
			GoToXY(20,20);
			cout << "COMPUTER has put a " << simboloBot << "in cell [" << posXbot << "," << posYbot << "]";
			TableroVisual();
			jugadas++;
			turno = oponente;
		}

		else if (turno == oponente)
		{
			cout << "\n\nIngrese la Posicion en X: ";
			cin >> posX;
			cout << "\nIngrese la Posicion en Y: ";
			cin >> posY;
			
			/*n--;
			x = n / 3;
			y = n % 3;*/
			if (tablero[posX][posY] == ' ' && (posX < 3 && posX >= 0) && (posY < 3 && posY >= 0))
			{
				tablero[posX][posY] = simboloOponente;
				GoToXY(50,50);
				cout << "HUMAN has put a " << simboloOponente << "in cell [" << posX << "," << posY << "]";
				TableroVisual();
				jugadas++;
				turno = bot;
			}
			else if (tablero[posX][posY] != ' ')
			{
				GoToXY(20,20);
				cout << "Posicion Ocupada, seleccione otra en un lugar disponible";
			}
			else
			{
				cout << "\n Posicion Invalida, fuera de rango \n";
			}
		}
	}

	// Empate
	if (HayVictoria(tablero) == false && jugadas == 9)
		cout << "DUROSSSSS EMPATE";
	else
	{
		// Declarar el ganador actual
		if (turno == bot)
			turno = oponente;
		else if (turno == oponente)
			turno = bot;

		Ganador(turno);
	}
}

int main()
{
	int opcionSimbolo;
	bool cerrar = false;
	do{
		system("cls");
	cout << "Que simbolo quiere ser?:\n\n";
	cout << "1) X (Empieza)\n";
	cout << "2) O (Es Segundo)\n";
	cout << "3) Salir\n\n";
	cout << "Opcion Elegida: ";
	cin >> opcionSimbolo;

	

	switch (opcionSimbolo) {
	case 1: 
		simboloBot = 'O';
		simboloOponente = 'X';
		jugar(oponente);
		_getch();
		break;
	case 2:
		botX = true;
		simboloBot = 'X';
		simboloOponente = 'O';
		jugar(bot);
		break;
	case 3:
		cerrar = true;
		GoToXY(20, 20);
		cout << "Cerrando......";
		break;
	default:
		cout << "Esa opcion no esta en el menu ";
		break;
	}
	} while (!cerrar);
		_getch();

}
