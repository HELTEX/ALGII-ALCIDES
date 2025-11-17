#include <stdio.h>
#include <stdbool.h>

// Função para verificar se as temperaturas estão em ordem crescente
bool verificaOrdem(int temperaturas[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        if (temperaturas[i] > temperaturas[i + 1]) {
            return false;  // Se encontrar uma temperatura maior que a seguinte, retorna false
        }
    }
    return true;  // Se passar por todas as comparações, retorna true
}

int main() {
    int n;
    printf("Digite o número de dias de monitoramento: ");
    scanf("%d", &n);

    // Cria um vetor para armazenar as temperaturas
    int temperaturas[n];
    
    // Solicita as temperaturas registradas
    printf("Digite as temperaturas registradas ao longo dos dias:\n");
    for (int i = 0; i < n; i++) {
        printf("Dia %d: ", i + 1);
        scanf("%d", &temperaturas[i]);
    }

    // Verifica se as temperaturas estão em ordem crescente
    if (verificaOrdem(temperaturas, n)) {
        printf("As temperaturas estão em ordem crescente.\n");
    } else {
        printf("As temperaturas não estão em ordem crescente.\n");
    }
    return 0;
}