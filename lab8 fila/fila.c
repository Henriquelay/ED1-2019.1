#include "fila.h"
#include <stdio.h>


No* inicia_No(Pessoa *p){
    if(p == NULL) return NULL;
    
    No *novono = (No*) malloc(sizeof(No));
    if(novono == NULL) return NULL;
    novono->p = p;
    novono->prox = NULL;
    return novono;
}

Fila *cria_fila(void){
    Fila *f = (Fila*) malloc(sizeof(Fila));
    if(f == NULL) return NULL;
    f->qtd = 0;
    f->ini = f->fim = NULL;
    return f;    
}

int Vazia_fila(Fila *f){
    if(f == NULL) return 1;
    return (f->qtd == 0);
}

void insere(Pessoa *pessoa, Fila *f){
    if(f == NULL || pessoa == NULL) return;
    
    No *novono = inicia_No(pessoa);
    if(Vazia_fila(f))
        f->ini = f->fim = novono;
    else{
        f->fim->prox = novono;
        f->fim = novono;
    }
    f->qtd++;
    return;
}

Pessoa *retira(Fila *f){
    if(f == NULL) return NULL;
    
    Pessoa *p = f->ini->p;
    No *no = f->ini;
    f->ini = f->ini->prox;
    free(no);
    f->qtd--;
    return p;
}

void imprime_fila(Fila *f){
    if(f == NULL) return;

    for(No *aux = f->ini; aux != NULL; aux = aux->prox)
        imprimepessoa(aux->p);
    return;
}

void separa_filas(Fila *f, Fila *f_maiores, Fila *f_menores){
    if(f == NULL || f_maiores == NULL || f_menores == NULL) return;
    if(Vazia_fila(f)) return;
    Pessoa *p = NULL;
    for(No *aux = f->ini; f->ini != NULL; aux = f->ini){
        f->ini = f->ini->prox;
        p = retira(f);
        if(retorna_idade(p) < 60)
            insere(p, f_menores);
        else
            insere(p, f_maiores);
    }
}

Fila *destroi_fila(Fila *f){
    if(f == NULL) return NULL;
       
    for(No *aux = f->ini; f->ini != NULL; aux = f->ini){
        f->ini = f->ini->prox;
        destroi_pessoa(retira(f));
    }
    free(f);
    return f;

}
