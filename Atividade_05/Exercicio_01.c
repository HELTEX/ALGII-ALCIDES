#include <stdio.h>

int somaDigitos(int numero) {
    if (numero < 10) {
        return numero;
    } else {
        return (numero % 10) + somaDigitos(numero / 10);
    }    
}

int main() {
    int codigo;
    
    printf("Codigo de acesso: ");
    scanf("%d", &codigo);
    
    int resultado = somaDigitos(codigo);
    printf("%d\n", resultado);
    
    return 0;
}