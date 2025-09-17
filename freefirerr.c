#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


//Void para gerar os diferentes tipos de listas


// Definições de tamanho máximo
#define MAX_STR_LEN 50
#define TAM_MAX 10

// Struct do Item
typedef struct {
    char nome[MAX_STR_LEN];
    char tipo[MAX_STR_LEN];
    int quantidade;
} Item;

// Struct para lista encadeada
typedef struct No {
    Item dados;
    struct No *proximo;
} No;

typedef No* ListaEncadeada;

// Função para inicializar a lista encadeada
void inicializarListaEncadeada(ListaEncadeada *lista) {
    *lista = NULL;
}

// Funções do vetor
// Função para inserir item no vetor
void inserirItemVetor(Item lista[], int *quantidade, Item item) {
    if (*quantidade < TAM_MAX) {
        lista[*quantidade] = item;
        (*quantidade)++;
        printf("Item \"%s\" inserido com sucesso!\n", item.nome);
    } else {
        printf("Mochila cheia! Não é possível adicionar mais itens.\n");
    }
}

// Função para remover item do vetor
void removerItemVetor(Item lista[], int *quantidade, const char* nome) {
    int i, encontrado = 0;
    for (i = 0; i < *quantidade; i++) {
        if (strcmp(lista[i].nome, nome) == 0) {
            encontrado = 1;
            // Desloca os itens para "remover" o item
            for (int j = i; j < *quantidade - 1; j++) {
                lista[j] = lista[j + 1];
            }
            (*quantidade)--;
            printf("Item \"%s\" removido com sucesso!\n", nome);
            break;
        }
    }
    if (!encontrado) {
        printf("Item \"%s\" não encontrado na mochila.\n", nome);
    }
}

// Função para listar itens do vetor
void listarVetor(const Item lista[], int quantidade) {
    if (quantidade == 0) {
        printf("A mochila está vazia.\n");
    } else {
        printf("Itens na mochila:\n");
        for (int i = 0; i < quantidade; i++) {
            printf("Nome: %s, Tipo: %s, Quantidade: %d\n", lista[i].nome, lista[i].tipo, lista[i].quantidade);
        }
    }
}

// Função para ordenar itens do vetor por nome (Bubble Sort)
void ordenarVetor(Item lista[], int quantidade) {
    for (int i = 0; i < quantidade - 1; i++) {
        for (int j = 0; j < quantidade - 1 - i; j++) {
            if (strcmp(lista[j].nome, lista[j + 1].nome) > 0) {
                // Troca os itens
                Item temp = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = temp;
            }
        }
    }
}

// Função de busca sequencial no vetor
int buscarSequencialVetor(const Item lista[], int quantidade, const char* nome) {
    for (int i = 0; i < quantidade; i++) {
        if (strcmp(lista[i].nome, nome) == 0) {
            printf("Item \"%s\" encontrado na mochila.\n", nome);
            return i;
        }
    }
    printf("Item \"%s\" não encontrado na mochila.\n", nome);
    return -1;
}

// Função de busca binária no vetor (deve ser chamado após a ordenação)
int buscarBinariaVetor(const Item lista[], int quantidade, const char* nome) {
    int esquerda = 0;
    int direita = quantidade - 1;
    int comparacoesBin = 0;  // Resetar o contador de comparações para cada busca

    while (esquerda <= direita) {
        comparacoesBin++;
        int meio = (esquerda + direita) / 2;
        int cmp = strcmp(lista[meio].nome, nome);

        if (cmp == 0) {
            printf("Item \"%s\" encontrado na mochila.\n", nome);
            return meio;
        } else if (cmp < 0) {
            esquerda = meio + 1;
        } else {
            direita = meio - 1;
        }
    }
    printf("Item \"%s\" não encontrado na mochila.\n", nome);
    return -1;
}


