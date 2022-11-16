/* ESTRUCTURAS DE DATOS Y ALGORITMOS II
* ENUNCIADO: TAREA 1. NÚMERO A PALABRA
* ASUNTO: ESTE PROGRAMA PREMITE CONVERTIR NUMEROS ENTEROS DE DIGITOS A LETRAS.
AUTORES: ANGEL MORENO ID:1104666
*        GLEIDY ESPINAL ID:1104225
*        ALLEN SILVERIO ID:1104220
*        CRISTIAN JIMÉNEZ ID:1106166
*        WILLIAM FERREIRA ID:1104228
* FECHA: 13/11/2022
*/
#include <iostream> 
#include <string>
#include <conio.h>
#include <math.h>
						
using namespace std; //0

string diccionario1D[10] = { "uno", "dos", "tres", "cuatro", "cinco", "seis", "siete", "ocho", "nueve" };
string diccionario2D[9] = { "dieci","veinti", "treinta", "cuarenta", "cincuenta", "sesenta", "setenta", "ochenta", "noventa" };
string diccionario3D[9] = { "ciento", "doscientos", "trescientos", "cuatrocientos", "quinientos", "seiscientos", "setecientos", "ochocientos", "novecientos"};
string diccionarioEspecial[12] = { "cero", "diez", "once", "doce", "trece", "catorce", "quince", "veinte", "cien", "mil", "millon", "un"};

void Alerta(string iniMensaje = "", string finMensaje = "", int variable = NULL) {
	cout << "\n" << iniMensaje;
	if (variable != NULL)
	{
		cout << variable << finMensaje;
	}
	cout << "\nPresione cualquier tecla para continuar\n";
	_getch();
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

void Menu() {
	string opcion = "";
	bool salir = false;
	
	while (!salir)
	{
		cout << "---Bienvenido, este es el conversor de números a palabras---\n\n";
		cout << "[1] Convertir Numero\n";
		cout << "[0] Cerrar Programa\n";
		cin >> opcion;

		if (ValidarNum(opcion)) {
			switch (stoi(opcion))
			{
			case 0:
				salir = true;
				break;
			case 1:
				string num = "", numEnPalabras;
				bool salirNum=false;
				while (!salirNum)
				{
					cout << "Introduzca su número: ";
					cin >> num;
				}
			}
		}
		else {
			//mensaje de error
		}
	}	
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

void Convertir3D(int n, int cantDigitos, string &palabra) {
	
	if (cantDigitos> 0)
	{
		int potencia = 0;
		(cantDigitos % 3 == 0) ? potencia = pow(10, cantDigitos - 3) : potencia = pow(10, cantDigitos - (cantDigitos % 3));
		int numerosTrabajar = n / potencia;
		int parteRestante = n % potencia;//123
		int unidad = numerosTrabajar % 10, decena = (numerosTrabajar % 100)/10, centena = numerosTrabajar / 100;
		int cantDigitosActual = cantDigitos - ContarDigitos(numerosTrabajar);

		if (numerosTrabajar / 100 >= 1) {
			(centena == 1 && unidad == 0 && decena == 0) ? palabra += diccionarioEspecial[8]: palabra += diccionario3D[(centena - 1)] + " ";
		}

		if (decena >= 1)
		{
			switch (decena)
			{
			case 0:
				break;
			case 1:
				switch (unidad)
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
					palabra += diccionarioEspecial[6] + +" ";
					break;
				default:
					palabra += diccionario2D[0] + diccionario1D[unidad - 1] + " ";
					break;
				}
				break;
			case 2:
				if (unidad == 0) {
					palabra += diccionarioEspecial[7] + " ";
				}
				else
				{
					palabra += diccionario2D[1] + diccionario1D[unidad - 1] + " ";
				}
				break;
			default:
				palabra += diccionario2D[(decena / 10) - 1];
				if (unidad > 0) palabra += " y " + diccionario1D[unidad - 1] + " ";
				break;
			}
		}
		else  if (unidad > 0)
		{
			(unidad==1 && cantDigitosActual==6 && decena ==0 && centena==0) ? palabra += diccionarioEspecial[11] + " " : palabra += diccionario1D[unidad - 1] + " ";
		}

		//Agregar mil o millon
		if (cantDigitosActual == 3)palabra += diccionarioEspecial[9] + " ";
		else if (cantDigitosActual == 6) {
			(decena > 1 || unidad > 1 || centena > 1) ? palabra += diccionarioEspecial[10] + "es " : palabra += diccionarioEspecial[10];
		}

		if (parteRestante > 0)
		{
			Convertir3D(parteRestante, cantDigitosActual, palabra);
		}
	}
	else
	{
		palabra = diccionarioEspecial[0];
	}
}

int main() {
	string palabra = "";
	
		double numf = 1000000;
		int numi = numf;
		int cantDigit = ContarDigitos(numi);
		Convertir3D(numi,cantDigit, palabra);
		float decimal = (numf - numi) * 100;
		numi = decimal;
		cout << palabra << " con " << numi << " centavos.\n\n";
	
	return 0;
};