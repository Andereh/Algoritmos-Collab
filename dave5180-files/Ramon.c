//ramon
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int numero, mil, centena, decena, unidad;
char control [100] = "1";


int main(){
    while (strcmp(control, "1") == 0){
        printf("Introdduzca un numero para convertir en romano: "); scanf("%d", &numero);
        while (numero > 3999 || numero < 1){
            if (numero > 3999){printf("No crees que el numero es muy alto? intenta otro: "); scanf("%d", &numero);}
            if (numero < 1){printf("Numero no valido, por favor intente otro: "); scanf("%d", &numero);}
        }

        unidad = numero%10; numero /= 10;
        decena = numero%10; numero /= 10;
        centena = numero%10; numero /= 10;
        mil = numero%10; numero /= 10;

        printf("El numero en romano es: ");

        if (mil == 1)printf("M");
        else if (mil == 2)printf("MM");
        else if (mil == 3)printf("MMM");

        if (centena == 1) printf("C");
        else if (centena == 2) printf("CC");
        else if (centena == 3) printf("CCC");
        else if (centena == 4) printf("CD");
        else if (centena == 5) printf("D");
        else if (centena == 6) printf("DC");
        else if (centena == 7) printf("DCC");
        else if (centena == 8) printf("DCCC");
        else if (centena == 9) printf("CM");

        if (decena == 1) printf("X");
        else if (decena == 2) printf("XX");
        else if (decena == 3) printf("XXX");
        else if (decena == 4) printf("XL");
        else if (decena == 5) printf("L");
        else if (decena == 6) printf("LX");
        else if (decena == 7) printf("LXX");
        else if (decena == 8) printf("LXXX");
        else if (decena == 9) printf("XC");

        if (unidad == 1) printf("I");
        else if (unidad == 2) printf("II");
        else if (unidad == 3) printf("III");
        else if (unidad == 4) printf("IV");
        else if (unidad == 5) printf("V");
        else if (unidad == 6) printf("VI");
        else if (unidad == 7) printf("VII");
        else if (unidad == 8) printf("VIII");
        else if (unidad == 9) printf("IX");

        sleep(1);
        printf("\n\nDesea calcular otro numero?\n1. --- Si\nOtro. ---No\n\nOpcion: ");scanf("%s", control);
        system("cls");
    }

    return 0;

}
