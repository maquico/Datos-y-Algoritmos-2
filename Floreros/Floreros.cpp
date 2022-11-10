#include "iostream"
#include "math.h"

using namespace std;

int main() {
	
	for (int i = 1; i < 100; i++)
	{
		int x = (100 - i);
		if (x % 6 ==0)
		{
			int floreros = x - 8;
			if (floreros%11 == 0)
			{
				cout << "Vendio: " << i << endl;
				cout << "Quedan: " << floreros << endl;
			}
		}
	}
	return 0;
}

