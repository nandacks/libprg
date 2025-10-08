//
// Created by aluno on 09/09/2025.
//
#include <stdbool.h>
#include "libprg/libprg.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct fila {
    int* elementos;
    int inicio;
    int fim;
    int tamanho;
    int capacidade;
}fila_t;


fila_t* criar_fila(int capacidade) {
    fila_t* f = malloc(sizeof(fila_t));
    f->elementos = malloc(sizeof(int) * capacidade);
    f->inicio = 0;
    f->fim = 0;
    f->tamanho = 0;
    f->capacidade = capacidade;
    return f;
}

bool cheia(fila_t* fila) {
    return fila->tamanho == fila->capacidade;
}

bool vazia(fila_t* fila) {
    return fila->tamanho == 0;
}

void enfileirar(fila_t* fila, int valor) {
    if (cheia(fila)) {
        printf("Fila cheia! Não é possível enfileirar %d\n", valor);
        return;
    }

    fila->elementos[fila->fim] = valor;
    fila->fim = (fila->fim + 1) % fila->capacidade; // comportamento circular
    fila->tamanho++;
}

int desenfileirar(fila_t* fila) {
    if (vazia(fila)) {
        printf("Fila vazia! Não é possível desenfileirar.\n");
        return -1; // valor de erro
    }

    int valor = fila->elementos[fila->inicio];
    fila->inicio = (fila->inicio + 1) % fila->capacidade;
    fila->tamanho--;
    return valor;
}

void destruir_fila(fila_t* fila) {
    free(fila->elementos);
    free(fila);
}









