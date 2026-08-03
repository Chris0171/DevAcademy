import random

#EJERCICIO 1
def cargar_participantes(participantes):

    fichero = open("decode.csv", "r", encoding="utf-8")

    for linea in fichero:

        linea = linea.strip()

        if linea == "":
            continue

        datos = linea.split(";")

        nick = datos[0]
        curso = int(datos[1])
        intereses = datos[2].split(",")

        participante = {
            "nick" : nick,
            "curso" : curso,
            "intereses" : intereses
        }

        participantes.append(participante)

    fichero.close()


#EJERCICIO 2
def identificar_intereses(participantes):
    intereses = []

    for participante in participantes:
        for interes in participante["intereses"]:
            if interes not in intereses:
                intereses.append(interes)
    
    return intereses


#EJERCICIO 3
def generar_eventos(participantes):

    eventos = []
    intereses = identificar_intereses(participantes)

    for mes in range(1, 13): # recorrer los 12 meses

        for i in range(3): #3 eventos por mes
            actividad = random.choice(intereses)
            dia = random.randint(1, 28)
            lista_participantes = random.sample(participantes, 4)

            evento = {
                "actividad" : actividad,
                "fecha": [2025, mes, dia],
                "participantes": lista_participantes
            }

            eventos.append(evento)

    return eventos


#EJERCICIO 4 
def contar_interesados(evento):
    contador = 0

    for participante in evento["participantes"]:

        if evento["actividad"] in participante["intereses"]:
            contador += 1

    return contador


def evento_mas_intereses(eventos):

    mejor = eventos[0]
    max = contar_interesados(mejor)

    for evento in eventos:
        interesados = contar_interesados(evento)

        if interesados > max:

            max = interesados
            mejor = evento

    return mejor


#EJERCICIO 5
def guardar_eventos(eventos):

    fichero = open("eventos.csv", "w", encoding = "utf-8")

    for evento in eventos:
        linea = evento["actividad"] + ";"

        linea += str(evento["fecha"][0]) + ";"
        linea += str(evento["fecha"][1]) + ";"
        linea += str(evento["fecha"][2]) + ";"

        for participante in evento["participantes"]:
            linea += participante["nick"] + ";" 
        
        fichero.write(linea + "\n")

    fichero.close()


#EJERCICIO 6
def intereses_peculiares(eventos):

    diccionario = {}

    for evento in eventos:
        for participante in evento["participantes"]:
            for interes in participante["intereses"]:
                if interes not in diccionario:

                    diccionario[interes] = []
                
                if participante["nick"] not in diccionario[interes]:
                    diccionario[interes].append(participante["nick"])
        
    menor_interes = None
    menor = 999999999

    for interes in diccionario:
        cantidad = len(diccionario[interes])

        if cantidad < menor:
            menor = cantidad
            menor_interes = interes

    return diccionario[menor_interes]


#EJERCICIO 7
def copia_eventos(eventos):

    eventos_copia = []  #crear copia de los eventos

    for evento in eventos: #recorrer cada evento y crear diccionario
        diccionario = {
            "actividad" : evento["actividad"],
            "fecha": evento["fecha"][:],
            "participantes": []
        }

        for participante in evento["participantes"]:  #recorrer participantes y crear diccionario
            dicc_participante = {
                "nick": participante["nick"],
                "curso": participante["curso"],
                "intereses": participante["intereses"][:]
            }

            diccionario["participantes"].append(dicc_participante) #añadir los participantes al evento

        eventos_copia.append(diccionario)
    
    return eventos_copia



def mover_participantes(eventos):

    copia = copia_eventos(eventos)

    for i in range(len(eventos)): 

        evento_original = eventos[i]

        for participante in evento_original["participante"]:

            if evento_original["actividad"] not in participante["intereses"]:
                print("A " +  participante["nick"] + " no le interesa " + evento_original["actividad"] + "...")
                
                encontrado = False
                for j in range(len(eventos)):
                    if i == j:
                        continue
                    otro_evento = eventos[j]
                    if(otro_evento["actividad"] in participante["intereses"]):
                        econtrado_ya = False
                        for k in otro_evento["participantes"]:
                            if k["nick"] == participante["nick"]:
                                encontrado_ya = True
                        if not encontrado_ya:
                            remplazo = None
                            for k in otro_evento["participantes"]:
                                if k["nick"] == participante["nick"]:
                                    remplazo = k
                                    break
                                
                            if remplazo is not None:
                                copia[i]["participantes"].remove(participante)
                                copia[i]["participantes"].append(remplazo)
                                copia[j]["participantes"].remove(participante)
                                copia[j]["participantes"].append(remplazo)
                                
                                print("Intercambiando a " + participante["nick"] +
                                      " para que vaya al evento " +  otro_evento["actividad"]
                                      +  otro_evento["fecha"] + " en lugar de "
                                      + evento_original["actividad"] + 
                                      evento_original["fecha"] + ["..."] if False else "...")
                                
                                encontrado = True
                                break
            if not encontrado:
                print("No hay enventos que interesen a " + participante["nick"] + " en los que no participe")
    
    return copia
                        
                            
    