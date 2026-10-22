#include <iostream>
#include <string>

using namespace std;


/*
    Array: es una estructura de datos que almacenn una 
    lista de elementos del mismo tipo.
*/ 

int main()
{
    int miArray[5]; // [ , , , , ]
    string miArray2[3] = {"Christian", "Maria", "Manuel"}; // [ "Christian", "Maria", "Manuel" ]
    /*
     0  1  2  3  4
    [1, 2, 3, 4, 5]
    */
    miArray[0] = 1; // [1, , , , ]
    miArray[1] = 2; // [1, 2, , , ]
    miArray[2] = 3; // [1, 2, 3, , ]
    miArray[3] = 4; // [1, 2, 3, 4, ]
    miArray[4] = 5; // [1, 2, 3, 4, 5]

    int miArray3[40]; 

    // sizeof: operador que devuelve el tamaño en bytes de un tipo de dato o variable.
    cout << sizeof(miArray3) << endl;

    // sizeof(miArray3[0]): devuelve el tamaño en bytes del primer elemento del array, que es un entero (4 bytes).
    cout << sizeof(miArray3[0]) << endl;

    // Calculo para obtener el número de elementos totales
    int size = sizeof(miArray3)/sizeof(miArray3[0]);

    for(int i = 0; i < size; i++){
        miArray3[i] = i + 1;
    }

    
    for(int i = 0; i < sizeof(miArray3)/sizeof(miArray3[0]); i++){
        cout << miArray3[i] << "->";
    } 
    
    string inventario[30] = {};

         0   1  2  3
    // [ [] [] [] []...]
    inventario[0] = "Pico";
    inventario[1] = "Hacha";
    inventario[2] = "Espada";
    inventario[3] = "Bloque de madera";

    
    string item = inventario[0]; // item = pico
    inventario[0] = inventario[1];  // 0 = hacha, 
    inventario[1] = inventario[0]; // 1 = pico

    bool decisiones[1000] = {};

    // te quieres mover?
    decisiones[0] = true; // ejemplo: el jugador decide moverse
    decisiones[1] = false;
    // quieres saltar?
    decisiones[2] = true; // ejemplo: el jugador decide saltar
    // quieres comer?
    decisiones[3] = true; // ejemplo: el jugador decide comer

    int duracionPico[6] = {};

    duracionPico[0] = 200; // pico madera
    duracionPico[1] = 300; // pico piedra
    duracionPico[2] = 400; // pico cobre
    duracionPico[3] = 500; // pico hierro
    duracionPico[4] = 600; // pico oro
    duracionPico[5] = 700; // pico diamante
    
    // quieres picar piedra? 
    duracionPico[0] = duracionPico[0] - 2; // ejemplo: se usa el pico de madera, se reduce su duracion en 1
    duracionPico[0] = duracionPico[0] - 1;

    

    return 0;
}
