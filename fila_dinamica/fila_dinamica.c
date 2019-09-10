#include "fila_dinamica.h"

struct no {
    int valor;
    struct no *proximo;
};

struct fila {
    TNO *inicio;
    TNO *fim;
    int qntd;  
};

TFILA *criar_fila_dinamica() {
    TFILA *fila = malloc(sizeof(TFILA));
    if (fila == NULL) return 0;

    fila->inicio = NULL;
    fila->fim = NULL;
    fila->qntd = 0;

    return fila;
}

int inserir_lista_dinamica(TFILA *fila, int valor) {
    if (fila == NULL) return 0;

    TNO *nno = malloc(sizeof(TNO));

    nno->valor = valor;

    if (fila->inicio == NULL) {
        fila->inicio = nno;
    }else {
        fila->fim->proximo = nno;
        nno->proximo = NULL;
    }
    
    fila->fim = nno;
    fila->qntd += 1;

    return 1;
}

int remover_fila_dinamica(TFILA *fila) {
    if (fila == NULL) return 0;
    if (fila->fim == NULL) return 0;
    TNO *naux = malloc(sizeof(TNO));

    naux = fila->inicio;

    fila->inicio = fila->inicio->proximo;
    free(naux);

    if (fila->inicio == NULL) fila->fim = NULL;

    return 1;
}

/*pilha guarda o indice do topo
adicionar =  topo+=1;
remover = topp-=1;
 */