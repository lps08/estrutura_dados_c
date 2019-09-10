#ifndef LIVRO_H_INCLUDED
#define LIVRO_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>

typedef struct livro LIVRO;

typedef struct livro{
    char *titulo;
    char *autor;
    char *genero;
    int ano;
}LIVRO;

LIVRO *criar_livro(char *titulo, char *autor, char *genero, int ano);

char livro_obtemGenero(LIVRO *livro);

char livro_obtemAutor(LIVRO *livro);

char livro_obtemTitulo(LIVRO *livro);

int livro_obtemAno(LIVRO *livro);

int livro_verificaNoModernismo(LIVRO *livro);

void imprimir_livro(LIVRO *livro);

void apaga_livro(LIVRO *livro);

#endif