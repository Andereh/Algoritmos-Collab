#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h> // windows on linux wtffff??

void id_number() {
    int vc = 1;
    while (vc == 1) {
        float num;
        system("cls");
        Sleep(300);
        printf("\nIngrese el numero a evaluar: ");
        scanf("%f", &num);
        Sleep(600);
        if (num > 0) {
            printf("\nEl numero es positivo");
            Sleep(800);
        }

        else if (num < 0) {
            printf("\nEl numero es negativo");
            Sleep(800);
        }

        else if (num == 0) {
            printf("\nEl numero es elemento neutro");
            Sleep(800);
        }

        printf(
            "\n\nDesea evaluar otro numero?\nSi = 1\nNo = Otro "
            "numero\n\nOpcion: ");
        scanf("%d", &vc);
    }
}
void sumaPromedio() {
    int suma = 0;
    float num = 1, Total;

    while (num <= 20) {
        suma += num;
        num++;
    }

    system("cls");
    Sleep(800);
    printf("\nLa suma de los 20 primeros numeros enteros es: %d\n", suma);
    Sleep(500);
    num--;
    Total = suma / num;
    printf("El promedio es: %f\n", Total);
    Sleep(1000);
    /*esta wea fue un dolor de oido*/
}
void ParesSP() {
    int suma = 0, x = 20;
    long long int producto = 1;
    system("cls");
    Sleep(600);
    printf("Los pares son: ");
    Sleep(1000);

    while (x >= 20 && x <= 40) {
        if (x % 2 == 0) {
            printf("%d, ", x);
            Sleep(250);
            suma += x;
            producto *= x;
        }
        x++;
    }
    Sleep(500);
    printf(
        "\nLa suma de los numeros es: %d\nEl producto de los numeros es: %lld",
        suma, producto);
    Sleep(1000);
}
void HospitalPresupuesto() {
    int vc = 1;
    while (vc == 1) {
        Sleep(400);
        system("cls");
        Sleep(600);
        int moneda, presupuesto = 0, Gine = 0, Trauma = 0, Pedi = 0;
        char por = 37, dolar = 36, mony[] = " bs.s";

        printf(
            "Desea trabajar con Dolares /$/ o bolivares /bs.s/?\n$ = 1\nbs.s = "
            "2\n");
        scanf("%d", &moneda);

        while (moneda < 1 || moneda > 2) {
            printf(
                "\nPor favor inserta una opcion correcta:\n$ = 1\nbs.s = 2: ");
            scanf("%d", &moneda);
        }

        Sleep(800); // lo mejor es que linux no lo soporta
        printf(
            "\nEl presupuesto anual del hospital se reparte en...\nGinecologia "
            "= 40%c\nTraumatologia = 35%c\nPediatria = 25%c\n",
            por, por, por);
        Sleep(800);
        printf("\nIntroduzca el monto presupuestal: ");
        scanf("%d", &presupuesto);

        Gine = presupuesto * 0.4;
        Trauma = presupuesto * 0.35;  // calculos del % presupuestal
        Pedi = presupuesto * 0.25;

        Sleep(600);
        printf(
            "\nSe ha repartido el presupuesto insertado de la siguiente "
            "manera:\n\n");
        Sleep(600);
        if (moneda == 1) {
            printf(
                "Ginecologia = %d %c\nTraumatologia = %d %c\nPediatria = %d "
                "%c\n",
                Gine, dolar, Trauma, dolar, Pedi, dolar);
        }
        if (moneda == 2) {
            printf(
                "Ginecologia = %d%s\nTraumatologia = %d%s\nPediatria = %d%s\n",
                Gine, mony, Trauma, mony, Pedi, mony);
        }
        Sleep(600);// diossss hasta cuando
        printf(
            "\nDesea calcular otro monto presupuestal?\nSi = 1\nNo = otro "
            "numero\nOpcion: ");
        scanf("%d", &vc);
    }
}

int main() {
    printf("\n                 BIENVENIDO/A\n\n");
    Sleep(3000);// Cual es tu maldita obsesion con los Sleep????
    int vc = 1, opcion = 0;
    while (vc == 1) {
        system("cls");
        printf("                     Menu\n\n");
        Sleep(1500); 
        printf("Elija una de las siguientes opciones:\n\n");
        Sleep(1000);
        printf("         1. Identificar un numero real\n");
        Sleep(200);
        printf("         2. Promedio de los primeros 20 numeros enteros\n");
        Sleep(200);
        printf("         3. Suma y producto de los pares entre 20 y 40\n");
        Sleep(200);
        printf("         4. Calcular presupuesto de un hospital\n");
        Sleep(200);
        printf("         5. Salir\n\n");
        Sleep(400);
        printf("Opcion: ");
        scanf("%d", &opcion);

        // bucle de validacion de opción
        if (opcion == 5) {
            printf("\nFin del programa.");
            Sleep(1300);
            return 0;
        }
        while (opcion < 1 || opcion > 5) {
            printf("\nPor favor ingrese una opcion valida: ");
            scanf("%d", &opcion);
        }

        // recuerda dar formato hdp

        switch (opcion) {
            case 1:
                id_number();
                break;

            case 2:
                sumaPromedio();
                break;

            case 3:
                ParesSP();
                break;

            case 4:
                HospitalPresupuesto();
                break;
        }

        Sleep(800);
        printf(
            "\n\nDesea realizar alguna otra operacion?\n\nSi = 1\nNo = Otro "
            "numero\n\nOpcion: ");
        scanf("%d", &vc);

        if (vc != 1) {
            printf("\nFin del programa.");
            Sleep(1500);
            return 0;
        }
    }
}
