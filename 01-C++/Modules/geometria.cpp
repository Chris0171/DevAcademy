#include "geometria.h"


int area_recangulo(int base, int altura) {
    return multiplicar(base, altura);
}

int perimetro_recangulo(int base, int altura) {
    return multiplicar(2, sumar(base, altura));
}
