#include <stdio.h>
#include <stdlib.h>

typedef struct NoDuplo {
    int dado_valor;
    struct NoDuplo *elo_anterior;
    struct NoDuplo *elo_proximo;
} ElementoDuplo;

ElementoDuplo* fabricar_no(int informacao) {
    ElementoDuplo *novo_no = (ElementoDuplo*) malloc(sizeof(ElementoDuplo));
    if (novo_no != NULL) {
        novo_no->dado_valor = informacao;
        novo_no->elo_anterior = NULL;
        novo_no->elo_proximo = NULL;
    }
    return novo_no;
}

ElementoDuplo* adicionar_no_inicio(ElementoDuplo *cabeca, int informacao) {
    ElementoDuplo *novo_no = fabricar_no(informacao);
    novo_no->elo_proximo = cabeca;
    if (cabeca != NULL) {
        cabeca->elo_anterior = novo_no;
    }
    return novo_no;
}

ElementoDuplo* adicionar_no_final(ElementoDuplo *cabeca, int informacao) {
    ElementoDuplo *novo_no = fabricar_no(informacao);
    if (cabeca == NULL) {
        return novo_no;
    }
    ElementoDuplo *auxiliar = cabeca;
    while (auxiliar->elo_proximo != NULL) {
        auxiliar = auxiliar->elo_proximo;
    }
    auxiliar->elo_proximo = novo_no;
    novo_no->elo_anterior = auxiliar;
    return cabeca;
}

void mostrar_sentido_direto(ElementoDuplo *cabeca) {
    ElementoDuplo *auxiliar = cabeca;
    while (auxiliar != NULL) {
        printf("%d ", auxiliar->dado_valor);
        auxiliar = auxiliar->elo_proximo;
    }
    printf("\n");
}

void mostrar_sentido_inverso(ElementoDuplo *cabeca) {
    if (cabeca == NULL) return;
    ElementoDuplo *auxiliar = cabeca;
    while (auxiliar->elo_proximo != NULL) {
        auxiliar = auxiliar->elo_proximo;
    }
    while (auxiliar != NULL) {
        printf("%d ", auxiliar->dado_valor);
        auxiliar = auxiliar->elo_anterior;
    }
    printf("\n");
}

int main() {
    ElementoDuplo *lista_dupla = NULL;

    lista_dupla = adicionar_no_inicio(lista_dupla, 20);
    lista_dupla = adicionar_no_inicio(lista_dupla, 10);
    lista_dupla = adicionar_no_final(lista_dupla, 30);
    lista_dupla = adicionar_no_final(lista_dupla, 40);

    printf("Exibicao Direta:\n");
    mostrar_sentido_direto(lista_dupla);

    printf("Exibicao Reversa:\n");
    mostrar_sentido_inverso(lista_dupla);

    return 0;
}