#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_STRING 100

struct Territorio{
    char nome[30];
    char cor[10];
    int tropas;
};

void limparBufferEntrada(){
    int y;
    while ((y = getchar()) != '\n' && y != EOF);
}

int main(){
    struct Territorio a;
    printf("Vamos cadastrar os 5 territórios iniciais do nosso mundo.\n");
    printf("---  Cadastrando território 1  ---\n");
    printf("Nome do território:");
    fgets(a.nome, sizeof a.nome, stdin);
    
    printf("Cor do exército (ex.: Azul, Verde, etc.): ");
    fgets(a.cor, sizeof a.cor, stdin);

    printf("Número de tropas: ");
    scanf("%d", &a.tropas);

    limparBufferEntrada();

    struct Territorio b;
    printf("---  Cadastrando território 2  ---\n");
    printf("Nome do território:");
    fgets(b.nome, sizeof b.nome, stdin);

    printf("Cor do exército (ex.: Azul, Verde, etc.):");
    fgets(b.cor, sizeof b.cor, stdin);

    printf("Número de tropas:");
    scanf("%d", &b.tropas);

    limparBufferEntrada();

    struct Territorio c;
    printf("---  Cadastrando território 3  ---\n");
    printf("Nome do território:");
    fgets(c.nome, sizeof c.nome, stdin);

    printf("Cor do exército (ex.: Azul, Verde, etc.):");
    fgets(c.cor, sizeof c.cor, stdin);

    printf("Número de tropas:");
    scanf("%d", &c.tropas);

    limparBufferEntrada();

    struct Territorio d;
    printf("---  Cadastrando território 4  ---\n");
    printf("Nome do território:");
    fgets(d.nome, sizeof d.nome, stdin);

    printf("Cor do exército (ex.: Azul, Verde, etc.):");
    fgets(d.cor, sizeof d.cor, stdin);

    printf("Número de tropas:");
    scanf("%d", &d.tropas);

    limparBufferEntrada();

    struct Territorio e;
    printf("---  Cadastrando território 5  ---\n");
    printf("Nome do território:");
    fgets(e.nome, sizeof e.nome, stdin);

    printf("Cor do exército (ex.: Azul, Verde, etc.):");
    fgets(e.cor, sizeof e.cor, stdin);

    printf("Número de tropas:");
    scanf("%d", &e.tropas);

    limparBufferEntrada();

    printf("TERRITÓRIO 1");
    printf(" - Nome: %s", a.nome);
    printf(" - Dominado por: %s", a.cor);
    printf(" - Tropas: %d\n", a.tropas);

    printf("TERRITÓRIO 2");
    printf(" - Nome: %s", b.nome);
    printf(" - Dominado por: %s", b.cor);
    printf(" - Tropas: %d\n", b.tropas);

    printf("TERRITÓRIO 3");
    printf(" - Nome: %s", c.nome);
    printf(" - Dominado por: %s", c.cor);
    printf(" - Tropas: %d\n", c.tropas);

    printf("TERRITÓRIO 4");
    printf(" - Nome: %s", d.nome);
    printf(" - Dominado por: %s", d.cor);
    printf(" - Tropas: %d\n", d.tropas);

    printf("TERRITÓRIO 5");
    printf(" - Nome: %s", e.nome);
    printf(" - Dominado por: %s", e.cor);
    printf(" - Tropas: %d\n", e.tropas);


}