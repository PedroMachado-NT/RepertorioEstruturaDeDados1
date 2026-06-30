#include <stdio.h>
#include <stdlib.h>

typedef struct NoLista {
    int valor_info;
    struct NoLista *proximo_no;
} ElementoLista;

ElementoLista* criar_lista_vazia() {
    return NULL;
}

ElementoLista* inserir_no_topo(ElementoLista *lista_atual, int informacao) {
    ElementoLista *novo_no = (ElementoLista*) malloc(sizeof(ElementoLista));
    if (novo_no != NULL) {
        novo_no->valor_info = informacao;
        novo_no->proximo_no = lista_atual;
    }
    return novo_no;
}

void exibir_estrutura(ElementoLista *lista_atual) {
    ElementoLista *auxiliar = lista_atual;
    while (auxiliar != NULL) {
        printf("%d -> ", auxiliar->valor_info);
        auxiliar = auxiliar->proximo_no;
    }
    printf("NULL\n");
}

ElementoLista* pesquisar_elemento(ElementoLista *lista_atual, int alvo) {
    for (ElementoLista *auxiliar = lista_atual; auxiliar != NULL; auxiliar = auxiliar->proximo_no) {
        if (auxiliar->valor_info == alvo) {
            return auxiliar;
        }
    }
    return NULL;
}

ElementoLista* excluir_cauda(ElementoLista *lista_atual) {
    if (lista_atual == NULL) return NULL;
    if (lista_atual->proximo_no == NULL) {
        free(lista_atual);
        return NULL;
    }
    
    ElementoLista *auxiliar = lista_atual;
    while (auxiliar->proximo_no->proximo_no != NULL) {
        auxiliar = auxiliar->proximo_no;
    }
    free(auxiliar->proximo_no);
    auxiliar->proximo_no = NULL;
    return lista_atual;
}

void limpar_memoria(ElementoLista *lista_atual) {
    ElementoLista *auxiliar = lista_atual;
    while (auxiliar != NULL) {
        ElementoLista *proximo_pendente = auxiliar->proximo_no;
        free(auxiliar);
        auxiliar = proximo_pendente;
    }
}

int main() {
    ElementoLista *minha_lista = criar_lista_vazia();
    int valor_digitado;

    for (int i = 0; i < 5; i++) {
        printf("Informe um numero inteiro: ");
        scanf("%d", &valor_digitado);
        minha_lista = inserir_no_topo(minha_lista, valor_digitado);
    }

    printf("\nEstado atual da Lista:\n");
    exibir_estrutura(minha_lista);

    printf("\nDigite um numero para busca: ");
    scanf("%d", &valor_digitado);
    ElementoLista *busca_resultado = pesquisar_elemento(minha_lista, valor_digitado);
    
    if (busca_resultado != NULL) {
        printf("Resultado: Encontrado com sucesso!\n");
    } else {
        printf("Resultado: Nao localizado na lista.\n");
    }

    minha_lista = excluir_cauda(minha_lista);
    printf("\nLista apos a remocao da cauda (ultimo):\n");
    exibir_estrutura(minha_lista);

    limpar_memoria(minha_lista);
    return 0;
}