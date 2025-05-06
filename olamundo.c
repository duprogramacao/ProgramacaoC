#include <stdio.h>
int main () {
    //Desafio - Cartas Super Trunfo - Intermediário 
    //Inserção de dados para a Carta I
    printf("--- Desafio das cartas Super Trunfo ---\n");

    int numerocarta;
    printf ("Digite o número da sua carta: \n");
    scanf ("%d", &numerocarta);

    char estado;
    printf("Digite o caractere do estado: \n");
    scanf (" %c", &estado);

    char codigo[3];
    printf("Digite o código de três dígitos da carta: \n");
    scanf("%s", codigo);

    char nomecidade[25];
    printf("Digite o nome da cidade: \n");
    scanf("%s", nomecidade);
    
    unsigned long int populacao;
    printf("Digite a população da cidade: \n");
    scanf("%lu", &populacao);

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
    
    //Cálculo do Super Poder
    float superpoder;
    superpoder = populacao + area + pib + pontoturistico + pibpercapta + 1 / densidade;

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
    
    unsigned long int populacao2;
    printf("Digite a população da cidade: \n");
    scanf("%lu", &populacao2);

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
    //Cálculo do Super Poder
    float superpoder2;
    superpoder2 = populacao2 + area2 + pib2 + pontoturistico2 + pibpercapta2 + 1 / densidade2;

    //print das cartas I e II
    printf("Carta 1: \n");
    printf("Número da carta: %d", numerocarta);
    printf("Estado: %c\n", estado);
    printf("Nome da Cidade: %s\n", nomecidade);
    printf("População: %lu\n", populacao);
    printf("Área: %.2f\n", area);
    printf("PIB: %d\n", pib);
    printf("PIB Per Capta: %.2f\n", pibpercapta);
    printf("Pontos turísticos: \n", pontoturistico);
    printf("Densidade populacional: %.2f\n", densidade);
    printf("Super Poder: %.2f", superpoder);

    //print carta II
    printf("Carta 2: \n");
    printf("Número da carta: %d", numerocarta2);
    printf("Estado: %c\n", estado2);
    printf("Nome da Cidade: %s\n", nomecidade2);
    printf("População: %d\n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: %d\n", pib2);
    printf("PIB Per Capta: %.2f\n", pibpercapta2);
    printf("Pontos turísticos: %d \n", pontoturistico2);
    printf("Densidade populacional: %.2f\n", densidade2);
    printf("Super Poder: %.2f\n", superpoder2);

    //Comparação das cartas, cálculo de Super Poder e exibição dos resultados
    printf("Selecione dois atributos para realizar a comparação: \n");

    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. Número de pontos turísticos\n");
    printf("5. Densidade demográfica\n");
    int opcao;
    scanf("%d", &opcao);
    switch (opcao)
    {
    case 1:
        if (populacao == populacao2){
            printf("Empate!\n");
        }
        else if (populacao > populacao2){
            printf("Carta 1 venceu!\n");
        } else {
            printf("Carta 2 venceu!\n");
        }
        break;

    case 2:
        if (area == area2){
        printf("Empate!\n");
        }
        else if (area > area2){
            printf("Carta 1 venceu!\n");
        } else {
            printf("Carta 2 venceu!\n");
        }
        break;

    case 3:
        if (pib == pib2){
        printf("Empate!\n");
        }
        else if (pib > pib2){
            printf("Carta 1 venceu!\n");
        } else {
            printf("Carta 2 venceu!\n");
        }
        break;

    case 4:
         if (pontoturistico == pontoturistico2){
        printf("Empate!\n");
        }
        else if (pontoturistico > pontoturistico2){
            printf("Carta 1 venceu!\n");
            } else {
            printf("Carta 2 venceu!\n");
            }
        break;

    case 5:
        if (densidade == densidade2){
        printf("Empate!\n");
        }
        else if (densidade > densidade2){
            printf("Carta 1 venceu!\n");
            } else {
            printf("Carta 2 venceu!\n");

            }
        break;

    default:
        printf("Opção inválida. Tente novamente.\n");
        break;
    }

    int opcao2;
    printf("Selecione a segunda opção para comparar: \n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. Número de pontos turísticos\n");
    printf("5. Densidade demográfica\n");
    char* vencedor;
    scanf("%d", &opcao2);
    

        if (opcao2 == opcao){
            printf("Digite outra opção que não seja igual à anterior.\n");
            scanf("%d", opcao2);

        }

    switch (opcao2)
    {
    case 1:
        vencedor = (populacao > populacao2) ? "Carta 1 venceu!" : "Carta 2 venceu!";
        printf("Vencedor: %s\n", vencedor);
        break;
    case 2: 
        vencedor = (area > area2) ? "Carta 1 venceu!" : "Carta 2 venceu!";
        printf("Vencedor: %s\n", vencedor);
        break;
    case 3:
        vencedor = (area > area2) ? "Carta 1 venceu!" : "Carta 2 venceu!";
        printf("Vencedor: %s\n", vencedor);
        break;
    case 4:
        vencedor = (pontoturistico > pontoturistico2) ? "Carta 1 venceu!" : "Carta 2 venceu!";
        printf("Vencedor: %s\n", vencedor);
        break;
    case 5:
        vencedor = (densidade > densidade2) ? "Carta 1 venceu!" : "Carta 2 venceu!";
        printf("Vencedor: %s\n", vencedor);
        break;
    
    default:
        ("Erro! Tente novamente. \n");
        break;
    }







   return 0;

}
