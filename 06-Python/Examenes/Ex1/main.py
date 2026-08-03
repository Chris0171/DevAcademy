import random
from haversine import haversine

def cargar_restaurantes(restaurantes):
    fichero = open("michelin.csv", "r", encoding="utf-8")
    
    for linea in fichero:
        linea = linea.strip()
        
        if linea == "":
            continue
        
        datos = linea.split(";")
        
        restaurante = {
            "nombre": datos[0],
            "estrellas": int(datos[1]),
            "latitud": float(datos[2]),
            "longitud": float(datos[3]),
            "estilos": datos[4].split(","),
            "precio": float(datos[5])
        }
        restaurantes.append(restaurante)
        
    fichero.close()
        
 
def generar_gourmets(restaurantes, gourmets):
    for i in range(100):
        
        gourmet = {
            "nombre": f"gourmet-{i}",
            "restaurantes": random.sample(restaurantes, 5)
        }
        
        gourmets.append(gourmet)

def presupuesto_gourmet(gourmet):
    total = 0
    
    for restaurante in gourmet["restaurantes"]:
        total += restaurante["precio"]
    
    return total

def gourmet_mas_caro(gourmets):
    mas_caro = gourmets[0]
    
    for gourmet in gourmets:
        if presupuesto_gourmet(gourmet) > presupuesto_gourmet(mas_caro):
            mas_caro = gourmet
        
    return mas_caro
        
def restaurante_mas_visitado(gourmets):
    visitas = {}
    
    for gourmet in gourmets:
        for restaurante in gourmet["restaurantes"]:
            nombre = restaurante["nombre"]
            if nombre not in visitas:
                visitas[nombre] = 1
            else:
                visitas[nombre] += 1
            
    mas_visitado = ""
    max_visitas = 0
            
    for nombre in visitas:
        if visitas[nombre] > max_visitas:
            mas_visitado = nombre
            max_visitas = visitas[nombre]
             
    return mas_visitado
            
def gourmets_por_estilo(gourmets):
    estilos = {}
    
    for gourmet in gourmets:
        for restaurante in gourmet["restaurantes"]:
            for estilo in restaurante["estilos"]:
                if estilo not in estilos:
                    estilos[estilo] = []
                if gourmet["nombre"] not in estilos[estilo]:
                    estilos[estilo].append(gourmet["nombre"])
            
    return estilos
    

def guardar_visitas(dict):
    fichero = open("visitas.csv", "w", encoding="utf-8")
    
    for estilo in dict:
        fichero.write(estilo + ";")
        for gourmet in dict[estilo]:
            fichero.write(gourmet + ";")
            
        fichero.write("\n")
    
    fichero.close()
        

def gourmet_mayor_viaje(gourmets):
    mayor_distancia = 0
    nombre = ""
    
    for gourmet in gourmets:
        distancia_total = 0
        
        restaurantes = gourmet["restaurantes"]
        
        for i in range(len(restaurantes) - 1):
            punto_a = restaurantes[i]
            punto_b = restaurantes[i + 1]
            
            distancia_total += haversine((punto_a["latitud"], punto_a["longitud"]),
                                         (punto_b["latitud"], punto_b["longitud"]))
            
        if distancia_total > mayor_distancia:
            mayor_distancia = distancia_total
            nombre = gourmet["nombre"]

    return nombre
    
def main():
    restaurantes = []
    gourmets = []
    
    # ? Ejercicio 1
    cargar_restaurantes(restaurantes)
    
    # Mostrar los restaurantes
    for restaurante in restaurantes[:5]:
        print(restaurante["nombre"])
        
    # ? Ejercicio 2
    generar_gourmets(restaurantes, gourmets)
    
    # Mostrar los 5 primeros gourmets
    for gourmet in gourmets[:5]:
        print(gourmet["nombre"])
        
    # ? Ejercicio 3
    print("Gourmet más caro: ")
    gourmet = gourmet_mas_caro(gourmets)
    print(gourmet["nombre"], " presupuesto: ", presupuesto_gourmet(gourmet))
    
    # ? Ejercicio 4
    print("Restaurante más visitado: ", restaurante_mas_visitado(gourmets))
    
    # ? Ejercicio 5 y 6
    guardar_visitas(gourmets_por_estilo(gourmets))
    
    # ? Ejercicio 7
    print("Gourmet que ha recorrido más distancia: ", gourmet_mayor_viaje(gourmets))
    
    
if __name__ == "__main__":
    main()