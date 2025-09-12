#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 50
#define TAM_MAX 10

typedef struct{
    char dados[TAM_MAX][MAX_STR_LEN]; // dez linhas e cinquenta colunas
    int quantidade;
} ListaEstatica;

void inicializarListaEstatica(ListaEstatica *lista){
    lista->quantidade = 0;
}

void inserirListaEstatica(ListaEstatica *lista, const char* texto){
    if(lista->quantidade == TAM_MAX){
        printf("Lista cheia! Nao é possível inserir.\n");
        return;
    }
    
    strcpy(lista->dados[lista->quantidade], texto);
    lista->quantidade++;
    printf("Texto \"%s\" inserido com sucesso\n", texto);
}

void removerListaEstatica(ListaEstatica *lista, const char* texto){
    int i, pos = -1;
    for(i = 0; i < lista->quantidade; i++){
        if(strcmp(lista->dados[i], texto) == 0){
            pos = i;
            break;
        }
    }

    if (pos == -1){
        printf("Erro: Texto \"%s\" nao encontrado na lista.\n", texto);
        return;
    }

    for(i = pos; i < lista->quantidade - 1; i++){
        strcpy(lista->dados[i], lista->dados[i + 1]);
    }
    lista->quantidade--;
    printf("Texto \"%s\" removido com sucesso.\n", texto);
}

void listarListaEstatica(const ListaEstatica *lista){
    if(lista->quantidade == 0){
        printf("A lista estática está vazia.\n");
        return;
    }
    printf("Itens da lista estática: [ ");
    for(int i = 0; i < lista->quantidade; i++){
        printf("\"%s\" ", lista->dados[i]);
    }
    printf("]\n");
}

typedef struct No{
    char nome[MAX_STR_LEN];
    char tipo[MAX_STR_LEN];
    int quantidade;
    struct No *proximo;
} No; 

typedef No* ListaEncadeada;

void inicializarListaEncadeada(ListaEncadeada *lista){
    *lista = NULL;
}

void inserirListaEncadeada(ListaEncadeada *lista, const char* nome, const char* tipo, int quantidade){
    No* novoNo = (No*) malloc(sizeof(No));

    if(novoNo == NULL){
        printf("Erro: falha na alocação de memória para o nó.\n");
        return;
    }

    strcpy(novoNo->nome, nome);
    strcpy(novoNo->tipo, tipo);
    novoNo->quantidade = quantidade;
    novoNo->proximo = *lista;
    *lista = novoNo;

    printf("Item \"%s\" inserido com sucesso.\n", nome);
}

void removerListaEncadeada(ListaEncadeada *lista, int indice){
    No *atual = *lista;
    No *anterior = NULL;
    int i = 0;

    // Percorre até encontrar o índice
    while(atual != NULL && i < indice){
        anterior = atual;
        atual = atual->proximo;
        i++;
    }

    if(atual == NULL){
        printf("Erro: índice %d não encontrado.\n", indice);
        return;
    }

    if(anterior == NULL){
        *lista = atual->proximo;
    } else{
        anterior->proximo = atual->proximo;
    }

    free(atual);
    printf("Item no índice %d removido com sucesso.\n", indice);
}

void listarListaEncadeada(const ListaEncadeada lista){
    No *temp = lista;
    int indice = 0;
    if (temp == NULL){
        printf("A lista encadeada está vazia.\n");
        return;
    }
    printf("Itens da lista encadeada:\n");
    while(temp != NULL){
        printf("[%d] Nome: %s, Tipo: %s, Quantidade: %d\n", indice, temp->nome, temp->tipo, temp->quantidade);
        temp = temp->proximo;
        indice++;
    }
}

void menuListaEncadeada(){
    ListaEncadeada lista;
    inicializarListaEncadeada(&lista);
    
    int opcao, quantidade, item = 0;
    char nome[MAX_STR_LEN], tipo[MAX_STR_LEN];

    do{
        printf("\n--- Itens na mochila: %d/10 ---\n", item);
        printf("1. Adicionar item (Loot)\n");
        printf("2. Remover item\n");
        printf("3. Listar itens na mochila\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); // Para capturar o '\n' deixado pelo scanf

        switch(opcao){
            case 1:
                if (item < 10) {
                    printf("Digite o nome do item: ");
                    fgets(nome, MAX_STR_LEN, stdin);
                    nome[strcspn(nome, "\n")] = '\0'; // Remover o '\n' final

                    printf("Digite o tipo do item: ");
                    fgets(tipo, MAX_STR_LEN, stdin);
                    tipo[strcspn(tipo, "\n")] = '\0'; // Remover o '\n' final

                    printf("Digite a quantidade do item: ");
                    scanf("%d", &quantidade);
                    getchar(); // Limpar o buffer

                    inserirListaEncadeada(&lista, nome, tipo, quantidade); 
                    item++;  // Incrementa o contador de itens
                } else {
                    printf("A mochila está cheia! Não é possível adicionar mais itens.\n");
                }
                break;

            case 2:
                listarListaEncadeada(lista);
                if (item > 0) {
                    int numero;
                    printf("Digite o índice do item a ser removido: ");
                    scanf("%d", &numero);
                    removerListaEncadeada(&lista, numero);
                    item--;
                }
                break;

            case 3:
                listarListaEncadeada(lista);
                break;

            case 0:
                printf("Voltando ao menu principal...\n");
                break;

            default:
                printf("Opção inválida!\n");
        }
    } while(opcao != 0);
}

int main(){
    int opcao;
    do{
        printf("1. Iniciar programa\n");
        printf("0. Sair do programa\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        
        switch(opcao){
            case 1:
                menuListaEncadeada();
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 0);
    return 0;
}
