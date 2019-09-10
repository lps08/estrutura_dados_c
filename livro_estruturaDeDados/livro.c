#include "livro.h"

LIVRO *criar_livro(char *titulo, char *autor, char *genero, int ano) { //cria um TAD do tipo livro
    LIVRO *itemLivro = (LIVRO *) malloc(sizeof(LIVRO)); //aloca um espaço na memória para o tipo de dado

    itemLivro->titulo = titulo; //inserção dos itens
    itemLivro->autor = autor;
    itemLivro->genero = genero;
    itemLivro->ano = ano;

    return itemLivro;
}

void imprimir_livro(LIVRO *livro) { //imprime o TAD do livro
    printf("Titulo : %s\n", livro->titulo);
    printf("Autor : %s\n", livro->autor);
    printf("Genero : %s\n", livro->genero);
    printf("Ano : %d\n", livro->ano);
}

char livro_obtemGenero(LIVRO *livro) { //retorna o genero dado uma lista que contém o TAD livro
    return *livro->genero;
}

char livro_obtemAutor(LIVRO *livro) {//retorna o autor dado uma lista que contém o TAD livro
    return *livro->autor;
}

char livro_obtemTitulo(LIVRO *livro) {//retorna o título dado uma lista que contém o TAD livro
    return *livro->titulo;
}

int livro_obtemAno(LIVRO *livro) {//retorna o ano dado uma lista que contém o TAD livro
    return livro->ano;
}

int livro_verificaNoModernismo(LIVRO *livro) {//função que verifica se o livro está no periodo do modernismo
    if(livro->ano < 1930) {//caso menor que o ano 1930
        return -1;
    
    }else if((livro->ano >= 1930)&&(livro->ano <= 1945)) { //caso entre 1930 e 1945
        return 0;

    }else {//caso maior que o ano 1945
        return 1;

    }
}

void apaga_livro(LIVRO *livro) {//apaga o TAD livro fornecido a função
    free(livro);
}