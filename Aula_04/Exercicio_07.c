#include <stdio.h>
#include <stdlib.h> // Necessário para alocação de memória (malloc, free)

// Define a média para aprovação como uma constante para fácil manutenção
#define MEDIA_APROVACAO 7.0

/**
 * @brief Calcula a média aritmética de um vetor de notas.
 * @param notas Vetor contendo as notas dos estudantes.
 * @param numEstudantes O número de estudantes (e de notas).
 * @return A média das notas da turma (tipo double).
 */
double calcularMediaTurma(float notas[], int numEstudantes) {
    // Se não houver estudantes, a média é 0 para evitar divisão por zero.
    if (numEstudantes == 0) {
        return 0.0;
    }

    double soma = 0.0;
    // Percorre o vetor de notas e acumula a soma.
    for (int i = 0; i < numEstudantes; i++) {
        soma += notas[i];
    }

    // Retorna a soma dividida pelo número de estudantes.
    return soma / numEstudantes;
}

/**
 * @brief Imprime o resultado individual de cada estudante (Aprovado ou Recuperação).
 * @param notas Vetor contendo as notas dos estudantes.
 * @param numEstudantes O número de estudantes.
 */
void imprimirResultados(float notas[], int numEstudantes) {
    printf("\n--- Resultados Individuais ---\n");
    // Percorre o vetor de notas para analisar cada estudante.
    for (int i = 0; i < numEstudantes; i++) {
        printf("Estudante %d: Nota %.1f - ", i + 1, notas[i]);
        
        // Verifica se a nota do estudante é maior ou igual à média para aprovação.
        if (notas[i] >= MEDIA_APROVACAO) {
            printf("Aprovado\n");
        } else {
            printf("RECUPERACAO\n");
        }
    }
     printf("----------------------------\n");
}


int main() {
    int numEstudantes;

    printf("--- Sistema de Avaliacao Escolar ---\n");
    printf("Digite o numero de estudantes na turma: ");
    scanf("%d", &numEstudantes);

    // Validação de entrada
    if (numEstudantes <= 0) {
        printf("Numero de estudantes invalido. Encerrando o programa.\n");
        return 1; // Encerra com erro
    }

    // Alocação dinâmica de memória para o vetor de notas.
    // O tamanho do vetor é definido pelo usuário.
    float *notas = (float *) malloc(numEstudantes * sizeof(float));

    // Verifica se a memória foi alocada com sucesso.
    if (notas == NULL) {
        printf("Erro ao alocar memoria. Encerrando o programa.\n");
        return 1; // Encerra com erro
    }

    printf("\nPor favor, insira a nota final de cada estudante:\n");
    for (int i = 0; i < numEstudantes; i++) {
        printf("Nota do Estudante %d: ", i + 1);
        scanf("%f", &notas[i]);
    }
    
    // Chama a função para calcular a média da turma.
    double mediaDaTurma = calcularMediaTurma(notas, numEstudantes);
    
    printf("\n----------------------------\n");
    // Imprime a média geral da turma, formatada com duas casas decimais.
    printf("Media geral da turma: %.2f\n", mediaDaTurma);
    
    // Chama a função para imprimir os resultados individuais.
    imprimirResultados(notas, numEstudantes);

    // Libera a memória que foi alocada dinamicamente para evitar vazamentos de memória.
    free(notas);

    return 0;
}