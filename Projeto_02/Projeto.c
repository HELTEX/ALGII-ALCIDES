#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool is_uniform(int ini_x, int ini_y, int tam_x, int tam_y, int img[tam_x][tam_y]){ //Verifica se a matriz é uniforme
    int first = img[0][0];
    for (int i = ini_x; i < tam_x; i++){
        for (int j = ini_y; j < tam_y; j++){
            if (img[i][j] != first) return false;
        }
    }
    return true;
}

char* solve(int ini_x, int ini_y, int tam_x, int tam_y, int img[tam_x][tam_y]){
    char* codigo = (char*)calloc(50, sizeof(char));
    printf("entrei\n");
    if(is_uniform(ini_x, ini_y, tam_x, tam_y, img)){
        if(img[ini_x][ini_y] == 0) return "B";
        return "P";
    }else{
        int new_tam_X = tam_x / 2;
        int new_tam_Y = tam_y / 2;
        printf("%d %d\n", new_tam_X, new_tam_Y);
        strcat(codigo, "X");
        strcat(codigo, solve(0, 0, new_tam_X, new_tam_Y, img));
        strcat(codigo, solve(new_tam_X + 1, 0, new_tam_X, new_tam_Y, img));
        strcat(codigo, solve(0, new_tam_Y + 1, new_tam_X, new_tam_Y, img));
        strcat(codigo, solve(new_tam_X + 1, new_tam_Y + 1, new_tam_X, new_tam_Y, img));
    }
    return codigo;
}

int main(int argv, char* args[]){
    if(argv == 2 && strcmp(args[1], "-m") == 0){
        int img[2][2] = {{1, 0}, {0, 1}};
        printf("%s\n", solve(0, 0, 2, 2, img));
    }else if(argv == 3 && strcmp(args[1], "-f") == 0){
        int img[2][2] = {{1, 0}, {0, 1}};
        printf("%s\n", solve(0, 0, 2, 2, img));
    }else{
        printf("Entrada incorreta\n");
        return 1;
    }

    return 0;
}