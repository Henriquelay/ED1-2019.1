#include "pilha.h"


No* iniciaNo(int n){
    No *novo = (No*) malloc(sizeof(No));
    novo->valor = n;
    novo->prox = NULL;
    return novo;
}

Sentinela* iniciaSent(){
    Sentinela *nova = (Sentinela*) malloc(sizeof(Sentinela));
    nova->qtd = 0;
    nova->primeiro = nova->ultimo = NULL;
    return nova;
}

char emPilha(Sentinela *p, No *n){
    if(p == NULL || n == NULL)
        return 0;
    if(p->qtd > 0){
        p->ultimo->prox = n;
        p->ultimo = p->ultimo->prox;
    }
    else
        p->primeiro = p->ultimo = n;
    p->qtd++;
    return 1;
}

No* desemPilha(Sentinela *p){
    if(p == NULL)
        return NULL;
    if(p->primeiro == NULL)
        return NULL;

    No* resp = p->primeiro;
    p->primeiro = p->primeiro->prox;
    resp->prox = NULL;
    p->qtd--;
    return resp;
}

char printaPilha(Sentinela *p){
    if(p == NULL)
        return 0;

    for(No* atual = p->primeiro; atual != NULL; atual = atual->prox)
        printf("%d -> ", atual->valor);
    puts("||");
    return 1;
}

char freePilha(Sentinela *p){
    if(p == NULL)
        return 0;

    for(No *atual = p->primeiro; atual != NULL; atual = atual->prox)
        free(atual);
    free(p);
    return 1;
}
