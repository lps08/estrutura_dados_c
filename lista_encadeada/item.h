#ifndef ITEM_H
#define ITEM_H

#include <stdlib.h>
#include <stdio.h>

typedef struct item{
  int matricula;
  int idade;
  float nota1;
  float nota2;
  //char nome[20];
} ITEM;

ITEM *criar_item(int matricula, int idade, float nota1, float nota2);
void apagar_item(ITEM *item);
void imprimir_item(ITEM *item);

#endif