#include "pilha_dinamica.h"

int main() {
    printf("Teste\n\n");

    PILHA *pilha = criar_pilha_dinamica();

    for(int i=0; i<=4; i++) inseiri_valor_pilha_dinamica(pilha, i);

    imprimir_pilha_dinamica(pilha);

    printf("%d\n\n", tamanho_pilha_dinamica(pilha));

    printf("%d\n\n", pilha_dinamica_vazia(pilha));

    topo_pilha_dinamica(pilha);

    return 0;
}