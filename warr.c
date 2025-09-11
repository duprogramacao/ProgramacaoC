#include <stdio.h>
#include <stdlib.h>

int main(){
//Lista linear dinâmica
int* numeros = (int*) malloc(3* sizeof(int));
// ^ Essa função aloca espaço na memória para guardar 3 números do tipo int

//passo 2: preencher a lista
numeros[0] = 10;
numeros[1] = 20;
numeros[2] = 30;

//passo 3: realocando a memória para expandir a lista
numeros = (int*) realloc(numeros, 5 * sizeof(int));
//''Ei, sistema, lembra daquele bloco de memória para 3 inteiros?
//Preciso que ele agora tenha o espaço para 5 inteiros."

numeros[3] = 40;
numeros[4] = 50;
}

// lista circular duplamente encadeada
//nó
struct No{
    int dado; //onde é guardada a informação
    struct No* proximo; //a ''seta'' que aponta para o próximo nó
    struct No* anterior; //conecta a lista tanto para frente quanto para trás;
};

int main() {
    struct No* primeiro = (struct No*) malloc(sizeof(struct No));
    struct No* segundo = (struct No*) malloc(sizeof(struct No));
    struct No* terceiro = (struct No*) malloc(sizeof(struct No));

    primeiro->dado = 10;
    primeiro->proximo = segundo;

    segundo->dado = 20;
    segundo->proximo = terceiro;

    terceiro->dado = 30;
    terceiro->proximo = NULL;

    // Percorrendo a lista
    struct No* atual = primeiro;
    while (atual != NULL) {
        printf("%d\n", atual->dado);
        atual = atual->proximo;
    }

    return 0;
} 

//função
//remove o primeiro nó da lista
void removerDoInicio(struct No** inicio){
    //primeiro checa se a lista não está vazia
    if (inicio == NULL || *inicio == NULL){
        printf("A lista já está vazia");
        return;
    }

    //guarda o endereço do nó que vamos promover
    struct No* noParaRemover = *inicio;

    //o inicio da lista passa a ser o segundo nó
    *inicio = (*inicio)->proximo;

    //libera a memória do nó que foi guardado
    free(noParaRemover);
}

void listar(struct No* inicio) {
    struct No* atual = inicio;
    while (atual != NULL) {
        printf("%d\n", atual->dado);
        atual = atual->proximo;
    }
} 

//busca linear
