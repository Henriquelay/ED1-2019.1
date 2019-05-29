#include "fila.h"
#include <stdio.h>

Fila* cria_fila(void){
    return (Fila*) cria_pilha();
}

void insere(Pessoa* pessoa, Fila* f){
    push(pessoa, (Pilha*)f); 
}

Pessoa* retira(Fila* f){
    Fila* f2 = (Fila*) cria_pilha();
    int tam = tamanho_pilha((Pilha*) f);
    for(int i = 0; i < tam - 1; i++)
        push(pop((Pilha*)f), (Pilha*)f2);
    Pessoa* p = pop((Pilha*)f);
    tam = tamanho_pilha((Pilha*) f2);
    for(int i = 0; i < tam; i++)
        push(pop((Pilha*)f2), (Pilha*)f);
    destroi_pilha((Pilha*)f2);
    return p;
}

void imprime_fila(Fila* f){
    imprime_pilha((Pilha*)f);
}

int Vazia_fila(Fila* f){
    return vazia_pilha((Pilha*)f);
}

Fila* destroi_fila(Fila* f){
    return (Fila*) destroi_pilha((Pilha*)f);
}

void separa_filas(Fila* f, Fila* f_maiores, Fila* f_menores){
    if(f == NULL)
        return;
    Pessoa* p = NULL;
    int tam = tamanho_pilha((Pilha*) f);
    for(int i = 0; i < tam; i++){
        p = pop((Pilha*)f);
        if(retorna_idade(p) >= 60)
            push(p, (Pilha*) f_maiores);
        else
            push(p, (Pilha*) f_menores);
    }
    return;
}
