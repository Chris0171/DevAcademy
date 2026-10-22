#include <iostream>
#include <string>

using namespace std;

int main()
{
    // Creacion de juego
    string titulo = "===Menu minecraft===";
    string opciones[4] = {"Jugar", "Ajustes", "Lenguaje","Salir"};

    cout << titulo << endl;

    cout << opciones[0] << endl;
    cout << opciones[1] << endl;
    cout << opciones[2] << endl;
    cout << opciones[3] << endl;

    cout << "Seleccione una opción: " << endl;
    int opcion;
    cin >> opcion;


    cout << opciones[opcion - 1] << endl;



   
    return 0;
}
