#include "item.h"

ITEM *criar_item(int matricula, int idade, float nota1, float nota2){
  ITEM *itemAluno = (ITEM *) malloc(sizeof(ITEM));
  itemAluno->matricula = matricula;
  itemAluno->idade = idade;
  itemAluno->nota1 = nota1;
  itemAluno->nota2 = nota2;
   return itemAluno;
}
void apagar_item(ITEM *item){
  free(item);
}
void imprimir_item(ITEM *item){
  printf("Matricula: %d\n", item->matricula);
  printf("Idade: %d\n", item->idade);
  printf("nota1: %f\n", item->nota1);
  printf("nota2: %f\n\n\n", item->nota2);
}