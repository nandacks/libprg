#include <stdlib.h>
#include <stdio.h>

typedef struct pilha {
    int* elementos;
    int topo;
    int capacidade;
} pilha_t;

pilha_t* criar_pilha(int capacidade) {
    pilha_t* p = malloc(sizeof(pilha_t));
    p->elementos = malloc(capacidade * sizeof(int));

    p->topo = -1;
    p->capacidade = capacidade;

    return p;
}

void empilhar(pilha_t* pilha, int valor){
    if (pilha->topo == (pilha->capacidade - 1)) {
        pilha->capacidade *= 2;
        pilha->elementos = realloc(pilha->elementos, pilha->capacidade * sizeof(int));
    }
    pilha->topo++;
    pilha->elementos[pilha->topo] = valor;
}

int vazia(pilha_t* pilha) {
    return pilha->topo == -1;
}

int desempilhar(pilha_t* pilha) {
    if (vazia(pilha)) {
        printf("Erro: Pilha vazia!\n");
        return -1; // Valor de erro
    }
    int valor = pilha->elementos[pilha->topo];
    pilha->topo--;
    return valor;
}

int tamanho(pilha_t* pilha) {
    return pilha->topo + 1;
}

void destruir(pilha_t* pilha) {
    free(pilha->elementos);
    free(pilha);
}