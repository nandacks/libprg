//
// Created by Nanda on 08/10/2025.
//
//
// Created by wander on 25/09/2025.
//
#include <stdio.h>
#include <stdlib.h>
#include "stdbool.h"
#include "libprg/libprg.h"


ListaEncadeada* criar_lista_encadeada() {
    ListaEncadeada* lista = malloc(sizeof(ListaEncadeada));
    lista->inicio = NULL;
    lista->tamanho = 0;
    return lista;
}

void inserir_no_inicio(ListaEncadeada* lista, int valor) {
    No* novo = malloc(sizeof(No));
    novo->valor = valor;
    novo->proximo = lista->inicio;
    lista->inicio = novo;
    lista->tamanho++;
}

void inserir_no_fim(ListaEncadeada* lista, int valor) {
    No* novo = malloc(sizeof(No));
    novo->valor = valor;
    novo->proximo = NULL;

    if (lista->inicio == NULL) {
        lista->inicio = novo;
    } else {
        No* atual = lista->inicio;
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = novo;
    }
    lista->tamanho++;
}

bool remover_elemento(ListaEncadeada* lista, int valor) {
    if (lista->inicio == NULL) return false;

    No* atual = lista->inicio;
    No* anterior = NULL;

    while (atual != NULL && atual->valor != valor) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL) return false; // não encontrado

    if (anterior == NULL) {
        lista->inicio = atual->proximo;
    } else {
        anterior->proximo = atual->proximo;
    }

    free(atual);
    lista->tamanho--;
    return true;
}

No* buscar_elemento(ListaEncadeada* lista, int valor) {
    No* atual = lista->inicio;
    while (atual != NULL) {
        if (atual->valor == valor) {
            return atual;
        }
        atual = atual->proximo;
    }
    return NULL;
}

void exibir_lista(ListaEncadeada* lista) {
    No* atual = lista->inicio;
    printf("[");
    while (atual != NULL) {
        printf("%d", atual->valor);
        if (atual->proximo != NULL) printf(", ");
        atual = atual->proximo;
    }
    printf("]\n");
}

void destruir_lista_encadeada(ListaEncadeada* lista) {
    No* atual = lista->inicio;
    while (atual != NULL) {
        No* temp = atual;
        atual = atual->proximo;
        free(temp);
    }
    free(lista);
}