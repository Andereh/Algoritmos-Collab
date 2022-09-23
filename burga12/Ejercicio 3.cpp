/*

	3. Realizar un programa que lea un arreglo de estructuras los datos de N empleados 
	de la empresa y que imprima los datos del empleado con mayor y menor salario. 

*/


#include <iostream>
#include <stdlib.h>
#include <windows.h>

using namespace std;

struct infoEmpleados

{
	string name;
	int edad;
	string cargo;
	float salario;	
};


int main()

{	

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	int mayor = -1, menor = 102321339,posMayor,posMenor;
	int nEmpleados; //Numero de empleados

	cout << "\n\t\t\t\t Bienvenido \n\n";

	cout << "\n\t Este programa funciona para comparar los datos de empleados\n";

	do{
		cout << "\n\t Porfavor. Ingrese el numero de empleados: "; cin>>nEmpleados;
		if (nEmpleados <= 1)
			cout << "\n Para comparar se necesita un minimo de 2 empleados\n";
	}while(nEmpleados <= 1);
	
	struct infoEmpleados empleados[nEmpleados];

	cout << "\n\n Ingrese los datos de los " << nEmpleados << " empleados\n\n";

	for (int i = 0; i < nEmpleados; i++)
	{
		cout << "\n\t Empleado " << i + 1 << ":\n";

		fflush(stdin); //Resetear buffer
		cout << "\n\t\t Nombre: "; getline(cin,empleados[i].name);
		cout << "\n\t\t Edad: "; cin >> empleados[i].edad;
		fflush(stdin);
		cout << "\n\t\t Cargo: "; getline(cin,empleados[i].cargo);
		cout << "\n\t\t Salario: "; cin >> empleados[i].salario;

		//Comparamos el salario para determinar el mayor
		if (empleados[i].salario > mayor)
			{
				mayor = empleados[i].salario;
				posMayor = i;//Guardamos la posicion, nos indicara el empleado
			}
		//De igual forma que el anterior pero con el menor
		if (empleados[i].salario < menor)
			{
				menor = empleados[i].salario;
				posMenor = i;//Guardamos la posicion, nos indicara el empleado
			}	
	}


	cout << "\n\n Empleado con el salario mas alto: ";

	cout << "\n\n\t Nombre: " << empleados[posMayor].name;
	cout << "\n\n\t Edad: " << empleados[posMayor].edad;
	cout << "\n\n\t Cargo: " << empleados[posMayor].cargo;

	//Ponerle color al texto, unicomente en la linea de abajo
	SetConsoleTextAttribute(hConsole, (FOREGROUND_GREEN | FOREGROUND_GREEN | FOREGROUND_RED));
	cout << "\n\n\t Salario: " << empleados[posMayor].salario << "$";
	//Devolver los colores a la normalidad
	SetConsoleTextAttribute(hConsole, (FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN));

	cout << "\n\n Empleado con el salario mas bajo: ";

	cout << "\n\n\t Nombre: " << empleados[posMenor].name;
	cout << "\n\n\t Edad: " << empleados[posMenor].edad;
	cout << "\n\n\t Cargo: " << empleados[posMenor].cargo;

	//Ponerle color al texto, unicomente en la linea de abajo
	SetConsoleTextAttribute(hConsole, (FOREGROUND_RED | FOREGROUND_RED | FOREGROUND_RED));
	cout << "\n\n\t Salario: " << empleados[posMenor].salario << "$";
	//Devolver los colores a la normalidad
	SetConsoleTextAttribute(hConsole, (FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN));


	cout<<endl<<endl;
	system("pause");
	return 0;
}