#include "listaproduto.h"

/////////"SETTERS"


void addCodigo(tProduto *produto, int *codigo){
    produto->codigo = *codigo;
}
void addNome(tProduto *produto, char *nome){
    if(strlen(nome) > 29)
        printf("O nome eh muito grande!");

    strcpy(produto->nome, nome);
}
void addPreco(tProduto *produto, float *preco){
    produto->preco = *preco;
}
void addQuantidade(tProduto *produto, int *quantidade){
    if(*quantidade < 0)
        printf("==Warning: A quantidade eh menor que 0!!!Continuando==");
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

void esvaziaLista(tLista *lista){
    lista->Ultimo = lista->Primeiro;
}

int estaVazia(tLista *lista){
    if(lista->Primeiro!=lista->Ultimo) 
        return 0;

    return 1;
}

void imprimeLista(tLista *lista){
    for(int i = 0; i < lista->Ultimo - 1; i++){
        printf("[Item %d:\n", i);
        imprimeProduto(&lista->item[i]);
        printf("]\n");
    }
    printf("\n");
}

void insere(tLista *lista, tProduto *produto){
    if(lista->Ultimo > MAXTAM)
        printf("Esse produto nao cabe na lista, ela esta cheia!\n");
    else{
            if(!existeNaLista(lista, &produto->codigo)){
                lista->item[lista->Ultimo - 1] = *produto;
                lista->Ultimo++;
            } else 
                printf("O item ja esta na lista! Nao foi adicionado");
    }
}

void removeItemIndice(tLista *lista, int *indice){
    if(*indice < lista->Primeiro || *indice > lista->Ultimo)
        printf("Esse produto eh invalido nessa lista!\n");
    else
        if(lista->item[*indice].quantidade > 0)
            printf("Produto em estoque nao pode ser removido!\n");
        else{
            lista->Ultimo--;
            for(int i = *indice; i < lista->Ultimo; i++)
                lista->item[i] = lista->item[i+1];
            }
}

void removeItemCodigo(tLista *lista, int *codigo){
    int indiceNaLista = existeNaLista(lista, codigo);

    if(!indiceNaLista)
        printf("Esse item nem existe na lista!\n");
    else
        removeItemIndice(lista, &indiceNaLista);
}

tProduto buscaCodigo(tLista *lista, int *codigo){
    for(int i = 0; i < lista->Ultimo; i++)
        if(lista->item[i].codigo == *codigo)
            return lista->item[i];

    printf("Nao foram encontrados produtos com esse indice!\n");
}

int existeNaLista(tLista *lista, int *codigo){
    for(int i = 0; i < lista->Ultimo; i++)
        if(lista->item[i].codigo == *codigo)
            return i;

    return 0;
}

tProduto maisBarato(tLista *lista){
    tProduto produtoMaisBarato = lista->item[0];

    for(int i = 0; i < lista->Ultimo; i++)
        if(lista->item[i].preco < produtoMaisBarato.preco)
            produtoMaisBarato = lista->item[i];
    
    return produtoMaisBarato;
}

int quantidadeItens(tLista *lista){
    return lista->Ultimo - lista->Primeiro;
}