#include "livro.h"
#include "lista.h"

int main() {

    printf("heelo world\n");

    LISTA *novaLista = criar_lista();

    LIVRO *novoLivro1;
    LIVRO *novoLivro2;
    LIVRO *novoLivro3;
    LIVRO *novoLivro4;

    novoLivro1 = criar_livro("olb", "nenhum", "masculina", 1900); 
    inserir_livro(novaLista, novoLivro1);
    novoLivro2 = criar_livro("ola", "nenhum", "masculina", 1900); 
    inserir_livro(novaLista, novoLivro2);
    novoLivro3 = criar_livro("olc", "nenhum", "masculina", 1900);
    inserir_livro(novaLista, novoLivro3);   

    novoLivro4 = criar_livro("ole", "tralha", "mascs", 1901);

    //inserir_livro_posicao(novaLista, novoLivro4, 2);

    imprimir_lista(novaLista);

    printf("----------------------------------------------\n");

    ordenar_alf(novaLista);

    imprimir_lista(novaLista);

    return 0;
}