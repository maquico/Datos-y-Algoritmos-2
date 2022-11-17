/* ESTRUCTURAS DE DATOS Y ALGORITMOS II
* ENUNCIADO: TAREA 1. NÚMERO A PALABRA
* ASUNTO: ESTE PROGRAMA PREMITE CONVERTIR NUMEROS ENTEROS DE DIGITOS A LETRAS.
AUTORES: ANGEL MORENO ID:1104666
*        GLEIDY ESPINAL ID:1104225
*        ALLEN SILVERIO ID:1104220
*        CRISTIAN JIMÉNEZ ID:1106166
*        WILLIAM FERREIRA ID:1104228
* FECHA: 17/11/2022
*/
#include <iostream> 
#include <string>
#include <conio.h>
#include <math.h>
#include <windows.h>
						
using namespace std; 

//Arrays Globales
string diccionario1D[10] = { "uno", "dos", "tres", "cuatro", "cinco", "seis", "siete", "ocho", "nueve" };
string diccionario2D[9] = { "dieci","veinti", "treinta", "cuarenta", "cincuenta", "sesenta", "setenta", "ochenta", "noventa" };
string diccionario3D[9] = { "ciento", "doscientos", "trescientos", "cuatrocientos", "quinientos", "seiscientos", "setecientos", "ochocientos", "novecientos"};
string diccionarioEspecial[12] = { "cero", "diez", "once", "doce", "trece", "catorce", "quince", "veinte", "cien", "mil", "millon", "un"};


//Variables Globales
HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE);

//Prototipos
void Alerta(string, bool,int);
bool ValidarNum(string);
void MenuPrincipal();
int ContarDigitos(int);
void NumEnPalabras(int, int, string&);
void MenuConversion();
bool ValidarRango(float, float, float);

//Main
int main() {
	
	MenuPrincipal();
	return 0;
};

//Funciones
void Alerta(string mensaje = "", bool color = false, int nColor = 7) {
	if (color)
	{
		SetConsoleTextAttribute(hconsole, nColor);
		cout << "\n" << mensaje;
		cout << "\nPresione cualquier tecla para continuar\n";
		_getch();
		SetConsoleTextAttribute(hconsole, 7);
	}
	else {
		cout << "\n" << mensaje;
		cout << "\nPresione cualquier tecla para continuar\n";
		_getch();
	}
}

bool ValidarNum(string entrada) {

	bool numValido = true;
	bool hayPunto = false;
	for (int i = 0; i < entrada.length() && numValido; i++)
	{
		if (entrada[i] == '.' && !hayPunto) hayPunto = true;
		else if (entrada[i] == '.' && hayPunto) numValido = false;
		else {
			if (!isdigit(entrada[i])) numValido = false;
		}
	}
	return numValido;
}

bool ValidarRango(float cotaInf, float cotaSup, float n) {
	bool dentroRango = false;
	(n >= cotaInf && n <= cotaSup) ? dentroRango= true : dentroRango=false;
	return dentroRango;
}

