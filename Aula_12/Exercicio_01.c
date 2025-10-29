#include <stdio.h>

void dobrar(int *ptr){
    *ptr *= 2;
}

int main(){
    int num;
    printf("Digite um número inteiro: ");
    scanf("%d", &num);
    dobrar(&num);
    printf("O valor dobrado é: %d\n", num);
    return 0;
}