#include <iostream>
#include "user.h"
using namespace std;

#include <string>

struct Usuario
{
    string name;
    string email;
};


int main() {

    Usuario usuarioStruct;
    usuarioStruct.name = "John Doe";
    usuarioStruct.email = "john.doe@example.com";


    User usuario = User("John Doe", "john.doe@example.com", "password123");

    cout << "Acceder a contraseña con email correcto: " << usuario.getPassword("john.doe@example.com") << endl;
    cout << "Acceder a contraseña con email incorrecto: " << usuario.getPassword("wrong.email@example.com") << endl;

    cout << "Nombre del usuario: " << usuario.getName() << endl;
    cout << "Email del usuario: " << usuario.getEmail() << endl;

    return 0;
}
