#include <stdio.h>

int minutos(int hora, int minuto) {
    return hora * 60 + minuto;
}

int diferenca(int tempo1, int tempo2) {
    return tempo1 - tempo2;
}

int main() {
    int hora1, minuto1, hora2, minuto2;
    int tempo1, tempo2, diferencaMinutos;

    // Solicita o primeiro horário
    printf("Digite o primeiro horário (formato 24 horas, HH:MM): ");
    scanf("%d:%d", &hora1, &minuto1);

    // Solicita o segundo horário
    printf("Digite o segundo horário (formato 24 horas, HH:MM): ");
    scanf("%d:%d", &hora2, &minuto2);

    // Converte os horários para minutos
    tempo1 = minutos(hora1, minuto1);
    tempo2 = minutos(hora2, minuto2);

    // Calcula a diferença 
    diferencaMinutos = diferenca(tempo1, tempo2);

    printf("A diferença entre %02d:%02d e %02d:%02d é de %d minutos.\n", hora1, minuto1, hora2, minuto2, diferencaMinutos < 0 ? -diferencaMinutos : diferencaMinutos);

    return 0;
}