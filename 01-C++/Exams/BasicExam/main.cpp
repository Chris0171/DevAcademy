#include <iostream>
#include <string>

using namespace std;

// Protoype of the function

int main()
{
    // Q 1:
    // Variable que controla nombre de usuario
    string nombreUsuario = "Manu";

    /*
    imprimir menu
    1. Saludar
    2. Despedir
    3. Salir
    */

    // Q2:
    string texto = "Hola Mundo";
    // Imprimir texto completo
    cout << texto << endl;
    // impirmir el cuarto caracter de mi texto
    // [H, o, l, a,  , M, u, n, d, o]
    // 0   1  2  3  4  5  6  7  8  9
    cout << texto[3] << endl;
    // imprimir sexto caracter
    cout << texto[5] << endl;

    // Q3: 
    int a = 5;
    int b = 10;
    double resultado = a / b;

    // Q4:
    string nombre = "Manuel"; // Variable de tipo string
    cout << nombre.length() << endl; // Imprime la longitud del string

    // Q5:
    string saludo = "Hola "; // Variable tipo string 1 para concatenar
    string str = "mundo"; // Variable tipo string 2 para concatenar

    string saludoCompleto = saludo + str; // Concatenación de ambos strings
    
    return 0;
}

// Implementation of the function
