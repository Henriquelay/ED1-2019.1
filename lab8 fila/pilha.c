/*
 * pilha.c
 *
 *  Created on: 11/07/2013
 *      Author: pdcosta
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"
#define MaxTam 10

struct pessoa{
   char* nome;
   char* end;
   int idade;
};

struct pilha{
    int topo;
    Pessoa* vet[MaxTam];
};

Pilha* cria_pilha()
{
   Pilha* p = (Pilha*) malloc(sizeof(Pilha));
   p->topo = 0;
   return p;
}

void push(Pessoa* pessoa, Pilha* pilha){

   if (pilha->topo == MaxTam)
		return;
	else {
	  pilha->vet[pilha->topo] = pessoa;
	  pilha->topo++;
	}
}


Pessoa* pop(Pilha* pilha){
   Pessoa* p;

   if (vazia_pilha (pilha))
		return NULL;
	else {
		p = pilha->vet[pilha->topo-1];
		pilha->topo--;
	}
    return p;
}


void destroi_pessoa(Pessoa* p){
     free(p->nome);
     free(p->end);
     free(p);
}


Pilha* destroi_pilha(Pilha* pilha){
  while (!vazia_pilha(pilha)){
          
   destroi_pessoa(pop(pilha));
  }
  free(pilha); 
  return NULL;
}

int vazia_pilha (Pilha* pilha){
   return (pilha->topo == 0);
}

int tamanho_pilha (Pilha* p){
   return p->topo;
}

Pessoa* inicializaPessoa(char* nome, int idade, char* endereco){
	Pessoa* p = (Pessoa*) malloc (sizeof(Pessoa));
	p->idade = idade;
	p->end = (char*)malloc((strlen(endereco)+1)*sizeof(char));
	strcpy (p->end, endereco);
	p->nome = (char*)malloc((strlen(nome)+1)*sizeof(char));
	strcpy (p->nome, nome);
	return p;
}


//--------------------------------

/*Imprime os dados de todos os alunos da lista
* inputs: a lista de alunos
* output: nenhum
* pre-condicao: lista não é nula
* pos-condicao: dados dos alunos impressos na saida padrao
*/
void imprime_pilha (Pilha* pilha){
	int Aux; int topo;
	topo = pilha->topo-1;
		for (Aux = topo; Aux >= 0; Aux--)
		{
			printf ("Pessoa: %s\n", pilha->vet[Aux]->nome);
			printf ("Idade: %d\n", pilha->vet[Aux]->idade);
			printf ("Endereco: %s\n", pilha->vet[Aux]->end);
			printf ("\n");
		}

}

void imprimepessoa(Pessoa* p){
		printf ("Pessoa: %s\n", p->nome);
		printf ("Idade: %d\n", p->idade);
		printf ("Endereco: %s\n", p->end);
		printf ("\n");

}

int retorna_idade (Pessoa* p){
    return p->idade;
}
   






