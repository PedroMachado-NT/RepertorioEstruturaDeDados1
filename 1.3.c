#include <stdio.h>

typedef struct {
    char nome_estudante[50];
    int idade_anos;
    float nota_disciplina;
} RegistroAluno;

void mostrar_dados(RegistroAluno estudante) {
    printf("\nEstudante: %s\n", estudante.nome_estudante);
    printf("Idade: %d anos\n", estudante.idade_anos);
    printf("Nota Final: %.2f\n", estudante.nota_disciplina);
}

void aplicar_bonificacao(RegistroAluno *estudante) {
    estudante->nota_disciplina += 1.0;
    if (estudante->nota_disciplina > 10.0) {
        estudante->nota_disciplina = 10.0;
    }
}

int main() {
    RegistroAluno grupo[3];
    float somatorio_notas = 0.0;

    for (int i = 0; i < 3; i++) {
        printf("\nCadastro do Aluno #%d\n", i + 1);
        printf("Nome completo: ");
        scanf(" %[^\n]", grupo[i].nome_estudante);
        printf("Idade atual: ");
        scanf("%d", &grupo[i].idade_anos);
        printf("Nota: ");
        scanf("%f", &grupo[i].nota_disciplina);
        somatorio_notas += grupo[i].nota_disciplina;
    }

    printf("\n===== LISTAGEM GERAL =====\n");
    for (int i = 0; i < 3; i++) {
        aplicar_bonificacao(&grupo[i]);
        mostrar_dados(grupo[i]);
    }

    printf("\nDesempenho medio do grupo: %.2f\n", somatorio_notas / 3);
    return 0;
}