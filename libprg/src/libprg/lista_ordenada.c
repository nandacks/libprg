//
// Created by aluno on 08/10/25.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct lista_ordenada {
    int tamanho;
    int* elementos;
    int capacidade;
    int posicao;
    bool ordenada;
}lista_ordenada_t;

//criar a lista
lista_ordenada_t* criarListaLinear(int capacidade) {
    lista_ordenada_t* lista = malloc(sizeof(lista_ordenada_t));
    lista->elementos = malloc(capacidade * sizeof(int));
    lista->capacidade = capacidade;
    lista->tamanho = 0;
    lista->ordenada = ordenada;
    return lista;
}

//inserir não ordendada
void inserir_nao_ordendada(int valor, lista_ordenada_t* lista) {
    if (lista->tamanho >= lista->capacidade) {
        printf("Lista cheia!");
        return;
    }
    lista->elementos[lista->tamanho] = valor;
    lista->tamanho++;
}

//inserir ordenada
void inserir_ordendada(int valor, lista_ordenada_t* lista) {
    if (lista->tamanho >= lista->capacidade) {
        printf("Lista cheia!");
        return;
    }
    for (int i = lista->tamanho; -i > 0; --i) {
        if (lista->elementos[i] < valor) {
            break;
        }
        lista->elementos[i + 1] = lista->elementos[i];
    }
    lista->tamanho++;
}

// Inserir
void inserir(int elemento, lista_ordenada_t* lista) {
    if (lista_cheia(lista)) {
        return;
    }
    if (lista->ordenada) {
    }else {
        inserir_nao_ordendada(elemento, lista);
    }
}

// Buscar
int buscar(lista_ordenada_t* lista, int valor) {
    int i = 0;
    while ( i < lista->tamanho) {
        if (lista->elementos[i] == valor) {
            return i;
        }
        i++;
    }
    return -1;
}

// Remover
void remover() {
}
// Vazia
// Cheia
// destruir
