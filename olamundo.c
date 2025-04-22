#include <stdio.h>
int main () {
    //Desafio - Cartas Super Trunfo - Intermediário 
    //Inserção de dados para a Carta I
    int numerocarta;
    printf ("Digite o número da sua carta: \n");
    scanf ("%d", &numerocarta);

    char estado;
    printf("Digite o caractere do estado: \n");
    scanf (" %c", &estado);

    char codigo[3];
    printf("Digite o código de três dígitos da carta: \n");
    scanf("%s", &codigo);

    char nomecidade[25];
    printf("Digite o nome da cidade: \n");
    scanf("%s", nomecidade);
    
    int populacao;
    printf("Digite a população da cidade: \n");
    scanf("%d", &populacao);

    float area;
    printf("Digite a área em km²: \n");
    scanf("%f", &area);

    int pib;
    printf("Digite o PIB: \n");
    scanf("%d", &pib);

    int pontoturistico;
    printf("Digite a quantidade de pontos turísticos: \n");
    scanf("%d", &pontoturistico);

    //Cálculo da densidade populacional
    float densidade;
    densidade = populacao / area;

    //Cálculo do PIB Per Capta
    float pibpercapta;
    pibpercapta = pib / populacao;

    //Dados da Carta II
    int numerocarta2;
    printf ("Digite o número da segunda carta: \n");
    scanf ("%d", &numerocarta2);

    char estado2;
    printf("Digite o caractere do estado: \n");
    scanf (" %c", &estado2);

    char codigo2[3];
    printf("Digite o código de três dígitos da segunda carta: \n");
    scanf("%s", codigo2);

    char nomecidade2[25];
    printf("Digite o nome da cidade: \n");
    scanf("%s", nomecidade2);
    
    int populacao2;
    printf("Digite a população da cidade: \n");
    scanf("%d", &populacao2);

    float area2;
    printf("Digite a área em km²: \n");
    scanf("%f", &area2);

    int pib2;
    printf("Digite o PIB: \n");
    scanf("%d", &pib2);

    int pontoturistico2;
    printf("Digite a quantidade de pontos turísticos: \n");
    scanf("%d", &pontoturistico2);
    //Cálculo da densidade populacional (Carta II)
    float densidade2;
    densidade2 = populacao2 / area2;
    //Cálculo do PIB Per Capta (Carta II)
    float pibpercapta2;
    pibpercapta2 = pib2 / populacao2;

    //print das cartas I e II
    printf("Carta 1: \n");
    printf("Estado: %c\n", estado);
    printf("Nome da Cidade: %s\n", nomecidade);
    printf("População: %d\n", populacao);
    printf("Área: %.2f\n", area);






   return 0;

}
