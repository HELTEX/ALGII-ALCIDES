#include <stdio.h>

int mdc(int a, int b) {
    if (b == 0)
        return a;
    else
        return mdc(b, a % b);
}

int main() {
    int a, b;

    printf("Digite o primeiro número: ");
    scanf("%d", &a);
    printf("Digite o segundo número: ");
    scanf("%d", &b);

    printf("O MDC de %d e %d é %d\n", a, b, mdc(a, b));

    return 0;
}
