#ifndef ArvBin_H_
#define ArvBin_H_
#include <stdio.h>
#include <stdlib.h>

/**
Contem um inteiro e dois apontadores (esquerda/direita)
*/
typedef struct NO NO;
typedef struct NO{
    int info;
    NO *esq, *dir;
} NO;

/**
Inicializa a árvore e deixa a raiz NULL
retorna: Raiz alocada e apontada para NULL
*/
NO* cria_No(int valor);


/**
Insere 'valor' na árvore utilizando a regra que o filho esquerdo é menor que a raiz que é menor o filho direito.

Retorna: 1 em caso de sucesso. 
*/
int insere_No(NO** raiz, int valor);

/**
Pesquisa um valor a partir da árvore raiz
retorna 1 se encontrar o valor e 0 caso não encontre
*/
int consulta_No(NO *raiz, int valor);

/**
Verifica se a árvore está vazia
*/
int estaVazia_No(NO *raiz);

/* 
Conta o número de nós não-folha de uma árvore binária 
retorna: Numero de nós não folha
*/
int totalNaoFolha_No(NO *raiz);

/** 
Conta o número de folhas de uma árvore binária.
retorna: Numero de nós folhas
*/
int totalFolha_No(NO *raiz);

/*conta o número de nós de uma árvore binária. */
int totalNO_No(NO *raiz);

/** Imprime em pre-ordem */ 
void preOrdem_No(NO *raiz);

/** Imprime em-ordem */ 
void emOrdem_No(NO *raiz);

/** Imprime em pós-ordem */ 
void posOrdem_No(NO *raiz);


/**
Libera a árvore binária da memória
*/
void libera_No(NO *raiz);

#endif
