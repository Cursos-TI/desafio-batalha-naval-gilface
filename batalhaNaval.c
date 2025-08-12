#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.3

#define TAM_TABULEIRO 10   // Tamanho do tabuleiro (10x10)
#define TAM_NAVIO 3        // Tamanho fixo dos navios
#define VALOR_AGUA 0       // Valor para água no tabuleiro
#define VALOR_NAVIO 3    // Valor para parte do navio no tabuleiro


int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0
 // Declaração e inicialização do tabuleiro com água (0)
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = VALOR_AGUA;
        }
    }

    // Vetores representando os navios (cada posição vale 3)
    int navio_horizontal[TAM_NAVIO] = {VALOR_NAVIO, VALOR_NAVIO, VALOR_NAVIO};
    int navio_vertical[TAM_NAVIO] = {VALOR_NAVIO, VALOR_NAVIO, VALOR_NAVIO};

    // Coordenadas iniciais dos navios (definidas diretamente)
    int linha_h = 2, coluna_h = 4; // Navio horizontal começa na linha 2, coluna 4
    int linha_v = 6, coluna_v = 1; // Navio vertical começa na linha 6, coluna 1

    // Validação: garantir que os navios estão dentro dos limites do tabuleiro
    if (coluna_h + TAM_NAVIO > TAM_TABULEIRO || linha_h >= TAM_TABULEIRO) {
        printf("Erro: Navio horizontal fora dos limites do tabuleiro.\n");
        return 1;
    }
    if (linha_v + TAM_NAVIO > TAM_TABULEIRO || coluna_v >= TAM_TABULEIRO) {
        printf("Erro: Navio vertical fora dos limites do tabuleiro.\n");
        return 1;
    }

    // Validação: garantir que não há sobreposição
    int sobreposicao = 0;
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (linha_h == linha_v + i && coluna_h + i == coluna_v) {
            sobreposicao = 1;
            break;
        }
        if (linha_v + i == linha_h && coluna_v == coluna_h + i) {
            sobreposicao = 1;
            break;
        }
    }
    if (sobreposicao) {
        printf("Erro: Sobreposição de navios detectada.\n");
        return 1;
    }

    // Posiciona o navio horizontal no tabuleiro
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha_h][coluna_h + i] = navio_horizontal[i];
    }

    // Posiciona o navio vertical no tabuleiro
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha_v + i][coluna_v] = navio_vertical[i];
    }

    // Exibe o tabuleiro no console
    printf("\n");
    printf("Tabuleiro de Batalha Naval:\n\n");
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    // Exibe a legenda e posição dos navios
    printf("Legenda:\n");
    printf("Tamanho do navio: %d\n", TAM_NAVIO);
    printf("Valores no tabuleiro: 0 = Água, %d = Parte do Navio\n", VALOR_NAVIO);
    printf("Posição do navio horizontal: linha %d, colunas %d a %d.\n", linha_h, coluna_h, coluna_h + TAM_NAVIO - 1);
    printf("Posição do navio vertical: coluna %d, linhas %d a %d.\n", coluna_v, linha_v, linha_v + TAM_NAVIO - 1);
    printf("\n");
    printf("Pressione Enter para sair...\n");
    getchar(); // Espera o usuário pressionar Enter antes de encerrar
    printf("\n");

    return 0;
}
