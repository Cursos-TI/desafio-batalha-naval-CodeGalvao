#include <stdio.h>
#include <stdlib.h> 

// Constantes do jogo
#define TAM_TABULEIRO 10
#define TAM_HABILIDADE 5
#define TAM_NAVIO 3
#define AGUA 0
#define NAVIO 3
#define CONE 1
#define CRUZ 2
#define OCTAEDRO 4

// Função para inicializar o tabuleiro
void inicializarTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Função para posicionar os 4 navios
void posicionarNavios(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    // Navio horizontal (linha 2, coluna 3)
    for (int j = 3; j < 3 + TAM_NAVIO; j++) {
        tabuleiro[2][j] = NAVIO;
    }
    
    // Navio vertical (coluna 7, linha 5)
    for (int i = 5; i < 5 + TAM_NAVIO; i++) {
        tabuleiro[i][7] = NAVIO;
    }
    
    // Navio diagonal principal (linha 1, coluna 1)
    for (int k = 0; k < TAM_NAVIO; k++) {
        tabuleiro[1 + k][1 + k] = NAVIO;
    }
    
    // Navio diagonal secundária (linha 0, coluna 8)
    for (int k = 0; k < TAM_NAVIO; k++) {
        tabuleiro[0 + k][8 - k] = NAVIO;
    }
}

// Função para criar matriz de habilidade em Cone
void criarCone(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            habilidade[i][j] = (j >= i && j < TAM_HABILIDADE - i) ? 1 : 0;
        }
    }
}

// Função para criar matriz de habilidade em Cruz
void criarCruz(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {
    int centro = TAM_HABILIDADE / 2;
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            habilidade[i][j] = (i == centro || j == centro) ? 1 : 0;
        }
    }
}

// Função para criar matriz de habilidade em Octaedro
void criarOctaedro(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {
    int centro = TAM_HABILIDADE / 2;
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            int dist = abs(i - centro) + abs(j - centro);
            habilidade[i][j] = (dist <= centro) ? 1 : 0;
        }
    }
}

// Função para aplicar habilidade ao tabuleiro
void aplicarHabilidade(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], 
                      int habilidade[TAM_HABILIDADE][TAM_HABILIDADE],
                      int linha_centro, int coluna_centro, int tipo_habilidade) {
    int offset = TAM_HABILIDADE / 2;
    
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            int tab_i = linha_centro - offset + i;
            int tab_j = coluna_centro - offset + j;
            
            if (tab_i >= 0 && tab_i < TAM_TABULEIRO && 
                tab_j >= 0 && tab_j < TAM_TABULEIRO) {
                if (habilidade[i][j] == 1 && tabuleiro[tab_i][tab_j] == AGUA) {
                    tabuleiro[tab_i][tab_j] = tipo_habilidade;
                }
            }
        }
    }
}

// Função para exibir o tabuleiro com legenda
void exibirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    printf("\nTabuleiro:\n");
    printf("Legenda:\n");
    printf("0 = Água | 3 = Navio | 1 = Cone | 2 = Cruz | 4 = Octaedro\n\n");
    
    printf("   ");
    for (int j = 0; j < TAM_TABULEIRO; j++) printf("%2d ", j);
    printf("\n");
    
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        printf("%2d ", i);
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];
    int cone[TAM_HABILIDADE][TAM_HABILIDADE];
    int cruz[TAM_HABILIDADE][TAM_HABILIDADE];
    int octaedro[TAM_HABILIDADE][TAM_HABILIDADE];
    
    // Inicializa e posiciona os 4 navios
    inicializarTabuleiro(tabuleiro);
    posicionarNavios(tabuleiro);
    
    // Cria as matrizes de habilidade
    criarCone(cone);
    criarCruz(cruz);
    criarOctaedro(octaedro);
    
    // Aplica as habilidades ao tabuleiro em posições diferentes
    aplicarHabilidade(tabuleiro, cone, 4, 4, CONE);       // Cone centrado em (4,4)
    aplicarHabilidade(tabuleiro, cruz, 2, 7, CRUZ);       // Cruz centrada em (2,7)
    aplicarHabilidade(tabuleiro, octaedro, 7, 2, OCTAEDRO); // Octaedro centrado em (7,2)
    
    // Exibe o tabuleiro final com legenda
    exibirTabuleiro(tabuleiro);
    
    return 0;
}