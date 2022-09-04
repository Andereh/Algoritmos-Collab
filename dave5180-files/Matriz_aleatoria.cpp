#include <iostream>
#include <conio.h>
#include <stdlib.h> // VariableRand = Limite_inferior + rand() % (limite_superior +1 - limite_inferior) ;

#include <time.h>

using namespace std;

int main(){
    srand(time(NULL));

    int ramdom, x, y, matrizAleatoria[100][100];

    cout<<"Inserte el Numero de filas a generar: "; cin>>x;
    cout<<"Inserte el Numero de columnas a generar: "; cin>>y; cout<<endl;

    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            matrizAleatoria[i][j] = 1 + rand()%(10 - 1);
            cout<<"["<<matrizAleatoria[i][j]<<"] ";

        }
        cout<<"\n";
    }

    getch();
    return 0;
}
