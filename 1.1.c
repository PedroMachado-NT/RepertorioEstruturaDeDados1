#include <stdio.h>

int main() {
    int total_alunos, contador = 1;
    int total_aprovados = 0;
    float nota_atual, soma_notas = 0.0, media_geral;
    char opcao_repetir;

    printf("Digite a quantidade de alunos para o cadastro: ");
    scanf("%d", &total_alunos);

    for (contador = 1; contador <= total_alunos; contador++) {
        printf("\nRegistro do Aluno %d\n", contador);
        printf("Informe a nota obtida: ");
        scanf("%f", &nota_atual);
        soma_notas += nota_atual;

        if (nota_atual >= 7.0) {
            printf("Status: Aprovado\n");
            total_aprovados++;
        } else if (nota_atual >= 5.0) {
            printf("Status: Recuperacao\n");
        } else {
            printf("Status: Reprovado\n");
        }
    }

    media_geral = soma_notas / total_alunos;
    printf("\n====================================\n");
    printf("Media final da turma: %.2f\n", media_geral);
    printf("Quantidade de aprovados: %d\n", total_aprovados);

    do {
        printf("\nDeseja exibir o valor da media novamente? (S/N): ");
        scanf(" %c", &opcao_repetir);
        if (opcao_repetir == 'S' || opcao_repetir == 's') {
            printf("Media calculada: %.2f\n", media_geral);
        }
    } while (opcao_repetir == 'S' || opcao_repetir == 's');

    printf("\nExecucao encerrada.\n");
    return 0;
}