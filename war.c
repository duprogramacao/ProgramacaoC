#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO 5
#define NOME_MAX_TAM 30
#define COR_MAX_TAM 10

typedef struct {
    char **nome;
    char **cor;
    int *tropas;
} Territorio;

void limparBufferEntrada(){
    int y;
    while ((y = getchar()) != '\n' && y != EOF);
};

//Sistema de ataque do war
void atacar(Territorio* atacante, Territorio* defensor){
    int ataque, defesa;
    if(ataque > defesa){
        printf("Atacante venceu!")
    }
}



int main(){
    Territorio* p = (Territorio*)malloc(sizeof(Territorio));
    if (p == NULL) {
        printf("Falha ao alocar a memória.\n");
        return 1;
    }

    p->nome = (char**)malloc(TAMANHO * sizeof(char*));  
    p->cor = (char**)malloc(TAMANHO * sizeof(char*));   
    p->tropas = (int*)malloc(TAMANHO * sizeof(int));


    if (p->nome == NULL || p->cor == NULL || p->tropas == NULL) {
        printf("Falha ao alocar memória para os dados.\n");
        free(p);
        return 1;
    }

    for (int i = 0; i < TAMANHO; i++){
        p->nome[i] = (char*)malloc(NOME_MAX_TAM * sizeof(char));
        p->cor[i] = (char*)malloc(COR_MAX_TAM * sizeof(char));

        if (p->nome[i] == NULL || p->cor[i] == NULL){
            printf("Falha ao inserir memória para cor ou nome.\n");
        }
        

    printf("Insira o nome do território %d: ", i + 1);
    scanf("%s", p->nome[i]);
    
    printf("Insira a cor do território %d (ex.: Azul, Verde, etc.): ", i +1);
    scanf("%s", p->cor[i]);

    printf("Insira o número de tropas do território %d: ", i + 1);
    scanf("%d", p->tropas);
    }

    printf("\nTerritórios cadastrados:\n");
    for (int i = 0; i < TAMANHO; i++) {
        printf("Território %d - Nome: %s, Cor: %s\n", i + 1, p->nome[i], p->cor[i]);
    }
    




}