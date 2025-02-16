// *********************************************************
// * Aluno:  Sofia Freitas Batista Prata                   *
// * Matrícula: 20241045050448                             *
// * Avaliação 04: Trabalho Final                          *
// * 04.505.23 - 2024.2 - Prof. Daniel Ferreira            *
// * Compilador: gcc (MinGW.org GCC-6.3.0-1) 6.3.0         *
// *********************************************************
// * Aluno: Pedro Felipe Monteiro Ventura                  *
// * Matrícula: 20241045050294                             *
// * Avaliação 04: Trabalho Final                          *
// * 04.505.23 - 2024.2 - Prof. Daniel Ferreira            *
// * Compilador: gcc (MinGW.org GCC-6.3.0-1) 6.3.0         *
// *********************************************************
// * Aluno: Miguel Antonio Florencio Felix                 *
// * Matrícula: 2024104505                                 *
// * Avaliação 04: Trabalho Final                          *
// * 04.505.23 - 2024.2 - Prof. Daniel Ferreira            *
// * Compilador: gcc (MinGW.org GCC-6.3.0-1) 6.3.0         *
// *********************************************************

#include "imagem.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

PGM lerPGM(const char *caminho) {
    FILE *arquivo = fopen(caminho, "rb");
    if (!arquivo) return (PGM){NULL, 0, 0, 0};
    
    char tipo[3];
    fscanf(arquivo, "%2s", tipo);
    if (strcmp(tipo, "P5")) {
        fclose(arquivo);
        return (PGM){NULL, 0, 0, 0};
    }
    
    while (fgetc(arquivo) == '#') while (fgetc(arquivo) != '\n');
    fseek(arquivo, -1, SEEK_CUR);
    
    PGM pgm;
    fscanf(arquivo, "%d %d %d", &pgm.largura, &pgm.altura, &pgm.max_intensidade);
    fgetc(arquivo);
    
    pgm.imagem = malloc(pgm.largura * pgm.altura);
    fread(pgm.imagem, 1, pgm.largura * pgm.altura, arquivo);
    fclose(arquivo);
    return pgm;
}

void liberarImagem(PGM *pgm) {
    free(pgm->imagem);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função para salvar a imagem em formato PGM
void salvarImagem(const PGM *pgm, int k, const char *pasta_destino, const char *nome_imagem) {
    char caminho_saida[256]; // Buffer para armazenar o caminho completo do arquivo de saída

    // Formata o caminho de saída com a pasta e o nome da imagem
    snprintf(caminho_saida, sizeof(caminho_saida), "%s/%s_clustered.pgm", pasta_destino, nome_imagem);
    
    // Abre o arquivo para escrita no formato binário
    FILE *arquivo = fopen(caminho_saida, "wb");
    if (!arquivo) {
        // Se o arquivo não puder ser aberto, exibe uma mensagem de erro e encerra a função
        printf("Erro ao abrir o arquivo para escrita: %s\n", caminho_saida);
        return;
    }
    
    // Escreve o cabeçalho do arquivo PGM no formato "P5"
    fprintf(arquivo, "P5\n%d %d\n%d\n", pgm->largura, pgm->altura, pgm->max_intensidade);
    
    // Itera por todos os pixels da imagem
    for (int i = 0; i < pgm->largura * pgm->altura; i++) {
        // Converte o cluster do pixel para um valor de intensidade e grava no arquivo
        fputc(pgm->imagem[i] * (pgm->max_intensidade / k), arquivo);
    }
    
    // Fecha o arquivo após escrever todos os dados
    fclose(arquivo);
}
