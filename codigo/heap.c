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
Heap *inserir(Heap *raiz)
{
    int prioridade, dado;

    printf("Digite o dado do elemento: ");
    scanf("%d", &dado);
    printf("Digite a prioridade do elemento: ");
    scanf("%d", &prioridade);

    raiz = fila_prio_inserir(raiz, prioridade, dado);
    printf("Elemento inserido com sucesso!\n");
    return raiz;
}

void imprimir_arv(Heap *a)
{
    if (a != NULL)
    {
        if (a->esquerda != NULL && a->direita != NULL)
        {
            printf("No %d:", a->info.prioridade);
            printf("Filho esq: %d | Filho dir: %d\n", a->esquerda->info.prioridade, a->direita->info.prioridade);
        }
        else if (a->direita == NULL && a->esquerda != NULL)
        {
            printf("No %d:", a->info.prioridade);
            printf("Filho esq: %d | Filho dir: NULL\n", a->esquerda->info.prioridade);
        }
        else
        {
            printf("No %d:", a->info.prioridade);
            printf("Filho esq: NULL | Filho dir: NULL\n");
        }

        printf("\n");
        imprimir_arv(a->esquerda);
        imprimir_arv(a->direita);
    }
}


void imprimir(Heap *a){
    if(a == NULL){
        printf("Nao existem elementos na Fila!!\n");
    }
    else{
        imprimir_arv(a);
    }
}



Heap *fila_troca(Heap *raiz, Heap *primeiro_no)
{
    primeiro_no->info = raiz->info;
    return NULL;
}

Heap *fila_prio_remover(Heap *raiz, Heap *primeiro_no)
{
    if (raiz == NULL)
        return NULL;

    if (raiz->esquerda == NULL)
    {
        raiz = fila_troca(raiz, primeiro_no);
    }
    else if (raiz->direita == NULL)
    {
        raiz->esquerda = fila_troca(raiz->esquerda, primeiro_no);
    }
    else
    {
        if (quant_de_nos(raiz->direita) == quant_de_nos(raiz->esquerda))
        {
            raiz->direita = fila_prio_remover(raiz->direita, primeiro_no);
        }
        else if (quant_de_nos(raiz->direita->esquerda) != quant_de_nos(raiz->direita->direita))
        {
            raiz->direita = fila_prio_remover(raiz->direita, primeiro_no);
        }
        else
        {
            raiz->esquerda = fila_prio_remover(raiz->esquerda, primeiro_no);
        }
    }

    return raiz;
}


Heap *ordenar_toda_heap(Heap *raiz)
{
    if (raiz != NULL)
    {
        if (raiz->esquerda != NULL && raiz->esquerda->info.prioridade > raiz->info.prioridade)
        {
            Informacoes temp = raiz->info;
            raiz->info = raiz->esquerda->info;
            raiz->esquerda->info = temp;
            ordenar_toda_heap(raiz->esquerda);
        }

        if (raiz->direita != NULL && raiz->direita->info.prioridade > raiz->info.prioridade)
        {
            Informacoes temp = raiz->info;
            raiz->info = raiz->direita->info;
            raiz->direita->info = temp;
            ordenar_toda_heap(raiz->direita);
        }
    }
    return raiz;
}

Heap *remover(Heap *raiz)
{
    if (raiz == NULL)
        printf("Heap vazia, nao foi possivel remover um elemento!!\n");
    else
    {
        raiz = fila_prio_remover(raiz, raiz);
        ordenar_toda_heap(raiz);

        printf("Elemento removido com sucesso!\n");
    }
    return raiz;
}