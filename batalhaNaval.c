#include <stdio.h>

// Constantes do jogo
#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define AGUA 0
#define NAVIO 3

// Função para inicializar o tabuleiro
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Função para posicionar navio horizontalmente
int posicionarNavioHorizontal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], 
    int linha, int coluna) {
// Verifica se o navio cabe no tabuleiro
if (coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
printf("Erro: Navio horizontal não cabe nas coordenadas (%d,%d)\n", linha, coluna);
return 0; // Falha
}
   // Posiciona o navio
   for (int j = coluna; j < coluna + TAMANHO_NAVIO; j++) {
    tabuleiro[linha][j] = NAVIO; // Navio representa 3 parte de um navio
}

return 1; // Sucesso
}

// Função para posicionar navio verticalmente
int posicionarNavioVertical(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], 
    int linha, int coluna) {
// Verifica se o navio cabe no tabuleiro
if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
printf("Erro: Navio vertical não cabe nas coordenadas (%d,%d)\n", linha, coluna);
return 0; // Falha
}

// Posiciona o navio
for (int i = linha; i < linha + TAMANHO_NAVIO; i++) {
tabuleiro[i][coluna] = NAVIO; // 3 representa parte de um navio
}

return 1; // Sucesso
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("\nTabuleiro do Batalha Naval:\n");
    printf("   ");
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
        printf("%2d ", j); // Cabeçalho das colunas
    }
    printf("\n");
    
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%2d ", i); // Número da linha
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int posicionarNavioDiagonalPrincipal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    // Verifica se cabe no tabuleiro
    if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO || coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        return 0;
    }
    for (int k = 0; k < TAMANHO_NAVIO; k++) {
        tabuleiro[linha + k][coluna + k] = NAVIO;
    }
    return 1;
}

int posicionarNavioDiagonalSecundaria(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    // Verifica se cabe no tabuleiro
    if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO || coluna - TAMANHO_NAVIO + 1 < 0) {
        return 0;
    }
     // Posiciona o navio
     for (int k = 0; k < TAMANHO_NAVIO; k++) {
        tabuleiro[linha + k][coluna - k] = NAVIO;
    }
    return 1;
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    
    // Inicializa o tabuleiro
    inicializarTabuleiro(tabuleiro);
    
    // Posiciona os navios
    printf("Posicionando navios...\n");
    
    // Navio horizontal na linha 2, coluna 3
    if (!posicionarNavioHorizontal(tabuleiro, 2, 3)) {
        printf("Falha ao posicionar navio horizontal.\n");
        return 1;
    }
    
    // Navio vertical na linha 5, coluna 7
    if (!posicionarNavioVertical(tabuleiro, 5, 7)) {
        printf("Falha ao posicionar navio vertical.\n");
        return 1;
    }

    // Navios diagonais
    if (!posicionarNavioDiagonalPrincipal(tabuleiro, 1, 1)) {
        printf("Erro ao posicionar navio diagonal principal em (1,1)\n");
        return 1;
    }
    
    if (!posicionarNavioDiagonalSecundaria(tabuleiro, 0, 8)) {
        printf("Erro ao posicionar navio diagonal secundária em (0,8)\n");
        return 1;
    }

    // Exibe o tabuleiro com os navios posicionados
    exibirTabuleiro(tabuleiro);
    
    return 0;
}