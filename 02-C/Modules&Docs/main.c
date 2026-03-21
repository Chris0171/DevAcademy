#include <stdio.h>
#include "operaciones.h"
#include "usuario.h"
#include <stdlib.h>

void mostrarMensaje()
{
    printf("Hola desde otro modulo\n");
}

int main()
{
    // ? Que es programación modular
    // * Consiste en dividir un programa en partes pequeñas
    // * Cada modulo tiene un función específica
    // * Es independiente
    // * Se puede reutilizar

    mostrarMensaje();

    // * Ventajas
    // * Código más organizado
    // * Más fácil de mantener
    // * Reutilización de código
    // * Más fácil de entender y depurar

    // ? Estructura modular en C
    // * En C, Se trabaja con lo siguiente:
    // * Archivos de cabecera (archivos.h)
    // * Archivos de implementación (archivos.c)

    printf("La suma es: %d\n", sumar(5, 40));
    printf("La resta es: %d\n", restar(5, 40));
    printf("La multiplicación es: %d\n", multiplicar(5, 40));
    struct Usuario user = {1, "Chris", "chris@example.com", 25};

    printf("PI es: %.4f\n", PI);
    for(int i = 0; i < 5; i++){
        printf("Número %d: %d\n", i, *(pNumeros + i));
    }

    // ? Encapsulamiento
    // * Implica ocultar detalles internos
    // * Ejemplo: El usuario usa sumar() sin saber como está hecha

    // ? Documentación de código
    // * Explicar mediante comentarios el próposito de cada parte de tu código

    // ? Buenas prácticas al documentar.
    /*
    * Suma dos números enteros.
    * @param a El primer número entero
    * @param b El segundo número entero
    * @return El resultado de la suma
    */

    return 0;
}