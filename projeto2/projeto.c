#include <stdio.h>

int main (){

    int tabuleiro [10][10];
    char linha[][10] = ('A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J');

    for (int i = 0; i < 10; i++)
    {
        printf("%s", linha[i]);
    }
    
    

    return 0;
}