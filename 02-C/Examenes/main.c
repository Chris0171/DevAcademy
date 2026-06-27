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

bool anadirPedido(Pedido pedidos[], int *numPedidos){
    bool anadido = false;
    if(*numPedidos < MAX_PEDIDOS){
        // Añadir pedido
        Pedido nuevoPedido;
        printf("Nombre del destinatario: ");
        getchar(); // Limpiar el buffer de entrada
        fgets(nuevoPedido.destinatario, 101, stdin);

        nuevoPedido.destinatario[strcspn(nuevoPedido.destinatario, "\n")] = '\0';
        // strcspn -> devuelve la posiscion que corresponde a una cadena de caracteres

        printf("Identificador: ");
        scanf("%d", &nuevoPedido.identificador);

        int opcionTipo;

        printf("Tipo de pedido: \n");
        printf("1- [NORMAL]\n");
        printf("2- [URGENTE]\n");
        printf("3- [PREMIUM]\n");
        scanf("%d", &opcionTipo);

        while(opcionTipo < 1 || Opcion > 3){
            printf("Opcion no válida. Teclee 1, 2 0 3:");
            scanf("%d", &opcionTipo);
        }
        // nuevoPedido  = (TipoPedidos) opcionTipo -1;
        switch(opcionTipo){
           case 1: nuevoPedido.tipo = NORMAL; break;
           case 2: nuevoPedido.tipo = URGENTE; break;
           case 3: nuevoPedido.tipo = PREMIUM; break;
        }

        printf("Tecle numero de productos (máximo %d): ", MAX_PRODUCTOS);
        scanf("%d", &nuevoPedido.numProductos);
        while(nuevoPedido.numProductos < 1 || nuevoPedido.numProductos > MAX_PRODUCTOS){
            printf("Número de productos inválido. Teclee un número entre 1 y %d: ", MAX_PRODUCTOS);
            scanf("%d", &nuevoPedido.numProductos);
        }
        
        getchar(); // Limpiar

        for(int i = 0, i < nuevoPedido.numProductos; i++){
            printf("Tecle el nombre del producto %d \n", i + 1);
            printf("Nombre: ");
            fgets(nuevoPedido.productos[i].nombre, 51, stdin);
            nuevoPedido.productos[i].nombre[strcspn(nuevoPedido.productos[i].nombre, "\n")] = '\0';
            
            printf("Precio: ");
            scanf("%f", &nuevoPedido.productos[i].precio);

            getchar(); // Limpiar
        }
        
        
        pedidos[*numPedidos] = nuevoPedido;
        (*numPedidos)++;

        printf("Pedido añadido con éxito\n");

        anadido = true;
    }
    return anadido;
}

int contarPedidosTipo(Pedido pedidos[], int numPedidos, TipoPedidos tipo){
    int contador = 0;
    for(int i = 0; i < numPedidos; i++){
        if(pedidos[i].tipo == tipo) contador++;
    }
    return contador;
}
// Obtener el coste total de los pedidos de un usuario
float costeTotalPorUsuario(Pedido pedidos[], int numPedidos, const char *usuario){
    float costeTotal = 0;
    for(int i = 0; i < numPedidos; i++){
        if(strcmp(pedidos[i].destinatario, usuario) == 0){

            for(int j = 0; j <pedidos[i].numProductos; j++){
                costeTotal += pedidos[i].productos[j].precio;
            }
        }
    }
    return costeTotal;
}


int main(){
    int opcion = 0; 
    Pedido pedidos[MAX_PEDIDOS];
    int numPedidos = 0;
    
    do{
        printf("\n======= AMAZON - Gestión de Pedidos =======\n");
        printf("1. Almacenar un nuevo pedido\n");
        printf("2. Obtener numero de pedidos de tipo NORMAL ipo\n");
        printf("3. Obtener numero de pedidos de tipo URGENTE po\n");
        printf("4. Obtener numero de pedidos de tipo PREMIUM\n");
        printf("5. Obtener precio total de los pedidos de un usuario\n");
        printf("6. Salir\n");

        printf("Seleccione una opción: ");
        scanf("%d", &opcion);
        switch(opcion){
            case 1: break;
            case 2: printf("Total de pedidos de tipo NORMAL: %d\n", contarPedidosTipo(pedidos, numPedidos, NORMAL)) break;
            case 3: printf("Total de pedidos de tipo URGENTE: %d\n", contarPedidosTipo(pedidos, numPedidos, URGENTE)) break;
            case 4: printf("Total de pedidos de tipo PREMIUM: %d\n", contarPedidosTipo(pedidos, numPedidos, PREMIUM)) break;
            case 5: 
            char nombre[101];
            getchar();
            printf("Teclee el nombre del usuario: ");
            fgets(nombre, 101, stdin);
            nombre[strcspn(nombre, "\n")] = '\0';

            printf("Coste total de los pedidos de %s: %.2f\n", 
                nombre, costeTotalPorUsuario(pedidos, numPedidos, nombre));
            break;
            case 6: printf("Saliendo...\n"); break;
            default: printf("Opción inválida\n"); break;
        }
    }while(opcion != 6); 
    
    return 0;
}


