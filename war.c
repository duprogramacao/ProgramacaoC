#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_STRING 100

struct Territorio{
    char nome[30];
    char cor[10];
    int tropas;
};


int main(){
    struct Territorio a;
    printf("Vamos cadastrar os 5 territórios iniciais do nosso mundo.\n");
    printf("---  Cadastrando território 1  ---\n");
    printf("Nome do território:");
    fgets(a.nome, sizeof a.nome, stdin);

    printf("Cor do exército (ex.: Azul, Verde, etc.): \n");
    fgets(a.cor, sizeof a.cor, stdin);

    printf("Número de tropas: \n");
    scanf("%d", &a.tropas);

    //território 2
    struct Territorio b;
    printf("---  Cadastrando território 2  ---\n");
    printf("Nome do território:");
    fgets(b.nome, sizeof b.nome, stdin);

    printf("Cor do exército (ex.: Azul, Verde, etc.): \n");
    fgets(b.cor, sizeof b.cor, stdin);

    printf("Número de tropas: \n");
    scanf("%d", &b.tropas);

    //território  3
    struct Territorio c;
    printf("---  Cadastrando território 3  ---\n");
    printf("Nome do território:");
    fgets(c.nome, sizeof c.nome, stdin);

    printf("Cor do exército (ex.: Azul, Verde, etc.): \n");
    fgets(c.cor, sizeof c.cor, stdin);

    printf("Número de tropas: \n");
    scanf("%d", &c.tropas);

    //território 4
    struct Territorio d;
    printf("---  Cadastrando território 4  ---\n");
    printf("Nome do território:");
    fgets(d.nome, sizeof d.nome, stdin);

    printf("Cor do exército (ex.: Azul, Verde, etc.): \n");
    fgets(d.cor, sizeof d.cor, stdin);

    printf("Número de tropas: \n");
    scanf("%d", &d.tropas);

    //território 5
    struct Territorio e;
    printf("---  Cadastrando território 5  ---\n");
    printf("Nome do território:");
    fgets(e.nome, sizeof e.nome, stdin);

    printf("Cor do exército (ex.: Azul, Verde, etc.): \n");
    fgets(e.cor, sizeof e.cor, stdin);

    printf("Número de tropas: \n");
    scanf("%d", &e.tropas);



    

}