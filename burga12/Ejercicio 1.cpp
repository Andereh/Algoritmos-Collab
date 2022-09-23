/*
Hacer una estructura llamada corredor en la cual se tendran los siguientes campos:
Nnombre,edad,sexo,club. Pedir datos al usuario para un solo corredor y asignarle
una categoria:
Juvenil <= 18 años
Señor  <= 40 anos
Veterano > 40 anos

Posteriormente mostrar los datos en pantalla
*/


#include <iostream>
#include <stdlib.h>

using namespace std;

struct corredor
{
	
	char nombre[100];
	int edad;
	char sexo[15];
	char club[100];

}corredor;

int main()

{		

	string categoria;

	cout << "\n\t\t\t\t Bienvenido \n\n\n\n";
	cout << "\t A continuacion se le pediran datos de un corredor.\n\n\t Ingreselos correctamente\n\n";

	cout << "\n\n Nombre: "; cin.getline(corredor.nombre,100,'\n');
	cout << "\n Edad: "; cin>>corredor.edad;
	fflush(stdin);// Resetear buffer
	cout << "\n Sexo: "; cin.getline(corredor.sexo,15,'\n');
	cout << "\n Club al que pertenece: "; cin.getline(corredor.club,100,'\n');

	cout<<"\n\n";

	//Determinar a que categoria pertenece el corredor
	if (corredor.edad <= 18)
		categoria =  "Juvenil";
	else if (corredor.edad <= 40)
		categoria = "Senior";
	else
		categoria = "Veterano";

	//Mostrar los datos del corredor

	cout << "\n\n\n Corredor: " << corredor.nombre<<endl;
	printf("\n Edad: %d ",corredor.edad);
	cout << "\n Sexo: " << corredor.sexo;
	cout << "\n Club: " << corredor.club;
	cout << "\n Categoria: " << categoria;

	cout<<endl<<endl;
	system("pause");

	return 0;
}