int ContarDigitos(int n) {
	int cont = 0;
	while (n > 0)
	{
		n = n / 10;
		cont++;
	}
	return cont;
}
void NumEnPalabras(int n, int cantDigitos, string& palabra) {

	if (cantDigitos > 0)
	{
		int potencia = 0;
		(cantDigitos % 3 == 0) ? potencia = pow(10, cantDigitos - 3) : potencia = pow(10, cantDigitos - (cantDigitos % 3));
		int numTrabajar = n / potencia;
		int numRestante = n % potencia;
		int unidad = numTrabajar % 10, decena = (numTrabajar % 100) / 10, centena = numTrabajar / 100;
		int digitosRestantes = cantDigitos - ContarDigitos(numTrabajar);

		//SE TRADUCE LA CENTENA
		if (numTrabajar / 100 >= 1) //Si la centena es 100 escribe cien, de lo contrario busca en el diccionario de 3 dig ciento, doscientos, etc.
			(centena == 1 && unidad == 0 && decena == 0) ? palabra += diccionarioEspecial[8]+ " " : palabra += diccionario3D[(centena - 1)] + " ";

		//SE TRADUCE LA DECENA CON SU UNIDAD
		if (decena >= 1) {
			switch (decena)
			{
			case 1:
				switch (unidad) //Un switch para los casos del 11, 12, 13, 14 y 15
				{
				case 0:
					palabra += diccionarioEspecial[1] + " ";
					break;
				case 1:
					palabra += diccionarioEspecial[2] + " ";
					break;
				case 2:
					palabra += diccionarioEspecial[3] + " ";
					break;
				case 3:
					palabra += diccionarioEspecial[4] + " ";
					break;
				case 4:
					palabra += diccionarioEspecial[5] + " ";
					break;
				case 5:
					palabra += diccionarioEspecial[6] + " ";
					break;
				default: //Este default escribe los numeros 16, 17, 18 y 19
					palabra += diccionario2D[0] + diccionario1D[unidad - 1] + " ";
					break;
				}
				break;
			case 2:
				// si es 20 escribe veinte, sino escribe veinti y agrega el numero de la unidad
				if (unidad == 0) palabra += diccionarioEspecial[7] + " ";
				else if (unidad==1 && (digitosRestantes==3 || digitosRestantes == 6)) palabra = palabra + diccionario2D[1] + diccionarioEspecial[11] + " ";
				else palabra += diccionario2D[1] + diccionario1D[unidad - 1] + " ";
				break;
			default:
				// para numeros de 30 hasta 99.
				palabra += diccionario2D[decena - 1] + " ";
				if (unidad == 1 && (digitosRestantes == 3 || digitosRestantes == 6)) palabra += "y " + diccionarioEspecial[11] + " ";
				if (unidad > 1 ) palabra += "y " + diccionario1D[unidad - 1] + " ";
				break;
			}
		}
		//SE TRADUCE UNA UNIDAD SOLA
		else if (unidad > 0)
			if (unidad == 1 && (digitosRestantes == 6))  palabra += diccionarioEspecial[11] + " "; //Para escribir 'un' en lugar de uno
			else if (unidad == 1 && digitosRestantes == 3 && centena == 0) ; // para que si es 1000 no escriba uno delante de mil
			else palabra += diccionario1D[unidad - 1] + " "; // cualquier otro caso de unidad sin decena.

		//SE AGREGA MIL O MILLON
		if (digitosRestantes == 3)palabra += diccionarioEspecial[9] + " "; //Sobran 3 digitos, se agrega 'mil'
		else if (digitosRestantes == 6) { //Sobran 6 digitos, se agrega 'millones' si centenas o decenas o unidades son mayores que 1, de lo contrario se agrega 'millon'
			( decena == 0 && unidad == 1 && centena ==0) ? palabra += diccionarioEspecial[10] + " " : palabra += diccionarioEspecial[10] + "es ";
		}

		if (numRestante > 0) NumEnPalabras(numRestante, digitosRestantes, palabra); //Si el numero restante es mayor que 0 se llama a la misma funcion
	}
	else
	{   //Caso especial del 0 solo, escribir 'cero'
		palabra = diccionarioEspecial[0];
	}
}

void MenuConversion() {
	string sNum = "";
	bool salirNum = false;
	while (!salirNum)
	{
		string numEnPalabras = "";
		system("cls");
		cout << "NOTA: Solo se toman en cuenta 2 decimales\n";
		cout << "Introduzca su numero: ";
		cin >> sNum;
		if (ValidarNum(sNum))
		{
			float fNum = stof(sNum);
			if (ValidarRango(0.00, 999999999.99, fNum))
			{
				int iNum = stoi(sNum), cantDigit = ContarDigitos(iNum);
				NumEnPalabras(iNum, cantDigit, numEnPalabras);
				float decimales = (fNum  - iNum) * 100;
				int centavos = decimales;
				cout << "\n\nNumero en palabras: ";
				SetConsoleTextAttribute(hconsole, 6);
				cout << numEnPalabras << "con " << centavos<< " centavos.\n\n";
				SetConsoleTextAttribute(hconsole, 7);
				_getch();
			}
			else Alerta("No introduzca numeros mayores que 999,999,999.99", true, 4);
		}
		else Alerta("No introduzca letras ni simbolos que no sean el punto decimal", true, 4);

		system("cls");
		cout << "Presione ""ESC"" para salir.\n\n";
		cout << "Presione CUALQUIER LETRA para continuar.\n\n";
		unsigned int letraSalir = _getch();
		if (letraSalir == 27) salirNum = true;
	}
}

void MenuPrincipal() {
	string opcion = "";
	bool salir = false;
	
	while (!salir)
	{
		system("cls");
		cout << "---Bienvenido, este es el conversor de números a palabras---\n\n";
		cout << "[1] Convertir Numero\n";
		cout << "[0] Cerrar Programa\n\n";
		cout << "Opcion a Elegir: ";
		cin >> opcion;

		if (ValidarNum(opcion)) {
			switch (stoi(opcion))
			{
			case 0:
				salir = true;
				break;
			case 1:
				MenuConversion();
				break;
			default:
				Alerta("La entrada no forma parte del menu de opciones");
				break;
			}
		}
		else {
			SetConsoleTextAttribute(hconsole, 4);
			Alerta("No introduzca letras ni simbolos que no sean el punto decimal");
			SetConsoleTextAttribute(hconsole, 7);
		}
	}	
}
