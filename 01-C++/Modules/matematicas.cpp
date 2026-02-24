#include "matematicas.h"
#include <iostream>

//implemtacion 
// private
int sumar(int a, int b){
    return a + b;
}
// private
int restar(int a, int b){
    return a - b;
}
// private
int multiplicar(int a, int b){
    return a * b;
}
// private
int dividir(int a, int b){
    if (b != 0) {
        return a / b;
    } else {
        std::cout << "Error: División por cero no permitida." << std::endl;
        return 0; // o podrías lanzar una excepción
    }
}

void mostrarResultados(int a, int b) {
    std::cout << "Suma: " << sumar(a, b) << std::endl;
    std::cout << "Resta: " << restar(a, b) << std::endl;
    std::cout << "Multiplicación: " << multiplicar(a, b) << std::endl;
    std::cout << "División: " << dividir(a, b) << std::endl;
}