// Funções da lista encadeada
// Função para inserir item na lista encadeada
void inserirItemListaEncadeada(ListaEncadeada *lista, Item item) {
    No *novoNo = (No *)malloc(sizeof(No));
    if (!novoNo) {
        printf("Erro ao alocar memória para o novo item.\n");
        return;
    }
    novoNo->dados = item;
    novoNo->proximo = *lista;
    *lista = novoNo;
    printf("Item \"%s\" inserido com sucesso!\n", item.nome);
}

// Função para remover item da lista encadeada
void removerItemListaEncadeada(ListaEncadeada *lista, const char* nome) {
    No *atual = *lista;
    No *anterior = NULL;

    while (atual != NULL && strcmp(atual->dados.nome, nome) != 0) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL) {
        printf("Item \"%s\" não encontrado na mochila.\n", nome);
        return;
    }

    if (anterior == NULL) {
        *lista = atual->proximo;
    } else {
        anterior->proximo = atual->proximo;
    }

    free(atual);
    printf("Item \"%s\" removido com sucesso!\n", nome);
}

// Função para listar todos os itens da lista encadeada
void listarListaEncadeada(ListaEncadeada lista) {
    if (lista == NULL) {
        printf("A mochila está vazia.\n");
        return;
    }

    printf("Itens na mochila (Lista Encadeada):\n");
    No *temp = lista;
    int indice = 0;
    while (temp != NULL) {
        printf("[%d] Nome: %s, Tipo: %s, Quantidade: %d\n", indice, temp->dados.nome, temp->dados.tipo, temp->dados.quantidade);
        temp = temp->proximo;
        indice++;
    }
}

// Função de busca sequencial na lista encadeada
int buscarSequencialListaEncadeada(ListaEncadeada lista, const char* nome) {
    int comparacoes = 0;
    No *temp = lista;

    while (temp != NULL) {
        comparacoes++;  // Contabiliza cada comparação
        if (strcmp(temp->dados.nome, nome) == 0) {
            printf("Item \"%s\" encontrado na mochila.\n", nome);
            return comparacoes;  // Retorna o número de comparações realizadas
        }
        temp = temp->proximo;
    }

    printf("Item \"%s\" não encontrado na mochila.\n", nome);
    return comparacoes;  // Retorna o número de comparações realizadas (sem encontrar o item)
}


int comparacoesSeq = 0;  // Contador de comparações sequenciais
int comparacoesBin = 0;  // Contador de comparações binárias

