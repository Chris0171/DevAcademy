#include <iostream>
#include "Persona.h"

using namespace std;

void redimesionar(Persona *&personas, int nuevaCapcidad)
{
    // Creamos un nuevo arreglo con la nueva capacidad
    Persona *aux = new Persona[nuevaCapcidad];
    
    for(int i = 0; i < capacidad; i++){
        aux[i] = personas[i];
    }
    delete[] personas; // * Liberamos la memoria de array antiguo 
    personas = aux; // * Actualizamos el puntero para que apunte al nuevo
    capacidad = nuevaCapcidad; // * Actualizamos la capacidad global
}


int main()
{
    Persona *pers = new Persona[capacidad];
    pers[0] = {"Juan", 30, "Madrid"};
    pers[1] = {"Maria", 28, "Barcelona"};
    pers[2] = {"Pedro", 35, "Valencia"};
    pers[3] = {"Ana", 32, "Sevilla"};
    pers[4] = {"Luis", 29, "Bilbao"};

    for (int i = 0; i < capacidad; i++)
    {
        cout << pers[i].nombre << endl;
    }

    redimesionar(pers, 7);
    pers[5] = {"Sofia", 27, "Granada"};
    pers[6] = {"Diego", 31, "Zaragoza"};

    for (int i = 0; i < capacidad; i++)
    {
        cout << pers[i].nombre << endl;
    }

    delete[] pers;
    pers = nullptr;

    return 0;
}

// ? Tarea:
// * - Implementar una función de motrar array teniendo en cuento su capacidad redimensionable. 
// * - Crear un función insertar que agregue elementos al array, 
// * si al hacer la inserción se supera la capacidad, se debe redimensionar
// * - Crear una función eliminar que elimine un elemento del array,
// * opcionalmente: si eliminas un elemento apartir de su maximo, redimensiones el array.

