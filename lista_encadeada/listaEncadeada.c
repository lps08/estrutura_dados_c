#include "item.h"
#include "listaEncadeada.h"

typedef struct NO{
    ITEM *item;
    struct NO *proximo;
}NO; 

struct lista_encadeada {//nó ligando cada elemento da lista;
    NO *inicio;
    NO *fim;
    int tamanho;
};

LISTA_ENC *criarListaEncadeada() {
    LISTA_ENC *lista = (LISTA_ENC *) malloc(sizeof(LISTA_ENC));

    if(lista != NULL) {  //verifica se item espaço para criar uma lista, caso sim, cria uma lista vazia;
        lista->inicio = NULL;
        lista->fim = NULL;
        lista->tamanho = 0;
    }

    return lista;
}

int inserir_item(LISTA_ENC *lista, ITEM *item) {
    NO *pnovo = (NO*) malloc(sizeof(NO));

    if(pnovo != NULL){ // verifica se a lista foi criada;
        pnovo->item = item;
        pnovo->proximo = NULL;

        if(lista->inicio == NULL) { //verifica se está vazia;
            lista->inicio = pnovo;
        }else { //se nao estiver vazia, o nó será colocado no fim apontando para o proximo;
            lista->fim->proximo = pnovo;
        }

        lista->fim = pnovo;
        lista->tamanho += 1;

        return 1;
    }

    return 0;
}

ITEM *recuperar_item(LISTA_ENC *lista, int chave) {
    NO *paux = lista->inicio;

    while(paux != NULL) {
        if(paux->item->matricula == chave) {
            return paux->item;
        }
        paux = paux->proximo;
    }

    return NULL;
}

void imprimir(LISTA_ENC *lista) {
    NO *paux = lista->inicio;
    int indice = 0;

    while(paux != NULL) {
        printf("%d\n", indice);
        imprimir_item(paux->item);
        indice += 1;

        paux = paux->proximo;
    }

}

int inserir_item_posicao(LISTA_ENC *lista, ITEM *item, int posicao) {
    NO *pnovo = (NO *) malloc(sizeof(NO));
    NO *panterior = (NO *) malloc(sizeof(NO));

    lista = (LISTA_ENC *) realloc(lista, sizeof(LISTA_ENC));
    int indice=0;

    pnovo->item = item;

    NO *paux = lista->inicio;

    if(posicao < lista->tamanho) { //verifica se a posicao esta contida na lista;
        while(paux != NULL) {
            if(posicao == 0) {
                pnovo->proximo = paux;
                lista->inicio = pnovo;
                lista->tamanho += 1;

                return 1;

            
            }else if(posicao == indice){
                panterior->proximo = pnovo;
                pnovo->proximo = paux;
                lista->tamanho += 1;

                return 1;
               
            }        

            indice += 1;
            panterior = paux;
            paux = paux->proximo;
            
        }

    }else if(posicao >= lista->tamanho) {
        inserir_item(lista, item);

        return 1;
    }

    return 0;
}

void apagar_item_ListaEnc(LISTA_ENC *lista, int posicao) {
    NO *paux = lista->inicio;
    NO *pauxAnterior = NULL;

    int indice=0;

    if(posicao <= lista->tamanho) {
        while(paux != NULL) {
            if(indice == posicao) {
                if(paux == lista->inicio) {
                    lista->inicio = paux->proximo;
                }else if(paux == lista->fim) {
                    lista->fim = pauxAnterior->proximo;
                }else {
                    pauxAnterior->proximo = paux->proximo;
                }

                lista->tamanho -= 1;
                apagar_item(paux->item);
                free(paux);
            }
            indice += 1;
            pauxAnterior = paux;
            paux = paux->proximo;
        }
    }
}