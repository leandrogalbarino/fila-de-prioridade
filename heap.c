#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "heap.h"

Heap *heap_cria_vazia()
{
    return NULL;
}

Heap *insere_na_fila(int prioridade, int dado)
{
    Heap *novo = (Heap *)malloc(sizeof(Heap));
    novo->info.prioridade = prioridade;
    novo->info.dado = dado;
    novo->esquerda = heap_cria_vazia();
    novo->direita = heap_cria_vazia();
    return novo;
}

int quant_de_nos(Heap *raiz)
{
    int somador = 0;
    if (raiz == NULL)
        return 0;
    somador++;
    somador += quant_de_nos(raiz->esquerda);
    somador += quant_de_nos(raiz->direita);

    return somador;
}

Heap *ordena_heap(Heap *raiz)
{
    if (raiz->esquerda != NULL && raiz->esquerda->info.prioridade > raiz->info.prioridade)
    {
        Informacoes temp = raiz->info;
        raiz->info = raiz->esquerda->info;
        raiz->esquerda->info = temp;
    }

    if (raiz->direita != NULL && raiz->direita->info.prioridade > raiz->info.prioridade)
    {
        Informacoes temp = raiz->info;
        raiz->info = raiz->direita->info;
        raiz->direita->info = temp;
    }
    return raiz;
}

Heap *fila_prio_inserir(Heap *raiz, int prioridade, int dado)
{
    if (raiz == NULL)
    {
        Heap *novo = insere_na_fila(prioridade, dado);
        return novo;
    }

    if (raiz->esquerda == NULL)
        raiz->esquerda = fila_prio_inserir(raiz->esquerda, prioridade, dado);

    else if (raiz->direita == NULL)
        raiz->direita = fila_prio_inserir(raiz->direita, prioridade, dado);

    else
    {
        if (quant_de_nos(raiz->direita) == quant_de_nos(raiz->esquerda))
            raiz->esquerda = fila_prio_inserir(raiz->esquerda, prioridade, dado);

        else if (quant_de_nos(raiz->esquerda->esquerda) != quant_de_nos(raiz->esquerda->direita))
            raiz->esquerda = fila_prio_inserir(raiz->esquerda, prioridade, dado);

        else
            raiz->direita = fila_prio_inserir(raiz->direita, prioridade, dado);
    }

    raiz = ordena_heap(raiz);

    return raiz;
}

void fila_prio_imprime(Heap *a)
{
    if (a != NULL)
    {
        printf("No %d:", a->info.prioridade);
        if (a->esquerda != NULL && a->direita != NULL)
            printf("Filho esq:%d | Filho dir:%d\n", a->esquerda->info.prioridade, a->direita->info.prioridade);

        else if (a->direita == NULL && a->esquerda != NULL)
            printf("Filho esq:%d | Filho dir: NULL\n", a->esquerda->info.prioridade);
        else
            printf("Filho esq:NULL | Filho dir: NULL\n");
        printf("\n");
        fila_prio_imprime(a->esquerda);
        fila_prio_imprime(a->direita);
    }
}


void fila_prio_libera(Heap *f)
{
}



// int main()
// {
//     Heap *a = heap_cria_vazia();
//     a = fila_prio_inserir(a, 7, 10);
//     a = fila_prio_inserir(a, 2, 10);
//     a = fila_prio_inserir(a, 3, 10);
//     a = fila_prio_inserir(a, 11, 10);
//     a = fila_prio_inserir(a, 15, 10);
//     a = fila_prio_inserir(a, 15, 10);
//     a = fila_prio_inserir(a, 31, 10);
//     a = fila_prio_inserir(a, 221, 10);
//     a = fila_prio_inserir(a, 211, 10);
//     a = fila_prio_inserir(a, 251, 10);
//     a = fila_prio_inserir(a, 231, 10);
//     a = fila_prio_inserir(a, 20, 10);
//     fila_prio_imprime(a);
// }