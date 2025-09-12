// Cálculo de Produção em uma Fábrica

#include <stdio.h>

int main(){

    //definição de variáveis
    char nome_linha[50];
    unsigned int itens_hora;
    unsigned int num_horas_trabalhadas;

    //entradas
    printf("Nome da linha de montagem: ");
    fgets(nome_linha, sizeof(nome_linha), stdin);
    
    printf("Itens produzidos por hora: ");
    scanf("%u", &itens_hora);

    printf("Número de horas trabalhadas: ");
    scanf("%u", &num_horas_trabalhadas);

    //calculos
    int producao_total = itens_hora * num_horas_trabalhadas;
    unsigned int triplica = producao_total *3 ;

    printf("\nLinha de montagem: %s\n", nome_linha);
    printf("Produção total: %u itens\n", producao_total);
    printf("Produção triplicada: %u itens\n", triplica);

    if (triplica >= 1000) {
        printf("Linha produtiva\n");
    } else {
        printf("Linha não produtiva\n");
    }

    return 0;
}