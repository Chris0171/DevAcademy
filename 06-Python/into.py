import math

nombre = "Marta" # Variable de tipo string-cadena
entero = -25 # Variable de tipo int-entero
flotante = 3.1416 # Variable de tipo float-flotante
booleano = False # Variable de tipo bool-boleano

mi_variable = 10


print(type(mi_variable)) # Muestra el tipo de variable
print(mi_variable) # Muestra el valor de la variable

mi_variable = "27.650000" 

print(type(mi_variable)) # Muestra el tipo de variable
print(mi_variable) # Muestra el valor de la variable

mi_variable = float(mi_variable) # Convertir a flotante

print(type(mi_variable)) # Muestra el tipo de variable
print(mi_variable) # Muestra el valor de la variable

# ? Listas Mutables
# Una lista es un conjunto de elementos que pueden ser de 
# cualquier tipo de datos. Separados por comas y encapsulados entre [].

#                0  1  ... 
lista_enteros = [1, 3, 50, 20, 3, 4, 54, 5, 6, 6, 54, 4, 105]

print(lista_enteros[2]) # Muestra la posición 2 de la lista (50)

print(len(lista_enteros)) # Muestra la cantidad de elementos de la lista

lista_enteros[2] = 59

print (lista_enteros[2]) # Muestra la posición 2 de la lista (59)

print(lista_enteros[len(lista_enteros) - 1])


lista_enteros[len(lista_enteros) - 1] = 999

print(lista_enteros[len(lista_enteros) - 1]) # Muestra la última posición de la lista (999)

lista_enteros.append(490)

print(lista_enteros[len(lista_enteros) - 1]) # Muestra la última posición de la lista (490)

# ? Listas Inmutables
# Una tupla es un conjunto de elementos que pueden ser de
# cualquier tipo de datos. Separados por comas y encapsulados entre ().

tupla_enteros = (3, 4, 2, 5, 9)


# ! Expresiones y operadores
a = 10
b = 2
c = a * b # Multiplicación
d = a / b # División
d = a // b # División entera

e = a % b # Resto de la división
f = a ** 2 # Potencia

x = 4

respuesta = (2 + x * 3) / 2 + (2 + 12) / 2

print(respuesta) # Muestra el resultado de la expresión
print(f) # Muestra el resultado de la expresión

# ? Expresiones de asignación

k = 20
k = k * 2
print(k) # Muestra el resultado de la expresión
k += 1
k -= 1
k *= 2
print(k)

k /= 4
k //= 4
k %= 4
k **= 2
print(k)

print(math.sqrt(144)) # Muestra la raíz cuadrada de k
print(math.pow(2, 3)) # Muestra la potencia de 2 elevado a 3

print(math.pi) # Muestra el valor de pi
print(math.cos(math.pi))

# sin() seno
# log() logaritmo
# ceil() redondea hacia arriba
# floor() redondea hacia abajo
# log10() logaritmo en base 10
# sqrt() raíz cuadrada
# cos() coseno
# pow() potencia

"""
    Pedir datos al usuario (5 notas)
    calcular la media de las notas
    mostrar la media al usuario
        
"""
nota1 = 8
nota2 = 7
nota3 = 9
nota4 = 6
nota5 = 3

nota_final = (nota1 + nota2 + nota3 + nota4 + nota5) / 5

print(nota_final) # Muestra la media de las notas
