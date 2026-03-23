#ifndef alumnos_h
#define alumnos_h

/**
 * @brief Estructura que representa a un alumno
 **/

typedef struct
{
    int id;
    char nombre[50];
    float nota;
} Alumno;

void guardarTexto(const char *nombreArchivo, Alumno *a, int n);
void leerTexto(const char *nombreFichero);
void guardarBinario(const char *nombreFichero, Alumno *v, int n);
void leerBinario(const char *nombreFichero);
Alumno leerAlumnoPos(const char *nombreFichero, int posicion);
float calcularMedia(const Alumno *v, int n);
void modificarNota(Alumno *a, float nuevaNota);

#endif