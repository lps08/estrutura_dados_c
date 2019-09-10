#include "arvore_binaria.h"

int main() {
    printf("Teste\n\n");

    ARVORE* novaArvore = criar_arvore();

    inserir_arvore(&novaArvore, 11);
    inserir_arvore(&novaArvore, 9);
    inserir_arvore(&novaArvore, 10);
    inserir_arvore(&novaArvore, 12);
    inserir_arvore(&novaArvore, 14);

    printf("%d\n", arvore_vazia(novaArvore));

    printf("\n--------------------------\n\n");

    imprimir_arvore(novaArvore);

    printf("\n--------------------------\n\n");

    remover_valor_arvore(&novaArvore, 9);

    imprimir_arvore(novaArvore);

    printf("\n--------------------------\n\n");

    imprimir_arvore(buscar_arvore(novaArvore, 12));

    return 0;
}