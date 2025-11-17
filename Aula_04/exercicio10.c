#include <stdio.h>
#include <string.h>

#define MAX_FILMES 100
#define MAX_NOME 50
#define MAX_GENERO 30

// Função para calcular a média das avaliações dos filmes
float calcularMediaAvaliacoes(float avaliacoes[], int numeroFilmes) {
    float soma = 0;
    for (int i = 0; i < numeroFilmes; i++) {
        soma += avaliacoes[i];
    }
    return soma / numeroFilmes;
}

// Função para imprimir os filmes com avaliações acima da média
void imprimirFilmesBemAvaliados(char nomes[][MAX_NOME], float avaliacoes[], float media, int numeroFilmes) {
    printf("Filmes com avaliações acima da média:\n");
    for (int i = 0; i < numeroFilmes; i++) {
        if (avaliacoes[i] > media) {
            printf("Nome: %s (Avaliação: %.2f)\n", nomes[i], avaliacoes[i]);
        }
    }
}

// Função para categorizar filmes por gênero
void categorizarFilmesPorGenero(char nomes[][MAX_NOME], char generos[][MAX_GENERO], int numeroFilmes) {
    printf("\nFilmes categorizados por gênero:\n");

    // Exibir os filmes de Ação
    printf("\nAção:\n");
    for (int i = 0; i < numeroFilmes; i++) {
        if (strcmp(generos[i], "Ação") == 0) {
            printf("%s\n", nomes[i]);
        }
    }

    // Exibir os filmes de Drama
    printf("\nDrama:\n");
    for (int i = 0; i < numeroFilmes; i++) {
        if (strcmp(generos[i], "Drama") == 0) {
            printf("%s\n", nomes[i]);
        }
    }

    // Exibir os filmes de Romance
    printf("\nRomance:\n");
    for (int i = 0; i < numeroFilmes; i++) {
        if (strcmp(generos[i], "Romance") == 0) {
            printf("%s\n", nomes[i]);
        }
    }

    // Exibir os filmes de Ficção Científica
    printf("\nFicção Científica:\n");
    for (int i = 0; i < numeroFilmes; i++) {
        if (strcmp(generos[i], "Ficção Científica") == 0) {
            printf("%s\n", nomes[i]);
        }
    }
}

int main() {
    int numeroFilmes;

    // Solicita o número de filmes
    printf("Digite o número de filmes: ");
    scanf("%d", &numeroFilmes);

    // Declaração dos vetores
    char nomes[MAX_FILMES][MAX_NOME];
    char generos[MAX_FILMES][MAX_GENERO];
    float avaliacoes[MAX_FILMES];

    // Solicita as informações dos filmes
    for (int i = 0; i < numeroFilmes; i++) {
        printf("\nDigite o nome do filme %d: ", i + 1);
        getchar(); // Limpa o buffer do teclado
        fgets(nomes[i], MAX_NOME, stdin);
        nomes[i][strcspn(nomes[i], "\n")] = '\0';  // Remove o '\n' do final

        printf("Digite o gênero do filme %d (Ação, Drama, Romance, Ficção Científica): ", i + 1);
        fgets(generos[i], MAX_GENERO, stdin);
        generos[i][strcspn(generos[i], "\n")] = '\0';  // Remove o '\n'

        printf("Digite a avaliação do filme %d (0 a 10): ", i + 1);
        scanf("%f", &avaliacoes[i]);
    }

    // Calcula a média das avaliações
    float media = calcularMediaAvaliacoes(avaliacoes, numeroFilmes);
    printf("\nMédia das avaliações: %.2f\n", media);

    // Imprime os filmes com avaliações acima da média
    imprimirFilmesBemAvaliados(nomes, avaliacoes, media, numeroFilmes);

    // Categoriza os filmes por gênero
    categorizarFilmesPorGenero(nomes, generos, numeroFilmes);

    return 0;
}