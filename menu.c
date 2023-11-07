#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

void espera_enter() 
{
    printf("\nPressione Enter para continuar...");
    while (getchar() != '\n');
    getchar(); 
}

void menu_opcoes(Heap **raiz, int opcao) 
{
    switch (opcao) 
    {
        case 1:
            inserir(raiz);
            break;
        case 2:
            remover(raiz);
            break;
        case 3:
            imprimir(*raiz);
            break;
        case 4:
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
        printf("\n\tMENU:\n");
        printf("1. Inserir\n");
        printf("2. Remover\n");
        printf("3. Imprimir\n");
        printf("4. Sair\n");

        do 
        {
            printf("DIGITE A OPERACAO QUE DESEJA REALIZAR: ");
            scanf("%d", &opcao);
            if (opcao < 1 || opcao > 5) {
                printf("POR FAVOR DIGITE UM NUMERO VALIDO!\n");
            }
        } while (opcao < 1 || opcao > 5);

        if (opcao != 5)
        {
            menu_opcoes(&raiz, opcao);
            espera_enter();
        }

    } while (opcao != 5);
}

int main() 
{
    Heap *raiz = heap_cria_vazia();
    menu(raiz);
    return 0;
}