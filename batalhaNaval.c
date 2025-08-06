#include <stdio.h>

void posicionarDiagonal(int tabuleiro[10][10], int linhaInicio, int colunaInicio, int tamanho, int direcao) {
    // direcao: 1 = diagonal principal ↘, -1 = diagonal secundária ↙
    for (int i = 0; i < tamanho; i++) {
        tabuleiro[linhaInicio + i][colunaInicio + (i * direcao)] = 3;
    }
}

int main() {
    int tabuleiro[10][10];
    char colunas[10] = {'A','B','C','D','E','F','G','H','I','J'};

    printf("   TABULEIRO BATALHA NAVAL\n\n");

    // Cabeçalho das colunas (letras)
    printf("   ");
    for (int i = 0; i < 10; i++) {
        printf(" %c", colunas[i]);
    }
    printf("\n");

    // Inicializa a matriz com 0
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Substituir valores da coluna B até D (índices 1 a 3) na linha 6 (índice 5) por 3
    for (int j = 1; j <= 3; j++) {
        tabuleiro[5][j] = 3;
    }

        // Substituir coluna H (índice 7) da linha 2 até a linha 4 (índices 1 a 3)
    for (int i = 1; i <= 3; i++) {
        tabuleiro[i][7] = 3;
    }

    // Preenche o cone (triângulo invertido)
    for (int i = 0; i < 4; i++) {
        for (int j = 3 - i; j <= 3 + i; j++) {
            tabuleiro[i][j] = 2;
        }
    }

    // Diagonal ↘ começando em linha 2, coluna C (índices 1,2)
    posicionarDiagonal(tabuleiro, 1, 2, 2, 1);

    // Exibir o tabuleiro com as alterações
    for (int i = 0; i < 10; i++) {
        printf("%2d ", i + 1);  // Números das linhas

        for (int j = 0; j < 10; j++) {
            printf(" %d", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
