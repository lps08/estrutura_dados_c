#include <stdio.h>
#include <stdlib.h>

typedef struct no NO;
typedef struct pilha PILHA;

PILHA *criar_pilha_dinamica();
int inseiri_valor_pilha_dinamica(PILHA *pilha, int valor);
int remover_valor_pilha_dinamica(PILHA *pilha);
void topo_pilha_dinamica(PILHA *pilha);
int tamanho_pilha_dinamica(PILHA *pilha);
int exterminar_pilha_dinamica(PILHA *pilha);
int pilha_dinamica_vazia(PILHA *pilha);
void imprimir_pilha_dinamica(PILHA *pilha);