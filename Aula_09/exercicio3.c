#include <stdio.h>

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

int main() {
    int vencimentos[12] = {
        20250601, 20250410, 20250405, 20250615,
        20250328, 20250701, 20250315, 20250530,
        20250325, 20250420, 20250605, 20250430
    };
    
    int n = 12;
    
    selectionSort(vencimentos, n);
    
    printf("Datas ordenadas de vencimento:\n");
    for (int i = 0; i < n; i++)
        printf("%d\n", vencimentos[i]);
    
    printf("\nTop 3 produtos com vencimento mais próximo:\n");
    for (int i = 0; i < 3; i++)
        printf("%d\n", vencimentos[i]);
    
    return 0;
}
