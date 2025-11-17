#include<stdio.h>

int main(){
    char opcao;
    int valor, notas100, notas50, notas20, notas10;

    do {
        printf("Insira o valor que deseja sacar: R$ ");
        scanf("%d", &valor);
        if (valor < 10 || valor > 1000 || valor % 10 != 0){
            printf("Valor inválido! Insira um valor entre R$10 e R$1000, múltiplos de 10.\n");
        } else {
            notas100 = valor / 100;
            valor %= 100;
            notas50 = valor / 50;
            valor %= 50;
            notas20 = valor / 20;
            valor %= 20;
            notas10 = valor / 10;
            
            printf("Notas de R$100: %d\n", notas100);
            printf("Notas de R$50: %d\n", notas50);
            printf("Notas de R$20: %d\n", notas20);
            printf("Notas de R$10: %d\n", notas10);
            
        }

        printf("Deseja realizar outra operação? (s/n): ");
        scanf(" %c", &opcao);

   } while (opcao == 's' || opcao == 'S');


    return 0;
}