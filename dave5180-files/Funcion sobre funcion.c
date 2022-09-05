//Programa ejemplo de funciones

#include<stdio.h>
int r1 = 0 , r2 = 0, r3 = 0;

int ricolino(){
    int i = 1, c = 1, num = 0, new_num = 0;
    printf("\nDiga cuantos numeros quiere sumarr: "); scanf("%d", &c);
    for (i = 1; i <= c; i++){
        printf("\nInserte el valor del numero %d: ", i);scanf("%d", &new_num);
        num += new_num;    
    }
    printf("El Total es : %d\n", num);

return num;

}

int mariquillo(int r1, int r2){
    if (r1 > r2) printf("\nel primer conjunto es el mayor");
    else if (r1 < r2) printf("\nel segundo conjunto es mayor");
    else printf("\nLos conjuntos son iguales");
    printf("\ningrese un caracter para finalizar: "); scanf("%d");

return 0;
}

// epa vale, no me entendiste. Aqui solo las definiste
// Yo me referia a que no podias definir una funcion dentro de otra funcion Ej.
//
// int prueba()
// {
//     string otraPrueba()
//     {
//         printf("Algo");
//     }
// }

int main(){
    printf("Comparador de la suma de dos conjuntos\n");
    r1 = ricolino();
    r2 = ricolino();
    r3 = mariquillo (r1, r2);

}
