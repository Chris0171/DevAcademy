#include <stdio.h>
#include <stdlib.h>


void incrementar(int *num){
    (*num)++;
}
void mostrar(const int *num){
    printf("Valor: %d\n", *num);
    // (*num)++; // * num es constante, no se puede modificar
}
int* crearPuntero(){
    int *p = malloc(sizeof(int)); 
    *p = 200;

    return p;
}

int main(){
    // ? Que es un puntero en C?
    // * - Variable normal: Almacena un valor
    int i = 10;

    // * - Puntero: Apunta a una dirección de memoria
    int *p1 = &i; // * p1 apunta a la dirección de memoria de i

    printf("valor: %d\n", *p1); // * *p1 accede al valor
    printf("direccion: %p\n", p1); // * direccion de memoria de i

    // * - Operadores de punteros:
    // * [&] -> Operdador de dirección: devuelve la dirección de memoria.
    // * [*] -> Operador de indirección: devuelve le valor

    // ? Asignacion de punteros.
    int j = 20;
    int *p2 = &j;

    printf("Valor de j: %d\n", *p2);
    
    int k = 40;
    p2 = &k;
    printf("Valor de k: %d\n", *p2);

    *p2 = 50;
    printf("Valor de k: %d\n", k);

    // ? Punteros como argumentos de funciones.

    int num = 5; 
    int *pNum = &num;

    //incrementar(pNum);
    incrementar(pNum);
    printf("Valor de num: %d\n", num);
    
    // ? Proteger argumentos
    int num2 = 60;
    int *pNum2 = &num2;
    mostrar(pNum2);

    // ? Devolver punterso desde funciones
    int *pNum4 = crearPuntero(); // * Crear un puntero dinámicamente.
    printf("Valor de pNum4: %d\n", *pNum4);

    free(pNum4);

    return 0;
}