#include "listaCirc.h"

struct no {
    int matricula; //No que irão compor a lista
    struct no *prox;
};

struct lista { //estrutura que representa a lista circular
    TNO *inicio;
};

void imprimi_mat(TNO *no) {  //imprime conteudo do nó
    printf("Matricula: %d\n\n", no->matricula);
}

TLISTA *criar_lista_circ() { //cria a lista circular
    TLISTA *lista = malloc(sizeof(TLISTA));

    if (lista == NULL) return NULL; //caso não conseguir criar a lista

    lista->inicio = NULL;

    return lista;
}

int tamanho_lista(TLISTA *lista) { //retorna o tamanho da lista
    TNO *paux = malloc(sizeof(TNO)); //nó auxiliar
    paux = lista->inicio;
    int tamanho = 0;

    while (paux->prox != lista->inicio) { //percorre a lista circular e o paux sai como a ultima posição
        tamanho += 1;
        paux = paux->prox;
    }

    return tamanho;
}

int inserir_inicio(TLISTA *lista, int matricula) { //insere no inicio da lista circular
    if (lista == NULL) return 0; //caso lista for NULL, cancela tudo

    TNO *pnovo = malloc(sizeof(TNO)); //criação do novo nó
    pnovo->matricula = matricula; //novo nó recebendo os novos dados

    if (lista->inicio == NULL) { //caso a lista for vazia, os dados são inseridos no na lista->inicio
        lista->inicio = pnovo;
        pnovo->prox = pnovo; //aponta para ele msm, pois representa a lista ligada
    
    }else { //caso a lista não esteja vazia
        TNO *paux = malloc(sizeof(TNO)); //nó auxiliar

        paux = lista->inicio; //no auxiliar recebendo o inicio da lista

        while (paux->prox != lista->inicio) paux = paux->prox; //percorrendo a lista

        paux->prox = pnovo; //ligando o final da lista com o novo nó
        pnovo->prox = lista->inicio; //colocando como o próximo do novo nó, o nó: lista->inicio
        lista->inicio = pnovo; //colocando o novo nó na lista->inicio
    }

    return 1;
}

int inserir_final(TLISTA *lista, int matricula) { //insere no final da lista
    if (lista == NULL) return 0;

    if(lista->inicio == NULL) { //caso a lista estiver vazia, é feita a chamada da função insere inicio
        inserir_inicio(lista, matricula);
    
    }else { //caso n esteja vazia
        TNO *paux = malloc(sizeof(TNO));
        TNO *pnovo = malloc(sizeof(TNO));
        paux = lista->inicio;
        pnovo->matricula = matricula;

        while (paux->prox != lista->inicio) paux = paux->prox;

        paux->prox = pnovo; //novo nó sendo inserido na ultima posição
        pnovo->prox = lista->inicio; //novo nó tendo como proximo o inicio da lista
    }

    return 1;
}

int inserir_meio(TLISTA *lista, int posicao, int matricula) { //insere por posição na lista
    if (lista == NULL) return 0;
    TNO *paux = malloc(sizeof(TNO)); //no auxiliar
    TNO *pauxAnt = malloc(sizeof(TNO)); //nó que será o anterior do auxiliar
    TNO *pnovo = malloc(sizeof(TNO)); //novo nó
    paux = lista->inicio; 
    pnovo->matricula = matricula;
    int indice = 0; //variável que representará o indice da lista

    while(paux->prox != lista->inicio) {
        if(indice == posicao) { //caso o indice for igual a posição desejada
            if (posicao == 0) inserir_inicio(lista, matricula); //se a posição for a inicial, é chamada a função insere inicio
            else {
                pauxAnt->prox = pnovo; //nó anterior->proximo sendo apontado para o o novo nó
                pnovo->prox = paux; //novo nó apontando para o auxiliar
            }

            return 1;
        }

        pauxAnt = paux;
        paux = paux->prox;
        indice += 1;
        if (tamanho_lista(lista) == indice) { //caso a posição da lista for a ultima, chama a função insere final. Teste feito depois, porque quando o nó está na ultima posição ele sai do laço de repetição
            inserir_final(lista, matricula);
            return 1;
        }else if(posicao > tamanho_lista(lista)) printf("Posicao nao encontrada\n\n"); //caso a posição n for encontrada
    }
    return 0;
}

