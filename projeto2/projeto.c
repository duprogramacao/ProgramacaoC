#include <stdio.h>

int main(){
    
    int populacao, populacao2, opcao2;
    populacao = 1000;
    populacao2 = 2000;
    char* vencedor;
    scanf("%d", &opcao2);

    switch (opcao2){
    case 1:
        vencedor = (populacao > populacao2) ? "Carta 1 venceu!" : "Carta 2 venceu!";
        printf("Vencedor: %s\n", vencedor);
        break;

    default:

    break; 
    }
    return 0;
}