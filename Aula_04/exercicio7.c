#include <stdio.h>

// Função para calcular a média das notas
float calcularMedia(float notas[], int numeroEstudantes) {
    float soma = 0;
    for (int i = 0; i < numeroEstudantes; i++) {
        soma += notas[i];
    }
    return soma / numeroEstudantes;
}

// Função para imprimir os resultados dos estudantes
void imprimirResultados(float notas[], int numeroEstudantes) {    
    for (int i = 0; i < numeroEstudantes; i++) {
        if (notas[i] >= 7.0) {
            printf("Estudante %d: Aprovado (Nota: %.2f)\n", i + 1, notas[i]);
        } else {
            printf("Estudante %d: Recuperação (Nota: %.2f)\n", i + 1, notas[i]);
        }
    }
}

int main() {
    int numeroEstudantes;

    // Solicita o número de estudantes
    printf("Digite o número de estudantes: ");
    scanf("%d", &numeroEstudantes);

    float notas[numeroEstudantes];

    // Solicita as notas dos estudantes
    for (int i = 0; i < numeroEstudantes; i++) {
        printf("Digite a nota final do estudante %d: ", i + 1);
        scanf("%f", &notas[i]);
    }

    // Calcula a média das notas
    float media = calcularMediaTurma(notas, numeroEstudantes);
    printf("Média da turma: %.2f\n", media);

    // Imprime os resultados
    imprimirResultados(notas, numeroEstudantes);

    return 0;
}