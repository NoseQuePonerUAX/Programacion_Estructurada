#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Estudiante {
    char nombre[50];
    int edad;
    float promedio;
}; //1) a. Constitución de una estructura

union Dato {
    int i;
    float f;
    char str[20];
};

struct Estudiante copiarEstudiante(struct Estudiante est) {
    struct Estudiante nuevoEst;
    strcpy(nuevoEst.nombre, est.nombre);
    nuevoEst.edad = est.edad;
    nuevoEst.promedio = est.promedio;
    return nuevoEst; //3. Copia de estructuras
}

int main() {

    struct Estudiante estudiante1;
    strcpy(estudiante1.nombre, "Joseph");
    estudiante1.edad = 21;
    estudiante1.promedio = 9.5; //1) b. Instanciación de estructuras

    struct Estudiante *estudiante2 = (struct Estudiante *) malloc(sizeof(struct Estudiante));
    strcpy(estudiante2->nombre, "Ana");
    estudiante2->edad = 19;
    estudiante2->promedio = 9.8; //1) c. Instanciación con el operador "malloc"

    struct Estudiante *punteroEst = &estudiante1;
    printf("Nombre: %s, Edad: %d, Promedio: %.2f\n", punteroEst->nombre, punteroEst->edad, punteroEst->promedio); //1) d. Punteros y estructuras
    struct Estudiante *punteroEst2 = estudiante2;
    printf("Nombre: %s, Edad: %d, Promedio: %.2f\n", punteroEst2->nombre, punteroEst2->edad, punteroEst2->promedio);

    union Dato dato;
    dato.i = 10;
    printf("dato.i: %d\n", dato.i);

    dato.f = 220.5;
    printf("dato.f: %f\n", dato.f);

    strcpy(dato.str, "C programming");
    printf("dato.str: %s\n", dato.str); //2) a. Uniones

    typedef struct Estudiante Estudiante;
    Estudiante estudiante3;
    strcpy(estudiante3.nombre, "Diego");
    estudiante3.edad = 18;
    estudiante3.promedio = 8.5; //4) Creacion de alias de tipos de estructuras

    struct Estudiante estudiantereal = {"Martin", 15, 5.5};
    struct Estudiante copiaEstudiante = copiarEstudiante(estudiantereal);
    printf("Estudiante real - Nombre: %s, Edad: %d, Promedio: %.2f\n", estudiantereal.nombre, estudiantereal.edad, estudiantereal.promedio);
    printf("Copia del estudiante - Nombre: %s, Edad: %d, Promedio: %.2f\n", copiaEstudiante.nombre, copiaEstudiante.edad, copiaEstudiante.promedio);

    return 0;
}
