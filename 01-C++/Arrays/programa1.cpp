#include <iostream>
#include <string>

using namespace std;

struct Empleado
{
    string nombre;
    string codigoEmpleado;
    int edad;
};
// {"Christian", "E001", 25}

int main()
{
    int numeroEmpleados = 0;
    cout << "Ingrese el numero de empleados: ";
    cin >> numeroEmpleados;

    // Empleado emp1 = {"Christian", "E001", 25}; -> Inicialización de un solo empleado

    Empleado listaEmpleados[numeroEmpleados]; // [{"Christian", "E001", 25}, {}, {}, ...]

    for (int i = 0; i < numeroEmpleados; i++)
    {
        cout << "Ingrese el nombre de empleado " << i + 1 << ": ";
        cin >> listaEmpleados[i].nombre;
        cout << "Ingrese el codigo de empleado " << i + 1 << ": ";
        cin >> listaEmpleados[i].codigoEmpleado;
        cout << "Ingrese la edad de empleado " << i + 1 << ": ";
        cin >> listaEmpleados[i].edad;
        // limpiar el buffer de entrada para evitar problemas con la lectura de cadenas
        cin.ignore();
    }
    for (int i = 0; i < numeroEmpleados; i++)
    {
        cout << "Empleado con codigo " << listaEmpleados[i].codigoEmpleado << endl;
        cout << "Nombre: " << listaEmpleados[i].nombre << endl;
        cout << "Edad: " << listaEmpleados[i].edad << endl;

        switch (listaEmpleados[i].edad)
        {
        case 18:
            cout << "El empleado acaba de cumplir la mayoria de edad" << endl;
            break;
        case 25:
            cout << "El empleado esta en la flor de la vida" << endl;
            break;
        case 16: 
            cout << "El empleado es menor de edad" << endl;
            break;
        default: 
            cout << "El empleado tiene una edad diferente" << endl;
            break;
        }
    }

    return 0;
}
