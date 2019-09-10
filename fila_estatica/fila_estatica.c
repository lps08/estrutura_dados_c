#include "fila_estatica.h"

struct filaEstatica {
    int inicio;
    int final;
    int qntd;
    int vetor[100];
};

TFILA *criar_fila_estatica() {
    TFILA *fila = malloc(sizeof(TFILA));
    if (fila == NULL) return NULL;

    fila->inicio = 0;
    fila->final = 0;
    fila->qntd = 0;

    return fila;
}

int inserir_fila_estatica(TFILA *fila, int valor) {
    if (fila == NULL) return 0;
    
    if (fila->qntd == 100) return 0;

    fila->vetor[fila->final] = valor;

    fila->final = (fila->final + 1) % 100;
    fila->qntd += 1;

    return 1;
}

int remover_fila_estatica(TFILA *fila) {
    if (fila == NULL) return 0;

    if (fila->qntd == 0) return 0;

    fila->inicio  = (fila->final + 1) % 100;
    fila->qntd -= 1;

    return 1;
}