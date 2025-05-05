#include <stdio.h>

int main(){
    
    
    int idade;
    printf("Digite sua idade para saber se você pode votar\n");
    scanf("%d", &idade);

    if (idade >= 17) {
        printf("Você pode votar");
    } else {
        printf("Você não pode votar");
    }



    return 0;
}