int main() {
    int opcao, tipoEstrutura, quantidade = 0;
    Item mochilaVetor[TAM_MAX];
    ListaEncadeada mochilaLista;
    inicializarListaEncadeada(&mochilaLista);
    
    do {
        printf("Escolha a estrutura de dados:\n");
        printf("1. Mochila com Vetor\n");
        printf("2. Mochila com Lista Encadeada\n");
        printf("Escolha uma opção: ");
        scanf("%d", &tipoEstrutura);
        getchar();  // Para limpar o buffer do enter

        switch(tipoEstrutura) {
            case 1:  // Mochila com Vetor
                do {
                    printf("\n--- Mochila com Vetor ---\n");
                    printf("1. Adicionar item\n");
                    printf("2. Remover item\n");
                    printf("3. Listar itens\n");
                    printf("4. Buscar item (Sequencial)\n");
                    printf("5. Buscar item (Binário)\n");
                    printf("0. Voltar\n");
                    printf("Escolha uma opção: ");
                    scanf("%d", &opcao);
                    getchar();

                    Item item;
                    int indice;

                    switch(opcao) {
                        case 1:
                            printf("Digite o nome do item: ");
                            fgets(item.nome, MAX_STR_LEN, stdin);
                            item.nome[strcspn(item.nome, "\n")] = '\0';  // Remover o '\n'

                            printf("Digite o tipo do item: ");
                            fgets(item.tipo, MAX_STR_LEN, stdin);
                            item.tipo[strcspn(item.tipo, "\n")] = '\0';  // Remover o '\n'

                            printf("Digite a quantidade: ");
                            scanf("%d", &item.quantidade);
                            getchar();

                            inserirItemVetor(mochilaVetor, &quantidade, item);
                            break;

                        case 2:
                            printf("Digite o nome do item a remover: ");
                            char nomeRemover[MAX_STR_LEN];
                            fgets(nomeRemover, MAX_STR_LEN, stdin);
                            nomeRemover[strcspn(nomeRemover, "\n")] = '\0';  // Remover o '\n'

                            removerItemVetor(mochilaVetor, &quantidade, nomeRemover);
                            break;

                        case 3:
                            listarVetor(mochilaVetor, quantidade);
                            break;

                        case 4:
                            printf("Digite o nome do item a buscar: ");
                            char nomeBuscarSeq[MAX_STR_LEN];
                            fgets(nomeBuscarSeq, MAX_STR_LEN, stdin);
                            nomeBuscarSeq[strcspn(nomeBuscarSeq, "\n")] = '\0';  // Remover o '\n'

                            buscarSequencialVetor(mochilaVetor, quantidade, nomeBuscarSeq);
                            break;

                        case 5:
                            ordenarVetor(mochilaVetor, quantidade);  // Ordenar o vetor antes de fazer busca binária
                            printf("Digite o nome do item a buscar: ");
                            char nomeBuscarBin[MAX_STR_LEN];
                            fgets(nomeBuscarBin, MAX_STR_LEN, stdin);
                            nomeBuscarBin[strcspn(nomeBuscarBin, "\n")] = '\0';  // Remover o '\n'

                            buscarBinariaVetor(mochilaVetor, quantidade, nomeBuscarBin);
                            break;

                        case 0:
                            break;

                        default:
                            printf("Opção inválida.\n");
                    }
                } while(opcao != 0);
                break;

            case 2:  // Mochila com Lista Encadeada
                do {
                    printf("\n--- Mochila com Lista Encadeada ---\n");
                    printf("1. Adicionar componente\n");
                    printf("2. Descartar componente\n");
                    printf("3. Listar componentes\n");
                    printf("4. Organizar mochila (ordenar componentes)\n");
                    printf("5. Busca binária por componente-chave (nome)\n");
                    printf("0. Voltar\n");
                    printf("Escolha uma opção: ");
                    scanf("%d", &opcao);
                    getchar();

                    Item item;
                    int indice;

                    switch(opcao) {
                        case 1:
                            printf("---Coletando novo componente---");
                            printf("Nome: ");
                            fgets(item.nome, MAX_STR_LEN, stdin);
                            item.nome[strcspn(item.nome, "\n")] = '\0';  // Remover o '\n'

                            printf("Tipo (Estrutural, Eletronico, Energia): ");
                            fgets(item.tipo, MAX_STR_LEN, stdin);
                            item.tipo[strcspn(item.tipo, "\n")] = '\0';  // Remover o '\n'

                            printf("Digite a quantidade: ");
                            scanf("%d", &item.quantidade);
                            getchar();

                            inserirItemListaEncadeada(&mochilaLista, item);
                            break;

                        case 2:
                            printf("Digite o nome do item a remover: ");
                            char nomeRemover[MAX_STR_LEN];
                            fgets(nomeRemover, MAX_STR_LEN, stdin);
                            nomeRemover[strcspn(nomeRemover, "\n")] = '\0';  // Remover o '\n'

                            removerItemListaEncadeada(&mochilaLista, nomeRemover);
                            break;

                        case 3:
                            listarListaEncadeada(mochilaLista);
                            break;

                        case 4:
                            printf("Como deseja organizar os componentes?\n");
                            printf("1. Por nome\n");
                            printf("2. Por tipo");
                            printf("3. por prioridade de montagem.\n");
                            printf("0. Cancelar\n");
                            switch ()
                            {
                            case 1:
                                
                                break;
                            
                            default:
                                break;
                            }
                        case 0:
                            break;

                        default:
                            printf("Opção inválida.\n");
                    }
                } while(opcao != 0);
                break;

            default:
                printf("Opção inválida.\n");
        }
    } while(opcao != 0);

    return 0;
}