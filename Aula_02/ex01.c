/*Programa que recebe como entrada via teclado 
a média de um aluno, e sua porcentagem de frequencia
retorna se o aluno está aprovado ou reprovado
*/

#include<stdio.h>

int main(){
    float media;
    int frequencia;

    printf("Digite a média: ");
    scanf("%f", &media);
    printf("Digite a porcentagem de frequencia (0 a 100): ");
    scanf("%d", &frequencia);

    if (frequencia <= 75){
        printf("REPROVADO\n");
    } else if (media >= 6.0){
        printf("APROVADO\n");
    } else {
        printf("EXAME\n");
    }
    return 0;
}