/* Programa que simula a velocidade média de ciclistas em uma corrida
* Cada ciclista tem um nome, a distancia total percorrida em quilômetros
* e o tempo total gasto em horas. 
* O sistema deve calcular a velocidade média, dobrar a distância percorrida usando deslocamento
* e exibir se o ciclista é veloz (1) ou não (0).
*/
#include <stdio.h>
#include <string.h>

int main(){
    //criação das variáveis
    char nome[50];
    unsigned int distancia_percorrida;
    unsigned int tempo_total;

    // Entradas
    printf("Nome: ");
    fgets(nome, sizeof(nome), stdin);
    printf("Distância Percorrida: ");
    scanf("%d", &distancia_percorrida);
    printf("Tempo total: ");
    scanf("%d", &tempo_total);

    //Calculos
    int velocidade_media = (distancia_percorrida / tempo_total);
    int distancia_percorrida_dobrada = distancia_percorrida << 1;

    //impressão
    printf("Nome: %s", nome);
    printf("Velocidade_media: %d\n", velocidade_media);
    printf("Distancia dobrada: %d\n", distancia_percorrida_dobrada);
    if (velocidade_media < 30) {
        printf("Não é veloz!\n");
    } else {
        printf("É veloz!\n");
    }
    return 0;
}