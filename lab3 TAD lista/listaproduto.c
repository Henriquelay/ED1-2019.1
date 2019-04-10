#include "listaproduto.h"

/////////"SETTERS"


void addCodigo(tProduto *produto, int *codigo){
    produto->codigo = *codigo;
}
void addNome(tProduto *produto, char *nome){
    strcpy(produto->nome, nome);
}
void addPreco(tProduto *produto, float *preco){
    produto->preco = *preco;
}
void addQuantidade(tProduto *produto, int *quantidade){
    produto->quantidade = *quantidade;
}


/////////"GETTERS"


int pegaCodigo(tProduto *produto){
    return produto->codigo;
}
char* pegaNome(tProduto *produto){
    return produto->nome;
}
float pegaPreco(tProduto *produto){
    return produto->preco;
}
int pegaQuantidade(tProduto *produto){
    return produto->quantidade;
}


//////Functions

tProduto criaProduto(int *codigo, char *nome, float *preco, int *quantidade){
    tProduto produto;

    addCodigo(&produto, codigo);
    addNome(&produto, nome);
    addPreco(&produto, preco);
    addQuantidade(&produto, quantidade);
    
    return produto;
}

void imprimeProduto(tProduto *produto){
    printf("Codigo: \t%d\nNome: \t\t%s\nPreco: \t\t%.2f\nQuantidade: \t%d\n", produto->codigo, produto->nome, produto->preco, produto->quantidade);
}


///////////////
/////////LISTA


tLista criaListaVazia(void){
    tLista lista;
    lista.Primeiro = INICIOARRANJO;
    lista.Ultimo = INICIOARRANJO;
    return lista;
}

void esvaziaLista(tLista *l){
    l->Ultimo = l->Primeiro;
}

int estaVazia(tLista *l){
    if(l->Primeiro!=l->Ultimo) return 0;
    return 1;
}

void imprimeLista(tLista *l){
    for(int i = 0; i < l->Ultimo - 1; i++){
        printf("[\tItem %d:\n", i);
        imprimeProduto(&l->item[i]);
        puts("]");
    }
}