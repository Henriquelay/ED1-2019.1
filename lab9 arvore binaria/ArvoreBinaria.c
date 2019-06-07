#include "ArvoreBinaria.h"

ArvBin *cria_ArvBin(void){
    ArvBin *nova = (ArvBin*) malloc(sizeof(ArvBin));
    if(nova == NULL) return NULL;
    
    *nova = NULL;
    return nova;
}

NO *cria_No(int valor){
    NO *novo = (ArvBin) malloc(sizeof(NO));
    if(novo == NULL) return NULL;

    novo->esq = novo->dir = NULL;
    novo->info = valor;
    return novo;
}

int insere_ArvBin(ArvBin *raiz, int valor){
    if(raiz == NULL) return 0;
    if(*raiz == NULL)   //encontrei um lugar
        *raiz = cria_No(valor);
    else{
        if(valor == (*raiz)->info) 
            return 0;
        if(valor < (*raiz)->info)
            return insere_ArvBin(&(*raiz)->esq, valor);
        if(valor > (*raiz)->info)
            return insere_ArvBin(&(*raiz)->dir, valor);
    }
    return 1;
}

int estaVazia_ArvBin(ArvBin *raiz){
    if(raiz == NULL) return 0;
    return (*raiz == NULL);
}

int consulta_ArvBin(ArvBin *raiz, int valor){
    if(raiz == NULL) return 0;
    if(valor < (*raiz)->info)
        return consulta_ArvBin(&(*raiz)->esq, valor);
    if(valor > (*raiz)->info)
        return consulta_ArvBin(&(*raiz)->dir, valor);
    return 1;
}

void preOrdem_ArvBin(ArvBin *raiz){
    if(raiz == NULL) return;
    if(estaVazia_ArvBin(raiz)) return;
    printf("%d ", (*raiz)->info);
    preOrdem_ArvBin(&(*raiz)->esq);
    preOrdem_ArvBin(&(*raiz)->dir);
}

void emOrdem_ArvBin(ArvBin *raiz){
    if(raiz == NULL) return;
    if(estaVazia_ArvBin(raiz)) return;
    emOrdem_ArvBin(&(*raiz)->esq);
    printf("%d ", (*raiz)->info);
    emOrdem_ArvBin(&(*raiz)->dir);
}

void posOrdem_ArvBin(ArvBin *raiz){
    if(raiz == NULL) return;
    if(estaVazia_ArvBin(raiz)) return;
    posOrdem_ArvBin(&(*raiz)->esq);
    posOrdem_ArvBin(&(*raiz)->dir);
    printf("%d ", (*raiz)->info);
}

int totalNaoFolha_ArvBin(ArvBin *raiz){
    int cont = 0;
    if(&(*raiz)->esq != NULL) cont++;
    if(&(*raiz)->dir != NULL) cont++;
    return cont;
}

int totalFolha_ArvBin(ArvBin *raiz){
    int cont = 0;
    if(&(*raiz)->esq == NULL) cont++;
    if(&(*raiz)->dir == NULL) cont++;
    return cont;
}

void libera_ArvBin(ArvBin *raiz){
    if(raiz == NULL) return;
    libera_ArvBin(&(*raiz)->esq);
    libera_ArvBin(&(*raiz)->dir);
    free(raiz);
    return;
}
