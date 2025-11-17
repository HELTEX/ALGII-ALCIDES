//Converter Fahrenheit para Celsius

#include<stdio.h>

int converterParaCelsius (float temp_far){
    return (5.0 / 9.0) * (temp_far - 32);
    
}

int main(){
    int far;
    char continua;

    do{
       
        printf("Digite a temperatura que deseja converter para Celsius: ");
        scanf("%d", &far);
        printf("%d é igual a %d em Ceusius", far, (converterParaCelsius(far)));
        printf("Deseja continuar s/n: ");
        scanf(" %c", &continua);


    } while (continua == 's');
    return 0;
}