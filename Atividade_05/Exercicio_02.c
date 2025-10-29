#include <stdio.h>

void imprimeBinario(int numero) {
    if (numero == 0) {
        printf("0");
        return;
    }
    if (numero == 1) {
        printf("1");
        return;
    }
    imprimeBinario(numero / 2);
    printf("%d", numero % 2);
}

int main() {
    int numero;

    printf("Digite um numero: ");
    scanf("%d", &numero);
    
    if (numero == 0) {
        printf("0\n");
        return 0;
    }
    
    imprimeBinario(numero);
    printf("\n");
    
    return 0;
}