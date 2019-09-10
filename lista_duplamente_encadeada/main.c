#include "listaDuplaEncadeada.h"

int main() {
    TLISTA *novalista = NULL;
    int opcao;
    int novoValor;
    int posicao;
    int valor;

    do {
        printf("Escolha a opcao: \n");
        printf("1 - criar lista\n");
        printf("2 - verficar se esta vazia\n");
        printf("3 - verificar tamanho da lista\n");
        printf("4 - Imprimir lista\n");
        printf("5 - Inserir no inicio\n");
        printf("6 - Inserir no final\n");
        printf("7 - Inserir dada uma posicao\n");
        printf("8 - Remover inicio\n");
        printf("9 - Remover final\n");
        printf("10 - Remover dado um valor\n");
        printf("11 - pesquisar dado um valor\n");
        printf("0 - sair\n");
        printf("--> ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (novalista != NULL) printf("\n\nJa existe\n\n");
                else {
                    novalista = criar_lista();
                    printf("Lista criada\n\n");
                }
                break;
            case 2:
                if (lista_vazia(novalista) == 1) printf("\n\nLista vazia\n\n");
                else {
                    printf("Nao esta vazia\n\n");
                }
                break;
            case 3:
                printf("Tamanho: %d\n\n", lista_tamanho(novalista));
                break;
            case 4:
                imprimir_lista(novalista);
                break;
            case 5:
                printf("Inserira o novo valor no inicio: ");
                scanf("%d", &novoValor);
                if (inserir_inicio(novalista, novoValor) == 1) printf("\n\nInserido com sucesso\n\n");
                else printf("Erro na operacao\n\n");

                break;
            case 6:
                printf("Insira o novo valor no final: ");
                scanf("%d", &novoValor);
                if (inserir_final(novalista, novoValor) == 1) printf("\n\nInserido com sucesso\n\n");
                else printf("Erro na operacao\n\n");
                
                break;
            case 7:
                printf("Insira o novo valor: ");
                scanf("%d", &novoValor);
                printf("Posicao do novo valor: ");
                scanf("%d", &posicao);
                if (inserir_posicao(novalista, posicao, novoValor) == 1) printf("\n\nInserido com sucesso\n\n");

                break;
            case 8:
                if (remover_inicio(novalista) == 1) printf("\n\nRemovido com sucesso\n\n");
                else printf("\n\nErro na operacao\n\n");
                break;
            case 9:
                if (remover_final(novalista) == 1) printf("\n\nRemovido com sucesso\n\n");
                else printf("\n\nErro na operacao\n\n");
                break;
            case 10:
                printf("\n\nPosicao a ser removida: ");
                scanf("%d", &posicao);
                if (remover_posicao(novalista, posicao) == 1) printf("\n\nRemovido com sucesso\n\n");
                break;
            case 11:
                printf("\n\nValor a ser buscado: ");
                scanf("%d", &valor);
                pesquisar_valor(novalista, valor);
                break;
            case 0:
                break;
            
            default: printf("\n\nOpcao invalida\n\n");
        }

    } while (opcao != 0);

    return 0;
}