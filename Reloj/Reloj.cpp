
#include <iostream>
#include <math.h>

using namespace std;

void BuscarHora( int j, int k) {
	int prueba, num;
	while (j< 999 )
	{
		k = 0;
		while (k<999)
		{
			num = (j * 100) + k;
			prueba = (j * j)+ ( k * k);
			if (num == prueba)
			{
				cout << "ese " << num << " es la vuelta.";
			}
			k++;
		}
		j++;
	}
}

int main()
{
	BuscarHora(0, 0);
}


