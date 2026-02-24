#include <iostream>
#include "geometria.h"

using namespace std;

int main() {
    
    mostrarResultados(10, 5);

    cout << "El área de un rectángulo de base 4 y altura 6 es: " << area_recangulo(4, 6) << endl;
    cout << "El perímetro de un rectángulo de base 4 y altura 6 es: " << perimetro_recangulo(4, 6) << endl;

    return 0;
}
