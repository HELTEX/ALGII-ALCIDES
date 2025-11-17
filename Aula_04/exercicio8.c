#include <stdio.h>

// Função para calcular a média semanal das temperaturas
float calcularMediaSemanal(float temperaturas[], int dias) {
    float soma = 0;
    for (int i = 0; i < dias; i++) {
        soma += temperaturas[i];
    }
    return soma / dias;
}

// Função para identificar tendências de temperatura
void identificarTendencias(float temperaturas[], int dias) {
    for (int i = 0; i < dias - 1; i++) {
        if (temperaturas[i] < temperaturas[i + 1]) {
            printf("Dia %d para Dia %d: Aumentou\n", i + 1, i + 2);
        } else if (temperaturas[i] > temperaturas[i + 1]) {
            printf("Dia %d para Dia %d: Diminuiu\n", i + 1, i + 2);
        } else {
            printf("Dia %d para Dia %d: Manteve-se constante\n", i + 1, i + 2);
        }
    }
}

int main() {
    int dias = 7;
    float temperaturas[dias];

    // Solicita ao usuário as temperaturas médias dos 7 dias
    for (int i = 0; i < dias; i++) {
        printf("Digite a temperatura média do dia %d: ", i + 1);
        scanf("%f", &temperaturas[i]);
    }

    // Calcula a média semanal
    float mediaSemanal = calcularMediaSemanal(temperaturas, dias);
    printf("Média semanal das temperaturas: %.2f\n", mediaSemanal);

    // Identifica as tendências de variação de temperatura
    identificarTendencias(temperaturas, dias);

    return 0;
}