int remover_inicio(TLISTA *lista) {
    if (lista == NULL) return 0;
    TNO *paux = malloc(sizeof(TNO)); //no auxiliar
    TNO *pauxExcluir = malloc(sizeof(TNO)); //nó que armazanará o nó a ser excluido
    paux = lista->inicio;

    while (paux->prox != lista->inicio) paux = paux->prox;
    
    pauxExcluir = paux->prox; //nó recendo o que será excluido
    paux->prox = paux->prox->prox; //pulando o nó que será excluido
    lista->inicio = paux->prox; //inicio recebendo o proximo nó do que foi excluido
    free(pauxExcluir);

    return 1;
}

int remover_final(TLISTA *lista) {
    if (lista == NULL) return 0;
    TNO *paux = malloc(sizeof(TNO)); //nó auxilliar
    TNO *pauxAnt = malloc(sizeof(TNO)); //nó que armazenará o anterior do auxiliar
    paux = lista->inicio;

    while (paux->prox != lista->inicio) {
        pauxAnt = paux;
        paux = paux->prox;
    }

    pauxAnt->prox = paux->prox; //pulando o nó a ser excluido
    free(paux);

    return 1;
}

int remover_meio(TLISTA *lista, int posicao) {
    if (lista == NULL) return 0;
    TNO *paux = malloc(sizeof(TNO)); //nó auxiliar
    TNO *pauxAnt = malloc(sizeof(TNO)); //nó que será o anterior do auxiliar
    int indice = 0;
    paux = lista->inicio;

    while (paux->prox != lista->inicio) {
        if(indice == posicao) { //caso a posição for a desejada
            if (posicao == 0) remover_inicio(lista); //se posição for a do inico, chama a função ja desenvolvida
            else {
                pauxAnt->prox = paux->prox; //pulando o nó a ser excluido
                free(paux);
            }
            return 1;
        }

        pauxAnt = paux;
        paux = paux->prox;
        indice += 1;
        if (tamanho_lista(lista) == posicao) { //caso a posição da lista for a ultima, chama a função insere final. Teste feito depois, porque quando o nó está na ultima posição ele sai do laço de repetição
            remover_final(lista);
            return 1;
        }else if(posicao > tamanho_lista(lista)) printf("Posicao nao encontrada\n\n"); //caso a posicao n for encontrada
    }
}

TNO *busca_posicao(TLISTA *lista, int posicao) { //retorna a posicao dada um indice
    if (lista == NULL) return NULL;
    TNO *paux = malloc(sizeof(TNO)); //no auxiliar
    int indice = 0;
    paux = lista->inicio;

    while (paux->prox != lista->inicio) {
        if (indice == posicao) return paux; //caso a posicao for a desejada, retorna o nó

        paux = paux->prox;
        indice += 1;
    }
    if (tamanho_lista(lista) == posicao) { //caso a posição for a ultima
        return paux;
    }else if(posicao > tamanho_lista(lista)) printf("Posicao nao encontrada\n\n"); //caso a posicao n for encontrada
}

TNO *busca_valor(TLISTA *lista, int matricula) { //busca pelo valor contido no nó
    if (lista == NULL) return NULL;
    TNO *paux = malloc(sizeof(TNO));
    paux = lista->inicio;

    while (paux->prox != lista->inicio) {
        if (paux->matricula == matricula) return paux; //caso o valor for igual ao requerido, retorna o valor

        paux = paux->prox;
    }
    if (paux->matricula == matricula) return paux; //caso for a ultima
    else { //se n for encontrado
        printf("Valor nao encontrado\n\n");
        return NULL;
    }
}

void imprimir_listCirc(TLISTA *lista) {
    TNO *paux = malloc(sizeof(TNO));
    int indice=0;
    paux = lista->inicio;

    do {
        imprimi_mat(paux);
        indice += 1;
        paux = paux->prox;
    }while (paux->prox != lista->inicio->prox); //maneira para imprimir a ultima posição
}