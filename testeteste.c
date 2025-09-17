#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Definições de tamanho máximo
#define MAX_STR_LEN 50
#define TAM_MAX 10

// Estrutura para representar um componente
typedef struct {
    char nome[MAX_STR_LEN];
    char tipo[MAX_STR_LEN];
    int prioridade;
} Componente;

// Estrutura para lista encadeada
typedef struct No {
    Componente dados;
    struct No *proximo;
} No;

typedef No* ListaEncadeada;

// Funções para inicializar a lista encadeada
void inicializarListaEncadeada(ListaEncadeada *lista) {
    *lista = NULL;
}

// Função para listar componentes da lista encadeada
void listarListaEncadeada(ListaEncadeada lista) {
    if (lista == NULL) {
        printf("A mochila está vazia.\n");
        return;
    }

    printf("Itens na mochila (Lista Encadeada):\n");
    No *temp = lista;
    int indice = 0;
    while (temp != NULL) {
        printf("[%d] Nome: %s, Tipo: %s, Prioridade: %d\n", indice, temp->dados.nome, temp->dados.tipo, temp->dados.prioridade);
        temp = temp->proximo;
        indice++;
    }
}

// Função para inserir componente na lista encadeada
void inserirComponenteListaEncadeada(ListaEncadeada *lista, Componente item) {
    No *novoNo = (No *)malloc(sizeof(No));
    if (!novoNo) {
        printf("Erro ao alocar memória para o novo item.\n");
        return;
    }
    novoNo->dados = item;
    novoNo->proximo = *lista;
    *lista = novoNo;
    printf("Componente \"%s\" inserido com sucesso!\n", item.nome);
}

// Função para comparar componentes por nome
int compararPorNome(const void* a, const void* b) {
    Componente* compA = (Componente*)a;
    Componente* compB = (Componente*)b;
    return strcmp(compA->nome, compB->nome);
}

// Função para comparar componentes por tipo
int compararPorTipo(const void* a, const void* b) {
    Componente* compA = (Componente*)a;
    Componente* compB = (Componente*)b;
    return strcmp(compA->tipo, compB->tipo);
}

// Função para comparar componentes por prioridade
int compararPorPrioridade(const void* a, const void* b) {
    Componente* compA = (Componente*)a;
    Componente* compB = (Componente*)b;
    return compA->prioridade - compB->prioridade;
}

// Função para ordenar os componentes no vetor com base no critério escolhido
void ordenarComponentes(Componente lista[], int quantidade, int (*comparar)(const void*, const void*)) {
    qsort(lista, quantidade, sizeof(Componente), comparar);
}

// Função para busca binária no vetor (deve ser chamada após a ordenação)
int buscarBinariaVetor(const Componente lista[], int quantidade, const char* nome) {
    int esquerda = 0;
    int direita = quantidade - 1;
    int comparacoes = 0;

    while (esquerda <= direita) {
        comparacoes++;
        int meio = (esquerda + direita) / 2;
        int cmp = strcmp(lista[meio].nome, nome);

        if (cmp == 0) {
            printf("Componente \"%s\" encontrado na mochila.\n", nome);
            printf("Número de comparações: %d\n", comparacoes);
            return meio;
        } else if (cmp < 0) {
            esquerda = meio + 1;
        } else {
            direita = meio - 1;
        }
    }

    printf("Componente \"%s\" não encontrado na mochila.\n", nome);
    printf("Número de comparações: %d\n", comparacoes);
    return -1;
}

// Função para busca sequencial no vetor
int buscarSequencialVetor(const Componente lista[], int quantidade, const char* nome) {
    int comparacoes = 0;

    for (int i = 0; i < quantidade; i++) {
        comparacoes++;
        if (strcmp(lista[i].nome, nome) == 0) {
            printf("Componente \"%s\" encontrado na mochila.\n", nome);
            printf("Número de comparações: %d\n", comparacoes);
            return i;
        }
    }

    printf("Componente \"%s\" não encontrado na mochila.\n", nome);
    printf("Número de comparações: %d\n", comparacoes);
    return -1;
}

// Função para listar os componentes no vetor
void listarVetor(const Componente lista[], int quantidade) {
    if (quantidade == 0) {
        printf("A mochila está vazia.\n");
    } else {
        printf("Itens na mochila (Vetor):\n");
        for (int i = 0; i < quantidade; i++) {
            printf("Nome: %s, Tipo: %s, Prioridade: %d\n", lista[i].nome, lista[i].tipo, lista[i].prioridade);
        }
    }
}

