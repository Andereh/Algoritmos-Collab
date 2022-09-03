#include <iostream>
#include <conio.h>

using namespace std;

int main(){
    int x, i = 1, factorial = 1, numero, n_factoriales, sumaFactoriales = 0;

    cout<<"Programa que calcula la suma de factoriales\n";
    cout<<"Ingrese los numeros factoriales en total a calcular: "; cin>>n_factoriales;
    cout<<"\n";

    for(x = 1; x <= n_factoriales; x++){
        cout<<"Ingrese el factorial N-"<<x<<" a calcular: "; cin>>numero;

        for(i = 1; i <= numero; i++){
            factorial *= i;

    }
    sumaFactoriales += factorial;
    factorial = 1;

    }

    cout<<"\nLa suma total de los factoriales son: "<<sumaFactoriales;
    getch();

    return 0;
}
