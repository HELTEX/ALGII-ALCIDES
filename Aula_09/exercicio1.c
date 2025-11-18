#include <stdio.h>

void bubbleSort(float arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        int trocou = 0;
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                float temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                trocou = 1;
            }
        }
        if (!trocou) break;
    }
}

int main() {
    float temperaturas[20] = {23.5, 27.0, 21.4, 29.8, 22.3, 25.6, 24.7, 26.9, 30.2, 20.5,
                              28.3, 19.9, 31.1, 22.0, 26.0, 23.3, 25.0, 27.5, 20.1, 24.0};
    
    int n = 20;
    
    bubbleSort(temperaturas, n);
    
    printf("Temperaturas ordenadas:\n");
    for (int i = 0; i < n; i++)
        printf("%.1f ", temperaturas[i]);
    
    printf("\n\nMenor temperatura: %.1f°C\n", temperaturas[0]);
    printf("Maior temperatura: %.1f°C\n", temperaturas[n-1]);
    
    return 0;
}
