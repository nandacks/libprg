//
// Created by aluno on 09/09/2025.
//

#include <stdlib.h>
#include <stdbool.h>
#include "libprg/libprg.h"


// criar fila
fila_t* criar_fila(int capacidade) {
    fila_t* f = malloc(sizeof(fila_t));
    f->elementos = malloc(sizeof(int) * capacidade);
    f->inicio = 0;
    f->fim = 0;
    f->tamanho = 0;
    f->capacidade = capacidade;
    return f;
}

// enfileirar
void enfileirar(fila_t* fila, int valor) {
    if (!cheia(fila)) { // verifica se a fila esta cheia
        fila->elementos[fila->fim] = valor;
        fila->fim = (fila->fim + 1) % fila->capacidade; // Fila circular é mais segura
        fila->tamanho++;
    }
}

// cheia
bool cheia(fila_t* fila) {
    return fila->tamanho == fila->capacidade;
}

// vazia
bool vazia(fila_t* fila) {
    return fila->tamanho == 0;
}

// Desenfileirar
int desenfileirar(fila_t* fila) {
    if (vazia(fila)) {
        return -1; // Retorna -1 se a fila estiver vazia
    }
    int valor = fila->elementos[fila->inicio];
    fila->inicio = (fila->inicio + 1) % fila->capacidade; // Fila circular
    fila->tamanho--;
    return valor;
}

// Início - retorna o elemento no início da fila sem removê-lo
int inicio_fila(fila_t* fila) {
    if (vazia(fila)) {
        return -1; // Retorna -1 se a fila estiver vazia
    }
    return fila->elementos[fila->inicio];
}

// Fim - retorna o elemento no fim da fila
int fim_fila(fila_t* fila) {
    if (vazia(fila)) {
        return -1; // Retorna -1 se a fila estiver vazia
    }
    // O último elemento está na posição anterior ao fim
    int posicao_ultimo = (fila->fim - 1 + fila->capacidade) % fila->capacidade;
    return fila->elementos[posicao_ultimo];
}

// Tamanho
int tamanho_fila(fila_t* fila) {
    return fila->tamanho;
}

// Destruir
void destruir_fila(fila_t* fila) {
    if (fila != NULL) {
        free(fila->elementos);
        free(fila);
    }
}