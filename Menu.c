#include "Menu.h"

void opcoes(int* opcao); 
void opcoes2(int* opcao);

void menu(){
    system("@cls||clear");
    char nomeArq[25];
    FILE *arq;

    Matriz matriz;
    Pilha* pilha;

    int escolha = 0;
    int opcao2 = 0;
    
    printf(RED "\nPROGRAMA LABIRINTO: OPÇÕES DO PROGRAMA\n");

    while (escolha != 2) {
        opcoes(&escolha);

        if (escolha == 1) {
            printf(RESET"Entre com o nome do arquivo: ");
            scanf("%s", nomeArq);
            arq = fopen (nomeArq, "r");
            if (arq == NULL) {
                printf("Erro na leitura do arquivo!\n");
                printf("Tente inserir outro nome ou corrigir o que foi inserido.\n");
            } else {
                printf("\nARQUIVO INSERIDO COM SUCCESSO!! \n");
                int chave;
                matriz.qntMovimento = 0;

                fscanf(arq, "%d %d %d ", &matriz.linhas, &matriz.colunas, &matriz.chave);
               
                alocarMatriz(&matriz.labirinto, matriz);
  ;
                preencherMatrizLabirinto(arq, matriz);


                mostrarMatriz(matriz, matriz.labirinto);

          
            }
            
        }

    }
    printf(RED"Programa encerrado!\n\n");
}


void opcoes(int* opcao) {
    int valor;
    printf(BLU "============================================\n");
    printf("|Opções do Programa:                       |\n");
    printf("|1 - Carregar novo arquivo de dados.       |\n");
    printf("|2 - Sair do programa.                     |\n");
    printf(BLU "============================================\n");
    
    printf(GRN "Ecolha uma opção: ");
    scanf("%d", &valor); 
    *opcao = valor;
    printf(BLU "==========================================\n");
    system("@cls||clear");
}

void opcoes2(int* opcao){
    int opcao2;
    printf(BLU "==================================================\n");
    printf("|Opções do Programa para a utilização do arquivo:|\n");
    printf("|1 - Mostrar resultados.                         |\n");
    printf("|2 - Voltar menu anterior.                       |\n");
    printf(BLU "==================================================\n");

    printf(GRN "Ecolha uma opção: ");
    scanf("%d", &opcao2);
    printf(BLU "==============================================\n");
    *opcao = opcao2;
    system("@cls||clear");

}