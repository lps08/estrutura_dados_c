#include "lista.h"
#include "livro.h"
#include <string.h>

typedef struct NO{ //estrutura NO que será cada posição da lista
    LIVRO *livro; //estrutura que cada posição irá receber
    struct NO *proximo; //estrutura que apontará para o proximo NO ou ao FIM
}NO;

struct lista { //a estrutura que será a lista em si
    NO *inicio; //representa o inicio da lista
    NO *fim; //representa o final da lista
    int tamanho; //representa o tamamho da lista
};

LISTA *criar_lista() { //função que cria uma lista vazia
    LISTA *lista = malloc(sizeof(LISTA)); //aloca um espaço na memória para a criação da lista

    if(lista != NULL) { //verifica se tem espaço na memória
        lista->inicio = NULL; //inicio recebe null
        lista->fim = NULL; //final recebe null
        lista->tamanho = 0; // tamnho recebe 0, pois a lista está vazia
    }

    return lista;
}

int tamanho_lista(LISTA *lista) { //retorna o tmnho da lista
    return lista->tamanho;
}

int lista_vazia(LISTA *lista) { //verifica se a lista está vazia
    if(lista->inicio == NULL) {
        return 1;
    }
    return 0;    
}

int inserir_livro(LISTA *lista, LIVRO *livro) { //insere o livro na ultima posiçao
    NO *pnovo = (NO *)malloc(sizeof(NO)); //nó q irá receber o novo livro
    
    if(pnovo != NULL) {  //verifica se tem espaço
        pnovo->livro = livro;
        pnovo->proximo = NULL;

        if(lista->inicio == NULL) {  //se a lista estiver vazia, insere no inicio
            lista->inicio = pnovo;

        }else { //caso contrário, insere no final
            lista->fim->proximo = pnovo;
        }

        lista->fim = pnovo;
        lista->tamanho += 1; //incrementa o tamanho em += 1

        return 1;

    }

    return 0;
}

LIVRO *recuperar_livro(LISTA *lista, char *titulo) { //recupera o livro dado um titulo
    NO *paux = malloc(sizeof(NO)); //NO auxiliar que percorrerá a lista

    paux = lista->inicio; //recebe o !=inicio da lista para ser percorrida até o final

    while(paux != NULL) {
        if(strcmp(paux->livro->titulo, titulo) == 0) { //conpara as strings, caso igual, retorna o livro
            return paux->livro;
        }
        
        paux = paux->proximo;
    }

    return 0;
}

void imprimir_lista(LISTA *lista) { //imprime a lista completa;
    NO *paux = malloc(sizeof(NO)); //No auxiliar
    int indice = 0; //Variável que irá contar os índices

    paux = lista->inicio;

    while(paux != NULL) {
        printf("LIVRO N %d\n\n", indice);
        imprimir_livro(paux->livro); //imprime cada livro, a media que a lista está sendo percorrida
        printf("\n\n");

        paux = paux->proximo;    
        indice += 1; //incrementa o indice += 1 para cada posição percorrida
    }

}

int inserir_livro_posicao(LISTA *lista, LIVRO *item, int posicao) { //insere o livor na posição fornecida
    NO *pnovo = (NO *) malloc(sizeof(NO)); //NO auxiliar para percorrer a lista
    NO *panterior = (NO *) malloc(sizeof(NO)); //NO auxiliar que armazena a posição anterior que foi percorrida

    lista = (LISTA *) realloc(lista, sizeof(LISTA));
    int indice=0;//ira contar cada iteração

    pnovo->livro = item; //ponto que receberá o novo livro

    NO *paux = lista->inicio;

    if(posicao < lista->tamanho) { //verifica se a posicao esta contida na lista  e menor;
        while(paux != NULL) {
            if(posicao == 0) { //condição caso a posição fornecida for igual a 0
                pnovo->proximo = paux;
                lista->inicio = pnovo;
                lista->tamanho += 1;

                return 1; //retorno para parar o loop caso a condição anterior for verdadeira

            
            }else if(posicao == indice){ //caso posição estiver pelo meioe for igual a iteração percorrida no mon
                panterior->proximo = pnovo; //a posição atual recebe o livro novo
                pnovo->proximo = paux; //e o ponto atual erá ser movido para a próxima
                lista->tamanho += 1; //lista incrementa += 1

                return 1;
               
            }        

            indice += 1;
            panterior = paux; //variável recebendo a posicão atual que se tornará a anterior na proxima iteração
            paux = paux->proximo; //variável sendo passada o proximo nó a ser percorrido
            
        }

    }else if(posicao >= lista->tamanho) { //caso a a posição for a ultima ou maior
        inserir_livro(lista, item); //o ponto é inserido por maio da função já existente

        return 1;
    }

    return 0;
}

