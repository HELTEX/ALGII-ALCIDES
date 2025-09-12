#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main(){
    //declaração de variáveis
    char nome[50];
    char inicialNickname;
    int idade;
    float nivelHabilidade;
    unsigned int anosExperiencia;
    bool prefereEquipe;

    //leitura de dados do usuário
    printf("Digite o nome completo do jogador: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';

    printf("Digite a inicial do seu nickname: ");
    scanf("%c", &inicialNickname);

    printf("Digite a sua idade (em anos): ");
    scanf("%f", &nivelHabilidade);

    printf("Digite quantos anos você tem de experiência competitiva: ");
    scanf("%u", &anosExperiencia);

    printf("Você prefere jogos em equipe? (1 para sim, 0 para não): ");
    int temp;
    scanf("%d", &temp);
    prefereEquipe = temp;

    //calculo da idade em dias
    double idadeEmDias = idade * 365.25;

    //calculo do nível ajustado com base na experiencia
    float nivelAjustado = nivelHabilidade * (1 + anosExperiencia / 100.0);

    //verificações booleanas
    bool maiorDeIdade = idade >= 18;
    bool novato = anosExperiencia < 2;
    bool veteranoPrefereEquipe = prefereEquipe * !novato;

    //incremento e decremento
    unsigned int anosDepoisIncremento = anosExperiencia++;
    unsigned int anosDepoisDecremento = --anosExperiencia;

    //deslocamento de bits
    int metadeAnos = anosExperiencia >> 1;
    int dobroAnos = anosExperiencia << 1;

    //Saída dos resultados
    printf("\n***Resumo do Jogador***\n");
    printf("Nome Completo: %s\n", nome);
    printf("Inicial do Nickname: %c\n", inicialNickname);
    printf("Idade: %d anos\n", idade);
    printf("Idade em Dias: %.0f dias\n", idadeEmDias);
    printf("Nivel de Habilidade Ajustado: %.2f dias\n", nivelAjustado);
    printf("Anos de Experiência: %u\n", anosExperiencia);
    printf("Prefere Jogos em Equipe: %d\n", prefereEquipe);

    printf("\n***Análise***\n");
    printf("É maior de idade? %d\n", maiorDeIdade);
    printf("É novato? %d\n", novato);
    printf("Jogador Experiente e Prefere Jogos em Equipe? %d\n", veteranoPrefereEquipe);

    printf("\n***Incremento e Decremento***\n");
    printf("Anos de Experiência após Incremento: %d\n", anosDepoisIncremento);
    printf("Anos de Experiência após Decremento: %d\n", anosDepoisDecremento);

    printf("\n***Deslocamento de Bits***\n");
    printf("Metade dos Anos de Experiêcnia: %u\n", metadeAnos);
    printf("Dobro dos Anos de Experiência: %u\n", dobroAnos); 
    return 0;
}