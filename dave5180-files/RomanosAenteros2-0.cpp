#include <iostream>
#include <stdlib.h>
#include <cstring>

using namespace std;

int main(){
    char Roman[100];
    int Ramon = 0, Number[100], negative;

    cout<<"Por favor digite un numero romano: "; cin>>Roman;
    strupr(Roman);

    for(int i = 0; i < strlen(Roman); i++){
        switch(Roman[i]){
            case 'I': Number[i] = 1; break;
            case 'V': Number[i] = 5; break;
            case 'X': Number[i] = 10; break;
            case 'L': Number[i] = 50; break;
            case 'C': Number[i] = 100; break;
            case 'D': Number[i] = 500; break;
            case 'M': Number[i] = 1000; break;
        }
    }
    for(int i = 0; i <strlen(Roman); i++){
        
        negative = Number[i];
        if(Number[i] < Number[i+1] && i < strlen(Roman)-1) Number[i] -= negative*2;
        Ramon += Number[i];
    }
    cout<<"\nEl numero insertado en entero es: "<<Ramon<<endl;

    system("Pause");
    return 0;
}
