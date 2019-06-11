#include "ArvoreBinaria.h"
NO **cria_ArvBin(void){
    NO **novo = (NO**) malloc(sizeof(NO*));
    if(novo == NULL) return NULL;
    return novo;
}

NO *cria_No(int valor){
    NO *novo = (NO*) malloc(sizeof(NO));
    if(novo == NULL) return NULL;

    novo->esq = novo->dir = NULL;
    novo->info = valor;
    return novo;
}

int insere_No(NO **raiz, int valor){
    if(raiz == NULL)   //encontreu onde colocar
        raiz = cria_ArvBin();
    NO *conteudo = *raiz;
    if(conteudo == NULL){
        *raiz = cria_No(valor);
        printf("Inserido %d.\n", (*raiz)->info);
        return 1;
    }
    if(valor > conteudo->info)
        return insere_No(&conteudo->dir, valor);
    if(valor < conteudo->info)
        return insere_No(&conteudo->esq, valor);    
    if(conteudo->info == valor) return 0;
   
    return -1;
}

int nFilhos_No(NO *raiz){
    if (raiz == NULL) return -1;
    int cont = 0;
    if(raiz->esq == NULL) cont++;
    if(raiz->dir == NULL) cont++;
    return cont;
}

int consulta_No(NO *raiz, int valor){
    if(raiz == NULL) return 0; 
    if(valor > raiz->info)
        return consulta_No(raiz->dir, valor);
    if(valor < raiz->info)
        return consulta_No(raiz->esq, valor);    
    if(raiz->info == valor) return 1;
    return 0;
}

void preOrdem_No(NO *raiz){
    if(raiz == NULL) return;
    printf("%d ", raiz->info);
    preOrdem_No(raiz->esq);
    preOrdem_No(raiz->dir);
}

void emOrdem_No(NO *raiz){
    if(raiz == NULL) return;
    emOrdem_No(raiz->esq);
    printf("%d ", raiz->info);
    emOrdem_No(raiz->dir);
    return;
}

void posOrdem_No(NO *raiz){
    if(raiz == NULL) return;
    posOrdem_No(raiz->esq);
    posOrdem_No(raiz->dir);
    printf("%d ", raiz->info);
}

int totalNaoFolha_No(NO *raiz){
    int cont = 0;
    if(raiz->esq != NULL) cont++;
    if(raiz->dir != NULL) cont++;
    return cont;
}

int totalFolha_No(NO *raiz){
    int cont = 0;
    if(raiz->esq == NULL) cont++;
    if(raiz->dir == NULL) cont++;
    return cont;
}

void libera_No(NO *raiz){
    if(raiz == NULL) return;
    libera_No(raiz->esq);
    libera_No(raiz->dir);
    free(raiz);
}
