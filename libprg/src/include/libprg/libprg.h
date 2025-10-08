#define LIBPRG_LIBPRG_H
#include <stdbool.h>

/*----RESULTADOS----*/

typedef struct {
    double value;
    int error;
} result_t;

typedef enum { SUM, SUB } operation_t;

result_t sub(double a, double b);

result_t sum(double a, double b);

result_t compute(double a, double b, operation_t op);

/*----PILHA----*/

typedef struct pilha pilha_t;

pilha_t* criar_pilha(pilha_t* pilha, int capacidade);
int pilha_cheia(pilha_t* pilha);
int empilhar(pilha_t* pilha, int valor);
int desempilha(pilha_t* pilha);
int tamanho(pilha_t* pilha);
void destruir(pilha_t* pilha);
int topo(pilha_t* pilha);

// /*-----------------------------------------*/
//
// typedef enum { SUM, SUB } operation_t;
//
// result_t sub(double a, double b);
// result_t sum(double a, double b);
// result_t compute(double a, double b, operation_t op);
//
// /*----FILA----*/

// typedef struct fila fila_t;
// fila_t* criar_fila(int capacidade);
// void destruir_fila(fila_t* fila);
// bool vazia(fila_t* fila);
// bool cheia(fila_t* fila);
// int tamanho(fila_t* fila);
// bool enfileirar(fila_t* fila, int valor);
// bool desenfileirar(fila_t* fila, int* valor_removido);
// bool ver_inicio(fila_t* fila, int* valor_inicio);
// bool ver_fim(fila_t* fila, int* valor_fim);

// /*----LISTA----*/
//
// typedef struct lista_linear lista_linear_t;
// lista_linear_t* criar_lista_linear(int capacidade, bool ordenada);
// void inserir_lista_linear(lista_linear_t* lista, int valor);
// bool cheia_lista_linear(lista_linear_t* lista);
// int buscar_lista(lista_linear_t* lista, int valor);
//


// ---------- Lista Ordenada ----------
//
// typedef struct lista_ordenada lista_ordenada_t;
//
//
//
//
//
// // ---------- Lista Encadeada ----------
//
// typedef struct no no_t;
//
// no_t* crar_lista_encadeada(int valor);



#endif
