#include <stdio.h>

int potencia(int base, int exp) {
    if (exp == 0)
        return 1; // Qualquer número elevado a 0 é 1
    else
        return base * potencia(base, exp - 1);
}

int main() {
    int base, exp;

    printf("Digite a base: ");
    scanf("%d", &base);
    printf("Digite o expoente: ");
    scanf("%d", &exp);

    int resultado = potencia(base, exp);
    printf("%d elevado a %d = %d\n", base, exp, resultado);

    return 0;
}
