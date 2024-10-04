#include <stdio.h>
#include <string.h>

#define NUM_ESTUDIANTES 5
#define NUM_MATERIAS 3

float calcularPromedio(float notas[], int num_notas) {
    float suma = 0;
    for (int i = 0; i < num_notas; i++) {
        suma += notas[i];
    }
    return suma / num_notas;
}

float encontrarMax(float notas[], int num_notas) {
    float max = notas[0];
    for (int i = 1; i < num_notas; i++) {
        if (notas[i] > max) {
            max = notas[i];
        }
    }
    return max;
}

float encontrarMin(float notas[], int num_notas) {
    float min = notas[0];
    for (int i = 1; i < num_notas; i++) {
        if (notas[i] < min) {
            min = notas[i];
        }
    }
    return min;
}

int contarAprobados(float notas[], int num_notas, float nota_aprobacion) {
    int aprobados = 0;
    for (int i = 0; i < num_notas; i++) {
        if (notas[i] >= nota_aprobacion) {
            aprobados++;
        }
    }
    return aprobados;
}

int contarReprobados(float notas[], int num_notas, float nota_aprobacion) {
    int reprobados = 0;
    for (int i = 0; i < num_notas; i++) {
        if (notas[i] < nota_aprobacion) {
            reprobados++;
        }
    }
    return reprobados;
}

int main() {
    char nombres[NUM_ESTUDIANTES][50];
    char materias[NUM_MATERIAS][50];
    float notas[NUM_ESTUDIANTES][NUM_MATERIAS];
    float promedio_estudiante[NUM_ESTUDIANTES];
    float promedio_materia[NUM_MATERIAS] = {0};
    float max_materia[NUM_MATERIAS], min_materia[NUM_MATERIAS];
    int aprobados_materia[NUM_MATERIAS] = {0}, reprobados_materia[NUM_MATERIAS] = {0};
    float nota_aprobacion = 6.0;
    float max_general = 0;

   
    for (int j = 0; j < NUM_MATERIAS; j++) {
        printf("Ingrese el nombre de la materia %d: \n", j + 1);
        fgets(materias[j], 50, stdin);
        materias[j][strcspn(materias[j], "\n")] = 0;  
    }


    for (int i = 0; i < NUM_ESTUDIANTES; i++) {
        printf("Ingrese el nombre del estudiante %d:\n", i + 1);
        fgets(nombres[i], 50, stdin);
        nombres[i][strcspn(nombres[i], "\n")] = 0;  

        for (int j = 0; j < NUM_MATERIAS; j++) {
            float nota;
            do {
                printf("Ingrese la nota de %s para %s (0-10): \n", materias[j], nombres[i]);
                scanf("%f", &nota); 
                if (nota < 0 || nota > 10) {
                    printf("Error: La nota debe estar entre 0 y 10.\n");
                }
            } while (nota < 0 || nota > 10);
            notas[i][j] = nota;

            if (nota > max_general) {
                max_general = nota;
            }
        }

        getchar(); 
    }