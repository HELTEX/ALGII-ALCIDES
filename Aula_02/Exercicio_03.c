/*Desenvolva um programa que: Solicite ao usuário o valor total de uma compra. 
* Calcule o desconto com base nas seguintes regras: 
* Se o valor for menor que R$100,00, o desconto é de 5%. 
* Se o valor for entre R$100,00 e R$300,00, o desconto é de 10%. 
* Se o valor for maior que R$300,00, o desconto é de 15%. 
* Exiba o valor final após o desconto. Pergunte ao usuário se ele deseja fazer outro cálculo 
* (use um loop do...while para repetir o processo até que o usuário escolha sair).
*/

#include <stdio.h>

int main(){
    float valor_compra; 
    float desconto;
    char continuar = 's';

    while (continuar == 's'){
        
        printf("Valor da compra RS \n");
        scanf("%f", &valor_compra);

        if (valor_compra < 100) {
            desconto = valor_compra - (valor_compra * 0.05);
            printf("Valor com desconto: R$%.2f\n", desconto);
        } else if (valor_compra > 100 && valor_compra < 300) {
            desconto = valor_compra - (valor_compra * 0.10);
            printf("Valor com desconto: R$%.2f\n", desconto);
        } else if (valor_compra > 300) {
            desconto = valor_compra - (valor_compra * 0.15);
            printf("Valor com desconto: R$%.2f\n", desconto);
        }
        
        printf("\nDeseja fazer outro calculo? (s/n): ");
        scanf(" %c", &continuar);
    }
    
    return 0;
}