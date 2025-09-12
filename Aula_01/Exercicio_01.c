// Registro de Livros em uma Biblioteca
#include <stdio.h>
#include <string.h>

int main(){
    
    char titulo[50];
    unsigned int num_paginas;
    int ano_publicacao;

    printf("Título do livro: ");
    fgets(titulo, sizeof(titulo), stdin);

    printf("Número de páginas: ");
    scanf("%u", &num_paginas);

    printf("Ano de publicação: ");
    scanf("%d", &ano_publicacao);

    int tam_titulo = strlen(titulo);
    unsigned int dobro_paginas = num_paginas << 1;
    int ano_ajustado = ano_publicacao * 2;

    printf("Título Completo: %s\n", titulo);
    printf("Número Total de Caracteres do Título: %d\n", tam_titulo);
    printf("Número de Páginas Dobrado: %u\n", dobro_paginas);
    printf("Ano de Publicação Ajustado: %d\n", ano_ajustado);

    return 0;
}
