#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

char romano[100], control[100] = "1" , todosRomanos[] = {'I','V','X','L','C','D','M', 'P'};
int vcc = 1, pp = 1;


int main(){
    while (vcc == 1){
        system("cls");
        pp = 1;
        printf("Programa para transformar romanos a enteros\tPresione 'F' para salir\n\t\t\t\t\t\tPresione 'P' para limpiar pantalla");
        while (pp == 1){
            int vc = 1;
            printf("\nIntroduca un numero romano: "); gets(romano);

            if (strcmp(romano, "f") == 0 || strcmp(romano, "F") == 0){
                system("cls"); printf("Hasta la proxima!"); sleep(2); return 0;
            }

            if (strcmp(romano, "p") == 0 || strcmp(romano, "P") == 0){break;}

            while (vc == 1){
                int i;
                while (strlen(romano) < 1){
                    printf("Conjunto vacio, por favor introduzca almenos un caracter: "); gets(romano);
                }

                for(i = 0; i < strlen(romano); i++){
                    strupr(romano);
                    if (romano[i] != 73 && romano[i] != 86 && romano[i] != 88 && romano[i] != 76 &&
                    romano[i] != 67 && romano[i] != 68 && romano[i] != 77){
                        printf("No mi loco intente de nuevo: "); gets(romano); i = -1;
                        if (strcmp(romano, "p") == 0 || strcmp(romano, "P") == 0){i = strlen(romano); break;}
                        if (strcmp(romano, "f") == 0 || strcmp(romano, "F") == 0){
                            system("cls"); printf("Hasta la proxima!"); sleep(2); return 0;
                        }
                    }
                }

                if (i == strlen(romano)) vc = 0;
            }
            if (strcmp(romano, "p") == 0 || strcmp(romano, "P") == 0) break;

            int c = 0; //centena
            int d = 0; //decena
            int u = 0; //unidad
            printf("El numero en entero es: ");
        
            if (romano[0] == 77 && romano[1] == 77 && romano[2] == 77){ printf("3"); c = 3;}
            else if (romano[0] == 77 && romano[1] == 77){ printf("2"); c = 2;}
            else if(romano[0] == 77){ printf("1"); c = 1;}

            if (romano[c] == 67 && romano[c+1] == 77){printf("9"); d = c + 2;}
            else if (romano[c] == 68 && romano[c+1] == 67 && romano[c+2] == 67 && romano[c+3] == 67){printf("8"); d = c + 4;}
            else if (romano[c] == 68 && romano[c+1] == 67 && romano[c+2] == 67){printf("7"); d = c + 3;}
            else if (romano[c] == 68 && romano[c+1] == 67){printf("6"); d = c + 2;}
            else if (romano[c] == 68){ printf("5"); d = c + 1;}
            else if (romano[c] == 67 && romano[c+1] == 68){ printf("4"); d = c + 2;}
            else if (romano[c] == 67 && romano[c+1] == 67 && romano[c+2] == 67){printf("3"); d = c + 3;}
            else if (romano[c] == 67 && romano[c+1] == 67){printf("2"); d = c + 2;}
            else if (romano[c] == 67){printf("1"); d = c + 1;}
            else if (c > 0){printf("0"); d = c;}

            if (romano[d] == 88 && romano[d+1] == 67){printf("9"); u = d + 2;}
            else if (romano[d] == 76 && romano[d+1] == 88 && romano[d+2] == 88 && romano[d+3] == 88){printf("8"); u = d + 4;}
            else if (romano[d] == 76 && romano[d+1] == 88 && romano[d+2] == 88){printf("7"); u = d + 3;}
            else if (romano[d] == 76 && romano[d+1] == 88){printf("6"); u = d + 2;}
            else if (romano[d] == 76){printf("5"); u = d + 1;}
            else if (romano[d] == 88 && romano[d+1] == 76){printf("4"); u = d + 2;}
            else if (romano[d] == 88 && romano[d+1] == 88 && romano[d+2] == 88){printf("3"); u = d + 3;}
            else if (romano[d] == 88 && romano[d+1] == 88){printf("2"); u = d + 2;}
            else if (romano[d] == 88){printf("1"); u = d + 1;}
            else if (d > 0){printf("0"); u = d;}

            if (romano[u] == 73 && romano[u+1] == 88) printf("9");
            else if (romano[u] == 86 && romano[u+1] == 73 && romano[u+2] == 73 && romano[u+3] == 73) printf("8");
            else if (romano[u] == 86 && romano[u+1] == 73 && romano[u+2] == 73) printf("7");
            else if (romano[u] == 86 && romano[u+1] == 73) printf("6");
            else if (romano[u] == 86) printf("5");
            else if (romano[u] == 73 && romano[u+1] == 86) printf("4");
            else if (romano[u] == 73 && romano[u+1] == 73 && romano[u+2] == 73) printf("3");
            else if (romano[u] == 73 && romano[u+1] == 73) printf("2");
            else if (romano[u] == 73) printf("1");
            else if (u > 0) printf("0");
            printf("\n");
        }
    }
}
