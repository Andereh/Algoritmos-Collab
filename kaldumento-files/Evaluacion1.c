#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <windows.h>
int opcion = 0;


int main (void){
	
	do{
		system("cls");
		printf("Menu\n\n");
		printf("1. Suma de los numeros multiplos de 5\n\n");
		printf("2. Calcular el cuadrado y el cubo de los 15 mayores numeros que 0\n\n");
		printf("3. Calcula cuanto ganas al mes :3\n\n");
		printf("4. Aqui te muestro los numeros del 1 al 30 pero de atras pa lante\n\n");
		printf("5. Salir\n\n");
		printf("¿Que opcion prefieres?: ");
		scanf("%d", &opcion);
		switch(opcion){
			
			case 1:
				system("cls");
				int sum_num = 0, i, sum = 0;
				printf("Ingrese hasta que numero \n\n");             
	         	scanf("%d",&sum_num);
	         	while(sum_num<5){
				printf("Solo sumo numeros a partir del 5 ingrese otro : "); scanf("%d",&sum_num);}           /*tecnicamente es ingresarlo mediante while xddddd*/
	         	for(i=0;i<=sum_num;i=i+5){                          
                printf(" \n%d ",i);
                sum = sum + i;
		 		 }
				printf("\n\nLa suma de estos numeros multiplos de 5 es : %d",sum);
				getch();
				break;
		 
			case 2:
				system("cls");
				int num_elev = 0, num_cuadrado = 0, num_cubo = 0;
				printf("Ingresa un numero del 1 al 15 para elevarlo al cuadrado y al cubo\n\n");
				scanf ("%d",&num_elev); 
				while(num_elev<1){
				printf("Disculpa pero no elevo numeros menores a 1 pon otro: "); scanf("%d",&num_elev);
				}
				while(num_elev>15){
				printf("La tarea me dijo que no me pase de 15 asi que prueba otro xd :"); scanf("%d",&num_elev);          /*no se si sea asi profe pero asi sirvio*/ 
				}	
				num_cuadrado = pow (num_elev, 2);
				num_cubo = pow (num_elev, 3);
				printf("\n\nEl cuadrado del numero que introdujo es : %d",num_cuadrado);
				printf("\n\nEl cubo del numero que introdujo es : %d",num_cubo);
				getch();
				break;
				
			case 3:
				system("cls");
				float cat1, cat2, cat3, cat4, bon1=15, bon2=13 ,bon3=12 ,bon4=9.5, desc1=4, desc2=3 ,desc3=2, desc4=0, horas=0,pago_horas=0;
				printf("Ingresa las horas que trabajas al dia : "); scanf("%f",&horas);
				while (horas < 1){
				 printf("\n\n No trabajas nada, flojo"); return(0);} 
				printf("\n\nIngresa cuanto es tu pago por hora : "); scanf("%f",&pago_horas);
				if (horas < 3 ){	
				float cat1 =  ((horas * pago_horas ) * (bon1/100)+ horas*pago_horas) - ((((horas * pago_horas) * (bon1/100))+ horas*pago_horas) * desc1/100);
					printf("\n\nAl ser un empleado de categoria 1 tu sueldo es : %f",cat1);
					}
			
			    else
			    if (horas < 7  ){
			    float cat2 =  ((horas * pago_horas ) * (bon2/100)+ horas*pago_horas) - ((((horas * pago_horas) * (bon2/100))+ horas*pago_horas) * desc2/100);
					printf("\n\nAl ser un empleado de categoria 2 tu sueldo es : %f",cat2);
					}
					
				else
			    if (horas < 12 ){
			    float cat3 =  ((horas * pago_horas ) * (bon3/100)+ horas*pago_horas) - ((((horas * pago_horas) * (bon3/100))+ horas*pago_horas) * desc3/100);                /*OTRA COSA ASI Y A LA PROXIMA PROGRAMO UN TROYANO*/
					printf("\n\nAl ser un empleado de categoria 3 tu sueldo es : %f",cat3);
					}
				
				else
			    if (horas <= 16 ){
			    float cat4 =  ((horas * pago_horas ) * (bon4/100)+ horas*pago_horas) - ((((horas * pago_horas) * (bon4/100))+ horas*pago_horas) * desc4/100);
					printf("\n\nAl ser un empleado de categoria 4 tu sueldo es : %f",cat4);
					}
				
				else{
					printf("\n\nNah si me vas a hacer creer que eres una mula");
				}
				getch();
				break;
				
				
			case 4:
				system("cls");
				int contador;
				printf("Hola, en esta opcion te mostrare los numeros del 30 hasta el 0 empezando en...\n\n"); Sleep(5000);
				printf("Ya\n"); Sleep(1000);
				for(contador=30; contador>=0; contador--){
				printf("\n%d", contador); 
				Sleep(1000);
			}
				
				break;
				
				
				
			case 5:
		        break;	
				
			default:
				system("cls");
				printf("La opcion que Ingreso no es valida");
				getch();
				break;			
				
			}
			
		}while(opcion!= 5);
	
	return 0;
}
