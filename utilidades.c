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
#include "utilidades.h"
#include "imagem.h"
#include "kmeans.h"
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

void criarPastaDestino(const char *pasta) {
    struct stat st;
    if (stat(pasta, &st) == -1) mkdir(pasta);
}

void processarPasta(const char *pasta, const char *pasta_destino) {
    DIR *dir = opendir(pasta);
    if (!dir) return;
    
    criarPastaDestino(pasta_destino);
    struct dirent *entrada;
    
    while ((entrada = readdir(dir)) != NULL) {
        if (strstr(entrada->d_name, ".pgm")) {
            char caminho[256];
            snprintf(caminho, sizeof(caminho), "%s/%s", pasta, entrada->d_name);
            
            PGM pgm = lerPGM(caminho);
            if (!pgm.imagem) continue;
            
            int *clusters = malloc(pgm.largura * pgm.altura * sizeof(int));
            if (!clusters) {
                liberarImagem(&pgm);
                continue;
            }
            
            kmeans(&pgm, 10, clusters);
            salvarImagem(&pgm, clusters, 10, pasta_destino, entrada->d_name);
            
            free(clusters);
            liberarImagem(&pgm);
        }
    }
    closedir(dir);
}
