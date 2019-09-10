#ifndef FILA_ESTATICA_H_INCLUDED
#define FILA_ESTATICA_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>

typedef struct filaEstatica TFILA;
TFILA *criar_fila_estatica();
int remover_fila_estatica(TFILA *fila);

#endif