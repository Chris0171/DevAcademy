
# ? datos.txt
# ? fotos.jpg
# ? videos.mp4

# ! Importante 
# - Ruta de fichers.
# - Ruta absoluta: comienza desde la unidad o carpeta principal.
# - Ejemplo: D:\Users\Usuario\Desktop\archivo.txt
# - Ruta relativa: comienza desde la carpeta del programa.
# - Ejemplo: .\ficheros\datos.txt

# ? Pasos para trabajar con un fichero:
# 1. Abrir el fichero.
# * file = open("ruta_fichero", "modo(r, w, a), encoding="utf-8")
# 2. Leer o escribir en el fichero.
# * file.write("Hola mundo")
# 3. Cerrar el fichero.
# * file.close()


# * Pasos comunes para trabajar con ficheros:
# 1. Abrir el fichero.
# * file = open("ficheros/datos.txt", "r", encoding="utf-8")

# * operaciones 

# * Cerrar el fichero.


# ? Escribir en un fichero
# * edad = 25
# * file.write(f"Mi edad es: {edad}\n")


# ? Leer un fichero
# * variable = file.read() # Lee todo el contenido del fichero
# * variable = file.readline() # Lee una línea del fichero
# ! Linead fichero [1; 3; 4; 5]
# * lista_datos = file.readline().split(";")

# ? Metodos importantes de ficheros
# * fichero.rstrip() # Elimina los espaciones y saltode linea al final
# * ficheo.strip() # Elimina los espacion al inicio y al final


# !!!!!
"""
open()
close()
read()
readline()
readlines()
write()
split()
strip()
rstrip()
"""