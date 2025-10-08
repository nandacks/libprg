//
// Created by aluno on 16/09/2025.
//
#include <stdlib.h>
#include <stdbool.h>
#include "libprg/libprg.h"

typedef struct lista_linear {
    int* elementos;
    int tamanho;
    int capacidade;
    bool ordenada;
} lista_linear_t;

void inserir_ordenada(lista_linear_t* lista_linear, int valor);
void inserir_nao_ordenada(lista_linear_t* lista_linear, int valor);
lista_linear_t* criar_lista_linear(int capacidade, bool ordenada) {
    lista_linear_t* lista_linear = malloc(sizeof(lista_linear_t));
    lista_linear->elementos = malloc(sizeof(int) * capacidade);
    lista_linear->tamanho = 0;
    lista_linear->capacidade = capacidade;
    lista_linear->ordenada = ordenada;
}

void inserir_lista_linear(lista_linear_t* lista_linear, int valor) {
    if (cheia_lista_linear(lista_linear))  {
        return;
    }if (lista_linear->ordenada) {
        inserir_ordenada(lista_linear, valor);
    } else {  inserir_nao_ordenada(lista_linear, valor);
    }
}


void inserir_nao_ordenada(lista_linear_t* lista_linear, int valor) {
    lista_linear->elementos[lista_linear->tamanho] = valor;
    lista_linear->tamanho++;
}


void inserir_ordenada(lista_linear_t* lista_linear, int valor) {
    if (!cheia_lista_linear(lista_linear)) {
        int i;
        for (i = lista_linear->tamanho - 1; i >= 0; --i) {
            if (lista_linear->elementos[i] < valor) {
                lista_linear->elementos[i + 1] = valor;
                break;
            }
            lista_linear->elementos[i + 1] = lista_linear->elementos[i];
        }
        if (i < 0) {
            lista_linear->elementos[0] = valor;        }
    }        lista_linear->tamanho++;
}
}



int busca_linear(lista_linear_t *lista_linear, int valor) {
    int indice = 0;
    while(indice < lista_linear->tamanho) {
        if (lista_linear->elementos[indice] == valor) {
            return indice;
        }
        indice++;
    }
    return -1;
}

int busca_binaria(struct lista_linear_t* lista_linear, int valor) {
    int inicio = 0;
    int fim = lista_linear->tamanho - 1;
    while(inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;
        if (lista_linear->elementos[meio] == valor) {
            return meio;
        }
        if (lista_linear->elementos[meio] < valor) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return -1;
}

int buscar_lista(lista_linear_t* lista_linear, int valor) {
    if (lista_linear->ordenada) {
        return busca_binaria(lista_linear, valor);
    }
    return busca_linear(lista_linear, valor);
}

bool cheia_lista_linear(lista_linear_t* lista) {
   return lista->tamanho == lista->capacidade;
}

void destruir_lista_linear(lista_linear_t* lista) {
    if (lista != NULL) {
        if (lista->elementos != NULL) {
            free(lista->elementos);
        }
        free(lista);
    }
}