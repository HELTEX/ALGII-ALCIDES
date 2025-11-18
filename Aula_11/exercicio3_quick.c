#include <stdio.h>
#include <string.h>

#define TAM 12

typedef struct {
    int codigo;
    char cliente[100];
    int quantidade;
    float valor_total;
} Pedido;

// Troca dois pedidos
void trocar(Pedido *a, Pedido *b) {
    Pedido temp = *a;
    *a = *b;
    *b = temp;
}

// Quick Sort por valor_total decrescente
int particionar(Pedido v[], int inicio, int fim) {
    float pivo = v[fim].valor_total;
    int i = inicio - 1;

    for (int j = inicio; j < fim; j++) {
        if (v[j].valor_total > pivo) { // ordem decrescente
            i++;
            trocar(&v[i], &v[j]);
        }
    }

    trocar(&v[i + 1], &v[fim]);
    return i + 1;
}

void quickSort(Pedido v[], int inicio, int fim) {
    if (inicio < fim) {
        int p = particionar(v, inicio, fim);
        quickSort(v, inicio, p - 1);
        quickSort(v, p + 1, fim);
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

    // Ordena os pedidos por valor_total decrescente
    quickSort(pedidos, 0, TAM - 1);

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
