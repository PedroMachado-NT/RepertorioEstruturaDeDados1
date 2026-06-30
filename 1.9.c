#include <stdio.h>
#define CAPACIDADE_MAXIMA 5

typedef struct {
    int espaco_dados[CAPACIDADE_MAXIMA];
    int indicador_inicio;
    int indicador_fim;
} ControleFila;

void resetar_fila(ControleFila *fila) {
    fila->indicador_inicio = 0;
    fila->indicador_fim = -1;
}

int checar_vazia(ControleFila *fila) {
    return (fila->indicador_fim < fila->indicador_inicio);
}

void enfileirar(ControleFila *fila, int informacao) {
    if (fila->indicador_fim == CAPACIDADE_MAXIMA - 1) {
        printf("Aviso: Limite maximo atingido!\n");
        return;
    }
    fila->indicador_fim++;
    fila->espaco_dados[fila->indicador_fim] = informacao;
}

int desenfileirar(ControleFila *fila) {
    if (checar_vazia(fila)) {
        printf("Aviso: Fila sem registros disponíveis!\n");
        return -1;
    }
    int dado_removido = fila->espaco_dados[fila->indicador_inicio];
    fila->indicador_inicio++;
    return dado_removido;
}

void visualizar_fila(ControleFila *fila) {
    if (checar_vazia(fila)) {
        printf("Fila sem registros.\n");
        return;
    }
    for (int idx = fila->indicador_inicio; idx <= fila->indicador_fim; idx++) {
        printf("%d ", fila->espaco_dados[idx]);
    }
    printf("\n");
}

int main() {
    ControleFila fila_atendimento;
    resetar_fila(&fila_atendimento);

    enfileirar(&fila_atendimento, 10);
    enfileirar(&fila_atendimento, 20);
    enfileirar(&fila_atendimento, 30);
    enfileirar(&fila_atendimento, 40);

    printf("Registros na Fila:\n");
    visualizar_fila(&fila_atendimento);

    printf("\nItem removido via dequeue: %d\n", desenfileirar(&fila_atendimento));

    printf("\nFila apos atualizacao de remocao:\n");
    visualizar_fila(&fila_atendimento);

    enfileirar(&fila_atendimento, 50);
    printf("\nConfiguracao Final da Fila:\n");
    visualizar_fila(&fila_atendimento);

    return 0;
}