#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#define MaxTam  1000

TipoPilha* InicializaPilha(){
	TipoPilha* pilha =(TipoPilha*)malloc(sizeof(TipoPilha));
	return pilha;
}

void FPVazia(TipoPilha* Pilha){
	Pilha->Topo = 0;
}

int Vazia (TipoPilha* Pilha) { 
	return (Pilha->Topo == 0);
}

void Empilha (TipoItem* x, TipoPilha* Pilha) {
	if (Pilha->Topo == MaxTam)
		printf ("Erro: pilha esta cheia\n");
	else {
	  Pilha->Item[Pilha->Topo] = x;
	  Pilha->Topo++;
	}
}


void Desempilha (TipoPilha* Pilha, TipoItem* Item) { 
	if (Vazia (Pilha))
		printf ("Erro: pilha esta vazia\n");
	else { 
		Item = Pilha->Item[Pilha->Topo-1];
		Pilha->Topo--;
	}
}

int Tamanho (TipoPilha* Pilha) {
	return (Pilha->Topo);
}

TipoItem* InicializaTipoItem (int n)
{
	TipoItem* item = (TipoItem*)malloc(sizeof(TipoItem));
	item->valor = n;
	return item;
}

/*Imprime os itens da pilha */
void Imprime (TipoPilha* pilha)
{
	int Aux;
	printf ("Imprime Pilha Estatica: \n");
		
	for (Aux = 0; Aux < pilha->Topo; Aux++)
	{
		printf ("%d\n", pilha->Item[Aux]->valor); 
	}
}




