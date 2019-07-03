#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

TipoPilha* InicializaPilha(){
	TipoPilha* pilha = (TipoPilha*)malloc(sizeof(TipoPilha));
	return pilha;
}

void FPVazia (TipoPilha* Pilha)
{
	Pilha->Topo = (Celula*)malloc (sizeof(Celula));
	Pilha->Fundo = Pilha->Topo;
	Pilha->Topo->Prox=NULL;
	Pilha->Tamanho = 0;
}

int Vazia (TipoPilha* Pilha){	
	return (Pilha->Topo == Pilha->Fundo);
}

void Empilha (TipoItem* x, TipoPilha *Pilha){ 
	Celula* Aux;
	Aux = (Celula*) malloc(sizeof(Celula));
	Pilha->Topo->Item = *x;
	Aux->Prox = Pilha->Topo;
	Pilha->Topo = Aux;
	Pilha->Tamanho++;
}

void Desempilha (TipoPilha *Pilha, TipoItem *Item){ 
	Celula* q;
	if (Vazia (Pilha))	{
		printf ("Erro: lista vazia \n"); 
		return;
	}
	q = Pilha->Topo;
	Pilha->Topo = q->Prox;
	*Item = q->Prox->Item;
	free (q); 
	Pilha->Tamanho--;
}

int Tamanho(TipoPilha* Pilha){ 
	return (Pilha->Tamanho); 
}

void Imprime (TipoPilha* pilha){
	Celula* Aux;
	Aux = pilha->Topo->Prox;
	printf ("Imprime Pilha Encadeada: \n");
	while (Aux != NULL)
	{
		printf ("%d\n", Aux->Item.valor);
		Aux = Aux->Prox;
	}
}

TipoItem* InicializaTipoItem (int n)
{
	TipoItem* item = (TipoItem*)malloc(sizeof(TipoItem));
	item->valor = n;
	return item;
}

