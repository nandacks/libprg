#include <stdlib.h>
#include <stdio.h>

typedef struct pilha {
    int* elementos;
    int topo;
    int capacidade;
} pilha_t;


pilha_t* criar_pilha() {
    int capacidade;
    printf("Qual será a capacidade da sua pilha: ");
    scanf("%d", &capacidade);
    pilha_t* p = malloc(sizeof(pilha_t));
    p->elementos = malloc(capacidade * sizeof(int));

    p->topo = -1;
    p->capacidade = capacidade;

    return p;
}

int tamanho(pilha_t* pilha) {
    return pilha->topo + 1;
}

int vazia(pilha_t* pilha) {
    return pilha->topo == -1;
}

int valor;
void empilhar(pilha_t* pilha) {
    int resposta;
    do {
        printf("Qual valor deseja inserir na pilha? ");
        scanf("%d", &valor);
        if (pilha->topo == (pilha->capacidade - 1)) {
            printf("\n--- ATENCAO: Pilha cheia! Dobrando a capacidade... ---\n");
            int* temp = realloc(pilha->elementos, (pilha->capacidade * 2) * sizeof(int));
            pilha->elementos = temp;
            pilha->capacidade *= 2;
            printf("--- Capacidade da pilha aumentada para %d ---\n", pilha->capacidade);
        }
        pilha->topo++;
        pilha->elementos[pilha->topo] = valor;
        printf("=> Valor %d empilhado com sucesso. Tamanho atual: %d\n", valor, tamanho(pilha));
        int continuar = 1;
        while (continuar) {
            resposta = 0;
            printf("\nDeseja inserir outro item? (1 para SIM / 0 para NAO): ");
            scanf("%d", &resposta);
            switch (resposta) {
                case 1:
                    empilhar(pilha);
                    break;
                case 0:
                    continuar = 0;
                    return;

                default:
                    printf("Opção Invalida, tente novamente! \n");
                    if (continuar==1) {
                        if (resposta != 1 || resposta != 0) {
                            printf("realmente não deseja continuar????? 1/sim 0/não");
                            scanf("%d", &resposta);
                        }

            }
            }
            printf("\n");
        }
    } while (resposta == 1);
    printf("Operacao de insercao finalizada.\n");
}

int desempilhar(pilha_t* pilha) {
    if (vazia(pilha)) {
        printf("Erro: Pilha vazia!\n");
        return -1; // Valor de erro
    }
    printf("Desempilhado o item %d de valor %d. \n", tamanho(pilha), valor);
    int valor = pilha->elementos[pilha->topo];
    pilha->topo--;
    printf("Agora sua pilha agora tem tamanho %d",tamanho(pilha));
    return valor;
}

void destruir(pilha_t* pilha) {
    free(pilha->elementos);
    free(pilha);
    printf("A pilha foi destruida com sucesso!");
}