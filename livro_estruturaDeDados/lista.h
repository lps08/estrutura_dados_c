#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "livro.h"

typedef struct lista LISTA;

LISTA *criar_lista();
int tamanho_lista(LISTA *lista);
int lista_vazia(LISTA *lista);
int inserir_livro(LISTA *lista, LIVRO *livro);
LIVRO *recuperar_livro(LISTA *lista, char *titulo);
void imprimir_lista(LISTA *lista);
int inserir_livro_posicao(LISTA *lista, LIVRO *livro, int posicao);
int apagar_livro_ListaEnc(LISTA *lista, int posicao);
int troca_posicao(LISTA *lista, int menor_indice, int maior_indice);
void ordenar_alf(LISTA *lista);
void liberar_lista_comple(LISTA *lista);
int buscar(LISTA *lista, char *titulo);

#endif