#include <stdio.h>

void sacar(double *saldo) {
    double valorSaque;
    printf("Digite o valor do saque: R$ ");
    scanf("%lf", &valorSaque);
    
    if (valorSaque > *saldo) {
        printf("Saldo insuficiente para realizar o saque.\n");
    } else if (valorSaque <= 0) {
        printf("Valor de saque inválido. Tente novamente.\n");
    } else {
        *saldo -= valorSaque;
        printf("Saque de R$ %.2f realizado com sucesso.\n", valorSaque);
    }
}

void depositar(double *saldo) {
    double valorDeposito;
    printf("Digite o valor do deposito: R$ ");
    scanf("%lf", &valorDeposito);

    if (valorDeposito <= 0) {
        printf("Valor de depósito inválido. Tente novamente.\n");
    } else {
        *saldo += valorDeposito;
        printf("Depósito de R$ %.2f realizado com sucesso.\n", valorDeposito);
    }
}

void verificarSaldo(double saldo) {
    printf("Seu saldo atual é: R$ %.2f\n", saldo);
}

int main() {
    double saldo = 5000.0; 
    int opcao;

    do {
        // Menu
        printf("\nEscolha uma operação:\n");
        printf("1. Sacar\n");
        printf("2. Depositar\n");
        printf("3. Verificar Saldo\n");
        printf("4. Sair\n");
        printf("Digite a sua opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: sacar(&saldo); 
                    break;
            case 2: depositar(&saldo); 
                    break;
            case 3: verificarSaldo(saldo);
                    break;
            case 4: printf("Obrigado por usar o caixa eletrônico. Até mais!\n");
                    break;
            default:printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 4);
    return 0;
}