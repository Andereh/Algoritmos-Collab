#include <stdio.h>
#include <math.h>

int n, res, k;

int main() {
	printf("Programa que te ayuda a descomponer numeros\n");
	printf("Que numero quieres descomponer: ");
	scanf("%d", &n);

	while (n < 1) {
		printf("El numero debe ser positivo, intenta otro: ");
		scanf("%d", &n);
	}

	// for (int i = 0; n > 0; i++) {
	// 	res = n%10 * pow(10, i);  
	// 	printf("%d\n", res);
	// 	n /= 10;
	// }
	k = 1;
	while (n > 0) {
		res = n%10 * k;
		printf("%d\n", res);
		n /= 10;
		k *= 10;
	}

	return 0;
}
