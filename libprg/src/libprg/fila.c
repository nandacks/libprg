//
// Created by aluno on 09/09/2025.
//
#include <stdbool.h>
#include "libprg/libprg.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct fila {
    int* elementos;
    int tamanho;
    int inicio;
    int fim;
    int capacidade;
} fila_t;
fila_t* criar_fila(int capacidade) {
    // (Esta função continua igual)
    if (capacidade <= 0) {
        printf("Erro: A capacidade da fila deve ser maior que zero.\n");
        return NULL;
    }
    fila_t* f = (fila_t*) malloc(sizeof(fila_t));
    if (f == NULL) { exit(1); }
    f->elementos = (int*) malloc(capacidade * sizeof(int));
    if (f->elementos == NULL) { free(f); exit(1); }
    f->capacidade = capacidade;
    f->inicio = 0;
    f->fim = 0;
    f->tamanho = 0;
    return f;
}

void destruir_fila(fila_t* fila) {
    // (Esta função continua igual)
    if (fila != NULL) {
        free(fila->elementos);
        free(fila);
    }
}

bool vazia(fila_t* fila) { return fila->tamanho == 0; }
bool cheia(fila_t* fila) { return fila->tamanho == fila->capacidade; }
int tamanho(fila_t* fila) { return fila->tamanho; }

/**
 * Adiciona um elemento. Retorna true em caso de sucesso.
 */
bool enfileirar(fila_t* fila, int valor) {
    if (cheia(fila)) {
        printf("Erro: A fila esta cheia! Nao foi possivel inserir o valor %d.\n", valor);
        return false;
    }
    fila->elementos[fila->fim] = valor;
    fila->fim = (fila->fim + 1) % fila->capacidade;
    fila->tamanho++;
    return true;
}

/**
 * Remove um elemento. Retorna true e preenche 'valor_removido' em caso de sucesso.
 */
bool desenfileirar(fila_t* fila, int* valor_removido) {
    if (vazia(fila)) {
        return false; // Falha: fila vazia
    }
    // Sucesso: preenche o ponteiro com o valor e atualiza a fila
    *valor_removido = fila->elementos[fila->inicio];
    fila->inicio = (fila->inicio + 1) % fila->capacidade;
    fila->tamanho--;
    return true;
}

/**
 * Vê o elemento do início. Retorna true e preenche 'valor_inicio' em caso de sucesso.
 */
bool ver_inicio(fila_t* fila, int* valor_inicio) {
    if (vazia(fila)) {
        return false; // Falha: fila vazia
    }
    // Sucesso: preenche o ponteiro com o valor
    *valor_inicio = fila->elementos[fila->inicio];
    return true;
}

/**
 * Vê o elemento do fim. Retorna true e preenche 'valor_fim' em caso de sucesso.
 */
bool ver_fim(fila_t* fila, int* valor_fim) {
    if (vazia(fila)) {
        return false; // Falha: fila vazia
    }
    int indice_fim = (fila->fim - 1 + fila->capacidade) % fila->capacidade;
    // Sucesso: preenche o ponteiro com o valor
    *valor_fim = fila->elementos[indice_fim];
    return true;
}