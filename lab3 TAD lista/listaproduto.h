#ifndef LISTAARR_H_
#define LISTAARR_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INICIOARRANJO   1
#define MAXTAM          1000

typedef int Posicao;

typedef struct{ //produto
int codigo;
char nome[30];
float preco;
int quantidade;
} tProduto;

typedef struct{
    int Primeiro, Ultimo;
    tProduto item[MAXTAM];
} tLista;



////////////PRODUTO
//"setters"
void addCodigo(tProduto *produto, int *codigo);
void addNome(tProduto *produto, char *nome);
void addPreco(tProduto *produto, float *preco);
void addQuantidade(tProduto *produto, int *quantidade);

//"getters"
int pegaCodigo(tProduto *produto);
char* pegaNome(tProduto *produto);
float pegaPreco(tProduto *produto);
int pegaQuantidade(tProduto *produto);

///

tProduto criaProduto(int *codigo, char *nome, float *preco, int *quantidade);

void imprimeProduto(tProduto *produto);

////////////LISTA

tLista criaListaVazia(void);

void esvaziaLista(tLista *l);

int estaVazia(tLista *l);

void removeItemIndice(tLista *l, int *indice);

void removeItemCodigo(tLista *l, int *codigo);

void insere(tLista *l, tProduto *produto);

tProduto buscaCodigo(tLista *l, int codigo);

tProduto maisBarato(tLista *l);

int quantidadeItens(tLista *l);


#endif /* LISTAARR_H_ */