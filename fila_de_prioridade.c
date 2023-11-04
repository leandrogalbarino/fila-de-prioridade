// Elabore um material (.pdf) 

//  FILAS DE PRIORIDADE (implementadas como heaps binários) | RELATÓRIO
// APRESENTAR OS CONCEITOS
// EXEMPLOS(com imagens do heap a cada inserção e remoção)
// POSSIVEIS ALGORITMOS(contemplando inserção, remoção e impressão/consulta)
// REFERENCIAIS BIBLIOGRAFICAS

// PESQUISAR EM LIVROS, NA INTERNET,e inclusive vocês encontram implementações prontas dos algoritmos em diversas linguagens. Podem usar estes materiais, desde que bem entendido e que o relatório não seja cópia de algum livro e/ou site da internet.


// IMPLEMENTAR EM C
// INSERÇÃO                                         LEANDRO
// IMPRESSÃO(mostrando o valor do nó e seus filhos diretos da esquerda e direita)
// REMOÇÃO                                          LUCAS

// MENU
// 1 - INSERIR
// 2- REMOVER
// 3 - IMPRIMIR HEAP
// 4 - sair

//Ao imprimir o heap, certifiquem-se de mostrar quem é o pai e quem são seus filhos. 
// Exemplo: após inserir os valores 1, 2 e 3 num heap de máximo, a impressão deve mostrar:
// Nó 3: filho esq: 1, filho dir: 2
// Nó 1: filho esq: vazio, filho dir: vazio
// Nó 2: filho esq: vazio, filho dir: vazio
// Ao remover a primeira vez um elemento do heap (neste caso, o 3 será removido), o heap ficaria:
// Nó 2: filho esq: 1, filho dir: vazio
// Nó 1: filho esq: vazio, filho dir: vazio

#include <stdlib.h>
#include <stdio.h>

#define MAX 100

struct no {
    int v;
    int prioridade;
    struct no* esquerda;
    struct no* direita;
};
typedef struct no No;

struct heap {
    No* arvore;
};
typedef struct heap Heap;

Heap* fila_cria() {

}

void fila_libera(Heap* f) {

}

void fila_imprimir(Heap* f) {

}

int main() {
    //Heap* fila = fila_cria();
    int opcao;

    do {
        printf("\tMENU:\n");
        printf("1 - Inserir\n2 - Remover\n3 - Imprimir\n0 - Sair\n");
        scanf("%d", &opcao);
        switch(opcao) {
            case 1:
                //inserir
                break;
            case 2:
                //remover
                break;
            case 3:
                //imprimir
                break;
            case 0:
                //liberar
                break;
            default:
                printf("Opcao invalida.\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}
