
#include <iostream>
#include <string>
#include <conio.h>
#include <math.h>
#include <windows.h>
#include <cmath>

//Dos amigos juegan en el mismo equipo de futbol americano. Cada uno de ellos tiene su propio 
//numero dorsal marcado en su camiseta. Un dia, su entrenador observa el sorprendente hecho de que el cuadrado de la suma de sus respectivos
//numeros es precisamente el numero de cuatro cifras que se ve cuando estan el uno junto al otro. Por ejemplo, estos numeros no pueden ser 17
// y 33, dado que 17+33 = 40 y 40^2 no es 1733

using namespace std;


int main()
{
	for (int i = 0; i < 100; i++)
	{
		int j = 0;
		for ( j = 0; j < 100; j++)
		{
			int num1 = i;
			int num2 = j;
			int cuadradoSuma = (num1  + num2) * (num1 + num2);
			int numerosJuntos = (num1 * 100) + num2;

			if (cuadradoSuma == numerosJuntos)
			{
				cout << i << " y " << j << endl;
			}
		}
	}
    return 0;
}

