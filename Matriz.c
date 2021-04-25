#include "Matriz.h"

// Alocando posicoes da matriz
void alocarMatriz(int ***matrizTAD, Matriz matriz){
    *matrizTAD = (int**)malloc(matriz.linhas*(sizeof(int*))); // Alocando linhas do tipo ponteiro

    for(int i=0; i<matriz.linhas; i++){
        (*matrizTAD)[i] = (int*)malloc(matriz.colunas*(sizeof(int))); // Alocando colunas do tipo inteiro
    }
}

//Preenchendo a matriz Labirinto. Aqui são usados os dados do arquivo.
void preencherMatrizLabirinto(FILE *arq, Matriz labirinto){
    char texto[100];

    // Ler linhas
    for(int i=0;i<labirinto.linhas;i++){
        fgets(texto, 100, arq);
        if(i < labirinto.linhas-1)
            texto[strlen(texto)-1] = '\0';
        else
            texto[strlen(texto)] = '\0';

        // Quebrar linhas em partes de strings
        char *piece = strtok(texto, " ");
        int contColuna = 0;
        while(piece!=NULL){
            
            // Comparar strings com I e F
            if(!strcmp(piece, "F")){
                piece = "X";
                labirinto.linhaFinal = i;
                labirinto.colunaFinal = contColuna;
            }
            if(!strcmp(piece, "I")){
                piece = "X";
                labirinto.linhaInicial = i;
                labirinto.colunaInicial = contColuna;
            }
            
            // Converter valores de string para int e
            // atribuir valores a posicoes na matriz
            labirinto.labirinto[i][contColuna] = atoi(piece);
            piece = strtok(NULL, " ");
            contColuna++;
        }
    }
}

// Liberando a matriz
void desalocarMatriz(int **matriz, int linhas) {
  for (int i = 0; i < linhas; i++) {
    free(matriz[i]);
  }
  free(matriz);
}

// Mostrar matriz
void mostrarMatriz(Matriz matriz, int **matrizEscolhida){
    printf("\n");
    for(int i =0; i<matriz.linhas; i++){
        for(int j=0; j<matriz.colunas;j++){
            printf("%d ", matrizEscolhida[i][j]);
        }
        printf("\n");
    }
}