int main() {
    int opcao, tipoEstrutura, quantidade = 0;
    Componente mochilaVetor[TAM_MAX];
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
                    printf("1. Adicionar componente\n");
                    printf("2. Remover componente\n");
                    printf("3. Listar componentes\n");
                    printf("4. Buscar componente (Sequencial)\n");
                    printf("5. Buscar componente (Binário)\n");
                    printf("0. Voltar\n");
                    printf("Escolha uma opção: ");
                    scanf("%d", &opcao);
                    getchar();

                    Componente item;
                    int indice;

                    switch(opcao) {
                        case 1:
                            printf("Digite o nome do componente: ");
                            fgets(item.nome, MAX_STR_LEN, stdin);
                            item.nome[strcspn(item.nome, "\n")] = '\0';  // Remover o '\n'

                            printf("Digite o tipo do componente: ");
                            fgets(item.tipo, MAX_STR_LEN, stdin);
                            item.tipo[strcspn(item.tipo, "\n")] = '\0';  // Remover o '\n'

                            printf("Digite a prioridade: ");
                            scanf("%d", &item.prioridade);
                            getchar();

                            if (quantidade < TAM_MAX) {
                                mochilaVetor[quantidade++] = item;
                                printf("Componente \"%s\" inserido com sucesso!\n", item.nome);
                            } else {
                                printf("Mochila cheia!\n");
                            }
                            break;

                        case 2:
                            printf("Digite o nome do componente a remover: ");
                            char nomeRemover[MAX_STR_LEN];
                            fgets(nomeRemover, MAX_STR_LEN, stdin);
                            nomeRemover[strcspn(nomeRemover, "\n")] = '\0';  // Remover o '\n'

                            // Implementação da remoção do item no vetor (não foi implementado aqui por ser similar ao código original)
                            break;

                        case 3:
                            listarVetor(mochilaVetor, quantidade);
                            break;

                        case 4:
                            printf("Digite o nome do componente a buscar: ");
                            char nomeBuscarSeq[MAX_STR_LEN];
                            fgets(nomeBuscarSeq, MAX_STR_LEN, stdin);
                            nomeBuscarSeq[strcspn(nomeBuscarSeq, "\n")] = '\0';  // Remover o '\n'

                            buscarSequencialVetor(mochilaVetor, quantidade, nomeBuscarSeq);
                            break;

                        case 5:
                            ordenarComponentes(mochilaVetor, quantidade, compararPorNome);  // Ordenar antes da busca binária
                            printf("Digite o nome do componente a buscar: ");
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
                    printf("2. Remover componente\n");
                    printf("3. Listar componentes\n");
                    printf("4. Organizar mochila (ordenar componentes)\n");
                    printf("5. Busca binária por componente-chave (nome)\n");
                    printf("0. Ativar torre de fuga (Sair)\n");
                    printf("Escolha uma opção: ");
                    scanf("%d", &opcao);
                    getchar();

                    Componente item;

                    switch(opcao) {
                        case 1:
                            printf("Digite o nome do componente: ");
                            fgets(item.nome, MAX_STR_LEN, stdin);
                            item.nome[strcspn(item.nome, "\n")] = '\0';  // Remover o '\n'

                            printf("Digite o tipo do componente: ");
                            fgets(item.tipo, MAX_STR_LEN, stdin);
                            item.tipo[strcspn(item.tipo, "\n")] = '\0';  // Remover o '\n'

                            printf("Digite a prioridade: ");
                            scanf("%d", &item.prioridade);
                            getchar();

                            inserirComponenteListaEncadeada(&mochilaLista, item);
                            break;

                        case 2:
                            // Implementação da remoção no lista encadeada
                            break;

                        case 3:
                            listarListaEncadeada(mochilaLista);
                            break;

                        case 4:
                            printf("Como deseja organizar os componentes?\n");
                            printf("1. Por nome\n");
                            printf("2. Por tipo\n");
                            printf("3. Por prioridade\n");
                            printf("Escolha uma opção: ");
                            int critérioOrdenação;
                            scanf("%d", &critérioOrdenação);
                            getchar();

                            if (critérioOrdenação == 1) {
                                // Organizar por nome
                            } else if (critérioOrdenação == 2) {
                                // Organizar por tipo
                            } else if (critérioOrdenação == 3) {
                                // Organizar por prioridade
                            }
                            break;

                        case 5:
                            // Busca binária na lista encadeada
                            break;

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
