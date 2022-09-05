#include <stdio.h>
#include <string.h>

char cadena[100], control [100];

<<<<<<< HEAD
int main(int argc, char *argv[])
{
	
	printf("Inserte la cadena a comparar: "); fgets(cadena, 100, stdin);
=======
int main(){
printf("Inserte la cadena a comparar: "); gets(cadena);
>>>>>>> e06277b2f5042234a21a21b7a060209573e42b4e
	int i;
	int x = strlen(cadena);
	char capicua[100];
	int j = x - 1;
  	for (i = 0; i < x; i++){
		capicua[i] = cadena[j];
			j--;
		}
	cadena[x-1] = '\0';
	capicua[x-1] = '\0';
  
	printf("\n\nLa cadena: %s\nSu reverso: %s", cadena, capicua);
	if (strcmp(cadena, capicua) == 0) printf("\n\nLa cadena es capicua!!");
	else printf("\n\nLa cadena no es capicua.");
  
	printf("\n\nIngrese una tecla para continuar ");
<<<<<<< HEAD
	fgets(cadena, 100, stdin);
	return 0;
=======
	gets(control);
>>>>>>> e06277b2f5042234a21a21b7a060209573e42b4e
}
