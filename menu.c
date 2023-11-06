#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

void menu_opcoes(Heap *raiz, int opcao)
{
    switch (opcao)
    {
    case 1:
        // inserir
        break;
    case 2:
        // remover
        break;
    case 3:
        // imprimir
        break;
    case 4:
        // liberar
        break;
    default:
        break;
    }
}
void menu(Heap *raiz)
{
    int opcao;
    do
    {
        printf("MENU:\n");
        printf("1. Inserir\n");
        printf("2. Remover\n");
        printf("3. Imprimir\n");
        printf("4. Liberar\n");
        printf("5. Sair\n");
        do
        {
            printf("DIGITE A OPERACAO QUE DESEJA REALIZAR: ");
            if (opcao < 1 || opcao > 5)
            {
                printf("POR FAVOR DIGITE UM NUMERO VALIDO!\n");
            }
            scanf("%d", &opcao);
        } while (opcao < 1 || opcao > 5);
        menu_opcoes(raiz, opcao);
        espera_enter();
    } while (opcao != 5);
}

int main()
{
    Heap *raiz = heap_cria_vazia();
    int opcao;
    menu(raiz);
}