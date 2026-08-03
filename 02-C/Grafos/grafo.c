#include <stdio.h>
#include <stdlib.h>

const int MAX = 20;

typedef struct Nodo{
    int vertice;
    struct Nodo *sig;

} Nodo;

typedef struct Grafo{
    int numVertices;
    Nodo matriz[MAX][MAX];

} Grafo;

void inicializarGrafo(Grafo *grafo, int numVertices){
    grafo->numVertices = numVertices;
    
    for(int i = 0; i < numVertices; i++){
        for(int j = 0; j < numVertices; j++){
            grafo->matriz[i][j].vertice = 0;
            grafo->matriz[i][j].sig = 0;
        }
    }
}



int main(){

 
    
    return 0;
}
0 - 1
| /
2 - 3