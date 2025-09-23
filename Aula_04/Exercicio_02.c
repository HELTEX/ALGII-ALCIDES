#include <stdio.h>

// Define uma constante para o número de produtos, facilitando futuras alterações.
#define NUM_PRODUTOS 5

/**
 * @brief Inverte a ordem dos elementos de um vetor.
 * @param vetor O vetor de inteiros a ser invertido.
 * @param tamanho O número de elementos no vetor.
 */
void inverterVetor(int vetor[], int tamanho) {
    // O loop só precisa ir até a metade do vetor, pois trocamos os elementos das duas pontas.
    for (int i = 0; i < tamanho / 2; i++) {
        // --- Lógica de Troca (Swap) ---
        // 1. Guarda o valor do elemento do início em uma variável temporária.
        int temp = vetor[i];
        
        // 2. Coloca o valor do elemento do fim na posição do início.
        // O elemento correspondente do fim está na posição (tamanho - 1 - i).
        vetor[i] = vetor[tamanho - 1 - i];
        
        // 3. Coloca o valor guardado (original do início) na posição do fim.
        vetor[tamanho - 1 - i] = temp;
    }
}

/**
 * @brief Imprime os elementos de um vetor em um formato legível.
 * @param vetor O vetor de inteiros a ser impresso.
 * @param tamanho O número de elementos no vetor.
 */
void imprimirVetor(const char* titulo, int vetor[], int tamanho) {
    printf("%s", titulo);
    printf("[");
    for (int i = 0; i < tamanho; i++) {
        printf("%d", vetor[i]);
        // Adiciona uma vírgula e espaço para todos, exceto o último elemento.
        if (i < tamanho - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

int main() {
    // Declara um vetor para armazenar os dados de vendas.
    int vendas[NUM_PRODUTOS];

    printf("--- Analise de Vendas Semanais ---\n");
    printf("Por favor, insira os dados de vendas para os %d produtos.\n\n", NUM_PRODUTOS);

    // Loop para obter os dados do usuário.
    for (int i = 0; i < NUM_PRODUTOS; i++) {
        printf("Digite as vendas do produto %d: ", i + 1);
        scanf("%d", &vendas[i]);
    }

    printf("\n----------------------------------------\n");

    // Imprime o vetor original para verificação.
    imprimirVetor("Vendas na ordem original: ", vendas, NUM_PRODUTOS);

    // Chama a função para inverter o vetor.
    // Como vetores são passados por referência, a função modifica o vetor 'vendas' original.
    inverterVetor(vendas, NUM_PRODUTOS);

    // Imprime o vetor já invertido para a análise.
    imprimirVetor("Vendas na ordem invertida: ", vendas, NUM_PRODUTOS);
    
    printf("----------------------------------------\n");

    return 0;
}