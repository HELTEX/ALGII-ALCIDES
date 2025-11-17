#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_TENTATIVAS 6

void clear_screen() { 
    // Função para limpar a tela
    #ifdef _WIN32       //Diretivas de pré-processador 
        system("cls");
    #else               //Diretivas de pré-processador 
        system("clear");
    #endif
}

int main() {
    char palavra_secreta[100], tentativa;
    char progresso[100];
    int i, tentativas_restantes;
    bool acertou, encontrou;
    char opcao;

    do {
        // Solicitação da palavra secreta ao primeiro jogador
        printf("Jogador 1, insira a palavra secreta: ");
        scanf("%s", palavra_secreta);

        clear_screen(); 

        // Inicializa o progresso com underscores e configura as tentativas
        tentativas_restantes = MAX_TENTATIVAS;
        acertou = false;
        int tamanho_palavra = strlen(palavra_secreta);
        for (i = 0; i < tamanho_palavra; i++) {
            progresso[i] = '_';
        }
        progresso[tamanho_palavra] = '\0';

        // Jogo da Forca
        while (tentativas_restantes > 0 && !acertou) {
            printf("Jogador 2, adivinhe a palavra: %s\n", progresso);
            printf("Você tem %d tentativas restantes.\n", tentativas_restantes);
            printf("Digite uma letra: ");
            scanf(" %c", &tentativa);
            encontrou = false;
            for (i = 0; i < tamanho_palavra; i++) {
                if (palavra_secreta[i] == tentativa) {
                    progresso[i] = tentativa;
                    encontrou = true;
                }
            }

            if (!encontrou) {
                tentativas_restantes--;
                printf("Letra incorreta!\n");
            }
            if (strcmp(progresso, palavra_secreta) == 0) {
                acertou = 1;
            }
        }

        // Exibição do resultado
        if (acertou) {
            printf("Parabéns! Você acertou a palavra: %s\n", palavra_secreta);
        } else {
            printf("Você perdeu! A palavra era: %s\n", palavra_secreta);
        }        
        printf("Deseja jogar novamente? (s/n): ");
        scanf(" %c", &opcao);

        clear_screen();

    } while (opcao == 's' || opcao == 'S');

    return 0;
}