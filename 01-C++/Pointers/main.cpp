#include <iostream>
#include <string>

using namespace std;

struct Persona
{
    string nombre;
    int edad;
};

// ! Punteros: Es una variable que apunta a una dirección de memoria.
int main()
{
    // ? Como funciona la memoria en C++
    int i = 5;

    /*
     * Lo que ocurre en memoria:
     * - Se reserva una espacio(4 bytes)
     * - Tiene una direccion de memoria (ej: 0x1234)
     * - Se almacena el varlor 5. [000000101]
     * Idea clave: Toda variable tiene una direccion de memoria.
     */

    // ? Que es un puntero
    /*
     * Un puntero es una variable que guarda un direccion
     * de memoria de otra variable.
     */
    int *p; // ! Declaracion de un puntero a entero
    // * No guarda un numero normal
    // * Guarda una direccion de memoria [ej: 0x1234]

    // ? Operacion & (obtener direccion de memoria)
    int *p1 = &i; // ! p1 apunta a la direccion de memoria de i
    // * &i = direccion de memoria de i
    // * p1 -> apunta a la direccion de memoria de i

    // ? Operador * (desreferenciar)
    /*
     * *p: significa "ve a la direccion de memoria que guarda p 
     * y dame el valor que tiene"
     */
    int *p2 = &i;
    cout << *p2 << endl; // -> Imprime el valor de i (5)

    // ? Errores comunes con punteros
    int *p3; 
    // *p3 = 10;
    // ! Esto es un error porque p apunta a una direccion aleatoria.
    // ! Se está escribiendo en memoria aleatoria. 

    // ? Formas correctas de usar punteros
    int *p4 = &i; // * p4 apunta a la direccion de memoria
    int *p5 = nullptr; // * p5 no apunta a ninguna direccion de memoria

    // ? Acceso indirecto (clave)
    int k = 24;
    int *p6 = &k; // * p6 es quivalete a &k

    *p6 = 12;
    cout << k << endl; // -> Imprime 12
    *p6 = 10;
    cout << k << endl; // -> Imprime 10   
    // * El acceso indirecto es clave para modificar
    // * el valor de una variable a través de un puntero.

    // ? Varios punters apuntando a la misma variable
    int x = 50; // * La posicion de memoria de x nunca cambia.
    int *p7 = &x;
    int *p8 = &x;
    // * p7---
    // *      |--> x (50)
    // * p8---

    *p7 = 30; // * Modifica el valor de x a través de p7
    cout << x << endl; // -> Imprime 30
    cout << *p8 << endl; // -> Imprime 30 (porque p8 también apunta a x)

    // ? Punteros con estructuras
    // * Utilizamos la estructura Persona previamente definida

    Persona per1 = {"Christian", 25};

    Persona *p9 = &per1; 

    cout << per1.nombre << endl; // -> Imprime "Christian"
    cout << p9->edad << endl; // -> Imprime 25 (acceso a la edad a través de p9)
    
    p9->edad = 30; // * Modifica la edad de per1 a través de p9
    cout << p9->edad << endl; // -> Imprime 30
    
    (*p9).nombre = "Maria"; 
    cout << per1.nombre << endl; // -> Imprime "Maria" (modificado a través de p9)
    /*
    * Ve a la direccion de memoria que guarda p9 (devuelve per1).nombre
    */ 



    return 0;
}
