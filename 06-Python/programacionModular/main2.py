from funciones import pedir_nombre, pedir_edad, es_mayor_de_edad

import operaciones


def main():
    nombre = pedir_nombre()
    edad = pedir_edad()
    
    if es_mayor_de_edad(edad):
        print(nombre, "Es mayor de edad")
    else:
        print(nombre, "no es mayor de edad.")

    a = 15
    b = 40
    
    print("El área del triángulo es:", operaciones.areaTriangulo(a, b))
    l = 10
    print("El área del cuadrado es:", operaciones.areaCuadrado(l))
    r = 5
    print("El área del círculo es:", operaciones.areaCirculo(r))
    
main()