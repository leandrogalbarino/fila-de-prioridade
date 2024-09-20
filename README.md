# CONCEITOS

## FILAS DE PRIORIDADE

Uma fila de prioridade é uma fila na qual os elementos são inseridos com um nível de prioridade. Quando a função para remover um elemento da fila é chamada, o elemento com a prioridade mais alta é retirado da fila. As filas de prioridade são amplamente utilizadas em várias situações. Por exemplo, em filas de atendimento em bancos, clientes idosos ou mulheres grávidas têm prioridade mais alta em comparação com outros clientes. As filas de prioridade podem ser implementadas com listas encadeadas, usando uma variável adicional para representar a prioridade de cada elemento.

## OPERAÇÕES

As filas de prioridade prevêem duas operações básicas que são na realidade uma extensão das operações básicas de uma fila comum. São elas:
 - Inserir com prioridade
 - Remover elemento de mais alta prioridade

Não iremos implementar a fila de prioridade usando listas. Isso porque existe uma implementação que é mais rápida do que listas. Porém, antes precisamos estudar outra estrutura de dados chamada Heap.

## HEAP

A Heap é uma estrutura especializada baseada em árvores que satisfaz a seguinte propriedade:
1. Se B é um nó filho de A, então chave(A) >= chave(B), no caso de max_heap ou chave(B) >= chave(A) no caso de min_heap.

A propriedade implica em que o nó raiz seja sempre o elemento com maior ou menor chave na estrutura. Os principais usos da heap são na implementação eficiente de filas de prioridade, em alguns algoritmos como o Algoritmo de Djikstra, e em algoritmos de ordenação de dados tal como o algoritmo heapsort.

OBS: A heap é geralmente implementada em um array e não requer ponteiros entre os elementos. Porém, na nossa implementação, iremos implementar com ponteiros, para sair do convencional (lembrando que com vetores a heap é mais rápida).

## HEAP BINÁRIA

A Heap Binária é um caso à parte da estrutura Heap, pois ela adiciona mais uma propriedade.

### PROPRIEDADES:
1. Se B é um nó filho de A, então chave(A) >= chave(B), no caso de max_heap ou chave(B) >= chave(A) no caso de min_heap. (PROPRIEDADE DA HEAP)
2. A árvore binária deve ser completa ou quase completa. Ou seja, todos os níveis, exceto possivelmente o último, estão completamente preenchidos. Se o último nível não estiver completo, os nós folha deste nível estão completamente preenchidos da esquerda para a direita. (PROPRIEDADE DA HEAP BINÁRIA)

O que diferencia uma heap de uma árvore binária qualquer é a forma pelas quais os elementos são inseridos e removidos da heap. A ideia é inserir os elementos de tal maneira que o elemento de mais alta prioridade esteja sempre localizado na raiz, e a remoção do elemento de mais alta ordem pode ser feita via a remoção da raiz.

## Mais explicação
Para mais informações sobre a implementação, ler o PDF, que está explicado com imagens que ajudam para o entendimento.
