#include "libprg/libprg.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIM 1
#define NAO 2


pilha_t* criarPilha(int capacidade) {
    pilha_t* p = malloc(sizeof(pilha_t));
    p->elementos = malloc(capacidade * sizeof(int));
    p->topo = -1;
    p->capacidade = capacidade;
    printf("Pilha com capacidade %d criada.\n", capacidade);
    return p;
}

int pilha_cheia(pilha_t* pilha) {
    if (pilha->topo == pilha->capacidade - 1){
        printf("Sua pilha já está cheia :( \n");
        printf("Quer alocar mais espaço na memoria para colocar um novo elemento?\n");
        printf("Digite %d para SIM ou %d para NAO: ", SIM, NAO);
        int opcap;
        scanf("%d", &opcap);

        switch (opcap) {
            case SIM:
                printf("Certo, vamos alocar memoria!\n");
                pilha->capacidade *= 2;
                int* novo = realloc(pilha->elementos, pilha->capacidade * sizeof(int));
                //verificando se houve erro ao realocar memoria
                if (novo == NULL) {
                    printf("Erro ao alocar memoria!\n");
                    return 0; // Falhou ao realocar
                }
                pilha->elementos = novo;
                printf("Pilha expandida! Nova capacidade: %d\n", pilha->capacidade);
                return 1; // Sucesso

            case NAO:
                printf("Você optou por não aumentar a pilha.\n");
                return 0; // Usuário recusou

            default:
                printf("Opção inválida.\n");
                return 0; // Opção inválida
        }
    }
    return 1; // Pilha não está cheia
}

int empilhar(pilha_t* pilha, int valor) {

    if (pilha->topo == pilha->capacidade - 1) {
        if (!pilha_cheia(pilha)) {
            printf("Não foi possível empilhar. Pilha cheia!\n");
            return 0; // Falhou ao empilhar
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

int tamanho(pilha_t* pilha) {
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
    if (pilha->topo == -1) {
        return -1; // Erro, pilha vazia
    }
    return pilha->elementos[pilha->topo];
}