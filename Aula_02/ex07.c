#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(){
    int num_sorteado, palpite, tentativas;
    srand(time(0));
    num_sorteado = rand() % 100 + 1;

    do{ 
        printf("Advinhe o número (1 - 100): ");
        scanf("%d", &palpite);
        tentativas ++;
        if (palpite < 1 || palpite > 100){
            printf("Palpite inválido! Tente novamente!\n");
            
        } else if (palpite == num_sorteado){
            printf("Parabéns! Você acertou\n");
            printf("Foram %d tentativas", tentativas);
        } else if (palpite < num_sorteado) {
            printf("Você chutou muito baixo! Retorne para uma nova tentativa\n");
            
        } else if (palpite > num_sorteado){
            printf("Você chutou muito alto! tente novamente\n");
            
        }
    } while (palpite != num_sorteado);

    return 0;
}