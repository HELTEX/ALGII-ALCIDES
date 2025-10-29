#include <stdio.h>

void hm(int minutos, int *h, int *m){
    *h = minutos / 60;
    *m = minutos % 60;

}

int main(){
    int total_minutos = 135;
    int horas;
    int minutos;
    hm(total_minutos, &horas, &minutos);
    printf("%d minutos equivalem à %d horas e %d minutos.\n", total_minutos, horas, minutos);
    return 0;
}