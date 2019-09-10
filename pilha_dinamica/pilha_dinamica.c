#include "pilha_dinamica.h"

struct no {
    int valor;
    struct no *proximo;
};

struct pilha {
    NO *topo;
    int tamanho;
};

PILHA *criar_pilha_dinamica() {
    PILHA *pilha = malloc(sizeof(PILHA));

    if (pilha == NULL) return 0;

    pilha->topo = NULL;
    pilha->tamanho = 0;

    return pilha;
}

int inseiri_valor_pilha_dinamica(PILHA *pilha, int valor) {
    if (pilha == NULL) return 0;
    NO *nno = malloc(sizeof(NO));
    nno->valor = valor;
    
    if (pilha->topo == NULL) {
        pilha->topo = nno;
        pilha->topo->proximo = NULL;
    
    }else {
        nno->proximo = pilha->topo;
        pilha->topo = nno;
    }

    pilha->tamanho += 1;

    return 1;
}

int remover_valor_pilha_dinamica(PILHA *pilha) {
    if (pilha == NULL) return 0;
    NO *naux = malloc(sizeof(NO));

    naux = pilha->topo;

    if(pilha->topo->proximo == NULL) pilha->topo = NULL;

    pilha->topo = naux->proximo;
    pilha->tamanho -= 1;

    free(naux);

    return 1;
}

void topo_pilha_dinamica(PILHA *pilha) {
    if (pilha->topo == NULL) printf("Lista vazia\n\n");
    else {
        printf("-------------------\n");
        printf("Valor: %d\n\n", pilha->topo->valor);
    }

}

int tamanho_pilha_dinamica(PILHA *pilha) {
    return pilha->tamanho;
}

int exterminar_pilha_dinamica(PILHA *pilha) {
    if (pilha == NULL) return 0;

    for(int i=0; i<=pilha->tamanho; i++) remover_valor_pilha_dinamica(pilha);

    free(pilha);

    return 1;

}

int pilha_dinamica_vazia(PILHA *pilha) {
    if (pilha->topo == NULL) return 1;

    return 0;
}

void imprimir_pilha_dinamica(PILHA *pilha) {
    NO *naux = malloc(sizeof(NO));
    int indice = 0;

    naux = pilha->topo;

    while(naux != NULL) {
        printf("-------------------\n");
        printf("Indice: %d\n", indice);
        printf("Valor: %d\n\n", naux->valor);

        naux = naux->proximo;
        indice += 1;
    }
}