#ifndef LISTAPROD_H_
#define LISTAPROD_H_

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
/*pre-condição: char tem até 30 caracteres incluindo o '\0'*/
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

void esvaziaLista(tLista *lista);

int estaVazia(tLista *lista);

void imprimeLista(tLista *lista);

void removeItemIndice(tLista *lista, int *indice);

void removeItemCodigo(tLista *lista, int *codigo);
/*pre-condição: produto cabe na lista lista (não está lotada)*/
void insere(tLista *lista, tProduto *produto);

tProduto buscaCodigo(tLista *lista, int *codigo);

char existeNaLista(tLista *lista, int *codigo);

tProduto maisBarato(tLista *lista);

int quantidadeItens(tLista *lista);


#endif /* LISTAPROD_H_ */