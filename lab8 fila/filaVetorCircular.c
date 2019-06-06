#include <stdio.h>
#include "fila.h"

Fila *cria_fila(void){
    Fila *nova = (Fila*) malloc(sizeof(Fila));
    if(nova == NULL) return NULL;
    nova->qtd = nova->ini = nova->fim = 0;
    return nova;
}

int Vazia_fila(Fila *f){
    if(f != NULL)
        return (f->qtd == 0);
    else return 1;
}

void insere(Pessoa *pessoa, Fila *f){
    if(pessoa == NULL || f == NULL) return;
    if(f->qtd >= MAXTAM) return;

    f->vetor[f->fim] = pessoa;
    f->qtd++;
    f->fim = (f->fim + 1) % MAXTAM;
    return;
}

Pessoa *retira(Fila *f){
    if(Vazia_fila(f)) return NULL;

    Pessoa *retirada = f->vetor[f->ini];
    f->ini = (f->ini + 1) % MAXTAM;
    f->qtd--;

    return retirada;
}

void imprime_fila(Fila *f){
    for(int i = 0; i < f->qtd; i++)
        imprimepessoa(f->vetor[(f->ini + i) % MAXTAM]);

    printf("Quantidade: %d\n", f->qtd);
    return;
}

Fila *destroi_fila(Fila *f){
    if(f == NULL) return NULL;
    if(Vazia_fila(f)){
        free(f);
        return f;
    }

    int iteracoes = f->qtd;
    for(int i = 0; i < iteracoes; i++)
        destroi_pessoa(retira(f));
    free(f);
    return f;
}

void separa_filas(Fila *f, Fila *f_maiores, Fila *f_menores){
    if(f == NULL || f_maiores == NULL || f_menores == NULL) return;
    if(Vazia_fila(f)) return;

    for(int i = 0; i < iteracoes; i++){
        Pessoa *retirado = retira(f);
        if(retorna_idade(p) < 60)
            insere(retirado, f_menores);
        else
            insere(retirado, f_maiores);
    }

    return;
}
