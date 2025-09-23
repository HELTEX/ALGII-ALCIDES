#include <stdio.h>

int minutos (int hora, int min) {
    return ((hora * 60) + min);
}

int diferenca (int tempo_1, int tempo_2) {
    return (tempo_1 - tempo_2);
}

int main() {
    int h1, m1, h2, m2;
    printf("Digite o primeiro horário (HH:MM): ");
    scanf("%d:%d", &h1, &m1);
    printf("Digite o segundo horário (HH:MM): ");
    scanf("%d:%d", &h2, &m2);
    printf("A diferença entre os horários é de %d minutos\n", diferenca(minutos (h1, m1), minutos (h2, m2)));
    return 0;
}