#include <stdio.h>
#include <string.h>

#define TAM 10

typedef struct {
    int codigo;
    char nome[100];
    int idade;
    int gravidade; // 0 a 100
} Paciente;

// Função para ordenar por gravidade decrescente
void selectionSortGravidade(Paciente v[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int maxIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (v[j].gravidade > v[maxIdx].gravidade) {
                maxIdx = j;
            }
        }
        if (maxIdx != i) {
            Paciente temp = v[i];
            v[i] = v[maxIdx];
            v[maxIdx] = temp;
        }
    }
}

int main() {
    Paciente pacientes[TAM] = {
        {101, "Ana Paula",       45, 85},
        {102, "Carlos Eduardo",  60, 92},
        {103, "Fernanda Lima",   33, 76},
        {104, "João Marcos",     70, 98},
        {105, "Luciana Alves",   55, 88},
        {106, "Bruno Rocha",     40, 69},
        {107, "Marta Silva",     28, 58},
        {108, "Rafael Tavares",  38, 73},
        {109, "Juliana Costa",   49, 91},
        {110, "Roberto Teixeira",65, 94}
    };

    // Ordenar por gravidade (decrescente)
    selectionSortGravidade(pacientes, TAM);

    printf("Top 5 casos mais urgentes:\n\n");
    for (int i = 0; i < 5; i++) {
        printf("Código: %d\n", pacientes[i].codigo);
        printf("Nome: %s\n", pacientes[i].nome);
        printf("Idade: %d\n", pacientes[i].idade);
        printf("Gravidade: %d\n", pacientes[i].gravidade);
        printf("-------------------------\n");
    }

    return 0;
}
