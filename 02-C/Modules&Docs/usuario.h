#ifndef USUARIO_H
#define USUARIO_H

// * Declaración de la estructura Usuario
struct Usuario
{
    // * Declaración de los atributos de la estructura
    int id;
    char nombre[50];
    char email[50];
    int edad;
};

/// * Declaración del numero PI
const int PI = 3.1416;

// * Array de numeros y un puntero al array
int numeros[] = {1, 2, 3, 4, 5};
int *pNumeros = numeros;

#endif