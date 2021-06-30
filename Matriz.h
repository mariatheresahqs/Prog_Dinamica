#ifndef _MATRIZ_H_
#define _MATRIZ_H_

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define RESET "\x1B[0m"

/*
Valor 1 caso queira ver todos os passos dados pelo estudante. 
Obs: Caso não queira acompanhar o passo a passo durante este processo,
comente a linha 105 do arquivo Matriz.c
*/
#define MODOANALISE 1 

#include "Pilha.h"

// typedef struct celula
// {
//     char valor[5];
// }Celula;


typedef struct Matriz{
    int **labirinto;
    int **solucao;
    char valor[5];
    int linhas, colunas, chave, qntMovimento, qntVida;
    int linhaInicial, linhaFinal, colunaInicial, colunaFinal;
}Matriz;


void alocarMatriz(int ***matriz, Matriz matrizEscolhida);
void desalocarMatriz(int **matriz, int linhas);
void mostrarMatriz(Matriz matriz,int **matrizEscolhida);
void preencherMatrizLabirinto(FILE *arq, Matriz labirinto);
void preencherMatrizSolucao(Matriz matriz);
void mostrarCaminhoColorido(Matriz matriz, int **matrizEscolhida);
int movimenta_estudante(Matriz *matriz, Pilha** pilha, int linha, int coluna);

#endif