#ifndef LISTAENCADEADA_H_INCLUDED
#define LISTAENCADEADA_H_INCLUDED

typedef struct lista_encadeada LISTA_ENC;

LISTA_ENC *criarListaEncadeada();
int inserir_item(LISTA_ENC *lista, ITEM *item);
ITEM *recuperar_item(LISTA_ENC *lista, int chave);
void imprimir(LISTA_ENC *lista);
int inserir_item_posicao(LISTA_ENC *lista, ITEM *item, int posicao);
void apagar_item_ListaEnc(LISTA_ENC *lista, int posicao);

#endif