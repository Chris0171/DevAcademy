#include <stdio.h>
#include <stdlib.h>

struct Alumno
{
    int id;
    char nombre[50];
    float nota;
    
};

// Funciones void || funciones con retorno 
void crearFicheroTexto(){
    FILE *fichero;

    struct Alumno al;
    int nAlunmnos;

    fichero = fopen("alumnos.txt", "w");

    if(fichero == NULL)
    {
        printf("Error al crear el fichero");
        return;
    }

    printf("Cuantos alumnos desea introducir: ");
    scanf("%d", &nAlunmnos);    // 4

    // 
    for(int i = 0; i < nAlunmnos; i++){
        printf ("ID: ");
        scanf("%d", &al.id);
        printf ("Nombre: ");
        scanf("%s", al.nombre);
        printf ("Nota: ");
        scanf("%f", &al.nota);


        fprintf(fichero, "%d %s %.2f\n",
            al.id, al.nombre, al.nota);
            
    }

    fclose(fichero);
}


int main(){
    // struct Alumno al1 = {1, "Juan Rodriguez", 7.3};
    // struct Alumno al2 = {2, "Maria Gomez", 8.5};
    // struct Alumno al3; 

    // al3.nota = 9.0;
    // al3.id = 3; 

    crearFicheroTexto();

    return 0;
}