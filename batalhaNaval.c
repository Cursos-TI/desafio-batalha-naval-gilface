#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.3

#define TAM_TABULEIRO 10   // Tamanho do tabuleiro (10x10)
#define TAM_NAVIO 3        // Tamanho fixo dos navios
#define VALOR_AGUA 0       // Valor para água no tabuleiro
#define VALOR_NAVIO 3      // Valor para parte do navio no tabuleiro


int main() {
    // Declaração e inicialização do tabuleiro com água (0)
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = VALOR_AGUA;
        }
    }

    // Vetores representando os navios (cada posição vale 3)
    int navio[TAM_NAVIO] = {VALOR_NAVIO, VALOR_NAVIO, VALOR_NAVIO};

    // Coordenadas iniciais dos navios (definidas diretamente)
    // IMPORTANTE: As coordenadas foram escolhidas para não sobrepor ou sair do tabuleiro.
    // Em um jogo real, seria necessário validar isso.
    int linha_h = 2, coluna_h = 4; // Navio horizontal
    int linha_v = 6, coluna_v = 1; // Navio vertical
    int linha_d1 = 0, coluna_d1 = 0; // Navio diagonal 1 (principal)
    int linha_d2 = 0, coluna_d2 = 9; // Navio diagonal 2 (secundária)

    // --- Posicionamento dos 4 Navios ---

    // Posiciona o navio horizontal no tabuleiro
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha_h][coluna_h + i] = navio[i];
    }

    // Posiciona o navio vertical no tabuleiro
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha_v + i][coluna_v] = navio[i];
    }

    // Posiciona o primeiro navio diagonal (linha e coluna aumentam)
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha_d1 + i][coluna_d1 + i] = navio[i];
    }

    // Posiciona o segundo navio diagonal (linha aumenta, coluna diminui)
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha_d2 + i][coluna_d2 - i] = navio[i];
    }


    // Exibe o tabuleiro no console
    printf("\n");
    printf("Tabuleiro de Batalha Naval (com 4 navios):\n\n");
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
    printf("Valores no tabuleiro: 0 = Água, %d = Parte do Navio\n\n", VALOR_NAVIO);
    printf("Posição do navio horizontal: linha %d, colunas %d a %d.\n", linha_h, coluna_h, coluna_h + TAM_NAVIO - 1);
    printf("Posição do navio vertical: coluna %d, linhas %d a %d.\n", coluna_v, linha_v, linha_v + TAM_NAVIO - 1);
    printf("Posição do navio diagonal 1: começa em (%d, %d), onde linha e coluna aumentam.\n", linha_d1, coluna_d1);
    printf("Posição do navio diagonal 2: começa em (%d, %d), onde linha aumenta e coluna diminui.\n", linha_d2, coluna_d2);
    printf("\n");
    printf("Pressione Enter para sair...\n");
    getchar(); // Espera o usuário pressionar Enter antes de encerrar
    printf("\n");

    return 0;
}