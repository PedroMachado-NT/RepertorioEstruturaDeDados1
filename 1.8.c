#include <stdio.h>
#include <stdlib.h>

typedef struct Componente {
    int valor_armazenado;
    struct Componente *abaixo;
} NoPilha;

typedef struct {
    NoPilha *elemento_topo;
} EstruturaPilha;

EstruturaPilha* inicializar_pilha() {
    EstruturaPilha *nova_pilha = (EstruturaPilha*) malloc(sizeof(EstruturaPilha));
    if (nova_pilha != NULL) {
        nova_pilha->elemento_topo = NULL;
    }
    return nova_pilha;
}

int verificar_vazia(EstruturaPilha *pilha) {
    return (pilha->elemento_topo == NULL);
}

void empilhar(EstruturaPilha *pilha, int informacao) {
    NoPilha *novo_no = (NoPilha*) malloc(sizeof(NoPilha));
    if (novo_no != NULL) {
        novo_no->valor_armazenado = informacao;
        novo_no->abaixo = pilha->elemento_topo;
        pilha->elemento_topo = novo_no;
    } else {
        printf("Falha crítica: Memoria esgotada.\n");
    }
}

int desempilhar(EstruturaPilha *pilha) {
    if (verificar_vazia(pilha)) {
        printf("Aviso: Pilha sem elementos.\n");
        return -1;
    }
    NoPilha *temporario = pilha->elemento_topo;
    int valor_extraido = temporario->valor_armazenado;
    pilha->elemento_topo = temporario->abaixo;
    free(temporario);
    return valor_extraido;
}

void mostrar_pilha(EstruturaPilha *pilha) {
    NoPilha *auxiliar = pilha->elemento_topo;
    while (auxiliar != NULL) {
        printf("[%d]\n", auxiliar->valor_armazenado);
        auxiliar = auxiliar->abaixo;
    }
}

int main() {
    EstruturaPilha *minha_pilha = inicializar_pilha();

    empilhar(minha_pilha, 4);
    empilhar(minha_pilha, 3);
    empilhar(minha_pilha, 2);

    printf("Estado da Pilha:\n");
    mostrar_pilha(minha_pilha);

    printf("\nElemento extraido via pop: %d\n", desempilhar(minha_pilha));

    printf("\nEstado da Pilha apos desempilhar:\n");
    mostrar_pilha(minha_pilha);

    return 0;
}