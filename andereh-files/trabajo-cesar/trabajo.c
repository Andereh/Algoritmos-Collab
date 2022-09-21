#include <stdio.h>
#include <stdlib.h> // para system()
#include <unistd.h> // para usleep()
#include <string.h> // para strcmp()

char usuario[] = "Cesar\n";
char clave[] = "mangos\n";

void programa() {
	char nombre_persona1[60];
	char apellido_persona1[60];
	char nombre_persona2[60];
	char apellido_persona2[60];

	char opcion[60];
	int longitud_linea = 45;
	char temp[60];

	system("clear");
	printf(" Bienvenido %s\n", usuario);


	printf("\n A continuacion tendras que proporcionar el nombre y apellido de dos personas\n");
	printf("\n\n\n\n Una vez entendido presiona una tecla para continuar\n");
	// getchar();
	getc(stdin);




	do {
		system("clear");

		printf("\n Persona 1:\n");
		printf("\tNombre: ");   scanf("%s", nombre_persona1);
		printf("\tApellido: "); scanf("%s", apellido_persona1);

		printf("\n\n Persona 2:\n");
		printf("\tNombre: ");   scanf("%s", nombre_persona2);
		printf("\tApellido: "); scanf("%s", apellido_persona2);


		do {
			system("clear"); // limpiamos la pantalla
			printf("\n Persona 1: %s %s\n", nombre_persona1, apellido_persona1);
			printf(" Persona 2: %s %s\n", nombre_persona2, apellido_persona2);

			printf("\n");
			for (int i = 0; i < longitud_linea; ++i) 
				printf("-~");

			printf("\n\n Ahora puedes elegir una de estas opciones:\n\n");

			printf("\n\t 1. Primer y segundo nombre ordenado alfabeticamente");
			printf("\n\t 2. Nombre de la persona uno con sus vocales en mayusculas");
			printf("\n\t 3. Apellido de la persona dos con las consonantes a mayusculas");
			printf("\n\t 4. Apellido de la primera y segunda persona concatenados");
			printf("\n\t 5. Nombres de las personas concatenados e invertidos");


			printf("\n\n Ahora deberias elegir una opcion: ");
			scanf("%s", opcion);
			
			// si tiene mas de un caracter
			// o si ese caracter esta fuera del rango
			while (strlen(opcion) > 1 || (opcion[0] < '1' || opcion[0] > '5')) {
				printf(" Eh! Elije una opcion correcta >:(\n");
				printf(" Opcion: ");
				scanf("%s", opcion);
			}

			printf("\n\n");
			switch (opcion[0]) {
				case '1':
					for (int i = 0; i < longitud_linea; ++i) 
						printf("-~");

					char mayor[60];
					char menor[60];

					if (strcmp(nombre_persona1, nombre_persona2) == 1) { // si el primer nombre es mayor que es segundo
						strcpy(mayor, nombre_persona1); // entonces el nombre de la persona 1 se copia a "mayor"
						strcpy(menor, nombre_persona2); // y el de la persona 2 se copia a menor
					} else {
						strcpy(mayor, nombre_persona2);
						strcpy(menor, nombre_persona1);
					}


					printf("\n\n Nombres ordenados:\n");
					printf("\n\tMayor: %s", mayor);
					printf("\n\tMenor: %s", menor);
					break;
				case '2':
					for (int i = 0; i < longitud_linea; ++i) 
						printf("-~");

					strcpy(temp, nombre_persona1);

					for (int i = 0; i < strlen(temp); ++i) {
						switch (temp[i]) {
						case 'a':
						case 'e':
						case 'i':
						case 'o':
						case 'u': // si es una vocal la pasa a mayusculas
							temp[i] -= 32;
						}
					}

					printf("\n\n Nombre de la persona uno con con las vocales en mayusculas: ");
					printf("\n\t %s", temp);
					break;
				case '3':
					for (int i = 0; i < longitud_linea; ++i) 
						printf("-~");

					strcpy(temp, nombre_persona1);

					for (int i = 0; i < strlen(temp); ++i) {
						switch (temp[i]) {
						case 'a':
						case 'e':
						case 'i':
						case 'o':
						case 'u':
							break; // si no es una vocal entonces entra en el default y la pasa a mayusculas
						default:
							temp[i] -= 32;
						}
					}

					printf("\n\n Apellido de la persona dos con con las consonantes en mayusculas: ");
					printf("\n\t %s", temp);
					break;
				case '4':
					for (int i = 0; i < longitud_linea; ++i) 
						printf("-~");

					printf("\n\n Apellido de la primera y segunda persona concatenados:");
					printf("\n\t%s%s\n", apellido_persona1, apellido_persona2);
					break;
				case '5':
					for (int i = 0; i < longitud_linea; ++i) 
						printf("-~");

					printf("\n\n Nombres concatenados e invertidos: ");
					printf("\n\t"); // dejamos el espacio


					for (int i = strlen(nombre_persona2) - 1; i >= 0; --i) // vamos desde el final hasta el inicio
						printf("%c", nombre_persona2[i]);

					for (int i = strlen(nombre_persona1) - 1; i >= 0; --i) 
						printf("%c", nombre_persona1[i]);
			}

			printf("\n\n");
			for (int i = 0; i < longitud_linea; ++i) 
					printf("-~");

			printf("\n\n Te gustaria continuar con los mismos nombres? (Si == s): ");
			scanf("%s", opcion);
		
		} while (opcion[0] == 's' || opcion[0] == 'S');

		printf(" Reingresar nombres? (Si == s | Otro == salir): ");
		scanf("%s", opcion);

	} while (opcion[0] == 's');
}


int main(int argc, char *argv[]) {
	char usuario_temporal[100];
	char clave_temporal[100];
	int intentos = 0;


	do {
		intentos++;
		system("clear");

		printf("\033[3m\n Usuario: \033[0m");
		fgets(usuario_temporal, 100, stdin);
		printf(" Clave de acceso: ");
		fgets(clave_temporal, 100, stdin);

		printf("\nValidando...\n");
		usleep(600 * 1000);

		if (intentos == 3)
		{
			printf("Demasiados intentos. Saliendo del programa\n");
			return 0;
		}

	} while (strcmp(usuario, usuario_temporal) != 0 ||
			 strcmp(clave,   clave_temporal  ) != 0);


	programa();

	return 0;
}

