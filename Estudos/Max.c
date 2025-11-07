/*A função abaixo recebe um inteiro n>=1 e um vetor v
e devolve o valor de um elemento máximo de v[0..n-1]*/

#include <stdio.h>

int Max(int v[], int n){
    int j, x = v[0];
    for (j = 1; j < n; j++) {
        if (x < v[j]){
            x = v[j];
        }
    }
    return x;
}