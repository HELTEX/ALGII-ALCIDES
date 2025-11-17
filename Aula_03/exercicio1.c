#include <stdio.h>

double converterParaCelsius(double f) {
    return (5.0 / 9.0) * (f - 32);
}

int main() {
    double f, c;
    char continuar;    
    do {
        // Solicita a temperatura em Fahrenheit
        printf("Digite a temperatura em Fahrenheit: ");
        scanf("%lf", &f);

        // Converte para Celsius
        c = converterParaCelsius(f);
        printf("A temperatura equivalente em Celsius é: %.2f\n", c);

        // Pergunta se deseja continuar
        printf("Deseja converter outra temperatura? (S/N): ");
        scanf(" %c", &continuar);
    } while (continuar == 'S' || continuar == 's');
    return 0;
}