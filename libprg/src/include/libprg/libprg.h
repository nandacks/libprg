#ifndef LIBPRG_LIBPRG_H
#define LIBPRG_LIBPRG_H

/*----PILHA----*/

typedef struct {
    double value;
    int error;
} result_t;

typedef struct pilha pilha_t;

pilha_t* criar_pilha(int capacidade);
void empilhar(pilha_t* pilha, int valor);
int desempilhar(pilha_t* pilha);
int tamanho(pilha_t* pilha);
int vazia(pilha_t* pilha);
void destruir(pilha_t* pilha);

/*-----------------------------------------*/

typedef enum { SUM, SUB } operation_t;

result_t sub(double a, double b);
result_t sum(double a, double b);
result_t compute(double a, double b, operation_t op);

/*----FILA----*/

typedef struct fila fila_t;
fila_t* criar_fila(int capacidade) ;
void enfileirar(fila_t* fila, int valor);


#endif
