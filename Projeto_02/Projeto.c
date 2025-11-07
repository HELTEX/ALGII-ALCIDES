#include <stdio.h>
#include <stdbool.h>~
#include <string.h>

bool is_uniform(int img[][], size_t tam_x, size_t tam_y){ //Verifica se a matriz é uniforme
    int first = img[0][0];
    for (int i = 0; i < tam_x; i++){
        for (int j = 0; j < tam_y; j++){
            if (img[i][j] != first) return false;
        }
    }
    return true;
}

int img[2][2] = {{1, 0}, {0, 1}};
char* solve(int img[][], int ini_x, int ini_y, size_t tam_x, size_t tam_y){
    char* codigo = (char*)calloc(50, sizeof(char));
    if(is_uniform(img, tam_x, tam_y)){
        if(img[0][0] == 0) return "B";
        return "P";
    }else{
        int new_tam_X = tam_x / 2;
        int new_tam_Y = tam_y / 2;
        codigo += solve(img, 0, 0, new_tam_X, new_tam_Y);;
        codigo += solve(img, new_tam_X + 1, 0, new_tam_X, new_tam_Y);
        codigo += solve(img, 0, new_tam_Y + 1, new_tam_X, new_tam_Y);
        codigo += solve(img, new_tam_X + 1, new_tam_Y + 1, new_tam_X, new_tam_Y);        
    }
    return codigo;
}

int main(){

    printf("%s", solve(img, 0, 0, 2, 2));
    return 0;
}