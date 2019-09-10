#include "listaDuplaEncadeada.h"

struct no { //estrutura que representa cada no da lista
    int valor; //tipo de dado que irá campor a lista
    struct no *proximo; //no que aponta para o proximo
    struct no *anterior; //no que aponta para o anterior
};

struct lista { //estrutura que representa a lista
    TNO *inicio; //no que define o primeiro elemento da lista 
    TNO *fim;  //no que define o ultimo elemento da lista
};

void imprime_no(TNO *no) {  //imprime o valor armazenado no nó
    printf("Valor: %d\n\n", no->valor);
}

void imprimir_lista(TLISTA *lista) { //imprime a lista completa
    TNO *paux = lista->inicio; //nó auxiliar que irá percorrer a lista
    int indice = 0; //variavel que representará os indices da lista
    while(paux != NULL) {  //laço que percorre a lista
        printf("\n----------------------------\n");
        printf("Posicao n: %d\n", indice);
        imprime_no(paux);

        indice += 1;
        paux = paux->proximo; //incremento que passa para o proximo elemento da lista
    }
}
TLISTA *criar_lista() { //função que aloca e cria a lista
    TLISTA *lista = malloc(sizeof(TLISTA)); //aloca o espaço na memoria para criar a lista
    if (lista == NULL) return NULL; //caso a operação de alocar não for concluida, retorna null

    lista->inicio = NULL; //inicio recebe NULL
    lista->fim = NULL; //fim recebe null, que representa a lista vazia

    return lista;
}

int lista_vazia(TLISTA *lista) { //retorna 1 caso a lista esteja vazia, e 0 caso não
    if (lista->inicio == NULL) return 1;

    return 0;
}

int lista_tamanho(TLISTA *lista) { //retorna o tamanho da lista
    TNO *paux = lista->inicio;
    int tamanho = 0;

    while(paux != NULL) {
        tamanho += 1;  //incrementa +1 para cada elemento percorrido
        paux = paux->proximo;
    }
    return tamanho;
}

int inserir_inicio(TLISTA *lista, int valor) { //insere um valor na primeira posicao
    if (lista == NULL) return 0; //caso a lista não esteja alocada
    TNO *pnovo = malloc(sizeof(TNO)); //cria um novo nó
    if (pnovo == NULL) return 0; //caso não seja possivel alocar o novo nó

    pnovo->valor = valor; //o novo recebendo o novo valor

    pnovo->proximo = lista->inicio;  //novo no entrando na primeira posicao
    pnovo->anterior = NULL;

    if(lista->inicio == NULL) lista->fim = pnovo; //caso a lista esteja vazia
    else lista->inicio->anterior = pnovo; //caso não esteja vazia

    lista->inicio = pnovo; //o novo nó recebendo a primeira posicao

    return 1;
}

int inserir_final(TLISTA *lista, int valor) {
    if(lista == NULL) return 0;
    TNO *pnovo = malloc(sizeof(TNO));
    if (pnovo == NULL) return 0;

    if (lista->inicio == NULL) inserir_inicio(lista, valor); //caso a lista esteja vazia

    pnovo->valor = valor; //novo ponto recebendo o novo valor

    lista->fim->proximo = pnovo; //o novo nó sendo inserido no final da lista
    pnovo->anterior = lista->fim; //o ponteiro anterior do novo nó apontando para o ultimo da lista
    lista->fim = pnovo; //o lista->fim recebendo o novo nó
    pnovo->proximo = NULL; //ponteiro proximo do novo nó apontando para null

    return 1;
}

int inserir_posicao(TLISTA *lista, int posicao, int valor) {
    if (lista == NULL) return 0;//caso a lista não esteja criada
    TNO *pnovo = malloc(sizeof(TNO));
    if (pnovo == NULL) return 0; //caso o novo nó não for alocado
    TNO *paux = malloc(sizeof(TNO));
    if(paux == NULL) return 0; //caso o nó auxiliar não for alocado

    int indice = 0;

    pnovo->valor = valor; //recebendo o novo valor
    paux = lista->inicio; //o nó auxiliar recebendo a primeira posicao da lista
    
    while (paux != NULL) {  //percorre a lista
        if (indice == posicao) { //se o indice da lista seja igual a posicao procurada
            if (posicao == 0) inserir_inicio(lista, valor);//se a posicao for primeira, chama a função ja criada
            else { //caso não for a primeira
                paux->anterior->proximo = pnovo; //a posicao anterior->proximo aponta para o novo nó a ser inserido
                pnovo->anterior = paux->anterior; //novo nó->anterior apontando para o anterior da posicao atual
                pnovo->proximo = paux; //novo nó->proximo apontando para a posicao atual
                paux->anterior = pnovo; //nó da posicao atual apontando para o novo nó a ser inserido na posicao dele
            }

            return 1;
        }

        paux = paux->proximo;
        indice += 1;
    }
    printf("Posicao não encontrada\n\n"); //caso a posicao não seja encontrada
    return 0;
}

