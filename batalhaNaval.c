#include <stdio.h>

// Constantes do jogo
int TAMANHO_TABULEIRO = 10;
int TAMANHO_NAVIO = 3;

// Função para inicializar o tabuleiro
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0; // 0 representa água
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
    tabuleiro[linha][j] = 3; // 3 representa parte de um navio
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
tabuleiro[i][coluna] = 3; // 3 representa parte de um navio
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
    
    // Exibe o tabuleiro com os navios posicionados
    exibirTabuleiro(tabuleiro);
    
    return 0;
}