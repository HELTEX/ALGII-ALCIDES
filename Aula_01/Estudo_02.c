#include <stdio.h>
#include <string.h>

int main(){
    //declarar variáveis
    char titulo[50];
    int pag;
    int ano;
    //ler entradas e guardar nas variáveis
    printf("Título: ");
    fgets(titulo, sizeof(titulo), stdin);
    titulo[strcspn(titulo, "\n")] = '\0';
    printf("Número de páginas: ");
    scanf("%d", &pag);
    printf("Ano de publicação: ");
    scanf("%d", &ano);
    //fazer os cálculos e dar as saídas
    printf("Total de caracteres do titulo: %zu\n", strlen(titulo));
    printf("Número de páginas dobrado: %d\n", pag << 1);
    printf("Ano publicação ajustado: %d\n", ano *2);

    return 0;
}