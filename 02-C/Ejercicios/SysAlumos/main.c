#include <stdio.h>
#include <stdlib.h>
#include "alumnos.h"

int main()
{
    Alumno alumnos[3] = {
        {1, "Juan", 7.5},
        {2, "María", 8.0},
        {3, "Pedro", 6.5}};
    guardarTexto("alumnos.txt", alumnos, 3);
    leerTexto("alumnos.txt");

    guardarBinario("alumnos.dat", alumnos, 3);
    leerBinario("alumnos.dat");

    Alumno a = leerAlumnoPos("alumnos.dat", 1);
    printf("Alumno en posición 1: ID: %d, Nombre: %s, Nota: %.2f\n", a.id, a.nombre, a.nota);

    modificarNota(&alumnos[0], 9.0);

    printf("Alumno modificado: ID: %d, Nombre: %s, Nota: %.2f\n",
           alumnos[0].id, alumnos[0].nombre, alumnos[0].nota);

    return 0;
}