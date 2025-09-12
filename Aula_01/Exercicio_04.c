/* Sistema para calcular o consumo de combustível de um veículo em uma viagem. 
* o sistema deverá captuar o modelo do veiculo, a distancia percorrida em quilometros
* e o consumo de combustivel em litros. O sistema deve calcular o consumo médio, quadruplicarr a d
* distancia percorrida usando deslocamento de bits e exibir se o veículo é economico ou não
* o veiculo é classificado como economico se o consumo médio for inferior a 5 km/l
*/

#include <stdio.h>

int main(){

    //declaração de variáveis
    char modelo_veiculo[15];
    unsigned int distancia_percorrida;
    unsigned int consumo_combustivel;

    // entrada de dados
    printf("Modelo do veículo: ");
    fgets(modelo_veiculo, sizeof(modelo_veiculo), stdin);
    printf("Distancia percorrida (km) ");
    scanf("%d", &distancia_percorrida);
    printf("Consumo de combustível (l): ");
    scanf("%d", &consumo_combustivel);

    //calculos
    int consumo_medio = (distancia_percorrida / consumo_combustivel);
    int distancia_percorrida_quadriplicada = distancia_percorrida << 4;

    //impressões
    printf("Modelo do veículo: %s\n", modelo_veiculo);
    printf("Consumo médio (km/l): %d\n", consumo_medio);
    printf("Distancia percorrida quadruplicada: %d\n", distancia_percorrida_quadriplicada);
    if (consumo_medio < 5){
        printf("É economico\n");
    } else {
        printf("Não é economico\n");
    }
    return 0;
}