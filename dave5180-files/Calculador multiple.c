#include <math.h>
#include <stdio.h>
int vc, vc1, opcion, vc3; // Variables de Control

void clasificarTrian();
void calcularPoten();
void descomponerNumeros();

int main() {
  vc = 1;

  while (vc == 1) {
    vc1 = 1;

    while (vc1 == 1) {
      vc3 = 1;
      printf("Calculador multiple\n\n");
      printf("\t1. determinador de triangulos\n");
      printf("\t2. Calculador de potencias\n");
      printf("\t3. Descomponedor de numeros\n");
      printf("\t4. Salir\n");

      printf("\n\t\033[32mTu opcion:\033[0m ");
      scanf("%d", &opcion);

      if (opcion == 4)
      {
        printf("Pero porque te sales mmgvo >:(\n");
        return 0;
      }
      if (opcion < 1 || opcion > 4)
        printf("Por favor introduzca una opcion valida\n");
      else
        vc1 = 0;
    }

    switch (opcion) {
    case 1:
      clasificarTrian();
      break;
    case 2:
      calcularPoten();
      break;
    case 3:
      descomponerNumeros();
    }

    printf("\nDesea calcular otra operacion?:\nSi = 1\nNo = 0\n");
    scanf("%d", &vc);
    if (vc != 1)
      printf("\nFin del programa.");
  }

  return 0;
}

void clasificarTrian() {
  int l1, l2, l3, lm; // Lados del triangulo

  do {
    printf("\n\nIngrese el valor del lado 1: ");
    scanf("%d", &l1);
    printf("Ingrese el valor del lado 2: ");
    scanf("%d", &l2);
    printf("Ingrese el valor del lado 3: ");
    scanf("%d", &l3);

    lm = l1;

    if (l2 > lm)
      lm = l2;
    if (l3 > lm)
      lm = l3;

    printf("El lado mayor es %d\n", lm);

    if (l1 == l2 && l2 == l3)
      printf("El triangulo es Equilatero\n");
    else if (l1 == l2 || l1 == l3 || l2 == l3)
      printf("El triangulo es Isosceles\n");
    else
      printf("El triangulo es escaleno\n");

    printf("\nDesea calcular otro triangulo?:\n\tSi = \033[32m1\033[0m\n\tNo = \033[31m0\033[0m\n");
    printf("\n\nOpcion: ");
    scanf("%d", &vc3);
  } while (vc3 == 1);
}

void calcularPoten() {
  int b, e, p = 0; // Base, exponente, Potencia
                   //
  do {

    printf("\nIntroduzca el Valor de la base: ");
    scanf("%d", &b);
    printf("\nIntroduzca el valor de el exponente: ");
    scanf("%d", &e);
    p = pow(b, e);
    printf("\nEl resultado de %d elevado a %d es igual a = %d", b, e, p);
    printf("\nDesea calcular otra potencia?:\nSi = 1\nNo = 0\n");
    scanf("%d", &vc3);

  } while (vc3 == 1);
}

void descomponerNumeros() {
  int num, i, res;
  do {
    printf("Introduce el numero a descomponer: ");
    scanf("%d", &num);

    while (num < 1) {
      printf("Por favor elije un numero positivo: ");
      scanf("%d", &num);
    }

    i = 1;
    while (num > 0) {
      res = num % 10 * i;
      printf("%d\n", res);
      num /= 10;
      i *= 10;
    }

    printf("\nDesea descomponer otro numero?:\nSi = 1\nNo = 0\n");
    scanf("%d", &vc3);
  } while (vc3 == 1);
}
// Algun bug reportar, Gracias ☺♥♥♥
