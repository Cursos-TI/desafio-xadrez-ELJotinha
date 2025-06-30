// codigo completo funcional
#include <stdio.h>
#include <stdlib.h>

#define TAM 8

char tabuleiro[TAM][TAM];

// Função para inicializar o tabuleiro com peças simbólicas
void iniciarTabuleiro() {
    int i, j;
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            tabuleiro[i][j] = '.';
        }
    }

    // Peças pretas (minúsculas)
    tabuleiro[0][0] = tabuleiro[0][7] = 't';
    tabuleiro[0][1] = tabuleiro[0][6] = 'c';
    tabuleiro[0][2] = tabuleiro[0][5] = 'b';
    tabuleiro[0][3] = 'q';
    tabuleiro[0][4] = 'k';
    for (j = 0; j < TAM; j++) tabuleiro[1][j] = 'p';

    // Peças brancas (maiúsculas)
    tabuleiro[7][0] = tabuleiro[7][7] = 'T';
    tabuleiro[7][1] = tabuleiro[7][6] = 'C';
    tabuleiro[7][2] = tabuleiro[7][5] = 'B';
    tabuleiro[7][3] = 'Q';
    tabuleiro[7][4] = 'K';
    for (j = 0; j < TAM; j++) tabuleiro[6][j] = 'P';
}

void exibirTabuleiro() {
    printf("   a b c d e f g h\n");
    for (int i = 0; i < TAM; i++) {
        printf("%d  ", 8 - i);
        for (int j = 0; j < TAM; j++) {
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int linhaOrigem, colOrigem, linhaDestino, colDestino;
    char coluna1, coluna2;
    int continuar = 1;
    int jogada = 0;

    iniciarTabuleiro();

    do {
        exibirTabuleiro();

        printf("Jogada %d - Digite sua jogada (ex: e2 e4): ", jogada + 1);
        scanf(" %c%d %c%d", &coluna1, &linhaOrigem, &coluna2, &linhaDestino);

        colOrigem = coluna1 - 'a';
        linhaOrigem = 8 - linhaOrigem;
        colDestino = coluna2 - 'a';
        linhaDestino = 8 - linhaDestino;

        if (linhaOrigem >= 0 && linhaOrigem < TAM && colOrigem >= 0 && colOrigem < TAM &&
            linhaDestino >= 0 && linhaDestino < TAM && colDestino >= 0 && colDestino < TAM) {

            char peca = tabuleiro[linhaOrigem][colOrigem];

            if (peca != '.') {
                char destinoPeca = tabuleiro[linhaDestino][colDestino];

                // Se o destino for um rei, encerra o jogo
                if (destinoPeca == 'K' || destinoPeca == 'k') {
                    tabuleiro[linhaDestino][colDestino] = peca;
                    tabuleiro[linhaOrigem][colOrigem] = '.';
                    exibirTabuleiro();
                    printf("O rei %s foi capturado! Fim de jogo.\n",
                           destinoPeca == 'K' ? "BRANCO" : "PRETO");
                    printf("%s venceu!\n", destinoPeca == 'K' ? "PRETO" : "BRANCO");
                    break;
                }

                // Movimento comum
                tabuleiro[linhaDestino][colDestino] = peca;
                tabuleiro[linhaOrigem][colOrigem] = '.';
                jogada++;
            } else {
                printf("Não há peça na posição de origem!\n");
            }

        } else {
            printf("Coordenadas inválidas!\n");
        }

        do {
            printf("Deseja continuar? (1 = sim, 0 = nao): ");
            scanf("%d", &continuar);
        } while (continuar != 1 && continuar != 0);

    } while (continuar);

    printf("\nJogo encerrado após %d jogadas!\n", jogada);

    return 0;
}
