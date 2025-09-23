#include <stdio.h>
#include <math.h>

float calcularAreaEsfera (float raio){
    return (4 * M_PI * pow(raio, 2));
}

int main() {
    float raio;
    char continua;

    do {
        printf("Digite o raio da esfera: ");
        scanf("%f", &raio);
        printf("A área da esfera é %.2f\n", calcularAreaEsfera(raio));
        printf("Deseja calcular outra área (s/n)");
        scanf(" %c", &continua);
    } while (continua == 's' || continua == 'S');
    return 0;
}