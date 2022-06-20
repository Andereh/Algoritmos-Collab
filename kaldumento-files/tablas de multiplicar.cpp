//mostrar cualquier tabla de multiplicar hasta el numero 10
#include <iostream>
 using namespace std;
 
 int num;
 int main(){
	 
 	cout<<"Hola, estre programa fue hecho para mostrarte las tablas de multiplicar ";
 	cout<<"\n\nIngresa el numero el cual quieres ver su tabla: "; cin>>num;
 		
	     while (num<1){
	     cout<<"Lo siento, solo evaluo numeros positivos, intenta otro: "; cin>>num;
	                  }
	     while (num>2000){
		 cout<<"\nNo te parece un numero muy alto? ingresa otro: "; cin>>num;
                             }
 	
 	for(int i=1;i<=10;i++){
 		cout<<num<<" * "<<i<<" = "<<num*i<<endl;
	                     }
 	
 	return 0;
 }
//LISTO COÑO
