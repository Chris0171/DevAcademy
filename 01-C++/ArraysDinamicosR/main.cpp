#include <iostream>
#include <string>

using namespace std;

int capacidad = 0;
struct Empleado
{
    string nombre;
    int edad;
    double salario;
};

int main()
{
    capacidad = 5;
    Empleado *empleados = new Empleado[capacidad];

    empleados[0] = {"Juan", 30, 2500.50};
    empleados[1] = {"Maria", 28, 3000.75};
    empleados[2] = {"Pedro", 35, 2800.00};
    empleados[3] = {"Ana", 32, 3200.25};
    empleados[4] = {"Luis", 29, 2700.80};

    for (int i = 0; i < capacidad; i++)
    {
        cout << empleados[i].nombre << endl;
    }
    // Sumpongamos que queremos ampliarlo a 20 empleados.
    int capacidadActual = capacidad;

    // Actualizamos la capacidad a 20
    capacidad = 20;

    Empleado *empleadosPlus = new Empleado[capacidad];

    for (int i = 0; i < capacidadActual; i++)
    {
        empleadosPlus[i] = empleados[i];
    }

    for (int i = 0; i < capacidad; i++)
    {
        if (empleadosPlus[i].nombre != ""){
            cout << empleadosPlus[i].nombre << endl;
        }
    }

    empleados = empleadosPlus;

    delete[] empleadosPlus;
    empleadosPlus = nullptr;
    
    empleadosPlus = new Empleado[50];

    for(int i = 0; i < capacidad; i++)
    {
        empleadosPlus[i] = empleados[i];
    }
    empleados = empleadosPlus;

    // * Empleado *empleados = new Empleado[5];
    // *Empleado *empleadosPlus = new Empleado[20];* /

    // * empleados = newEmpleado[20];
    // * delete[] empleadosPlus * /
    // * empeladosPlus = nullptr * /

    delete[] empleadosPlus;
    empleadosPlus = nullptr;



    return 0;
}
