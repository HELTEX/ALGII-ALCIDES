/*Um triângulo possui 3 lados com tamanhos a, b e c. 
* Para que um triângulo exista, um lado deve ser menor que a soma dos outros dois, 
* ou seja, as seguintes condições devem ser satisfeitas: a < b + c b < a + c c < a + b 
* Desenvolva um programa que: • Solicite que o usuário digite os tamanhos dos lados do triângulo (a, b e c)
* • Verifique se existe um triângulo com estes lados. • Apresente na tela o resultado.
*/
#include <stdio.h>

int main(){


int a;
int b;
int c;

printf("Digite o primeiro lado do triângulo: \n");
scanf("%d", &a);
printf("Digite o segundo lado do triângulo: \n");
scanf("%d", &b);
printf("Digite o terceiro lado do triângulo: \n");
scanf("%d", &c);

int triangulo;

if ((a < b + c) || (b < a + c) || (c < a + b)){
    printf("É triangulo!\n");
} else {
    printf("Não é triangulo.\n");
}
return 0;
}