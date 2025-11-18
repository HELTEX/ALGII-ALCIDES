#include <stdio.h>

void trocar(int v[], int w[], int i, int j) {
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;

    // Trocar as matrículas correspondentes
    temp = w[i];
    w[i] = w[j];
    w[j] = temp;
}

int particionar(int notas[], int matriculas[], int low, int high) {
    int pivo_nota = notas[high];       // Pivô com base nas notas
    int pivo_matricula = matriculas[high]; // Pivô para desempate pelas matrículas
    int i = low - 1;

    for (int j = low; j < high; j++) {
        // Compara pela nota primeiro e pela matrícula em caso de empate
        if (notas[j] > pivo_nota || (notas[j] == pivo_nota && matriculas[j] < pivo_matricula)) {
            i++;
            trocar(notas, matriculas, i, j); // Troca nota e matrícula correspondentes
        }
    }
    trocar(notas, matriculas, i + 1, high);
    return i + 1;
}

void quick_sort(int notas[], int matriculas[], int low, int high) {
    if (low < high) {
        int pi = particionar(notas, matriculas, low, high);

        quick_sort(notas, matriculas, low, pi - 1);  // Ordena a parte à esquerda do pivô
        quick_sort(notas, matriculas, pi + 1, high); // Ordena a parte à direita do pivô
    }
}

int main() {
    int n;
    printf("Digite o número de alunos: ");
    scanf("%d", &n);

    int notas[n], matriculas[n];
    printf("Digite a matrícula e a nota dos alunos:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &matriculas[i], &notas[i]);
    }

    // Aplicando Quick Sort
    quick_sort(notas, matriculas, 0, n - 1);

    printf("Alunos ordenados por nota (e matrícula em caso de empate):\n");
    for (int i = 0; i < n; i++) {
 
