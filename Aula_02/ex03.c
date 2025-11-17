#include<stdio.h>

int main(){
    float valor_compra, valor_com_desconto;
    char opcao;

    do {
        printf("Digite o valor total da compra R$ ");
        scanf("%f", &valor_compra);

        if (valor_compra < 100.0){
            valor_com_desconto = valor_compra * 0.95;
        } else if (valor_compra >= 100.0 && valor_compra < 300.0){
            valor_com_desconto = valor_compra * 0.90;
        } else {
            valor_com_desconto = valor_compra * 0.85;
        }
        printf("Total com desconto R$ %.2f\n", valor_com_desconto);
        printf("Deseja consultar outro valor? (s/n) ");
        scanf(" %c", &opcao);

    } while (opcao == 's' || opcao == 'S');
    return 0;
}