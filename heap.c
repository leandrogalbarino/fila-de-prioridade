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
        imprimir(a->esquerda);
        imprimir(a->direita);
    }
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
    raiz->ultimo_dado = dado;
    raiz->ultima_prioridade = prioridade;
    return raiz;
}

Heap *busca_no(Heap *raiz, int dado, int prioridade){
    if (raiz == NULL) {
        return NULL;
    }

    if (raiz->info.dado == dado && raiz->info.prioridade == prioridade) {
        return raiz;
    }

    Heap *no_na_esquerda = busca_no(raiz->esquerda, dado, prioridade);
    if (no_na_esquerda != NULL) {
        return no_na_esquerda;
    }

    Heap *no_na_direita = busca_no(raiz->direita, dado, prioridade);
    if (no_na_direita != NULL) {
        return no_na_direita;
    }
}

Heap *troca_nos(Heap *raiz, Heap *ultimo) {
    Informacoes temp_info = raiz->info; 
    raiz->info = ultimo->info; 
    ultimo->info = temp_info;
    
    return raiz; 
}


Heap *remover(Heap *raiz) {
    Heap *ultimo_no = busca_no(raiz,raiz->ultimo_dado,raiz->ultima_prioridade);
    printf("ULTIMO NO: %d com prioridade %d", ultimo_no->info.dado, ultimo_no->info.prioridade);
  

    if (ultimo_no != NULL) {
        raiz->ultima_prioridade = ultimo_no->info.prioridade;
        raiz->ultimo_dado = ultimo_no->info.dado;

        raiz = troca_nos(raiz, ultimo_no);
    }

    free(ultimo_no);

    return raiz;
}
