#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 50
#define TAM_MAX 10

//Criação da lista ESTÁTICA
typedef struct {
    char dados[TAM_MAX][MAX_STR_LEN];
    int quantidade;
} ListaEstatica;

void inicializarListaEstatica (ListaEstatica *lista);
void inserirListaEstatica (ListaEstatica *lista, const char* texto);
void removerListaEstatica (ListaEstatica *lista, const char* texto);
void listarListaEstatica (const ListaEstatica *lista);

//Criação  da lista ENCADEADA (de strings)
typedef struct No{
    char* dado;
    struct No *proximo;
} No;

typedef No* listaEncadeada;
//funções da lista encadeada
void InicializarListaEncadeada (listaEncadeada *lista);
void inserirListaEncadeada (listaEncadeada *lista, const char* texto);
void removerListaEncadeada (listaEncadeada *lista, const char* texto);
void listarListaEncadeada (const listaEncadeada lista);
void liberarListaEncadeada (listaEncadeada *lista);

void menuListaEstatica();
void menuListaEncadeada();

int main(){
    int opcao;

    do{
        printf("---MANIPULAÇÃO DE LISTAS---\n");
        printf("1. Lista Estática\n");
        printf("2. Lista Encadeada\n");
        printf("0. Sair do programa\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
            menuListaEstatica();
            break;

            case 2:
            menuListaEncadeada();
            break;

            case 0:
            printf("Saindo...\n");
            break;

            default:
            printf("Opção inválida.");
        }
    } while (opcao != 0);
    return 0;
}

void inicializarListaEstatica(ListaEstatica *lista){
    lista->quantidade = 0;
}

void inserirListaEstatica(ListaEstatica *lista, const char* texto){
    if (lista->quantidade == TAM_MAX){
        printf("Erro: Lista cheia. Impossível inserir mais itens. \n");
        return;
    }
    strcpy(lista->dados[lista->quantidade], texto);
    lista->quantidade++;
    printf("Texto \"%s\" inserido com sucesso.\n", texto);
}

void removerListaEstatica(ListaEstatica *lista, const char* texto){
    int i, pos = -1;
    for (i = 0; i <lista->quantidade; i++){
        if(strcmp(lista->dados[i], texto) == 0){
            pos = i;
            break;
        }
    }
    if (pos == 1){
        printf("Erro: texto não encontrado na lista.\n");
        return;
    }

    for (i = pos; i < lista->quantidade -1; i++){
        strcpy(lista->dados[i], lista->dados[i + 1]);
    }
    lista->quantidade--;
    printf("Texto removido com sucesso.\n");
}

void listarListaEstatica(const ListaEstatica *lista){
    if(lista->quantidade == 0 ){
        printf("A lista estática está vazia.\n");
        return;
    }
    printf("Itens da lista estática: [");
    for (int i = 0; i <lista->quantidade; i++){
        printf("\"%s\" ", lista->dados[i] );

    }
    printf("]\n");
}

void inicializarListaEncadeada(listaEncadeada *lista){
    *lista == NULL;
}

void inserirListaEncadeada(listaEncadeada *lista, const char* texto){
    No* novoNo = (No*) malloc (sizeof(No));

    if (novoNo == NULL){
        printf("Erro: falha na alocação de memória.\n");
        return;
    }

    novoNo->dado = (char*) malloc(strlen(texto) + 1);

    if(novoNo->dado == NULL){
        printf("Erro: falha na alocação de memória para texto.\n");
        free(novoNo);
        return;

    }

    strcpy(novoNo->dado, texto);
    novoNo->proximo = *lista;
    *lista = novoNo;

    printf("Texto inserido com sucesso.\n");

}

void removerListaEncadeada(listaEncadeada *lista, const char* texto){
    No *atual = *lista;
    No *anterior = NULL;
    while (atual != NULL && strcmp(atual->dado, texto) != 0){
        anterior = atual;
        atual = atual->proximo;
    } 

    if(atual == NULL){
        printf("Erro: texto não encontrado na lista.\n");
        return;
    }

    if(anterior == NULL){
        *lista = atual->proximo;
    } else{
        anterior->proximo = atual->proximo;
    }
    free(atual->dado);
    free(atual);

    printf("Texto removido com sucesso.\n");
}

void listarListaEncadeada(const listaEncadeada lista){
    No *temp = lista;
    if (temp == NULL){
        printf("A lista encadeada está vazia.\n");
        return;
    }
    printf("Itens da lista encadeada: [");
    while (temp != NULL){
        printf("\"%s\" ", temp->dado);
        temp = temp->proximo;

    }
    printf("]\n");

}
