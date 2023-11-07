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
    {
        return 0;
    }

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
    {
        raiz->esquerda = fila_prio_inserir(raiz->esquerda, prioridade, dado);
    }
    else if (raiz->direita == NULL)
    {
        raiz->direita = fila_prio_inserir(raiz->direita, prioridade, dado);
    }
    else
    {
        if (quant_de_nos(raiz->direita) == quant_de_nos(raiz->esquerda))
        {
            raiz->esquerda = fila_prio_inserir(raiz->esquerda, prioridade, dado);
        }
        else if (quant_de_nos(raiz->esquerda->esquerda) != quant_de_nos(raiz->esquerda->direita))
        {
            raiz->esquerda = fila_prio_inserir(raiz->esquerda, prioridade, dado);
        }
        else
        {
            raiz->direita = fila_prio_inserir(raiz->direita, prioridade, dado);
        }     
    }

    raiz = ordena_heap(raiz);
    return raiz;
}

void imprimir(Heap *a)
{
    if (a != NULL)
    {
        printf("No %d:", a->info.prioridade);
        if (a->esquerda != NULL && a->direita != NULL)
        {
            printf("Filho esq: %d | Filho dir: %d\n", a->esquerda->info.prioridade, a->direita->info.prioridade);
        }
        else if (a->direita == NULL && a->esquerda != NULL)
        {
            printf("Filho esq: %d | Filho dir: NULL\n", a->esquerda->info.prioridade);
        } 
        else
        {
            printf("Filho esq: NULL | Filho dir: NULL\n");
        }

        printf("\n");
        imprimir(a->esquerda);
        imprimir(a->direita);
    }
}

void inserir(Heap **raiz) 
{
    int prioridade, dado;
    
    printf("Digite o dado do elemento: ");
    scanf("%d", &dado);
    printf("Digite a prioridade do elemento: ");
    scanf("%d", &prioridade);

    *raiz = fila_prio_inserir(*raiz, prioridade, dado);
    printf("Elemento inserido com sucesso!\n");
}

Heap *encontra_ultimo_elemento(Heap *raiz) 
{
    while (raiz->esquerda != NULL || raiz->direita != NULL) 
    {
        if (raiz->direita != NULL) 
        {
            raiz = raiz->direita;
        } 
        else 
        {
            raiz = raiz->esquerda;
        }
    }
    return raiz;
}

Heap *troca_nos(Heap *raiz, Heap *ultimo) 
{
    Informacoes temp = raiz->info;
    raiz->info = ultimo->info;
    ultimo->info = temp;
    return raiz;
}

Heap *remover(Heap *raiz) {
    if (raiz == NULL) {
        printf("A arvore ja esta vazia.\n");
        return NULL;
    }

    Heap *ultimo = encontra_ultimo_elemento(raiz);

    if (ultimo == raiz) 
    {
        free(raiz);
        return NULL;
    }

    raiz = troca_nos(raiz, ultimo);

    Heap *pai = raiz;
    while (pai->esquerda != ultimo && pai->direita != ultimo) 
    {
        if (pai->esquerda != NULL) 
        {
            pai = pai->esquerda;
        } 
        else 
        {
            pai = pai->direita;
        }
    }

    if (pai->esquerda == ultimo) 
    {
        pai->esquerda = NULL;
    } 
    else 
    {
        pai->direita = NULL;
    }

    free(ultimo);
    raiz = ordena_heap(raiz);

    printf("Elemento removido com sucesso!\n");
    return raiz;
}
