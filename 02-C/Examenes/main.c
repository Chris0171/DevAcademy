#include <stdio.h>


#define MAX_PRODUCTOS = 10
#define MAX_PEDIDOS = 100

typedef enum {
    NORMAl,
    URGENTE,
    PREMIUM
} TipoPedidos;

typedef struct{
    char nombre[51];
    float precio;
} Producto;

typedef struct{
    char destinatario[101];
    int identificador;
    TipoPedidos tipo;
    Producto productos[10];
    int numProductos;
} Pedido;

int main(){
    int opcion = 0; 
    
    do{
        printf("\n======= AMAZON - Gestión de Pedidos =======\n");
        printf("1. Almacenar un nuevo pedido\n");
        printf("2. Obtener numero de pedidos PREMIUM\n");
        printf("3. Obtener precio total de los pedidos de un usuario\n");
        printf("4. Salir\n");

        printf("Seleccione una opción: ");
        scanf("%d", &opcion);
        switch(opcion){
            case 1: break;
            case 2: break;
            case 3: break;
            case 4: printf("Saliendo...\n"); break;
            default: printf("Opción inválida\n"); break;
        }
    }while(opcion != 4); 
    
    return 0;
}

