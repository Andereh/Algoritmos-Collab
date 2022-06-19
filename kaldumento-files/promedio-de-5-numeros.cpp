#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	int sum = 0, sum_aux, total;

	for (int i = 0; i < 5; i++) {
		cout << "Introduce un numero: ";
		cin >> sum_aux;

		while (sum_aux < 1) {
			cout << "Texto ofensivo, pon otro numero:";
			cin >> sum_aux;
		}

		sum += sum_aux;
	}

	total = sum / 5;

	cout << "El promedio es: " << total;

	return 0;
}

// @Kaldus, tal vez este te guste mas
