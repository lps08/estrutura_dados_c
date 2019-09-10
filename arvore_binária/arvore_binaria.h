#include <stdio.h>
#include <stdlib.h>


typedef struct arvore ARVORE;

ARVORE *criar_arvore();
int arvore_vazia(ARVORE *arvore);
void imprimir_arvore(ARVORE *arvore);
int inserir_arvore(ARVORE **arvore, int valor);
ARVORE *maiorDireita(ARVORE *arvore);
ARVORE *menorEsquerdo(ARVORE *arvore);
int remover_valor_arvore(ARVORE **arvore, int valor);
ARVORE *buscar_arvore(ARVORE *arvore, int valor);