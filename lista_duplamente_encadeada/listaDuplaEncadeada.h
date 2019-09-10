#ifndef LISTADUPLAENCADEADA_H_INCLUDED
#define LISTADUPLAENCADEADA_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>

typedef struct no TNO;
typedef struct lista TLISTA;

void imprime_no(TNO *no);
void imprimir_lista(TLISTA *lista);
TLISTA *criar_lista();
int lista_vazia(TLISTA *lista);
int lista_tamanho(TLISTA *lista);
int inserir_inicio(TLISTA *lista, int valor);
int inserir_final(TLISTA *lista, int valor);
int inserir_posicao(TLISTA *lista, int posicao, int valor);
int remover_inicio(TLISTA *lista);
int remover_final(TLISTA *lista);
int remover_posicao(TLISTA *lista, int posicao);
int remover_valor(TLISTA *lista, int valor);
void pesquisar_valor(TLISTA *lista, int valor);

#endif