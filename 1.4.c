#include <stdio.h>

int main() {
    int dados_vetor[5];
    int dados_matriz[2][2];
    int acumulador_vetor = 0;
    int acumulador_matriz = 0;

    printf("=== ENTRADA: VETOR ===\n");
    for (int idx = 0; idx < 5; idx++) {
        printf("Informe o valor da posicao %d: ", idx + 1);
        scanf("%d", &dados_vetor[idx]);
        acumulador_vetor += dados_vetor[idx];
    }

    printf("\nExibicao dos dados do vetor:\n");
    for (int idx = 0; idx < 5; idx++) {
        printf("Posicao [%d] = %d\n", idx, dados_vetor[idx]);
    }
    printf("Somatorio dos elementos do vetor: %d\n", acumulador_vetor);

    printf("\n====================================\n");
    printf("=== ENTRADA: MATRIZ 2x2 ===\n");
    for (int lin = 0; lin < 2; lin++) {
        for (int col = 0; col < 2; col++) {
            printf("Informe o valor para a coordenada [%d][%d]: ", lin, col);
            scanf("%d", &dados_matriz[lin][col]);
            acumulador_matriz += dados_matriz[lin][col];
        }
    }

    printf("\nVisualizacao da Matriz:\n");
    for (int lin = 0; lin < 2; lin++) {
        for (int col = 0; col < 2; col++) {
            printf("%d ", dados_matriz[lin][col]);
        }
        printf("\n");
    }
    printf("\nSomatorio dos elementos da matriz: %d\n", acumulador_matriz);

    return 0;
}