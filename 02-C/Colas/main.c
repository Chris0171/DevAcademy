#include <stdio.h>
#include <stdlib.h>


// * Estructura de datos(Pila)
// * Estructura Nodo

// const int MAX = 20;

typedef struct Nodo{
    int valor;
    struct Nodo *sig;

} Nodo;

typedef struct Cola{
    Nodo *frente;
    Nodo *final;
    // int size;
} Cola; 



//Nodo4 -> Nodo3 -> Nodo2 -> Nodo1
// Nodo1 -> h -> h -> h 


// Utilizas -> cuando se crea una estructura como puntero.

void encolar(Cola *cola, int valor){
    Nodo *nuevoNodo = (Nodo*)malloc(sizeof(Nodo)); // Reservar memoria para el nuevo nodo.
    // Guardar el valor en el nodo
    nuevoNodo->valor = valor;
    // El nodo siguiente debe apuntar a NULL
    nuevoNodo->sig = NULL;

    // si la cola esta vacia
    if(cola->frente == NULL){
        cola->frente = nuevoNodo;
        cola->final = nuevoNodo;
    }else{
        // Insertar al final de
        //  la cola
        cola->final->sig = nuevoNodo; // El nodo final apunta al nuevo nodo.
        cola->final = nuevoNodo; // El final de la cola ahora es el nuevo nodo.
    }

}

void desencolar(Cola *cola){
    if(cola->frente != NULL){
        Nodo *aux = cola->frente; // Guardar el nodo que se va a eliminar.

        aux = aux->sig;

        if(aux == NULL){
            cola->final = NULL;
        }

        free(cola->frente); // Liberar la memoria del nodo que se va a eliminar.
        cola->frente = aux; // El frente de la cola ahora es el siguiente nodo

    }else{
        printf("La cola esta vacia\n");
    }
}

void mostrar(Cola *cola){
    if (cola->frente != NULL){
        Nodo *aux = cola->frente; // Guardar el nodo que se va a mostrar.

        while(aux != NULL){
            printf("%d\n", aux->valor);
            aux = aux->sig; // Avanzar al siguiente nodo.
        }
    }{
        pirntf("La cola esta vacia\n");
    }

}

// a -> 23  b y c 



int main(){

    Cola *cola = (Cola*)malloc(sizeof(Cola)); // Reservar memoria para la cola.
    encolar(cola, 1);
    encolar(cola, 2);
    encolar(cola, 3);

    mostrar(cola);

    desencolar(cola);

    mostrar(cola);
    
    return 0;
}

// 3
// 2
// 1
// -  
/* void eliminar(Pila *pila){
    Nodo *temp = pila->head;
    temp = temp->sig;

    free(pila->head);

    pila->head = temp;

}
void recorrer(Pila *pila){
    Nodo *temp = pila->head;

    while(temp != NULL){
        printf("%d\n", temp->valor);
        temp = temp->sig;
    }
} */