#include <stdio.h>

#define TAMANHO 5

// Função para inverter os valores de um vetor
void inverterVetor(int vetor[], int tamanho) {
    int inicio = 0, fim = tamanho - 1;
    while (inicio < fim) {
        int temp = vetor[inicio];
        vetor[inicio] = vetor[fim];
        vetor[fim] = temp;       
        
        inicio++;
        fim--;
    }
}

int main() {
    int vendas[TAMANHO];
    
    printf("Digite as vendas dos 5 produtos:\n");
    for (int i = 0; i < TAMANHO; i++) {
        printf("Produto %d: ", i + 1);
        scanf("%d", &vendas[i]);
    }
    
    inverterVetor(vendas, TAMANHO);
    
    printf("O vetor invertido de vendas é:\n");
    for (int i = 0; i < TAMANHO; i++) {
        printf("%d ", vendas[i]);
    }
    printf("\n");
    return 0;
}