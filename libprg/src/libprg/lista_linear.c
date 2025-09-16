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
} lista_linear_t;

lista_linear_t* criar_lista_linear(int capacidade) {
    lista_linear_t* lista = malloc(sizeof(lista_linear_t));
    lista->elementos = malloc(sizeof(int)* capacidade);
    lista-> tamanho = 0;
    lista->capacidade = capacidade;

    return lista;
}
void inserir_lista_linear(lista_linear_t* lista, int valor) {
    lista->elementos[lista->tamanho]=valor;
    lista->tamanho++;
}



int buscar_lista(lista_linear_t* lista, int valor){
    int indice = 0;
    while(indice<lista->tamanho){
        if (lista->elementos[indice]==valor) {
            return indice;
        }
        indice++;
    }
    return -1;
}

// remover
// vazia

bool cheia_lista_linear(lista_linear_t* lista) {
   return lista->tamanho==lista->capacidade;
}
// destruir