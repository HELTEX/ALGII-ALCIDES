#include <stdio.h>

int main(){
    int n;
    unsigned long fat = 1;

    do {
        printf("Digite um número: ");
        scanf("%d", &n);

        if (n < 0) {
            printf("Número inválido, digite um número inteiro positivo\n");

        }

    } while (n < 0); 

    for (int i = 1; i <= n; i++){
        fat = fat*= i;
    }
    printf("O fatorial de %d é: %lu\n", n, fat);
    return 0;
}