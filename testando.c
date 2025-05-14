#include <stdio.h>
int main (){
    //Tabuleiro de Batalha Naval
    //Print do tabuleiro

    char letras[] = {'A', 'B', 'C', 'D', 'F', 'G', 'H', 'I', 'J'};
    printf("   ");
    for(int i = 0; i < 10; i++){
        printf("%c  ", letras[i]);
    }
    printf("\n");
    int tabuleiro[10][10] = { 
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {2, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0},
        {3, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0},
        {4, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0},
        {5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}


    };
    int linha, coluna;

            for (linha = 0; linha < 10; linha++){
                for (coluna = 0; coluna < 10; coluna++)
                {
                    printf("%d  ", tabuleiro[linha][coluna]);
                }
                printf("\n");
             }

            
             
        



    return 0;
}