#include <stdio.h>
#include <stdlib.h>

typedef struct ElementoCircular {
    int info_dado;
    struct ElementoCircular *proximo_elemento;
} NoCircular;

NoCircular* incluir_no_fim(NoCircular *cabeca, int informacao) {
    NoCircular *novo_elemento = (NoCircular*) malloc(sizeof(NoCircular));
    novo_elemento->info_dado = informacao;
    
    if (cabeca == NULL) {
        novo_elemento->proximo_elemento = novo_elemento;
        return novo_elemento;
    }
    
    NoCircular *auxiliar = cabeca;
    while (auxiliar->proximo_elemento != cabeca) {
        auxiliar = auxiliar->proximo_elemento;
    }
    auxiliar->proximo_elemento = novo_elemento;
    novo_elemento->proximo_elemento = cabeca;
    return cabeca;
}

void exibir_circular(NoCircular *cabeca) {
    if (cabeca == NULL) return;
    
    NoCircular *auxiliar = cabeca;
    do {
        printf("%d -> ", auxiliar->info_dado);
        auxiliar = auxiliar->proximo_elemento;
    } while (auxiliar != cabeca);
    printf("(retorna ao ponto de partida)\n");
}

int main() {
    NoCircular *lista_circular = NULL;
    int numero_usuario;

    for (int i = 0; i < 5; i++) {
        printf("Informe um numero inteiro: ");
        scanf("%d", &numero_usuario);
        lista_circular = incluir_no_fim(lista_circular, numero_usuario);
    }

    printf("\nEstrutura da Lista Circular:\n");
    exibir_circular(lista_circular);

    return 0;
}