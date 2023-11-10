#ifndef HEAP_H
#define HEAP_H

struct informacoes
{
    int dado;
    int prioridade;
};
typedef struct informacoes Informacoes;

struct heap
{
    Informacoes info;
    // int ultimo_dado;
    // int ultima_prioridade;
    struct heap *esquerda;
    struct heap *direita;
};
typedef struct heap Heap;

Heap *heap_cria_vazia();

Heap *insere_na_fila(int prioridade, int dado);

int quant_de_nos(Heap *raiz);

Heap *ordena_heap(Heap *raiz);

Heap *fila_prio_inserir(Heap *raiz, int prioridade, int dado);

void imprimir(Heap *a);

Heap *inserir(Heap *raiz);

// Heap *busca_no(Heap *raiz, int dado, int prioridade);

// Heap *busca_pai(Heap *raiz, int dado, int prioridade);

// Heap *troca_nos(Heap *raiz, Heap *ultimo_no);

// Heap *remover(Heap *raiz);

Heap *fila_troca(Heap *raiz, Heap *primeiro_no);

Heap *fila_prio_remover(Heap *raiz, Heap *primeiro_no);

Heap *remover(Heap *raiz);

#endif