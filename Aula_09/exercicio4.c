#include <stdio.h>
#include <string.h>

#define TAM 5

typedef struct {
    char titulo[100];
    char genero[50];
    int ano;
    int duracao; // em minutos
} Filme;

int main() {
    Filme filmes[TAM];
    /*
    ou
    Filme filmes[TAM] = {
        {"O Senhor dos Anéis: O Retorno do Rei", "Fantasia", 2003, 201},
        {"Coringa", "Drama", 2019, 122},
        {"Vingadores: Ultimato", "Ação", 2019, 181},
        {"Divertida Mente", "Animação", 2015, 95},
        {"A Origem", "Ficção Científica", 2010, 148}
    };
    */

    printf("Cadastro de %d filmes:\n", TAM);
    for (int i = 0; i < TAM; i++) {
        printf("\nFilme %d:\n", i + 1);
        
        printf("Título: ");
        fgets(filmes[i].titulo, sizeof(filmes[i].titulo), stdin);
        filmes[i].titulo[strcspn(filmes[i].titulo, "\n")] = '\0'; // Remove o \n
        
        printf("Gênero: ");
        fgets(filmes[i].genero, sizeof(filmes[i].genero), stdin);
        filmes[i].genero[strcspn(filmes[i].genero, "\n")] = '\0';
        
        printf("Ano de lançamento: ");
        scanf("%d", &filmes[i].ano);

        printf("Duração (em minutos): ");
        scanf("%d", &filmes[i].duracao);
        getchar(); // Limpa o buffer do ENTER
    }

    printf("\nFilmes com mais de 2 horas de duração:\n");
    int encontrou = 0;
    for (int i = 0; i < TAM; i++) {
        if (filmes[i].duracao > 120) {
            printf("\nTítulo: %s\nGênero: %s\nAno: %d\nDuração: %d minutos\n",
                filmes[i].titulo,
                filmes[i].genero,
                filmes[i].ano,
                filmes[i].duracao);
            encontrou = 1;
        }
    }

    if (!encontrou) {
        printf("\nNenhum filme com mais de 2h de duração foi cadastrado.\n");
    }

    return 0;
}