int apagar_livro_ListaEnc(LISTA *lista, int posicao) {//apaga o livro dada uma posição
    NO *paux = lista->inicio; //NO para percorrer a lista
    NO *pauxAnterior = NULL; //variável que guarda uma posição anterior

    int indice=0; //var que conta os índices

    if(posicao <= lista->tamanho) { //verifica se a posição fornecida contém na lista
        while(paux != NULL) {
            if(indice == posicao) { //caso a posição for a percorrida
                if(paux == lista->inicio) { //verifica se está no inicio
                    lista->inicio = paux->proximo;
                }else if(paux == lista->fim) { //verifica se está no fim
                    lista->fim = pauxAnterior->proximo;
                }else { //caso n esteja nem fim nem no inicio
                    pauxAnterior->proximo = paux->proximo;
                }

                lista->tamanho -= 1;
                apaga_livro(paux->livro); //função que libera o espaço armazenado no livro
                free(paux);//função que libera o nó a ser apagado

                return 1;
            }
            indice += 1;
            pauxAnterior = paux;
            paux = paux->proximo;
        }
    return 0;
    }
}

void liberar_lista_comple(LISTA *lista) {
    NO *paux;
    NO *paux2;

    while(paux != NULL) {
        paux2 = paux->proximo;
        free(paux);
        paux = paux2;
    }
}

int buscar(LISTA *lista, char *titulo) {
    NO *paux;
    int indice = 0;
    
    while(paux != NULL) {
        if(strcmp(paux->livro->titulo, titulo) == 0) {
            return indice;
        }
        paux = paux->proximo;
        indice += 1;
    }
}

int troca_posicao(LISTA *lista, int menor_indice, int maior_indice) { //troca a posição dado dois índices
    NO *paux = malloc(sizeof(NO));
    LIVRO *guardaP1 = malloc(sizeof(LIVRO)); //guarda o primeiro livro a ser trocado de posição
    LIVRO *guardaP2 = malloc(sizeof(LIVRO)); //guarda o segundo livro

    paux = lista->inicio;
    int indice = 0;

    while(paux != NULL) { //percorre a primeira vez para guardar os itens a serem trocados

        if(menor_indice == indice) { //guarda o livro de menor indice
            guardaP1 = paux->livro;
        
        }else if(maior_indice == indice) { //guarda o livro de maior indice
            guardaP2 = paux->livro;
        }
        
        paux = paux->proximo;
        indice += 1;
    }

    paux = lista->inicio; //paux volta ao inicio para percorrer de novo
    indice = 0; //indice retornado para a primeira posição

    while(paux != NULL) { //percorrendo para ser feita a troca de posição
        
        if(menor_indice == indice) { //troca a primeira posição com a segunda
            paux->livro = guardaP2;
        
        } 
        
        if(maior_indice == indice) { //troca a segunda com a primeira
            paux->livro = guardaP1;

        }

        paux = paux->proximo;
        indice += 1;
    }
}


void ordenar_alf(LISTA *lista) { //função que ordena a lista por titulo
    NO *paux1 = malloc(sizeof(NO)); //paux para percorrer a lista
    NO *paux2 = malloc(sizeof(NO)); //paux para percorrer a lista

    paux1 = lista->inicio; //recebe inicio
    paux2 = lista->inicio; //recebe inicio

    int indice1 = 0; //indice que representado o percorrimento da paux1
    int indice2 = 0; //indice que representado o percorrimento da paux2

    while(paux1 != NULL) { //percorre a lista para cada posição ser comparada com a lista toda

        while(paux2 != NULL) {
            if(indice1 <= indice2) {
                if(strcmp(paux1->livro->titulo, paux2->livro->titulo) > 0) {// compara a string de cada posição com a lista toda
                    troca_posicao(lista , indice1, indice2); //se a string 1 for maior que segunda, é chamada a função de troca de posição para efetuar o ordenamento
                }
            }
            
            paux2 = paux2->proximo;
            indice2 += 1;
        }

        paux1 = paux1->proximo;
        indice1 += 1;
        indice2 = 0;
    }
}