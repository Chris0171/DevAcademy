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
    
    return 0;
}
