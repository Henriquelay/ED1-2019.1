#include "fila.h"


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

void separa_filas(Fila *f, Fila *f_maiores, Fila *f_menores){}

void destroi_no(No *no){
    if(no == NULL) return;
    destroi_pessoa(no->p);
    free(no);
    return;
}

Fila *destroi_fila(Fila *f){
    if(f == NULL) return NULL;
       
    for(No *aux = f->ini; aux != NULL; aux = f->ini){
        f->ini = f->ini->prox;
        destroi_no(aux);
    }
    return f;

}
