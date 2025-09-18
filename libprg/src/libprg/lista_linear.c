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

void inserir_ordenada(lista_linear_t* lista, int valor);
void inserir_nao_ordenada(lista_linear_t*, int valor);

lista_linear_t* criar_lista_linear(int capacidade, bool ordenada) {

    lista_linear_t* lista = malloc(sizeof(lista_linear_t));
    lista->elementos = malloc(sizeof(int)* capacidade);
    lista-> tamanho = 0;
    lista->capacidade = capacidade;
    lista->ordenada = ordenada;

    return lista;
}
void inserir_lista_linear(lista_linear_t* lista, int valor) {
    if (!cheia_lista_linear(lista)) {
        return;
    }
        if (lista->ordenada) {
            inserir_ordenada(lista, valor);
            //algoritimo para lista ordenada
        }else{
           inserir_nao_ordenada(lista, valor);
        }
}
void inserir_nao_ordenada(lista_linear_t*, int valor) {
    lista.elementos[lista.tamanho]=valor;
    lista.tamanho++;
}

void inserir_ordenada(lista_linear_t* lista, int valor) {
    if (!cheia_lista_linear(lista)){
        for (int i=lista->tamanho -1; 1>=0; --i) {
            if (lista->elementos[i]<valor) {
                lista->elementos[i+1]= valor;
                break;
            }
            lista->elementos[i+1]=lista->elementos[i];
        }
        lista->tamanho++;
    }
}

int busca_linear(lista_linear_t *lista, int valor) {
    int indice = 0;
    while(indice<lista->tamanho){
        if (lista->elementos[indice]==valor) {
            return indice;
        }
        indice++;
    }
    return -1;
}

int busca_binaria(struct lista_linear_t *lista, int valor) {
    int indice = 0;
    while(indice<lista->tamanho){
        if (lista->elementos[indice]==valor) {
            return indice;
        }
        indice++;
    }
    return -1;

}

int buscar_lista(lista_linear_t* lista, int valor) {
    if (lista->ordenada) {
        return busca_binaria;
    }
    return busca_linear(lista, valor);
}

// remover
// vazia

bool cheia_lista_linear(lista_linear_t* lista) {
   return lista->tamanho==lista->capacidade;
}
// destruir