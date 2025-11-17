#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LIVROS 100
#define MAX_TITULO 50
#define MAX_AUTOR 50

// Função para emprestar um livro
void emprestarLivro(int codigos[], bool disponibilidade[], int codigo, int numeroLivros) {
    for (int i = 0; i < numeroLivros; i++) {
        if (codigos[i] == codigo) {
            if (disponibilidade[i]) {
                disponibilidade[i] = false;
                printf("O livro com código %d foi emprestado.\n", codigo);
            } else {
                printf("O livro com código %d já está emprestado.\n", codigo);
            }
            return;
        }
    }
    printf("Livro com código %d não encontrado.\n", codigo);
}

// Função para devolver um livro
void devolverLivro(int codigos[], bool disponibilidade[], int codigo, int numeroLivros) {
    for (int i = 0; i < numeroLivros; i++) {
        if (codigos[i] == codigo) {
            if (!disponibilidade[i]) {
                disponibilidade[i] = true;
                printf("O livro com código %d foi devolvido.\n", codigo);
            } else {
                printf("O livro com código %d já está disponível.\n", codigo);
            }
            return;
        }
    }
    printf("Livro com código %d não encontrado.\n", codigo);
}

// Função para imprimir os livros disponíveis
void imprimirLivrosDisponiveis(char titulos[][MAX_TITULO], char autores[][MAX_AUTOR], bool disponibilidade[], int numeroLivros) {
    printf("Livros disponíveis:\n");
    for (int i = 0; i < numeroLivros; i++) {
        if (disponibilidade[i]) {
            printf("Título: %s, Autor: %s\n", titulos[i], autores[i]);
        }
    }
}

int main() {
    int numeroLivros;
    
    // Solicita o número de livros na biblioteca
    printf("Digite o número de livros na biblioteca: ");
    scanf("%d", &numeroLivros);

    // Declaração dos vetores
    char titulos[MAX_LIVROS][MAX_TITULO];
    char autores[MAX_LIVROS][MAX_AUTOR];
    int codigos[MAX_LIVROS];
    bool disponibilidade[MAX_LIVROS];

    // Solicita ao usuário as informações de cada livro
    for (int i = 0; i < numeroLivros; i++) {
        printf("Digite o título do livro %d: ", i + 1);
        getchar();  // Limpa o buffer do teclado
        fgets(titulos[i], MAX_TITULO, stdin);
        titulos[i][strcspn(titulos[i], "\n")] = '\0';  // Remove o caractere de nova linha

        printf("Digite o autor do livro %d: ", i + 1);
        fgets(autores[i], MAX_AUTOR, stdin);
        autores[i][strcspn(autores[i], "\n")] = '\0';  // Remove o caractere de nova linha

        printf("Digite o código identificador do livro %d: ", i + 1);
        scanf("%d", &codigos[i]);

        disponibilidade[i] = true;  // Inicialmente, todos os livros estão disponíveis
    }

    // Exemplo de uso
    int opcao, codigo;
    do {
        printf("\n1. Emprestar Livro\n2. Devolver Livro\n3. Listar Livros Disponíveis\n4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o código do livro a ser emprestado: ");
                scanf("%d", &codigo);
                emprestarLivro(codigos, disponibilidade, codigo, numeroLivros);
                break;
            case 2:
                printf("Digite o código do livro a ser devolvido: ");
                scanf("%d", &codigo);
                devolverLivro(codigos, disponibilidade, codigo, numeroLivros);
                break;
            case 3:
                imprimirLivrosDisponiveis(titulos, autores, disponibilidade, numeroLivros);
                break;
            case 4:
                printf("Encerrando o sistema...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 4);

    return 0;
}