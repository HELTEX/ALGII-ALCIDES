#include <stdio.h>
#include <stdbool.h>

#define ARRAY_SIZE(arr)     (sizeof((arr)) / sizeof((arr)[0]))

// Função para encontrar e imprimir a diferença entre dois vetores (A - B)
void diferencaVetor(int A[], int tamanhoA, int B[], int tamanhoB) {
    printf("A diferença A - B é: ");
    bool encontrou;
    // Verifica cada elemento de A para ver se ele NÃO está em B
    for (int i = 0; i < tamanhoA; i++) {
        encontrou = false;  // Assume que o elemento não está em B
        for (int j = 0; j < tamanhoB; j++) {
            if (A[i] == B[j]) {
                encontrou = true;  // Marca que encontrou o elemento em B
                break;  // Se encontrar, sai do laço
            }
        }

        // Se o elemento de A não estiver em B, imprime ele
        if (!encontrou) {
            printf("%d ", A[i]);
        }
    }
    printf("\n");
}

int main() {
    int a[] = {7, 2, 5, 8, 4};
    int b[] = {4, 2, 9, 5};

    int tamanhoA = ARRAY_SIZE(a);
    int tamanhoB = ARRAY_SIZE(b);

    printf("Vetor 1: ");
    for (int i = 0; i < tamanhoA; ++i)
        printf("%d  ", a[i]);
    printf("\n");

    printf("Vetor 2: ");
    for (int i = 0; i < tamanhoB; ++i)
        printf("%d  ", b[i]);
    printf("\n");

    // Chama a função para encontrar a diferença A - B
    diferencaVetor(a, tamanhoA, b, tamanhoB);

    return 0;
}