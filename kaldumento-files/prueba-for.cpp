#include <iostream>

using namespace std;

int vidas = 7, num_oculto = 13, user_num;

int main(int argc, char *argv[])
{
	cout << "Bienvenido, llegaste al casino, tienes que adivinar el numero en el "
		"que pienso\n";
	
	for (int i = 0; i < vidas; i++) {
		cout << "\nIntentos " << i << "/" << vidas<< "\n";
		cout << "Intenta un numero: ";
		cin >> user_num;

		if (user_num < num_oculto) cout << "Intenta un numero mas alto\n";
		else if (user_num > num_oculto) cout << "Te pasaste, intenta uno mas bajo\n";
		else {
			cout << "Mientras mas me lo mamas mas me crece XD\n";
			break;
		}
	}


  return 0;
}
