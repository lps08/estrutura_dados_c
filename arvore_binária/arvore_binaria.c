#include "arvore_binaria.h"

struct arvore { // cria o nó para cada ramificação da arvore
    int valor;  
    struct arvore *esquerda; //ponteiro para a ramificação da esquerda
    struct arvore *direita;  //ponteiro para a ramificação da direita
};

ARVORE *criar_arvore() { //função para criar a arvore
    return NULL; //retorna NULL para o nó da estrutura
}

int arvore_vazia(ARVORE *arvore) { //verifica se a arvore está vazia
    if (arvore == NULL) return 1;
    return 0;
}

void imprimir_arvore(ARVORE *arvore) { //imprime a arvore de forma recursiva
    if (arvore != NULL) {  //se caso a arvore não for nula, imprime o conteúdo dela
        printf("%d\n", arvore->valor); //printa cada nó de acodorco com a função recursiva
        imprimir_arvore(arvore->esquerda);  //printa o nó da esquerda
        imprimir_arvore(arvore->direita);   //print o nó da direita
    }
}

int inserir_arvore(ARVORE **arvore, int valor) { //insere um elemento na arvore
    if (arvore == NULL) return 0; //caso a arvore for nula, retorna 0

    if (*arvore == NULL) {  //Quando chega no nó apropriado e nulo, insere o elemento na arvore
        *arvore = (ARVORE*) malloc(sizeof(ARVORE));
        (*arvore)->valor = valor;
        (*arvore)->esquerda = NULL;
        (*arvore)->direita = NULL;
    }else if (valor <= (*arvore)->valor) inserir_arvore(&(*arvore)->esquerda, valor); //caso o valor seja menor ou igual a valor do nó da esquerda, é feita a chamada da função de forma recursiva para a ramificação da esquerda
    else inserir_arvore(&(*arvore)->direita, valor); //caso o valor seja maior do que da direita, é feita a chamada da função de forma recursiva para a ramificação da direita

    return 1;
}

ARVORE *maiorDireita(ARVORE *arvore) { //retorna o maior nó de forma recursiva
    if (arvore->direita != NULL) { 
        maiorDireita(arvore->direita); //vai em busca da do valor maior na ramificações da direita
    }else {
        return arvore;
    }
}

ARVORE *menorEsquerdo(ARVORE *arvore) { //retorna o menor nó de forma recursiva
    if (arvore->esquerda != NULL) {
        menorEsquerdo(arvore->esquerda); //vai em busca da do valor menor na ramificações da direita
    }else {
        return arvore;
    }
}

int remover_valor_arvore(ARVORE **arvore, int valor) { //remove um nó dado o valor dele
    if (arvore == NULL) return 0; //caso a arvore for nula, retorna 0

    if (valor < (*arvore)->valor) remover_valor_arvore(&(*arvore)->esquerda, valor);  //caso o valor procurado seja menor que o valor do nó atual, irá fazer a busca na ramificação da esquerda por meio da recursividade
    else if (valor > (*arvore)->valor) remover_valor_arvore(&(*arvore)->direita, valor); //caso seja maior, irá buscar na ramificação da direita
    else { //se não for maior nem menor, é o valor buscado

        if ((*arvore)->esquerda == NULL && (*arvore)->direita != NULL) { //caso o nó procurado só tenha valor na ramificação da direita
            ARVORE *naux = *arvore; //nó auxiliar recebendo o nó procurado
            *arvore = (*arvore)->direita; //substituição do nó pelo que está na ramificação da direita
            free(naux);
        
        }else if ((*arvore)->esquerda != NULL && (*arvore)->direita == NULL) { //caso o nó procurado só tenha valor na ramificação da esquerda
            ARVORE *naux = *arvore; //nó auxiliar recebendo o nó procurado
            *arvore = (*arvore)->esquerda; //substituição do nó pelo que está na ramificação da esquerda
            free(naux);
        
        }else if ((*arvore)->esquerda != NULL && (*arvore)->direita != NULL) { //caso ambas das ramificações não forem nulas
            (*arvore)->valor = maiorDireita((*arvore)->esquerda)->valor; //o conteúdo do nó a ser removido é substituido pelo valor maior da ramificação à esquerda
            remover_valor_arvore(&(*arvore)->esquerda, maiorDireita((*arvore)->esquerda)->valor); //o maior nó que foi trocado o valor é então excluido
        }else { //caso o nó não possua ramificação nem na direita nem esquerda
            *arvore = NULL;
        }
    }
    return 1;
}

ARVORE *buscar_arvore(ARVORE *arvore, int valor) {  //faz a busca de um valor na arvore 
    if (arvore == NULL) return NULL;

    if (valor < arvore->valor) buscar_arvore(arvore->esquerda, valor);  //caso o valor for menor que o da raiz, procura na ramificação da esquerda
    else if (valor > arvore->valor) buscar_arvore(arvore->direita, valor); //caso o valor for maior, procura na direita
    else {  //se não for nem maior nem menor, é o numero procurado
        return arvore;
    }
}

