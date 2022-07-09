#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <windows.h>


void sum_fives(){
	int sal = 1;
	system("cls");
	while(sal==1){
	int sum_num = 0, i, sum = 0;
	printf("Ingrese hasta que numero \n\n");             
	scanf("%d",&sum_num);          
	for(i=0;i<=sum_num;i=i+5){                          
    printf(" \n%d ",i);
    sum = sum + i;
	 }
	printf("\n\nLa suma de estos numeros multiplos de 5 es : %d",sum);
	getch();
	printf("\n\nDesea evaluar otra suma?\n\nSi = 1\n\nNo = Presione cualquier numero\n\nOpcion : "); scanf ("%d",&sal);
     }
}

void pot_num(){
	    int sal = 1;
	    while (sal==1){
	    system("cls");
	    int num_elev = 0, num_cuadrado = 0, num_cubo = 0;
		printf("Ingresa un numero del 1 al 15 para elevarlo al cuadrado y al cubo\n\n");
		scanf ("%d",&num_elev); 
		while(num_elev<0){
		printf("Disculpe, pero no elevo numeros menores a 1 ingrese otro: "); scanf("%d",&num_elev);
		}
		while(num_elev>15){
		printf("Disculpe, solo elevo numeros del 1 al 15 ingrese otro : "); scanf("%d",&num_elev);          /*no se si sea asi profe pero asi sirvio*/ 
		}	
		num_cuadrado = pow (num_elev, 2);
		num_cubo = pow (num_elev, 3);
		printf("\n\nEl cuadrado del numero que introdujo es : %d",num_cuadrado);
		printf("\n\nEl cubo del numero que introdujo es : %d",num_cubo);
		getch();
	    printf("\n\nDesea ingresar otro numero?\n\n Si = 1\n\nNo = Presione cualquier numero\n\nOpcion : "); scanf ("%d",&sal);
	
     }
}

void cal_work(){
	int sal = 1;
	while (sal==1){
	            system("cls");
				float cat1, cat2, cat3, cat4, bon1=15, bon2=13 ,bon3=12 ,bon4=9.5, desc1=4, desc2=3 ,desc3=2, desc4=0, horas=0,pago_horas=0;
				printf("Ingresa las horas que trabajas al dia : "); scanf("%f",&horas);
				while (horas < 1){
				 printf("\n\nERROR el programa se cerrara"); break;} 
				printf("\n\nIngresa cuanto es tu pago por hora : "); scanf("%f",&pago_horas);
				if (horas < 3 ){	
				float cat1 =  ((horas * pago_horas ) * (bon1/100)+ horas*pago_horas) - ((((horas * pago_horas) * (bon1/100))+ horas*pago_horas) * desc1/100);
					printf("\n\nAl ser un empleado de categoria 1 tu sueldo es : %f bolivares",cat1);
					}
			
			    else
			    if (horas < 7  ){
			    float cat2 =  ((horas * pago_horas ) * (bon2/100)+ horas*pago_horas) - ((((horas * pago_horas) * (bon2/100))+ horas*pago_horas) * desc2/100);
					printf("\n\nAl ser un empleado de categoria 2 tu sueldo es : %f bolivares",cat2);
					}
					
				else
			    if (horas < 12 ){
			    float cat3 =  ((horas * pago_horas ) * (bon3/100)+ horas*pago_horas) - ((((horas * pago_horas) * (bon3/100))+ horas*pago_horas) * desc3/100);                /*OTRA COSA ASI Y A LA PROXIMA PROGRAMO UN TROYANO*/
					printf("\n\nAl ser un empleado de categoria 3 tu sueldo es : %f bolivares",cat3);
					}
				
				else
			    if (horas <= 16 ){
			    float cat4 =  ((horas * pago_horas ) * (bon4/100)+ horas*pago_horas) - ((((horas * pago_horas) * (bon4/100))+ horas*pago_horas) * desc4/100);
					printf("\n\nAl ser un empleado de categoria 4 tu sueldo es : %f bolivares",cat4);
					}
				
				else{
					printf("\n\nMas de 16 horas de trabajo puede ser dañino para su salud");
				}
				getch();
		         printf("\n\nDesea evaluar otro salario?\n\n Si = 1\n\nNo = Presione cualquier numero\n\nOpcion : "); scanf ("%d",&sal);
	
		
	}
	
}

void back_count(){
	int sal = 1;
	while (sal==1){
	system("cls");
	int contador;
	printf("Hola, en esta opcion te mostrare los numeros del 30 hasta el 0 empezando en...\n\n"); Sleep(5000);
	printf("Ya\n"); Sleep(1000);
	for(contador=30; contador>=0; contador--){
	printf("\n%d", contador); 
	Sleep(1000);
			}
	
	printf("\n\nDesea que se repita este conteo?\n\n Si = 1\n\nNo = Presione cualquier numero\n\nOpcion : "); scanf ("%d",&sal);
	
   } 

}

int main(){
	
	int opcion = 0, sal = 1;
	while(sal==1){
	
	
        system("cls");
		printf("Menu\n\n");
		printf("1. Suma de los numeros multiplos de 5\n\n");
		printf("2. Calcular el cuadrado y el cubo de los 15 mayores numeros que 0\n\n");
		printf("3. Calcula cuanto ganas al mes :3\n\n");
		printf("4. Conteo regresivo de el numero 30 hasta el 0\n\n");
		printf("5. Salir\n\n");
		printf("Que opcion prefieres?: ");
		scanf("%d", &opcion);
		switch(opcion){
	    
	    case 1:
	    
	    sum_fives();
	    break;
	    
	    case 2:
	    
	    pot_num();
	    break;
	    
	    case 3:
	    
	    cal_work();
	    break;
	    
	    case 4:
	    
	    back_count();
	    break;
	    
	    case 5:
	    return 0;
	    
	    default:
	    	
	    system("cls");
		printf("La opcion que Ingreso no es valida");
		getch();
		break;
	
           }
     }
      
       return 0;
  
}

