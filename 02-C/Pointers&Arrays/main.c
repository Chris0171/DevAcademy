#include <stdio.h>
#include <stdlib.h>

int main(){
    // ? Cual es la relación entre array y punteros
    // * El nombre de un array es un puntero constante a su primer elemento:
    int arr[5] = {1, 2, 3, 4, 5};
    int *pArr = arr;
    printf("Valor: %d\n", *(pArr + 2));

    // * arr[0] = *pArr
    // * arr[1] = *(pArr + 1)
    // * arr[2] = *(pArr + 2)
    // * arr[3] = *(pArr + 3)   
    // * arr[4] = *(pArr + 4)

    // ? Aritmetica de punteros
    // * Cuando haces operaciones con punteros
    // ! No avanzas 1 byte, avanzas el tamaño del tipo
    int v[3] = {10, 20, 30};

    int *pV = v; // * pV apunta a v[0]

    pV+=2;

    printf("Valor: %d\n", *pV);

    // ? Ejemplo tipico de examen
    int valores[3] = {100, 200, 300};
    int *pValores = valores;

    printf("Valor: %d\n", *(pValores+=2));

    


    return 0;
}