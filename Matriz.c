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

//Preenchendo a matriz solução
void preencherMatrizSolucao(Matriz matrizSolucao){
    for(int i=0; i<matrizSolucao.linhas;i++){
        for(int j=0;j<matrizSolucao.colunas;j++){
            matrizSolucao.solucao[i][j] = 0;
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

//mostra a solução colorida
void mostrarCaminhoColorido(Matriz matriz, int **matrizEscolhida){
    printf("\n");
    for(int i =0; i<matriz.linhas; i++){
        for(int j=0; j<matriz.colunas;j++){
            if (matrizEscolhida[i][j] == '0'){ // se for 0, colocar amarelo
                printf(YEL "%c", matrizEscolhida[i][j]);
                printf(RESET);
            }else if(matrizEscolhida[i][j] == 'S'){ // se for a posição do aluno, colocar vermelho            
                printf(RED "%c", matrizEscolhida[i][j]);
                printf(RESET);
            }else{ // se for o caminho feito pelo aluno, colocar verde
                printf(GRN "%c", matrizEscolhida[i][j]);
                printf(RESET);
            }
        }
        printf("\n");
    }
}

int movimenta_estudante(Matriz *matriz, Pilha** pilha, int linha, int coluna){ 
   
    if(linha<0 || 
       coluna<0 ||
       linha>=matriz->linhas ||
       coluna>=matriz->colunas || 
       matriz->solucao[linha][coluna] != '0' ||
       (matriz->qntVida<=0))
    {
        return 0;
    }else if(linha == matriz->linhaFinal && coluna == matriz->colunaFinal){
        matriz->solucao[linha][coluna] = 'S';
        inserirPilha(&(*pilha), linha, coluna);
        return 1;
    }

    matriz->solucao[linha][coluna] = '^';
    matriz->qntVida+= matriz->labirinto[linha][coluna];
    if(movimenta_estudante(matriz, pilha, linha-1, coluna)){
        inserirPilha(&(*pilha), linha-1, coluna);
        return 1;
    }
    matriz->qntVida+= matriz->labirinto[linha][coluna];
    matriz->solucao[linha][coluna] = '<';
    if(movimenta_estudante(matriz, pilha, linha, coluna-1)){
        inserirPilha(&(*pilha), linha, coluna-1);
        return 1;
    }
   
    
    matriz->qntVida+= matriz->labirinto[linha][coluna];
    matriz -> solucao[linha][coluna] = '0';
    return 0;
}
