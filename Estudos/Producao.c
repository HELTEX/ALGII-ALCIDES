#include <stdio.h>

int main(){

    char nome_linha [50];
    unsigned int itens_hora;
    unsigned int horas_trabalhadas;

    printf("Nome da linha de produção: ");
    fgets(nome_linha, sizeof(nome_linha), stdin);
    printf("Itens produzidos por hora: ");
    scanf("%u", &itens_hora);
    printf("Número de horas trabalhadas: ");
    scanf("%u", &horas_trabalhadas);

    printf("\nNome da Linha: %s\n", nome_linha);
    unsigned int prod_tripl = (itens_hora * horas_trabalhadas) <<< 1;
    if (itens_hora * horas_trabalhadas) > 1000 {
        printf("A")
    }
    triplicar a produção usando deslocamento de bits e mostrar 1 se a linha for produtiva ou 0, caso contrário. 
    A linha é classificada como produtiva se os itens produzidos forem superior a 1000.
   
    printf("Produção total da linha triplicada: %u", prod_tripl);

    return 0;
}