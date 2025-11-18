#include <stdio.h>
#include <string.h>

#define TAM 12

typedef struct {
    int codigo;
    char cliente[100];
    int quantidade;
    float valor_total;
} Pedido;

// Função para mesclar dois subvetores
void merge(Pedido v[], int inicio, int meio, int fim) {
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    Pedido L[n1], R[n2];

    // Copiando para vetores auxiliares
    for (int i = 0; i < n1; i++)
        L[i] = v[inicio + i];
    for (int j = 0; j < n2; j++)
        R[j] = v[meio + 1 + j];

    // Intercalação em ordem decrescente
    int i = 0, j = 0, k = inicio;
    while (i < n1 && j < n2) {
        if (L[i].valor_total >= R[j].valor_total) {
            v[k++] = L[i++];
        } else {
            v[k++] = R[j++];
        }
    }

    while (i < n1) v[k++] = L[i++];
    while (j < n2) v[k++] = R[j++];
}

// Merge Sort recursivo
void mergeSort(Pedido v[], int inicio, int fim) {
    if (inicio < fim) {
        int meio = inicio + (fim - inicio) / 2;
        mergeSort(v, inicio, meio);
        mergeSort(v, meio + 1, fim);
        merge(v, inicio, meio, fim);
    }
}

int main() {
    Pedido pedidos[TAM] = {
        {1001, "Maria Silva",        3, 450.75},
        {1002, "João Pereira",       1, 120.00},
        {1003, "Fernanda Costa",     5, 799.90},
        {1004, "Carlos Eduardo",     2, 310.50},
        {1005, "Beatriz Almeida",    4, 625.20},
        {1006, "Rafael Tavares",     6, 950.00},
        {1007, "Patrícia Gomes",     2, 299.99},
        {1008, "Luciana Ribeiro",    1, 150.00},
        {1009, "Bruno Fernandes",    3, 480.00},
        {1010, "Camila Andrade",     4, 699.90},
        {1011, "Thiago Souza",       7, 1120.00},
        {1012, "Juliana Rocha",      2, 350.30}
    };

    // Ordena usando Merge Sort
    mergeSort(pedidos, 0, TAM - 1);

    // Exibe os 5 maiores pedidos
    printf("🧾 Top 5 maiores pedidos por valor:\n\n");
    for (int i = 0; i < 5; i++) {
        printf("Código: %d\n", pedidos[i].codigo);
        printf("Cliente: %s\n", pedidos[i].cliente);
        printf("Quantidade: %d\n", pedidos[i].quantidade);
        printf("Valor Total: R$ %.2f\n", pedidos[i].valor_total);
        printf("-------------------------------\n");
    }

    return 0;
}
