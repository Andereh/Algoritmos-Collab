#include <stdio.h>
#include <string.h>

char cadena[100]; control [100];

int main(){
printf("Inserte la cadena a comparar: "); gets(cadena);
	int i;
	int x = strlen(cadena);
	char capicua[100];
	int j = x - 1;
  	for (i = 0; i < x; i++){
		capicua[i] = cadena[j];
			j--;
		}
	cadena[x-1] = 0;
	capicua[x-1] = 0;
  
	printf("\n\nLa cadena: %s\nSu reverso: %s", cadena, capicua);
	if (strcmp(cadena, capicua) == 0) printf("\n\nLa cadena es capicua!!");
	else printf("\n\nLa cadena no es capicua.");
  
	printf("\n\nIngrese una tecla para continuar ");
	gets(control);
}
