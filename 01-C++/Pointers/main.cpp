#include <iostream>
#include <string>

using namespace std;

struct Persona
{
    string nombre;
    int edad;
};

// ! Punteros: Es una variable que apunta a una dirección de memoria.

void incrementar(int *p){
    (*p)++;
}
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

    // ? Constantes en punteros
    const int *p10;

    // * NO se puede modificar el valor
    // * Si puedes cambiar el valor a donde apunta.
    
    int y = 320;
    int t = 500;
    p10 = &y;

    cout << *p10 << endl; // -> Imprime 320

    p10 = &t; // * Cambia el valor a donde apunta p10
    cout << *p10 << endl; // -> Imprime 500

    int *const p11 = &y;
    // Si se puede cambiar el valor, pero no se puede cambiar a donde apunta
    *p11 = 100; // * Modifica el valor de y a través de p11
    cout << *p11 << endl; // -> Imprime 100

    // ? Paso de punteros por referencia en funciones
    // ** Consultar funcion incrementar al inicio del codigo
    int q = 2;
    int *p12 = &q;

    incrementar(p12); // * Envio un puntero a la funcion
    cout << q << endl;

    incrementar(&q); // * Envio la direccion de memoria de q
    cout << q << endl;

    // ? Arrays y punteros
    int arr[5] = {10, 20, 30, 40, 50};
    int *p13 = arr; // * Un array es un puntero a su primer elemento

    cout << *p13 << endl;

    // ? Memoria: stack(pila) y heap(monticulo)
    // * Stack: La memoria donde se guardan las variables locales y punteros.
    int a = 5; // * a se guarda en el stack

    // * Heap: La memoria donde se guardan los objetos creados dinámicamente.
    // * Ejemplo: Crear un objeto Persona en el heap
    Persona *p14 = new Persona{"Ana", 28}; // * p14 apunta

    // ? Memoria dinámica: new y delete
    // * La memoria dinamica:
    // * - Se reserva en tiempo de ejecucion con new
    // * - Se debe liberar manualmente con delete
    // * - La memoria la controlas tu (no el sistema)
    
    int b = 10; // * memoria automatica (stack) 
    // * Aquí el sistema la crea y la destruye automáticamente. 

    // ** Por qué usar memoria dinámica?
    // * - Cuando no sabes el tamaño de datos(ej: arrays dinámicos)
    // * - Cuando necesitas crear y destruir objetos durante el programa
    // * - Cuando quieres estructuras flexibles (ej: listas enlazadas, árboles, pilas, colas.)

    int n; 
    cin >> n; // * El usuario ingresa el tamaño del array

    int *arr2 = new int[n]; // * Crea un array dinámico de tamaño n en el heap

    // * Como funciona el new: 
    int *p15 = new int; 
    // * Que pasa internamente:
    // * - El programa pide memoria al sistema
    // * - El sistema busca espacio libre en el heap
    // * - Devuelve la direccion de memoria donde se asigno el espacio
    // * - Esa direccion se guarda en p15

    int c = 20; // * Variable en el stack
    // * En memoria dinámica no hay nombre(x)
    // * Solo hay direcciones de memoria y valores.


    // ** Liberar memoria delete y delete[]
    delete[] arr2; // * Libera la memoria del array dinámico
    delete p15; // * Libera la memoria asignada a p15
    // * Liberar la memoria en el heap 
    // * El sistema reutilizar esa memoria
    // ! Pero: p15 sigue existiendo, pero apunta a una basura (puntero colgante)
    p15 = nullptr; // * Evita el uso de un puntero colgante

    // ? Errores Criticos con memoria dinámica

    // ! MEMORY LEAK: Ocurre cuando se asigna memoria dinámica pero no se libera.
    int *p16 = new int;
    
    delete p16; // * Si esta linea no se escribe, produce un memory leak
    // ! Problema: La memoria está ocupada para siempre.
    // ! No se puede recuperar. Eso se le llama "fuga de memoria"

    // ! Perder la referencia
    int *p17 = new int;
    // p17 = new int; // ! ERROR: 
    // ! La primera memoria ya no tiene puntero.
    // ! Se pierde la referencia a esa memoria y no se puede liberar.
    delete p17; // * Si se hace esto, solo se libera la segunda memoria, la primera queda ocupada para siempre.
    p17 = nullptr; 

    // ! Usar después de liberar
    int *p18 = new int;
    delete p18; // * Libera la memoria asignada a p18
    p18 = nullptr; 
    // *p18 = 10; // ! ERROR: Se está escribiendo en memoria que ya fue liberada (puntero colgante)

    return 0;
}
