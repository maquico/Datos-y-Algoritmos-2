

#include <iostream>
#include <fstream>
#include <conio.h>
#include <string.h>
#include <string>

using namespace std;

string TraducirNumero(int n) {
	string ruta = "traduccion.txt";
	ifstream archivo(ruta.c_str());
	int i = 0;
	string numeroEnLetras = "NO ENCONTRADO";
	bool numeroEncontrado = false, exit = false;

	if (archivo.is_open())
	{
		while (archivo.good() && !exit)
		{
			string linea;
			getline(archivo, linea);
			if (numeroEncontrado)
			{
				exit = true;
				numeroEnLetras = linea;
			}
			if (i == 0 || i % 2 == 0)
			{
				int numero = stoi(linea);
				(numero == n) ? numeroEncontrado = true : numeroEncontrado = false;
			}
			i++;
		}
	}
	archivo.close();
	return numeroEnLetras;
}

	int main()
	{
		int numeroUsuario = 0;
		cout << "Inserte un numero: ";
		cin >> numeroUsuario;
		cout << TraducirNumero(numeroUsuario);
		return 0;
	}

