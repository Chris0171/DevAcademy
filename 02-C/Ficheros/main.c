#include <stdio.h>
#include <stdlib.h>

struct Alumno
{
    int id;
    char nombre[50];
    float nota;
    
};

// Crear ficher de texto 
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

        // limpiar el buffer de entrada
        while(getchar() != '\n');


        fprintf(fichero, "%d %s %.2f\n",
            al.id, al.nombre, al.nota);
            
    }

    fclose(fichero);
}

// Leer fichero de texto
void leerFicheroTexto(){
    // Se quiere leer el fichero y mostrar algunos datos
    FILE *archivoTexto;
    struct Alumno al;

    archivoTexto = fopen("alumnos.txt", "r");
    
    if(archivoTexto == NULL){
        printf("Error al abrir el fichero");
        return; 
    }
    // El while funciona mientras se puendan leer 3 elementos, 
    // Si no se puede leer 3 elementos, se sale del bulcle
    while(fscanf(archivoTexto, "%d %s %f", &al.id, al.nombre, &al.nota) == 3){
        printf("ID: %d\n", al.id);
        printf("Nombre: %s\n", al.nombre);
        printf("Nota: %.2f\n", al.nota);
    }
    fclose(archivoTexto);

}

// Convertir fichero de texto a binario
void convertirTextoABinario(){
    FILE *file;
    FILE *binaryFile;

    struct Alumno alumno;

    file = fopen("alumnos.txt", "r");
    binaryFile = fopen("alumnos.dat", "wb");

    if(file == NULL || binaryFile == NULL){
        printf("Error al abrir el fichero\n");
        return;
    }

    while(fscanf(file, "%d %s %f", &alumno.id,
         alumno.nombre, &alumno.nota) == 3){
        
        // Escribir una estructura completa en el fichero binario
        // Un fichero binario guarda sus datos tal cual se encuentran
        // en memoria. 
        fwrite(&alumno, sizeof(struct Alumno), 1, binaryFile);
    }
    fclose(file);
    fclose(binaryFile);
}

// Modificar nota usando posicionamiento
void modificarNota(){
    FILE *bFile;
    struct Alumno al;
    int idAl;

    bFile = fopen("alumnos.dat", "rb+");

    if(bFile == NULL){
        printf("Error al abrir el fichero\n");
        return;
    }

    printf("ID del alumno: ");
    scanf("%d", &idAl);

    while(fread(&al, sizeof(struct Alumno), 1, bFile) == 1){
        if(al.id == idAl){
            printf("Nueva nota: ");
            float nuevaNota;
            scanf("%f", &nuevaNota);

            al.nota = nuevaNota;

            fseek(bFile, -sizeof(struct Alumno), SEEK_CUR);

            fwrite(&al, sizeof(struct Alumno), 1, bFile);

            printf("Nota modificada correctamente\n");

            fclose(bFile);
            return;
        }
    }

    printf("Alumno no encontrado\n");
    fclose(bFile);
}

char* renombrar(char *nombreActual, char *nuevoNombre){
    // true -> 0 false -> -1
    if(rename(nombreActual, nuevoNombre) == 0){
        printf("Fichero renombrado correctamente\n");
        return nuevoNombre;
    } else {
        printf("Error al renombrar el fichero\n");
        return nombreActual;
    }
}
void borrar(char *nombreFichero){
    if(remove(nombreFichero) == 0){
        printf("Fichero borrado correctamente\n");
    } else {
        printf("Error al borrar el fichero\n");
    }
}


int main(){
    char *nombreFichero = "alumnos.txt";

    nombreFichero = renombrar(nombreFichero, "al_renamed.txt");

    printf("Nombre del fichero: %s\n", nombreFichero);
    
    borrar(nombreFichero);

    return 0;
}