//calculo del promedio de cinco numeros

#include <iostream>

using namespace std;

int main(){

     float n1, n2, n3, n4, n5;
	float promedio = 0; // el promedio final debe ser float por la division que haras
     cout<<"Este programa es para calcular el promedio de 5 numeros";
     cout<<"\ningrese el primer numero : "; cin>>n1;
     
     while(n1<0){
     	
	  cout<<"ERROR, este programa no calcula numeros negativos, introduzca otro: "; cin>>n1;
	
	      }
	 cout<<"\ningrese el segundo numero : "; cin>>n2;

     while(n2<0){
     	
	  cout<<"ERROR, este programa no calcula numeros negativos, introduzca otro: "; cin>>n2;
	
	      }
	      
	      cout<<"\ningrese el tercer numero : "; cin>>n3;
	      
	 while(n3<0){
     	
	  cout<<"\nES LA TERCERA VEZ QUE TE DIGO QUE SIN NUMEROS NEGATIVOS CONCHALE PANA Y ENTONCES? PON OTRO : "; cin>>n3;
	
	      }

           cout<<"\ningrese el cuarto numero : "; cin>>n4;
           
    while(n4<0){
     	
	  cout<<"\nES LA CUARTA VEZ QUE TE DIGO QUE SIN NUMEROS NEGATIVOS CONCHALE PANA Y ENTONCES? PON OTRO : "; cin>>n4;
	
       }
           cout<<"\ningrese el quinto numero : "; cin>>n5;
           
    while(n5<0){
     	
	  cout<<"\nMe quitas la poca paciencia que tuve al hacer este programa, pon otro : "; cin>>n5;
	
       }
           
       promedio = (n1 + n2 + n3 + n4 + n5) / 5;

	   /*
		* Si no pones los parentesis se ejecutara primero la division, eso
		* te dara resultados erroneos
		*/
       
       cout<<"\nTu promedio es: "<<promedio;
       
       return 0;
}
