#include "item.h"
#include "listaEncadeada.h"

int main() {
  printf("Hello World\n");

  LISTA_ENC *listaNova = criarListaEncadeada();

  ITEM *aluno;
  ITEM *aluno2;
  ITEM *aluno3;
  ITEM *aluno4;
  
  aluno = criar_item(10,15,9,7);
  inserir_item(listaNova, aluno);

  aluno2 = criar_item(5,15,9,7);
  inserir_item(listaNova, aluno2);

  aluno3 = criar_item(2,15,9,7);
  inserir_item(listaNova, aluno3);

  aluno4 = criar_item(3,15,9,7);

  //imprimir_item(recuperar_item(listaNova, 2));

  inserir_item_posicao(listaNova, aluno4, 50);

  imprimir(listaNova);

  apagar_item_ListaEnc(listaNova, 0);
  
  imprimir(listaNova);
  /*
  aluno = criar_item(2,15,9,7);
  inserir_ordenado(listaNova, aluno);

  printf("\nBusca elemento 10");

  imprimir_item(busca_binaria(listaNova,10));*/
 
  return 0;
}