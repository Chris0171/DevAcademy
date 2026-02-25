# Examen C++ — Preguntas y Ejemplos

---

## Q1. Indica dos formas de añadir comentarios dentro del código en el lenguaje C++:

- Comentarios de una sola línea (`//`) son útiles para hacer anotaciones breves o explicar líneas específicas de código.
- Comentarios de múltiples líneas (`/* ... */`) son útiles para bloques grandes de texto o documentación extensa.

---

## Q2. Declara una variable que pueda almacenar un breve texto y explica cómo se puede acceder a cada uno de los caracteres que lo forman:

El operador de índice permite acceder directamente a los caracteres de un string especificando su posición.

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string text = "Hola, mundo!";
    cout << "El primer carácter es: " << text[0] << std::endl;
    cout << "El quinto carácter es: " << text[4] << std::endl;
    return 0;
}
```

---

## Q3. Escribe con tres líneas de código la declaración de variables y la operación necesaria para recoger en la variable "resultado" la división entre dos números enteros (supongamos que ya estás dentro del main()):

```cpp
int a = 10, b = 2; // Declaración e inicialización de variables
double resultado; // Declaración de la variable "resultado"
resultado = a / b; // Cálculo de la división
```

---

## Q4. ¿Qué función se puede utilizar para obtener la longitud de un string y cómo se utiliza?

En C++, para obtener la longitud de un string, puedes utilizar la función `length()` o `size()` (son equivalentes). Ambas te proporcionan el número de caracteres del string, incluidos los espacios, pero no el carácter nulo `\0`.

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string text = "Hola, mundo!";
    // Obtener la longitud del string
    size_t longitud = text.length(); // O puedes utilizar text.size()
    cout << "La longitud del texto es: " << longitud << endl;
    return 0;
}
```

---

## Q5. ¿Cómo podemos "concatenar" dos strings? Escribe un ejemplo.

Concatenando con el operador `+`:

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s1 = "Hola";
    string s2 = " mundo";
    string resultado = s1 + s2; // Concatenación
    cout << resultado << endl; // Imprime: Hola mundo
    return 0;
}
```
