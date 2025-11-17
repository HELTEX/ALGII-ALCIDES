#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

const int MAXN = 1000;

bool is_uniform(int ini_x, int ini_y, int tam_x, int tam_y, int img[tam_x][tam_y]){ //Verifica se a matriz é uniforme
    int first = img[ini_x][ini_y];
    for (int i = ini_x; i < tam_x; i++){
        for (int j = ini_y; j < tam_y; j++){
            if (img[i][j] != first) return false;
        }
    }
    return true;
}

char* solve(int ini_x, int ini_y, int tam_x, int tam_y, int img[tam_x][tam_y]){
    char* codigo = (char*)calloc(50, sizeof(char));
    if(is_uniform(ini_x, ini_y, tam_x, tam_y, img)){
        if(img[ini_x][ini_y] == 0) return "B";
        return "P";
    }else{
        int new_tam_X = ceil(tam_x / 2.0);
        int new_tam_Y = ceil(tam_y / 2.0);
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
    if(argv > 1){
        int img[MAXN][MAXN];
        int larg, alt;
        if(argv == 2 && strcmp(args[1], "-m") == 0){
            printf("Digite a largura e a altura da imagem separadas por espaço: ");
            scanf("%d %d", &larg, &alt);

            for(int i = 0; i < alt; i++){
                for(int j = 0; j < larg; j++){
                    scanf("%d", &img[i][j]);
                }
            }
        }else if(argv == 3 && strcmp(args[1], "-f") == 0){
            char* filename = args[2];
            FILE* input_file_pointer = fopen(filename, "r");

            if(input_file_pointer == NULL){
                printf("Deu ruim 1!");
                return 1;
            }

            char first_line[MAXN];
            fgets(first_line, MAXN, input_file_pointer);

            first_line[strlen(first_line)-2] = '\0';

            if(strcmp(first_line, "P1") != 0){
                printf("Não é um arquivo PBM");
                return 1;
            }

            strcpy(first_line, "");

            while(fgets(first_line, MAXN, input_file_pointer) && first_line[0] == '#'){}

            first_line[strlen(first_line)-2] = '\0';

            printf("%s\n", first_line);

            char* tokens = strtok(first_line, " ");
            larg = atoi(tokens);

            if(tokens != NULL){
                tokens = strtok(NULL, " ");
                alt = atoi(tokens);
            }else{
                printf("Deu ruim de novo!");
                return 1;
            }

            if(tokens != NULL){
                printf("%s\n", tokens);
                printf("Mais de 2 dimensões informadas!");
                return 1;
            }

            fclose(input_file_pointer);
        }else{
            printf("Entrada incorreta\n");
            return 1;   
        }

        printf("Código: %s\n", solve(0, 0, alt, larg, img));
    }else if(argv == 1){
        printf("Uso: ImageEncoder [-? | -m | -f ARQ]\n Codifica imagens binárias dadas em arquivos PBM ou por dados informados manualmente.\n Argumentos:\n -?, --help : apresenta essa orientação na tela.\n -m, --manual: ativa o modo de entrada manual, em que o usuário fornece todos os dados da imagem informando-os através do teclado.\n -f, --file: considera a imagem representada no arquivo PBM (Portable bitmap).");
    }else{
        printf("Entrada incorreta\n");
        return 1;
    }

    return 0;
}