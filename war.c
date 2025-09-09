#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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

void simularAtaque(Territorio *p, int atacante, int defendido) {
    // Gerando números aleatórios para simular o ataque
    int ataque = rand() % (p->tropas[atacante] + 1);  // O ataque será entre 0 e o número de tropas do território atacante
    int defesa = rand() % (p->tropas[defendido] + 1); // A defesa será entre 0 e o número de tropas do território defendido
    
    printf("\nResultado do ataque:\n");
    printf("Território atacante: %s (Tropas: %d)\n", p->nome[atacante], p->tropas[atacante]);
    printf("Território defendido: %s (Tropas: %d)\n", p->nome[defendido], p->tropas[defendido]);
    printf("Ataque: %d, Defesa: %d\n", ataque, defesa);

    if (ataque > defesa) {
        printf("O ataque foi bem-sucedido! %s conquista %s.\n", p->nome[atacante], p->nome[defendido]);
        p->tropas[defendido] -= (ataque - defesa); // As tropas do território defendido diminuem
        if (p->tropas[defendido] < 0) {
            p->tropas[defendido] = 0; // Garantir que não haja tropas negativas
        }
    } else {
        printf("O ataque falhou. %s consegue se defender contra o ataque de %s.\n", p->nome[defendido], p->nome[atacante]);
        p->tropas[atacante] -= (defesa - ataque); // As tropas do território atacante diminuem
        if (p->tropas[atacante] < 0) {
            p->tropas[atacante] = 0; // garante que não haja tropas negativas
        }
    }
}

const char* atribuirMissao(){
    char *vetorMissoesEstrategicas[] = {
        "Conquiste 3 territórios seguidos",
        "Elimine todas as tropas da cor vermelha",
        "Elimine todas as tropas da cor verde",
        "Conquiste todos os territórios",
        "Elimine todas as tropas da cor azul"
    };

    int totalMissoes = sizeof(vetorMissoesEstrategicas) / sizeof(vetorMissoesEstrategicas[0]);
    int indice = rand() % totalMissoes; // sorteia índice
    return vetorMissoesEstrategicas[indice];

    printf("\nMissão aleatória: %s\n", vetorMissoesEstrategicas[indice]);
}

//int global para verificar se missões foram cumpridas
int verificarMissao(char* missao, Territorio* mapa, int tamanho){
    int contagem = 0;

    if (strcmp(missao, "Conquiste todos os territórios") == 0){
        for (int i = 0; i < tamanho; i++){
            if (mapa->tropas[i] <= 0){
                return 0;
            }
        }
        printf("Missão cumprida!");
        return 1;
    }
    
    if (strcmp(missao, "Conquiste 3 territórios seguidos") == 0){
        for (int i = 0; i < tamanho - 2; i++){
            if (mapa->tropas[i] > 0 && mapa->tropas[i+1] > 0 && mapa->tropas[i+2] > 0){
                contagem++;
                break;
            }
        }
     return contagem > 0 ? 1 : 0;
    }

    if (strcmp(missao, "Elimine todas as tropas da cor vermelha") == 0){
        for (int i = 0; i < tamanho; i++){
            if(strcmp(mapa->cor[i], "Vermelha") == 0 && mapa->tropas[i] > 0){
                return 0;
            }
        }
        return 1;
    }

    if (strcmp(missao, "Elimine todas as tropas da cor verde") == 0){
        for (int i = 0; i < tamanho; i++){
            if(strcmp(mapa->cor[i], "Verde") == 0 && mapa->tropas[i] > 0){
                return 0;
            }
        }
        return 1;
    }

    if (strcmp(missao, "Elimine todas as tropas da cor azul") == 0){
        for (int i = 0; i < tamanho; i++){
            if(strcmp(mapa->cor[i], "Azul") == 0 && mapa->tropas[i] > 0){
                return 0;
            }
        }
        return 1;
    }



}



int main(){

    srand(time(NULL));

    Territorio* p = (Territorio*)malloc(sizeof(Territorio));
    if (p == NULL) {
        printf("Falha ao alocar a memória.\n");
        return 1;
    }

    p->nome = (char**)malloc(TAMANHO * sizeof(char*));  
    p->cor = (char**)malloc(TAMANHO * sizeof(char*));   
    p->tropas = (int*)malloc(TAMANHO * sizeof(int));

    //registro dos territórios
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
    scanf("%d", &p->tropas[i]);
    }

    printf("\nTerritórios cadastrados:\n");
    for (int i = 0; i < TAMANHO; i++) {
        printf("Território %d - Nome: %s, Cor: %s\n", i + 1, p->nome[i], p->cor[i]);
    }
    
    
    //seleção do território

    int atacante, defendido;
    int menu;
 

    //missão aparece na tela depois de cadastrar dados
    char missaoAtual[100];  
    strcpy(missaoAtual, atribuirMissao());  
    printf("Sua missão atual: %s\n", missaoAtual);  


    printf("--- MENU DE AÇÕES ---\n");
    printf("1 - Atacar\n");
    printf("2 - Missão\n");
    printf("0 - Sair\n");

    scanf("%d", &menu);
    switch(menu){  


        case 1:
        while (1) {
        printf("\n--- FASE DE ATAQUE ---\n");
        printf("Escolha o território atacante (1 a 5, ou 0 para sair): ");
        scanf("%d", &atacante);
        verificarMissao;

         if (atacante == 0) {
            printf("Saindo...\n");
            break; // sai do loop se o usuário escolher 0
          }

            if (atacante < 1 || atacante > TAMANHO) {
               printf("Escolha inválida! Digite um valor entre 1 e 5.\n");
             continue;
            }

            printf("Escolha o território defendido (1 a 5): ");
            scanf("%d", &defendido);

            if (defendido < 1 || defendido > TAMANHO) {
            printf("Escolha inválida! Digite um valor entre 1 e 5.\n");
            continue;
            }

            if (atacante == defendido) {
            printf("O território atacante e o defendido não podem ser o mesmo.\n");
            continue;
         }

        // Ajusta os índices pra começar de 0
            simularAtaque(p, atacante - 1, defendido - 1);

        // Mostra os territórios após o ataque
            printf("--- RESULTADO DA BATALHA ---\n");
            printf("\nTerritórios após o ataque:\n");
            for (int i = 0; i < TAMANHO; i++) {
            printf("Território %d - Nome: %s, Cor: %s, Tropas: %d\n", i + 1, p->nome[i], p->cor[i], p->tropas[i]);
        }
    
    }
    case 2:
      if (verificarMissao(missaoAtual, p, TAMANHO)) {
            printf("Você cumpriu a missão!\n");
            } else {
            printf("Você não cumpriu a missão ainda.\n");
            }
            break;

    case 0:
    break;
    
    default:
    printf("Escolha inválida.\n");
    limparBufferEntrada();

    
    // Liberando a memória alocada
    for (int i = 0; i < TAMANHO; i++) {
        free(p->nome[i]);
        free(p->cor[i]);
    }
    
}
    free(p->nome);
    free(p->cor);
    free(p->tropas);
    free(p);

    printf("Memória liberada com sucesso.");

    return 0;
}