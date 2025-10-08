#include "libprg/libprg.h"
#include <stdlib.h>
#include <stdio.h>

#define SIM 1
#define NAO 2

typedef struct pilha {
    int* elementos;
    int topo;
    int capacidade;
} pilha_t;



pilha_t* criar_pilha(int capacidade) {
    pilha_t* p = malloc (sizeof(pilha_t));
    p->elementos = malloc(capacidade * sizeof(int));
    p->topo = -1;
    printf("Pilha criada com sucesso! \n");
        return p; // pilha n ta cheia

}

int pilha_cheia(pilha_t* pilha) {
    if (pilha->topo == pilha->capacidade - 1){
        printf("Sua pilha já está cheia :( \n");
        printf("Quer alocar mais espaço na memoria para colocar um novo elemento?\n");
        printf("Digite %d para SIM ou %d para NAO: ", SIM, NAO);
        int opcao;
        scanf("%d", &opcao);
        switch (opcao) {
            case SIM:
                printf("Certo, vamos alocar memoria!\n");
                pilha->capacidade *= 2;
                int* novo = realloc(pilha->elementos, pilha->capacidade * sizeof(int));
                //vendo se teve erro ao por mais memoria
                if (novo == NULL) {
                    printf("Erro ao alocar memoria!\n");
                    return 0; // falhou
                }
                pilha->elementos = novo;
                printf("Pilha expandida! Nova capacidade: %d\n", pilha->capacidade);
                return 1; // caeto

            case NAO:
                printf("Você optou por não aumentar a pilha.\n");
                return 0; // recusou

            default:
                printf("Opção inválida.\n");
                return 0;
        }
    }
    return 1; // Pilha não está cheia
}

    int empilhar(pilha_t* pilha, int valor) {
    printf("Topo: %d, Capacidade: %d\n", pilha->topo, pilha->capacidade);
        if (pilha->topo == pilha->capacidade - 1) {
            if (!pilha_cheia(pilha)) {
                printf("Não foi possível empilhar. Pilha cheia!\n");
                return 0; // deu erro ao emplhar
            }
        }
        pilha->topo++;
        pilha->elementos[pilha->topo] = valor;
        printf("Valor %d empilhado com sucesso!\n", valor);
        return 1;
    }

    int desempilha(pilha_t* pilha) {
        if (pilha->topo == -1) {
            printf("Pilha vazia, não é possível desempilhar.\n");
            return -1;
        }
        int valor = pilha->elementos[pilha->topo];
        pilha->topo--;
        return valor;
    }


    int tamanhop(pilha_t* pilha) {
        return pilha->topo + 1;
    }

    void destruir(pilha_t* pilha) {
        if (pilha != NULL) {
            if (pilha->elementos != NULL) {
                free(pilha->elementos);
            }
            free(pilha);
        }
    }


    int topo(pilha_t* pilha) {
    printf("Ultimo elemento da pilha é: %d", pilha->elementos[pilha->topo]);
    return 0;
}