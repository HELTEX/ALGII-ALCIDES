#include <stdio.h>
#include <stdbool.h> // Biblioteca para usar os tipos 'true' e 'false'
#include <stdlib.h>  // Biblioteca para alocação de memória (malloc) e liberação (free)

/**
 * @brief Verifica se um vetor de temperaturas está em ordem estritamente crescente.
 * @param temperaturas Ponteiro para o vetor de temperaturas.
 * @param numDias O número de elementos no vetor.
 * @return Retorna 'true' se as temperaturas estiverem em ordem crescente, 
 * e 'false' caso contrário.
 */
bool verificaOrdemCrescente(int *temperaturas, int numDias) {
    // Se houver 0 ou 1 dia, a sequência é considerada crescente por definição.
    if (numDias <= 1) {
        return true;
    }

    // Percorre o vetor até o PENÚLTIMO dia.
    // Comparamos cada dia com o dia seguinte.
    for (int i = 0; i < numDias - 1; i++) {
        // Se a temperatura de um dia for maior ou igual à do dia seguinte,
        // a ordem crescente foi quebrada.
        if (temperaturas[i] >= temperaturas[i + 1]) {
            return false; // Retorna 'false' imediatamente e encerra a função.
        }
    }

    // Se o loop terminar sem nunca encontrar uma quebra na sequência,
    // significa que o vetor está em ordem crescente.
    return true;
}

int main() {
    int numDias;

    printf("--- Monitor de Tendencia Climatica ---\n");
    printf("Quantos dias voce deseja registrar? ");
    scanf("%d", &numDias);

    // Validação para garantir que o número de dias seja positivo
    if (numDias <= 0) {
        printf("Numero de dias invalido. O programa sera encerrado.\n");
        return 1; // Encerra o programa com um código de erro
    }

    // Alocação dinâmica de memória para o vetor de temperaturas
    // O tamanho do vetor é determinado pelo usuário em tempo de execução.
    int *temperaturas = (int *) malloc(numDias * sizeof(int));

    // Verifica se a alocação de memória foi bem-sucedida
    if (temperaturas == NULL) {
        printf("Erro ao alocar memoria! O programa sera encerrado.\n");
        return 1; // Encerra o programa com um código de erro
    }

    printf("\nPor favor, insira as temperaturas de cada dia:\n");
    for (int i = 0; i < numDias; i++) {
        printf("Temperatura do dia %d: ", i + 1);
        scanf("%d", &temperaturas[i]);
    }

    // Chama a função para verificar a ordem e armazena o resultado
    bool estaoEmOrdem = verificaOrdemCrescente(temperaturas, numDias);

    // Exibe o resultado da análise
    printf("\n--- Relatorio de Tendencia ---\n");
    if (estaoEmOrdem) {
        printf("ANALISE: As temperaturas estao em ordem crescente.\n");
        printf("CONCLUSAO: Ha uma clara tendencia de aquecimento ao longo do periodo.\n");
    } else {
        printf("ANALISE: As temperaturas NAO estao em ordem crescente.\n");
        printf("CONCLUSAO: Nao ha uma tendencia constante de aquecimento no periodo analisado.\n");
    }

    // Libera a memória que foi alocada dinamicamente
    free(temperaturas);

    return 0;
}