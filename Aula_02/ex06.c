#include <stdio.h>
#include <stdbool.h>

int main(){
    int n, i, primo;
    char opcao;

    do {
        printf("Insira um número inteiro positivo: ");
        scanf("%d", &n);

        if (n <= 1){
            primo = false;
        } else {
            primo = true;
            for (i = 2; i <= n / 2; i++){
                if (n % i == 0){
                    primo = false;
                    break;
                }
            }
        }
        if (primo){
            printf("É primo\n");
        } else {
            printf("Não é primo\n");
        }
        printf("Deseja continuar? ");
        scanf(" %c", &opcao);

    } while (opcao == 's' || opcao == 'S');

    return 0;
}