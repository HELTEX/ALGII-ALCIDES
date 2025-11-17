#include <stdio.h>

#define ARRAY_SIZE(arr)     (sizeof((arr)) / sizeof((arr)[0]))

// Função que busca a posição do valor x no vetor
int buscarValor(int vetor[], int tamanho, int x) {
    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] == x) {
            return i;  // Retorna a posição se o valor for encontrado
        }
    }
    return -1;  // Retorna -1 se o valor não for encontrado
}

int main() {
    int vetor[5] = {7, 3, 9, 12, 5};  // Exemplo de vetor com 5 números inteiros
    int x;

    printf("Vetor: ");
    for (int i = 0; i < n; ++i)
        printf("%d  ", vetor[i]);
    printf("\n");

    // Solicita que o usuário insira o valor a ser procurado
    printf("Digite o valor do produto a ser procurado: ");
    scanf("%d", &x);

    // Chama a função de busca e armazena o resultado
    int posicao = buscarValor(vetor, ARRAY_SIZE(vetor) , x);

    // Exibe o resultado
    if (posicao != -1) {
        printf("O valor %d foi encontrado na posição %d.\n", x, posicao);
    } else {
        printf("O valor %d não foi encontrado no vetor.\n", x);
    }

    return 0;
}