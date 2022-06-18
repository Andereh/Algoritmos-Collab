suma = 0

print("Programa para promediar una cantidad indeterminada de numeros\n")
n_elementos = int(input("Cuantos elementos quiere evaluar?: "))

while n_elementos < 1:
    n_elementos = int(input("Debe ser un numero positivo, intenta otro: "))

for i in range(1, n_elementos+1):
    suma += int(input(f"Elemento {i}/{n_elementos}: "))

total = suma/n_elementos

print(f"El promedio es de {total}")
