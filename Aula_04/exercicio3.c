#include <stdio.h>

#define ARRAY_SIZE(arr)     (sizeof((arr)) / sizeof((arr)[0]))

// Função para encontrar e imprimir a interseção entre dois vetores
void encontrarInterseccao(int A[], int tamanhoA, int B[], int tamanhoB) {
    printf("A interseção entre os dois vetores é: ");
    int encontrou = 0;

    // Verifica cada elemento de A para ver se ele está em B
    for (int i = 0; i < tamanhoA; i++) {
        for (int j = 0; j < tamanhoB; j++) {
            if (A[i] == B[j]) {
                printf("%d ", A[i]);
                encontrou = 1;  // Marca que encontrou um elemento em comum
                break;  
            }
        }
    }
    
    // Caso não tenha encontrado nenhum elemento em comum
    if (!encontrou) {
        printf("{}");  // Imprime um conjunto vazio
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

    // Chama a função para encontrar a interseção entre A e B
    encontrarInterseccao(a, tamanhoA, b, tamanhoB);

    return 0;
}