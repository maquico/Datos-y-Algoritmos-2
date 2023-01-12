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


void GoToXY(int x, int y)
{//La función coloca el cursor para imprimir en el lugar que queramos.
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hCon, dwPos);
}

bool validarEntrada(string entrada) {
	for (int i = 0; i < entrada.length(); i++) {
		if (!isdigit(entrada[i]))
		{
			return false;
		}
	}
	return true;
}

void TableroVisual(bool limpiarPantalla) 
{
	int posY = 2;
	int posX = 3;
	if (limpiarPantalla) {
		system("cls");
		cout << " * 0 | 1 | 2 *\n";
		cout << " *-----------*\n";
		cout << "0|   |   |   |\n";
		cout << " |-----------|\n";
		cout << "1|   |   |   |\n";
		cout << " |-----------|\n";
		cout << "2|   |   |   |\n";
	}
		for (int i = 0; i < 3; i++){
			
			for(int j = 0; j<3; j++){
				
				GoToXY(posX, posY);
				posX += 4;
				cout << (tablero[i][j]);
			}
			posX = 3;
			posY = 2+((i + 1) * 2);
		}
		GoToXY(25, 0);
		cout << "*--INSTRUCCIONES--*";
		GoToXY(25, 1);
		cout << "*-----------------*";
		GoToXY(25, 2);
		cout << "| 0,0 | 1,0 | 2,0 |";
		GoToXY(25, 3);
		cout << "|------------------";
		GoToXY(25, 4);
		cout << "| 0,1 | 1,1 | 2,1 |";
		GoToXY(25, 5);
		cout << "|------------------";
		GoToXY(25, 6);
		cout << "| 0,2 | 1,2 | 2,2 |";
		GoToXY(0, 7);
}

void Borrar()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
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
	if (Turno == bot) {
		GoToXY(0, 9);
		cout << "El BOT ha ganado\n";
		_getch();
	}
		
	else {
		GoToXY(0, 9);
		cout << "El HUMANO ha ganado\n";
		_getch();
	}
}

int minimax(char tablero[3][3], int profundidad, bool esBot)
{
	int puntuacion = 0;
	int mejorPuntuacion = 0;
	if (HayVictoria(tablero)) 
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

bool validarRango(int num, int cotInf, int cotSup) {
	if (num >= cotInf && num <= cotSup) return true;
	else return false;
}

void ImprimirError(string mensaje) {
	GoToXY(0, 15);
	cout << mensaje;
	_getch();
	TableroVisual(true);
}

void jugar(int turno)
{
	string posXS, posYS;
	int posX, posY;
	int jugadas = 0; 
	bool salir = false, recordatorio = false;


	TableroVisual(true);

	while (HayVictoria(tablero) == false && jugadas != 9)
	{
		if (turno == bot)
		{
			MejorMovimiento(tablero, jugadas);
			tablero[posXbot][posYbot] = simboloBot;
			TableroVisual(true);
			GoToXY(0, 9); 
			cout << "El bot coloco " << simboloBot << " en la posicion [" << posYbot << "," << posXbot << "]";
			_getch();
			TableroVisual(true);
			jugadas++;
			turno = oponente;
		}

		else if (turno == oponente)
		{
			do {
				salir = false;
				cout << "\n\nIngrese la Posicion en X: ";
				cin >> posYS;
				
					if (validarEntrada(posYS))
					{
						posY = stoi(posYS);
						if (validarRango(posY, 0, 2)) salir = true;
						else ImprimirError("Fuera de rango");
					}
					else {
						ImprimirError("ENTRADA INCORRECTA. Introduzca numeros enteros del 0 al 2");
					}
			} while (!salir);

				salir = false;
				do {
					if (recordatorio) {
						GoToXY(0, 8);
						cout << "Valor en X escogido: " << posY;
						
					}
					cout << "\n\nIngrese la Posicion en Y: ";
					cin >> posXS;

					if (validarEntrada(posXS) )
					{
						posX = stoi(posXS);
						if (validarRango(posX, 0, 2)) salir = true, recordatorio = false;
						else {
							ImprimirError("Fuera de rango");
							recordatorio = true;
						}
					}
					else {
						ImprimirError("ENTRADA INCORRECTA. Introduzca numeros enteros del 0 al 2");
						recordatorio = true;
					}
				} while (!salir);
			
			
			if (tablero[posX][posY] == ' ' && (posX < 3 && posX >= 0) && (posY < 3 && posY >= 0))
			{
				tablero[posX][posY] = simboloOponente;
				TableroVisual(true);
				GoToXY(0,9);
				cout << "El jugador coloco " << simboloOponente << " en la posicion [" << posY << "," << posX << "]";
				_getch();
				TableroVisual(true);
				jugadas++;
				turno = bot;
			}
			else if (tablero[posX][posY] != ' ')
			{
				ImprimirError("Posicion ocupada");
			}
			else
			{
				ImprimirError("Posicion fuera de rango");
			}
		}
	}

	// Empate
	if (HayVictoria(tablero) == false && jugadas == 9) {
		GoToXY(0, 9); //feliz año
		cout << "DUROSSSSS EMPATE";
		_getch();
	}
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
	string opcionS;
	bool cerrar = false;
	do{
		system("cls");
	cout << "Que simbolo quiere ser?:\n\n";
	cout << "1) X (Empieza)\n";
	cout << "2) O (Es Segundo)\n";
	cout << "3) Salir\n\n";
	
	cout << "Opcion Elegida: ";
	cin >> opcionS;
	if (validarEntrada(opcionS))
	{
		Borrar();
		switch (stoi(opcionS)) {
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
			_getch();
			break;
		case 3:
			cerrar = true;
			GoToXY(0, 20);
			cout << "Cerrando......";
			break;
		default:
			cout << "Esa opcion no esta en el menu ";
			_getch();
			break;
	}
	}
	else {
		GoToXY(0, 20);
		cout << "ENTRADA INCORRECTA. Introduzca numeros enteros del 0 al 2";
		_getch();
		cout << "                                                         ";
		GoToXY(0, 6);
	}
	} while (!cerrar);
		_getch();

}
