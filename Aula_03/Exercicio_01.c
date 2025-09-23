#include <stdio.h>

float converterParaCelsius(float far){
    return (5.0 / 9.0) * (far - 32);
}

int main() {
    float farhenheit;
    char continua;

    do {
        printf("Digite a temperatura em Farhenheit: ");
        scanf("%f", &farhenheit);
        printf("Temperatura em Celsius: %.2f\n", converterParaCelsius(farhenheit));
        printf("Deseja converter outra temperatura: (s/n)");
        scanf(" %c", &continua);
    } while (continua == 's' || continua == 'S');
    return 0;
}