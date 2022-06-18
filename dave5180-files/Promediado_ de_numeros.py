#calcular el promedio de N cantidad de numeros
from time import sleep
NewN = float #Nuevo Numero
Div = 0 #Contador De numeros totales
TotNum = 0 #Cantidad total insertada
Res = float(0) #Promedio a calcular
vc = 0 #Variable de control
print('calculador de promedio de numeros'); sleep(0.7)
while vc == 0:
    print('Inserte un numero para calcular'); sleep(0.7)
    NewN = float(input())
    TotNum = TotNum + NewN
    Div = Div + 1 ; sleep(0.5)
    print('¿Desea agregar otro numero?\nSi = enter\nNo = n\n')
    if input() == ('n'):
        vc = vc + 1
    else:
        vc = vc
print('el total es', TotNum)
print('el total de numeros es', Div)
Res = TotNum / Div
print('el promedio de los numeros insertados es:', Res)
