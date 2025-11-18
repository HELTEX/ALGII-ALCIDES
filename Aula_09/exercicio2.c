#include <stdio.h>

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int chave = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > chave) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = chave;
    }
}

int main() {
    int idades[15] = {34, 28, 45, 32, 40, 36, 29, 50, 27, 31, 38, 46, 33, 30, 44};
    int n = 15;
    
    insertionSort(idades, n);
    
    printf("Idades ordenadas:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", idades[i]);
    
    printf("\n\nTop 5 candidatos mais velhos:\n");
    for (int i = n - 5; i < n; i++)
        printf("%d anos\n", idades[i]);
    
    return 0;
}
