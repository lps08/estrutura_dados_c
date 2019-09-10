#include "listaCirc.h"

int main() {
    TLISTA *lista = criar_lista_circ();

    inserir_inicio(lista, 4545);
    inserir_inicio(lista, 3434);
    inserir_inicio(lista, 8686);
    inserir_inicio(lista, 2020);
    inserir_final(lista, 8787);
    inserir_inicio(lista, 6565);
    inserir_meio(lista, 4, 2121); //ver o q esta errado na 4th posição

    printf("%d\n", tamanho_lista(lista));

    imprimir_listCirc(lista);

    /*remover_meio(lista, 3);

    printf("----------------------------\n");

    imprimir_listCirc(lista);

    printf("----------------------------\n");
    if (busca_valor(lista, 8787) != NULL) {
        imprimi_mat(busca_valor(lista, 8787));
    }
    //imprimir_listCirc(lista);
*/
    return 0;
}