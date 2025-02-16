// *******************
// * Aluno:  Sofia Freitas Batista Prata                   *
// * Matrícula: 20241045050448                             *
// * Avaliação 04: Trabalho Final                          *
// * 04.505.23 - 2024.2 - Prof. Daniel Ferreira            *
// * Compilador: gcc (MinGW.org GCC-6.3.0-1) 6.3.0         *
// *******************
// * Aluno: Pedro Felipe Monteiro Ventura                  *
// * Matrícula: 20241045050294                             *
// * Avaliação 04: Trabalho Final                          *
// * 04.505.23 - 2024.2 - Prof. Daniel Ferreira            *
// * Compilador: gcc (MinGW.org GCC-6.3.0-1) 6.3.0         *
// *******************
// * Aluno: Miguel Antonio Florencio Felix                 *
// * Matrícula: 2024104505                                 *
// * Avaliação 04: Trabalho Final                          *
// * 04.505.23 - 2024.2 - Prof. Daniel Ferreira            *
// * Compilador: gcc (MinGW.org GCC-6.3.0-1) 6.3.0         *
// *******************

#include <stdio.h>
#include <time.h>
#include "utilidades.h"


int main() {
    clock_t begin = clock();
    processarPasta("C:/Users/Gleissi/Desktop/TrabalhoFinalLab/Carcinoma", "C:/Users/Gleissi/Desktop/TrabalhoFinalLab/linkedizado/output");
    ;
    clock_t end = clock();
    double time = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Tempo total: %lf segundos\n", time);
    return 0;
}
