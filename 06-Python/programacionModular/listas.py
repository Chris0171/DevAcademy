# ** Tipos de listas

# ?List
frutas = ["Manzana", "Pera", "Plátano", "Naranja"]

print (frutas)
print (frutas[1])

frutas.append("Melón")
print(frutas)

frutas[1] = "Uva"

print(frutas)

frutas.remove("Uva")

print(frutas)

# ? Tuplas
coloresPrimarios = ("Rojo", "Azul", "Verde")

print(coloresPrimarios[1])

print(len(coloresPrimarios))


# ? Conjuntos (set)

numeros = {1, 2, 3, 4, 5, 5 , 5, 6}

print(numeros)
print(len(numeros))
numeros.remove(5)
print(numeros)

numeros.add(6)
numeros.remove(4)
print(numeros)
print(len(numeros))

print(5 in numeros)

# ? Diccionarios (dict)
# clave: valor

alumno = {
    "nombre": "Christian Milanés",
    "edad": 25,
    "curso": "Ingeniería Informática"
}
# Acceder al elemento
print(alumno["curso"])

# Modificar elemento
alumno["edad"] = 24
print(alumno["edad"])

# Añadir una nueva pareja clave: valor
alumno["nota"] = 8.5
print(alumno["nota"])

# Eliminar una pareja de clave: valor
del alumno["curso"]

print(alumno)

# ! Métodos más utilizados
print(alumno.keys()) # Devuelve todas las claves
print(alumno.values())# Devuelve todos los valores
print(alumno.items()) # Devuelve todas las parejas
print(alumno.get("nota")) # Obtiene un valor mediante la clave
print(alumno.pop("nota")) # Elimina una clave y devuelve su valor
print(alumno.items())

alumno.update({"nota": 9.5}) # Actualiza o añade parejas
print(alumno.items())



# ! Comparativa
# * List sintaxis -> [], ordenado? -> si, Modificable? -> si,
# * duplicados-> si, Acceso por indice -> si

# * Tuplas sintaxis -> (), ordenado? -> no, Modificable? -> no, 
# * duplicados -> si, Acceso por indice -> si

# * Conjuntos sintaxis -> {}, ordenado? no, Modificable -> si,
# * Duplicados -> no, Acceso por indice -> no

# * Diccionarios sintaxis -> {clave: valor}, ordenado? si, Modificable -> si,
# * Duplicados -> claves únicas, Acceso por indice -> por clave


# ! Recorrer las listas con bulces
# for iterador in lista

nums = [18, 25, 24, 13, 20, 29]

for num in nums:
    print(num)
    
tupla = ("verde", "amarillo", "rojo", "rosado", "azul")
for color in tupla:
    print (color)
    
# para un conjunto es similar

persona = {
    "nombre": "Carlos",
    "edad": 21,
    "nota": 6.5
}

for clave, valor in persona.items():
    print (clave, ": ", valor)
    

print (" ============= Matrices ============= ")
# ? Que es una matriz?
# 1 3 12
# 2 5 11
# 4 6 9
# 3x3

# ? Lista comun
# [1, 3, 4, 6]
matriz = [[1, 3, 12], 
          [2, 5, 11], 
          [4, 6, 9]
]


print (matriz[1][1])
print (matriz[1][2])
print (matriz[2][1])
print (matriz[0][1])

matriz[2][1] = 90
print (matriz[2][1])


print ("Imprimir matriz")
for fila in matriz:
    for columna in fila: 
        print (columna)
        
print ("Impirmir tabla")
for fila in matriz:
    for columna in fila: 
        print (columna, end=" ")
    print()

print("Imprimir matriz con i y j")
for i in range(len(matriz)): # en este caso va 0-2
    for j in range(len(matriz[i])): # en este caso 0-len(fila)2
        # imprimir le elemento matriz[fila][columna] = matriz[i][j]
        print (matriz[i][j]) 

# Matriz pidiendo datos
# Pedir filas
# Pedir columnas

matriz = [] 
filas = 2
columnas = 4

for i in range(2):
    fila = []
    for j in range(4):
        numero = int(input("Introduce un número: "))
        fila.append(numero)
    matriz.append(fila)
