#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int opcion = 0, num1 = 0, num2 = 0;

int main (void){
	
	do{
		system("cls");
		printf("Menu\n\n");
		printf("1. Suma\n");
		printf("2. Restar\n");
		printf("3. Salir\n\n");
		printf("¿Que opcion prefieres?: ");
		scanf("%d", &opcion);
		switch(opcion){
			
			case 1:
				system("cls");
				printf("Ingresa dos numeros para ejecutar la operacion\n\n");
	        	        printf("Primer Numero: ");
	         	        scanf("%d",&num1);
	         	        printf("Segundo Numero: ");
	        	        scanf("%d",&num2);
				printf("La suma de %d + %d es: %d",num1,num2,num1+num2);
				getch();
				break;
				
			case 2:
				system("cls");
				printf("Ingresa dos numeros para ejecutar la operacion\n\n");
		                printf("Primer Numero: ");
		                scanf("%d",&num1);
		                printf("Segundo Numero: ");
	        	        scanf("%d",&num2);
				printf("La resta de %d - %d es: %d",num1,num2,num1-num2);
				getch();
				break;
				
			case 3:
				break;
			default:
				system("cls");
				printf("La opcion que Ingreso no es valida");
				getch();
				break;			
				
			}
			
		}while(opcion!= 3);
	
	return 0;
}
