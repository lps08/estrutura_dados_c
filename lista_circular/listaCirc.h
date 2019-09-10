#ifndef LISTCIRC_H_INCLUDED
#define LISTCIRC_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct no TNO;
typedef struct lista TLISTA;

void imprimi_mat(TNO *no);
TLISTA *criar_lista_circ();
int tamanho_lista(TLISTA *lista);
int inserir_inicio(TLISTA *lista, int matricula);
int inserir_final(TLISTA *lista, int matricula);
int inserir_meio(TLISTA *lista, int posicao, int matricula);
int remover_inicio(TLISTA *lista);
int remover_final(TLISTA *lista);
int remover_meio(TLISTA *lista, int posicao);
TNO *busca_posicao(TLISTA *lista, int posicao);
TNO *busca_valor(TLISTA *lista, int matricula);
void imprimir_listCirc(TLISTA *lista);

#endif