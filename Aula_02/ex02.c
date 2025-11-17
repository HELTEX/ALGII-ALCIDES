/*Desenvolva um programa que:
Solicite que o usuário digite os tamanhos dos lados do triângulo (a, b e c).
Verifique se existe um triângulo com estes lados.
Apresente na tela o resultado.*/

#include<stdio.h>

int main(){
    int a, b, c;

    printf("Digite o lado A: ");
    scanf("%d", &a);
    printf("Digite o lado B: ");
    scanf("%d", &b);
    printf("Digite o lado C: ");
    scanf("%d", &c);

    if (a < b + c && b < a + c && c < a + b){
        printf("É triangulo\n");
    } else {
        printf("Não é triangulo\n");
    }

    return 0;
}