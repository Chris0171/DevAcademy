#include <stdio.h>
#include <stdlib.h>


void imprimirArray(int valores[], int size){
    for(int i = 0; i < size; i++){
        printf("Valor: %d\n", valores[i]);
    }
}
// * La función anterior tambié se puede escribir así:
/*
* Función muestra los valores del array
* @param valores El puntero al primer elemento del array
* @param size El tamaño del array
* @return void 
*/
void mostrarArray(int *valores, int size){
    for(int i = 0; i < size; i++){
        printf("Valor: %d\n", *(valores + i));
    }
}
// * En C, los arrays que se pasan como parametros se pueden podificar
void modificarArray(int v[]){
    v[0] = 1000;
}


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

    // ? Recorrer arrays de forma clasica
    int nums[4] = {5, 10, 15, 20};

    for(int i = 0; i < 4; i++){
        printf("Valor: %d\n", nums[i]);
    }

    // ? Recorrer arrays con punteros
    int *pNums = nums; 
    for(int i = 0; i < 4; i++){
        printf("Valor: %d\n", *(pNums + i));
    }

    // ? Forma avansada de recorrer arrays con punteros
    while(pNums < nums + 4){
        printf("Valor: %d\n", *pNums);
        pNums++;
    }

    // ? Uso del nombre del array como puntero
    int numeros[4] = {20, 40, 60, 80};
    // * numeros se comporta como &numeros[0]
    int *pNumeros = numeros; 
    // * int *pNumeros = &numeros[0]; Otra forma de escribirlo
    
    // * Pasar array como argumentos a una función.
    imprimirArray(numeros, 4);
    mostrarArray(valores, 3);

    // * Modificar un array dentro de una función.
    // * Simpre se pasa por referencia.
    modificarArray(valores);
    printf("Valor: %d\n", valores[0]);

    // ? Punteros y arrays multidimensionales
    // * Arrays normal de 1 dimensión [10, 20, 30]
    // * Arrays de 2 dimensiones [[1, 2], [3, 4]]
    int tabla[2][3]= {
        {1, 2, 3},
        {4, 5, 6}
    };
    printf("Valor: %d\n", tabla[0][2]);

    int (*pTabla)[3] = tabla;

    printf("Valor: %d\n", *(*(pTabla) + 1));

    // * v[i] == *(v+i) -> Recorrer arrays
    // * El nombre del array es un puntero al primer elemento
    // * Los arrays se pueden pasar a funciones, y estas se puenden modifiar.
    // * En matrices, el nombre del array es un puntero a un array de columnas.
    // * -> m[i][j] == *(*(m+i)+j)

    return 0;
}