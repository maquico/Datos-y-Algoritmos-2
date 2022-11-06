#include "iostream"
#include "math.h"

using namespace std;

int RaizEntera(int n) {
	int x = 0;
	bool negativo = false;

	if (n < 0) {
		n *= -1;
		negativo = true;
	}
	while ((x * x) <= n) {
		x++;
	}
	if (negativo) {
		cout << "Raiz Imaginaria" << endl;
	}
	return x - 1;
}

void CalcSolPoliGrad2(int A, int B, int C) {
	int term1 = (B * -1) / (2 * A), discriminante = (B * B) - (4 * A * C), term2 = 0 ;
	bool imaginario = false, solUnica = false;

	if (discriminante < 0) {
		imaginario = true;
		discriminante *= -1;
	}
	else if (discriminante == 0) solUnica = true;

	if(!solUnica) term2 = sqrt(discriminante) / (2 * A);

	if (imaginario) cout << "Las soluciones complejas son: " << term1 << " + " << term2 << "i y " << term1 << " - " << term2 << "i";
	else if (solUnica) {
		cout << "La unica solucion es: " << term1;
	}
	else {
		int sol1 = term1 + term2, sol2 = term1 - term2;
		cout << "Las soluciones son: " << sol1 << " y " << sol2;
	}

}
int main() {
	cout << RaizEntera(5)<< endl;
	CalcSolPoliGrad2(1, 4, 4);
	cout << endl;
	CalcSolPoliGrad2(1, 6, 5);
	cout << endl;
	CalcSolPoliGrad2(1, 18, 4);
	cout << endl;
	CalcSolPoliGrad2(1, 4, 18);
	return 0;
}
