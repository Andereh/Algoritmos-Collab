/*
	Hacer un estructura llamada alumno que contenga los siguientes campos:
	nombre,edad,promedio. Pedir datos al usuario para 3 alumnos, comprobar
	cual de los 3 tiene mejor promedio y posteriormente mostrar los datos
	de los alumnos
*/

#include <iostream>
#include <stdlib.h>

using namespace std;


struct student
{
		
	char name[100];
	int yearOld;
	float promedio;

}students[3];

int main()
{


	float mayor = 0;
	int posMayor;

	cout << "\n\t\t\t\t Bienvenido \n\n";

	cout << "\n\t A continuacion debera ingresar los datos de 3 alumnos\n\n";

	for (int i = 0; i < 3; i++)
	{

		cout << "\n\n Datos alumno " << i+1 << ":\n";

		fflush(stdin);//resetear buffer
		cout << "\n\n\t Nombre del alumno "<< i+1 << ": ";
		cin.getline(students[i].name,100,'\n');
		cout << "\n\t Edad del alumno " << i+1 << ": ";
		cin >> students[i].yearOld;
		

		do{
			cout << "\n\t Promedio obtenido por el alumno " << i+1 << ": ";
			cin >> students[i].promedio;

			if(students[i].promedio < 1 || (students[i].promedio > 20))
				cout << "\n\t El promedio es en base a 20 (1-20ptos)\n";

		}while(students[i].promedio < 1 || (students[i].promedio > 20));
		
		if (students[i].promedio > mayor)
		{
			mayor = students[i].promedio;
			posMayor = i; //Guardamos la posicion para saber que ese es el alumno
						 // con mayor promedio
		}

	}

	cout << "\n\n\n\t Alumno con el mayor promedio \n";

	cout << "\n\t Nombre: " << students[posMayor].name;
	cout << "\n\t Edad: " << students[posMayor].yearOld;
	cout << "\n\t Promedio: "<<students[posMayor].promedio;
	cout << endl;
	
	cout<<endl<<endl;
	system("pause");

	return 0;	

}