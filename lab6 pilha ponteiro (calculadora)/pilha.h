#ifndef pilha_lib_
#define pilha_lib_

#include <stdlib.h>
#include <stdio.h>

typedef struct no No;
typedef struct no{
    No *prox;
    int valor;
}No;

typedef struct sentinela{
    No *primeiro, *ultimo;
    int qtd;
}Sentinela;

No* iniciaNo(int n);

Sentinela* iniciaSent();

char emPilha(Sentinela *p, No *n);

No* desemPilha(Sentinela *p);

char printaPilha(Sentinela *p);

char freePilha(Sentinela *p);


#endif
