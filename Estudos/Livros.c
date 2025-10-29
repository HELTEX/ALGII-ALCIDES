#include <stdio.h>
#include <string.h>

int main(){
    char titulo[50];
    unsigned int num_pag;
    int ano_pub;

    printf("Título do livro: ");
    fgets(titulo, sizeof(titulo), stdin);
    printf("Número de páginas: ");
    scanf("%u", &num_pag);
    printf("Ano de publicação: ");
    scanf("%d", &ano_pub);

    //calcular o número total de caracteres no título, 
    //dobrar o número de páginas e ajustar o ano de publicação multiplicando-o por 2
    int tam_titulo = strlen (titulo);
    unsigned int dobro_pag = num_pag << 1;
    int ano_ajustado = ano_pub * 2;
    
    printf("Titulo: %s\n", titulo);
    printf("Número de caracteres do titulo: %d\n", tam_titulo);
    printf("Número de páginas dobrado: %u\n", dobro_pag);
    printf("Ano de publicação ajustado: %d\n", ano_ajustado);

    return 0;
}