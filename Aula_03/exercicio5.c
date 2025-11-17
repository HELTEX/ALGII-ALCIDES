#include <stdio.h>
#include <ctype.h>  // Para usar as funções isdigit

int validarCPF(char cpf[]) {
    int i, digito1 = 0, digito2 = 0;
    int soma1 = 0, soma2 = 0;

    // Verifica o formato 
    for (i = 0; cpf[i] != '\0'; i++) {
        if (i == 3 || i == 7) {
            if (cpf[i] != '.') return 0;  
        } else if (i == 11) {
            if (cpf[i] != '-') return 0;  
        } else if (!isdigit(cpf[i])) {
            return 0;  
        }
    }

    // Verifica o tamanho correto
    if (i != 14) return 0;

    // Calcula o primeiro dígito verificador
    int multiplicador = 10; 
    for (i = 0; i < 11; i++) {
        if (isdigit(cpf[i])) {
            soma1 += (cpf[i] - '0') * multiplicador;
            multiplicador--;
        }
    }

    digito1 = 11 - (soma1 % 11);
    if (digito1 >= 10) digito1 = 0;

    // Calcula o segundo dígito verificador
    multiplicador = 11;  
    for (i = 0; i < 12; i++) {
        if (isdigit(cpf[i])) {
            soma2 += (cpf[i] - '0') * multiplicador;
            multiplicador--;
        }
    }

    digito2 = 11 - (soma2 % 11);
    if (digito2 >= 10) digito2 = 0;

    // Verifica se os dígitos verificadores estão corretos
    return (digito1 == (cpf[12] - '0')) && (digito2 == (cpf[13] - '0'));
}

int main() {
    char cpf[15];

    // Solicita o CPF
    printf("Digite o CPF no formato XXX.XXX.XXX-YY: ");
    scanf("%14s", cpf);  // Lê no máximo 14 caracteres + '\0'

    if (validarCPF(cpf)) {
        printf("CPF válido.\n");
    } else {
        printf("CPF inválido.\n");
    }
    return 0;
}