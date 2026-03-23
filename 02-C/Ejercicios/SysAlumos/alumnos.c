#include <stdio.h>
#include <stdlib.h>

#include "alumnos.h"

/** 
* @brief Guarda alumnos en fichero de texto
**/
void guardarTexto(const char *nombreArchivo, Alumno *a, int n)
{
    FILE *f = fopen(nombreArchivo, "w");

    if(f != NULL){
        for(int i = 0; i < n; i++){
            fprintf(f, "%d %s %.2f\n", (*(a + i)).id, (*(a + i)).nombre, (*(a + i)).nota);
        }
        fclose(f);
    }
    
}

/** 
* @brief Lee el fichero de texto y muestra su contenido
**/
void leerTexto(const char *nombreFichero){
    FILE *f = fopen(nombreFichero, "r");

    if(f != NULL){
        Alumno a;
        while(fscanf(f, "%d %s %f", &a.id, a.nombre, &a.nota) == 3){
            printf("ID: %d, Nombre: %s, Nota: %.2f\n", a.id, a.nombre, a.nota);
        }
        fclose(f);
    }
}
/** 
* @brief Guardar alumnos en fichero binario
**/
void guardarBinario(const char *nombreFichero, Alumno *v, int n){
    FILE *f = fopen(nombreFichero, "wb");

    if(f != NULL){
        fwrite(v, sizeof(Alumno), n, f);
        fclose(f);
    }
}
/** 
* @brief Leer el ficher binario
**/
void leerBinario(const char *nombreFichero){
    FILE *f = fopen(nombreFichero, "rb");

    if(f != NULL){
        Alumno a;
        while(fread(&a, sizeof(Alumno), 1, f)){
            printf("ID: %d, Nombre: %s, Nota: %.2f\n", a.id, a.nombre, a.nota);
        }
        fclose(f);
    }
}
/** 
* @brief LLeer un alumno en una posición concreta
**/
Alumno leerAlumnoPos(const char *nombreFichero, int posicion){
    FILE *f = fopen(nombreFichero, "rb");
    Alumno a;
    if(f != NULL){
        
        fseek(f, posicion * sizeof(Alumno), SEEK_SET);
        fread(&a, sizeof(Alumno), 1, f);
        fclose(f);

    }
    return a;

}
/** 
* @brief Calcular la media usando punteros
**/
float calcularMedia(const Alumno *v, int n){
    float suma = 0.0;
    for(int i = 0; i <n; i++){
        suma += (*(v + i)).nota;
    }

    return suma / n;
}
/** 
* @brief Modificar nota de un alumno
**/
void modificarNota(Alumno *a, float nuevaNota){
    (*a).nota = nuevaNota;
}