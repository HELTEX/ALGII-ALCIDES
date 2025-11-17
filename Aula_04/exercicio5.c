#include <stdio.h>
#include <stdbool.h>

#define ARRAY_SIZE(arr)     (sizeof((arr)) / sizeof((arr)[0]))

// Função para calcular a união dos vetores A e B
void uniaoVetor(int A[], int tamanhoA, int B[], int tamanhoB) {
    printf("A união de A e B é: ");

    // Primeiro imprime todos os elementos de A
    for (int i = 0; i < tamanhoA; i++) {
        printf("%d ", A[i]);
    }

    // Em seguida, imprime os elementos de B que não estão em A
    for (int j = 0; j < tamanhoB; j++) {
        bool estaPresente = false;  // Variável para verificar se o elemento de B está em A
        for (int i = 0; i < tamanhoA; i++) {
            if (B[j] == A[i]) {
                estaPresente = true;  // Marca que o elemento de B já está em A
                break;
            }
        }
        // Se o elemento de B não estiver em A, imprime ele
        if (!estaPresente) {
            printf("%d ", B[j]);
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

    // Chama a função para calcular a união de A e B
    uniaoVetor(a, tamanhoA, b, tamanhoB);

    return 0;
}