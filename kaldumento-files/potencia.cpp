//potenciacion
#include <iostream>
#include <math.h>

using namespace std;

int main (){
	int n1, n2, potencia = 0;
	cout<<"programa para la potenciacion de numeros ";
	
	cout<<"\nintroduzca el numero que desea potenciar: "; cin>>n1;
	cout<<"a cual numero desea potenciarlo?: "; cin>>n2;
	
	while (n2 < 1){
		cout<<"el numero a potenciar debe ser positivo introduce otro: "; cin>>n2;
		
	}
	potencia = pow (n1 , n2);
	
	cout<<"el resultado de tu potencia es: "<<potencia<<endl;
	return 0;
}
