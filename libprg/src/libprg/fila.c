//
// Created by aluno on 09/09/2025.
//
#include <stdbool.h>

#include "libprg/libprg.h"
#include <stdlib.h>

typedef struct fila {
    int* elementos;
    int tamanho;
    int inicio;
    int fim;
    int capacidade;
} fila_t;

fila_t* criar_fila(int) {
   fila_t* f = malloc(sizeof(fila_t));
    f->elementos = malloc(capacidade * sizeof(int));
    f->inicio = 0;
    f->fim = 0;
    f->tamanho = 0;
    f->capacidade = capacidade;

    return f;
}

void enfileirar(fila_t* fila, int valor) {
    fila->elementos[fila->fim]=valor;
    fila->fim++;
}
//desenfileira
//inicio
//fim
//tamanho
//vazia

bool cheia(fila_t fila) {
    if (fila.tamanho >= fila.capacidade) {
        return true;

    }else {
        return false;
    }
}
//destruir fila

