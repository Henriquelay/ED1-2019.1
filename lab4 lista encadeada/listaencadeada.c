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
    printf("Produto %s:\n-Codigo: \t%d\n-Preco: \t%.2f\n-Quantidade: \t%d\n\n", p.nome, p.codigo, p.preco, p.qtd);
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

    //Apenas aloco o primeiro elemento;
    if(Vazia(*Lista)){
        Lista->Primeiro = Lista->Ultimo = (TipoApontador) malloc(sizeof(TipoCelula));
        if(Vazia(*Lista))
            printf("####### ACABOU A MEMORIA A AO ALOCAR MAIS ESPACO, ITEM NÃO FOI ALOCADO... ###########");

    //Apenas aloco o próximo e configuro o Último corretamente.
    }else{
        Lista->Ultimo->Prox = (TipoApontador) malloc(sizeof(TipoCelula));
        if(Lista->Ultimo->Prox == NULL)
            printf("####### ACABOU A MEMORIA A AO ALOCAR MAIS ESPACO, ITEM NÃO FOI ALOCADO... ###########");
        else
            Lista->Ultimo = Lista->Ultimo->Prox;

    }
    //Está após o Else, ou seja, será executado sempre.
    Lista->Ultimo->Item = x;
    Lista->Ultimo->Prox = NULL;
}

void LiberaCelula(TipoCelula *Celula){
    free(Celula->Item.nome);
    free(Celula);
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
    TipoCelula *Selecionado = Lista.Primeiro;

    while(Selecionado != NULL){
        ImprimeProduto(Selecionado->Item);
        Selecionado = Selecionado->Prox;    
    }
}

int Quantidade(TipoLista Lista){

    if(Vazia(Lista))
        return 0;

    int cont = 1;
    TipoCelula *Selecionado = Lista.Primeiro;
    
    while(Selecionado != NULL){
        cont ++;
        //configura o passo do While
        Selecionado = Selecionado->Prox;
    }

    return cont;
}

TipoApontador BuscaCodigo(int codigo, TipoLista *Lista){

    if(Vazia(*Lista)){
        printf("###### A LISTA ESTA VAZIA, NAO POSSO PROCURAR!!! ##########");
        return NULL;
    }

    TipoCelula *Selecionado = Lista->Primeiro;

    while(Selecionado != NULL){
        if(Selecionado->Item.codigo == codigo)
            return Selecionado;

        Selecionado = Selecionado->Prox;
    }

    printf("Nao foram encontrado produtos com o codigo %d.\n", codigo);
    return NULL;
}

Produto maisBarato(TipoLista *Lista){
    //Fazendo o guarda da função
    if(Vazia(*Lista)){
        printf("##### NAO POSSO PEGAR O ITEM MAIS BARATO DE UMA LISTA QUE NAO EXISTE! SAINDO... #########");
        EXIT_FAILURE;
        Produto a;//para evitar warnings. O programa já foi interrompido.
        return a;//^
    }

    TipoCelula *Selecionado = Lista->Primeiro;
    Produto menosCaro = Selecionado->Item;

    int cont = 0;
    while (1){
        printf("#PASSOU VIADO! \t %d\n", cont);

        if(Selecionado->Prox == NULL)
            break;
            
        Selecionado = Selecionado->Prox;
        if(Selecionado->Item.preco < menosCaro.preco)
            menosCaro = Selecionado->Item;
        
        cont++;
    }
    return menosCaro;
}