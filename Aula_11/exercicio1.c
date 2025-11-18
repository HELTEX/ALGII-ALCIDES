#include <stdio.h>

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2]; // Vetores temporários

    // Copiando os dados para os vetores temporários
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Índices iniciais
    int i = 0, j = 0, k = left;

    // Mesclando os vetores temporários no original
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copiando os elementos restantes de L[], se houver
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copiando os elementos restantes de R[], se houver
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Ordena a primeira metade
        merge_sort(arr, left, mid);

        // Ordena a segunda metade
        merge_sort(arr, mid + 1, right);

        // Mescla as duas metades
        merge(arr, left, mid, right);
    }
}

int main() {
    int n;
    printf("Digite o número de arquivos: ");
    scanf("%d", &n);

    int datas[n];
    printf("Digite as datas de criação dos arquivos: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &datas[i]);
    }

    // Aplicando Merge Sort
    merge_sort(datas, 0, n - 1);

    printf("Datas ordenadas: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", datas[i]);
    }
    printf("\n");

    return 0;
}
