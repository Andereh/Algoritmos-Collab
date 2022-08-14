#include <stdio.h>
#include <string.h>

char cadena[100]; control [100];

printf("Inserte la cadena a comparar: "); gets(cadena);
	int i;
	int x = strlen(cadena);
	char capicua[100];
	int j = x - 1;
  
  //empezamos desde la posicion J que equivale a la longitud de la cadena menos uno; asi nos referirnos a la ultima posicion de la cadena
  //cada vuelta se le resta uno a J para que se almacene lo que hay en la posicion normal [I] en la nueva cadena por cada vuelta
  //es decir, se almacena lo que hay en el reverso de la cadena ingresada, en la nueva cadena
  //si no entendiste, dale laik
  
	for (i = 0; i < x; i++){ 
		capicua[i] = cadena[j];
		j--;
	}
	capicua[x] = '\0';
  
	printf("\n\nLa cadena: %s\nSu reverso: %s", cadena, capicua);
	if (strcmp(cadena, capicua) == 0) printf("\n\nLa cadena es capicua!!");
	else printf("\n\nLa cadena no es capicua.");
  
	printf("\n\nIngrese una tecla para continuar ");
	gets(control);
