# Operadores


"""

? Operadores de comparacion y control de flujo

<
>
<= 
>= 
==

? Operadores lógicos

and - es el y logico
or  - es el o logico
not - es el no logico


"""


# ? Estructura if
# ? Estructura switch
# ? Bucles while y for


edad = 18

if edad >= 18:
    print("Eres mayor de edad")

if edad == 18:
    print("Tienes 18 años")
else: 
    print("Eres menor de edad")

par = 4
if par % 2 == 0:
    print("Es un numero par")
    if par % 4 == 0:
        print("Es divisible entre 4")
else:
    print("Es un numero impar")
    
    
    
# ? Bulces
# * While, se utiliza cuando no sabemos cuantas veces se va a repetir

condicion = False

while condicion == False: 
    print(condicion)
    numero = int(input("Teclea algo: "))
    if(numero == 0):
        condicion = True

# * 1, 2, 3, 4
    

# ? Bulce for
# Se utiliza cuando sabemos cuantas veces se va a repetir
for i in range(3): 
    print(i)
    #    0  1  2  3  4  5   6
lista = [1, 3, 4, 6, 8, 12, 20]

for element in lista:
    print(element)
    
cadena = "Hola que tal"

for char in cadena:
    print(char)
    
archivo = open("datos.txt", "w", encoding="utf-8")

for linea in archivo:
    print(linea.strip())

archivo.close()