int remover_inicio(TLISTA *lista) {
    if (lista == NULL) return 0;
    TNO *paux = malloc(sizeof(TNO));
    if (paux == NULL) return 0;

    paux = lista->inicio;

    if (lista->inicio->proximo == NULL) { //caso a lista só tenha um nó, após ser excluida, ele fica vazia
        free(paux);
        lista->inicio = NULL;
        lista->fim = NULL;

    }else { //caso tenha mais que um elemento
        lista->inicio = paux->proximo; //o inicio recebe o proximo dele
        lista->inicio->anterior = NULL; //o proximo->anteriro aponta para null
        free(paux); //libera o primeiro nó
    }

    return 1;
}

int remover_final(TLISTA *lista) {
    if (lista == NULL) return 0;
    TNO *paux = malloc(sizeof(TNO));
    if (paux == NULL) return 0;

    paux = lista->fim; //nó auxiliar recebendo a ultima posicao para ser liberada

    if (lista->inicio->proximo == NULL) { //caso a lista só tenha 1 nó, a mesma ficará vazia
        free(paux);
        lista->inicio = NULL;
        lista->fim = NULL;

    }else { //caso tenha mais que 1 nó
        lista->fim = paux->anterior; //o fim recebe a posicao anterior
        lista->fim->proximo = NULL; //a posicao anterior que foi recebida pelo fim agora o proximo dele aponta para null
        free(paux); //libera a ultima posicao
    }

    return 1;
}

int remover_posicao(TLISTA *lista, int posicao) {
    if (lista == NULL) return 0;
    TNO *paux = malloc(sizeof(TNO));
    if (paux == NULL) return 0;

    int indice = 0;
    paux = lista->inicio;

    while (paux != NULL) {
        if (indice == posicao) { //se o indice percorrido for igual a posicao buscada
            if (posicao == 0) remover_inicio(lista); //caso seja a primeira posicao, chama função ja criada
            else if (lista_tamanho(lista) - 1 == posicao) remover_final(lista); //caso seja a ultima posicao, tbm chama a função ja criada
            else { //se não for nem a primeira nem a ultima
                paux->anterior->proximo = paux->proximo; //o nó anterior->proximo aponta para o proximo da posicao atual
                paux->anterior = paux->proximo->anterior; //nó anterior recebe o nó auxiliar->proximo anterior, para remover a ligação com o nó a ser removido
                free(paux); //libera o nó desejado
            }
            
            return 1;
        }

        paux = paux->proximo;
        indice += 1;
    }
}

int remover_valor(TLISTA *lista, int valor) {
    if (lista == NULL) return 0;
    TNO *paux = malloc(sizeof(TNO));
    if (paux == NULL) return 0;

    paux = lista->inicio;
    int indice = 0;

    while (paux != NULL) {
        if (paux->valor == valor) { //caso o valor do nó percorrido seja igual ao valor buscado
            remover_posicao(lista, indice); //chama a função já criada para remover o valor buscado

            return 1;
        }

        paux = paux->proximo;
        indice += 1;
    }
}

void pesquisar_valor(TLISTA *lista, int valor) { //retorna impresso o valor buscado, juntamente com seu indice na lista
    TNO *paux = malloc(sizeof(TNO));
    int indice = 0;
    paux = lista->inicio;

    while (paux != NULL) { 
        if (paux->valor == valor) { //caso o valor buscada for igual ao valor da posicao percorrida
            printf("\n----------------------------\n");
            printf("Indice: %d\n", indice);
            imprime_no(paux);
            printf("----------------------------\n");
        }
        paux = paux->proximo;
        indice += 1;
    }
}