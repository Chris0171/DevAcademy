#include <iostream>
#include <string>

using namespace std;

// Protoype of the function
string modifcaMensaje(string mensaje);
int suma(int a, int b);

int main() {
    string str = "Hola mundo";
    cout << str << endl;
    
    str = modifcaMensaje(str);

    cout << str << endl;

    int r = suma(5, 10);
    cout << r << endl;
    
    return 0;
}

// Implementation of the function
string modifcaMensaje(string mensaje) {
    mensaje += ", estoy cansado";
    return mensaje;
}

int suma(int a, int b){

    return a + b;
}