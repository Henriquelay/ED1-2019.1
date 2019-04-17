#include "listaencadeada.h"

////PRODUTO
Produto criaProduto(int cod, char *nome, int qtd, float preco){
    Produto produtoFinal;

    produtoFinal.codigo = cod;
    produtoFinal.nome = (char*) malloc(sizeof(char) * (strlen(nome) + 1));
    strcpy(produtoFinal.nome, nome);
    produtoFinal.preco = preco;
    produtoFinal.qtd = qtd;

    return produtoFinal;
}

void ImprimeProduto(Produto p){
    printf("Produto %s:\n-Codigo: %d\n-Preco: %.2f\n-Quantidade: %d\n\n", p.nome, p.codigo, p.preco, p.qtd);
}


/////LISTA


void FLVazia(TipoLista *Lista){
    Lista->Primeiro = Lista->Ultimo = NULL;
}

int Vazia(TipoLista Lista){
    if(Lista.Primeiro == NULL)
        return 1;
    return 0;
}

void Insere(Produto x, TipoLista *Lista){
    if(Vazia(*Lista)){
        Lista->Primeiro = Lista->Ultimo = (TipoApontador) malloc(sizeof(TipoCelula));
        if(Vazia(*Lista)){
            printf("####### ACABOU A MEMORIA A AO ALOCAR MAIS ESPACO, ITEM NÃO FOI ALOCADO... ###########");
        }else{
        //crio uma cópia para o produto X para não apontar para ele, evitando problemas de referenciação
            Lista->Ultimo->Item = x;
            Lista->Ultimo->Prox = NULL;
        }
    }else{
        Lista->Ultimo->Prox = (TipoApontador) malloc(sizeof(TipoCelula));
        if(Lista->Ultimo->Prox == NULL){
            printf("####### ACABOU A MEMORIA A AO ALOCAR MAIS ESPACO, ITEM NÃO FOI ALOCADO... ###########");
        } else{
            Lista->Ultimo = Lista->Ultimo->Prox;
            //crio uma cópia para o produto X para não apontar para ele, evitando problemas de referenciação
            Lista->Ultimo->Item = x;
            Lista->Ultimo->Prox = NULL;
        }
    }
}

void LiberaCelula(Produto *produto){
    free(produto->nome);
    free(produto);
}

void RetiraCelula(TipoCelula *Anterior, TipoCelula *Selecionada){
    if(Anterior != NULL){
        Anterior->Prox = Selecionada->Prox;
    }
    LiberaCelula(Selecionada);
}

void Retira(int codigo, TipoLista *Lista, Produto *Item){
    if(Vazia(*Lista))
        printf("####### A LISTA E VAZIA!! #######");
    else{
        TipoCelula *Selecionado = Lista->Primeiro;
        TipoCelula *Anterior = NULL;

        while(Selecionado != NULL){
            if(Selecionado->Item.codigo == codigo)
                RetiraCelula(Anterior, Selecionado);

            //configura o passo do While
            Anterior = Selecionado;
            Selecionado = Selecionado->Prox;
        }
    }
}

void ImprimeLista(TipoLista Lista){
    TipoCelula *Selecionado = Lista->Primeiro;

    while(Selecionado != NULL){
        ImprimeProduto(Selecionado->Item);
        Selecionado = Selecionado->Prox;    
    }
}