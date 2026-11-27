def pedir_nombre():
    
    nombre = input("Ingrese su nombre: ")
    
    return nombre

def pedir_edad():
    return int(input("Ingrese su edad: "))

def es_mayor_de_edad(edad): 
    mayor_de_edad = False
    
    if edad >= 18:
        mayor_de_edad = True

    return mayor_de_edad


    
# def nombre_funcion(param1, param2, ...): <- parametros si es necesario    
#   contenido de la funcion