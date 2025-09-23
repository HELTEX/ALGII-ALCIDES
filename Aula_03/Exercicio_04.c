#include <stdio.h>

// Função para realizar saque
void sacar(double *saldo) {
    double valor;
    printf("\nDigite o valor a sacar: R$ ");
    scanf("%lf", &valor);
    
    if (valor <= 0) {
        printf("Valor inválido! O valor deve ser maior que zero.\n");
        return;
    }
    
    if (valor > *saldo) {
        printf("Saldo insuficiente! Saldo atual: R$ %.2f\n", *saldo);
        return;
    }
    
    *saldo -= valor;
    printf("\n=== Recibo de Saque ===\n");
    printf("Valor sacado: R$ %.2f\n", valor);
    printf("Saldo atual: R$ %.2f\n", *saldo);
    printf("======================\n");
}

// Função para realizar depósito
void depositar(double *saldo) {
    double valor;
    printf("\nDigite o valor a depositar: R$ ");
    scanf("%lf", &valor);
    
    if (valor <= 0) {
        printf("Valor inválido! O valor deve ser maior que zero.\n");
        return;
    }
    
    *saldo += valor;
    printf("\n=== Recibo de Depósito ===\n");
    printf("Valor depositado: R$ %.2f\n", valor);
    printf("Saldo atual: R$ %.2f\n", *saldo);
    printf("=========================\n");
}

// Função para verificar saldo
void verificarSaldo(double saldo) {
    printf("\n=== Saldo Atual ===\n");
    printf("Saldo: R$ %.2f\n", saldo);
    printf("==================\n");
}

int main() {
    double saldo = 0.0;
    int opcao;
    
    printf("Bem-vindo ao Caixa Eletrônico\n");
    
    do {
        printf("\nMenu de Operações:\n");
        printf("1. Sacar\n");
        printf("2. Depositar\n");
        printf("3. Verificar Saldo\n");
        printf("4. Sair\n");
        printf("Escolha uma opção (1-4): ");
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1:
                sacar(&saldo);
                break;
            case 2:
                depositar(&saldo);
                break;
            case 3:
                verificarSaldo(saldo);
                break;
            case 4:
                printf("\nObrigado por usar o Caixa Eletrônico. Até logo!\n");
                break;
            default:
                printf("Opção inválida! Por favor, escolha uma opção válida (1-4).\n");
        }
    } while (opcao != 4);
    
    return 0;
}