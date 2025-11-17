#include <stdio.h>
#include <stdbool.h>

bool verifica_ordem(int temperaturas[], int n){
    for (int i = 0; i < tamanho -1; i++){
        if (temperaturas[i] > temperaturas[i + 1]){
            return false;
        } 
    }
    return true;
}

int main(){
    int n;
    printf("Temperatura de quantos dias deseja registrar? ");
    scanf("%d", &n);

    int temperaturas[n];
    for (i = 1; i <= n; i++){

    }

    return 0;
}