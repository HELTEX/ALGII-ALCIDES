#include <stdio.h>
#include <math.h> 

double calcularAreaEsfera(double raio) {
    return 4 * M_PI * raio * raio; 
}

int main() {
    double raio, area;
    char continuar;
    do {
        // Solicita o raio da esfera
        printf("Digite o raio da esfera: ");
        scanf("%lf", &raio);
        // Calcula a área com a função calcularAreaEsfera
        area = calcularAreaEsfera(raio);
        printf("A área da esfera é: %.2f unidades quadradas.\n", area);

        // Pergunta se deseja continuar
        printf("Deseja calcular a área de outra esfera? (S/N): ");
        scanf(" %c", &continuar);
    } while (continuar == 'S' || continuar == 's');
    return 0;
}