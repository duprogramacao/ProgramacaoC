#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TAMANHO 5
#define NOME_MAX_TAM 30
#define COR_MAX_TAM 10
#define NUM_MISSOES 5

typedef struct {
    char **nome;
    char **cor;
    int *tropas;
} Territorio;

// Função que sorteia e copia a missão para uma string destino
void atribuirMissao(char *destino, char *missoes[], int totalMissoes) {
    int indiceAleatorio = rand() % totalMissoes;
    strcpy(destino, missoes[indiceAleatorio]);
}

// Função que verifica se a missão foi cumprida (lógica simples inicial)
int verificarMissao(char *missao, Territorio *mapa, int tamanho) {
    if (strcmp(missao, "Conquistar 3 territorios seguidos") == 0) {
        int seguidos = 0;
        for (int i = 0; i < tamanho; i++) {
            if (mapa->tropas[i] > 0) seguidos++;
            if (seguidos >= 3) return 1; // vitória
        }
    } 
    // Por enquanto, apenas uma lógica simples para a primeira missão
    // Outras missões podem ser implementadas com mais condições
    return 0;
}

int main() {
    srand(time(NULL));

    // Vetor fixo de missões
    char *missoes[NUM_MISSOES] = {
        "Conquistar 3 territorios seguidos",
        "Eliminar todas as tropas da cor vermelha",
        "Eliminar todas as tropas da cor verde",
        "Conquistar todos os territorios",
        "Eliminar todas as tropas da cor azul"
    };

    // Aloca memória para a missão do jogador
    char *missaoJogador = (char *)malloc(100 * sizeof(char));
    if (missaoJogador == NULL) {
        printf("Erro ao alocar memoria para missao.\n");
        return 1;
    }

    // Atribui uma missão aleatória ao jogador
    atribuirMissao(missaoJogador, missoes, NUM_MISSOES);
    printf("Missao do jogador: %s\n", missaoJogador);

    // Exemplo de mapa só para teste (5 territórios com tropas aleatórias)
    Territorio mapa;
    mapa.tropas = (int *)malloc(TAMANHO * sizeof(int));
    for (int i = 0; i < TAMANHO; i++) {
        mapa.tropas[i] = rand() % 5; // tropas aleatórias
    }

    // Verificação simples (pode ser chamada no fim de cada turno)
    if (verificarMissao(missaoJogador, &mapa, TAMANHO)) {
        printf("Missao cumprida! Jogador venceu!\n");
    } else {
        printf("Missao ainda nao cumprida.\n");
    }

    // Libera memória
    free(mapa.tropas);
    free(missaoJogador);

    return 0;
}