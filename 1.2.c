#include <stdio.h>

void inverter_valores(int *num1, int *num2) {
    int auxiliar = *num1;
    *num1 = *num2;
    *num2 = auxiliar;
}

int main() {
    int valor_a = 10;
    int valor_b = 20;
    int *ptr_dados;

    ptr_dados = &valor_a;
    printf("Valor original de A: %d\n", valor_a);
    printf("Endereco de memoria de A: %p\n", (void*)&valor_a);
    printf("Endereco contido no ponteiro: %p\n", (void*)ptr_dados);
    printf("Conteudo acessado via ponteiro: %d\n\n", *ptr_dados);

    *ptr_dados = 50;
    printf("Novo valor modificado de A: %d\n\n", valor_a);

    int sequencia[5] = {2, 4, 6, 8, 10};
    ptr_dados = sequencia;
    printf("Navegacao no vetor por meio de ponteiros:\n");
    for (int idx = 0; idx < 5; idx++) {
        printf("sequencia[%d] = %d\n", idx, ptr_dados[idx]);
    }

    printf("\nValores antes da inversao:\n");
    printf("A = %d, B = %d\n", valor_a, valor_b);

    inverter_valores(&valor_a, &valor_b);

    printf("\nValores apos a inversao:\n");
    printf("A = %d, B = %d\n", valor_a, valor_b);

    return 0;
}