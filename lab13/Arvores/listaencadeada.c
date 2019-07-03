/*
 * lista.c
 *
 *  Created on: 05/04/2019
 *      Author: vm
 */

#include "listaencadeada.h"

typedef struct{
  int codigo;
}produto;

void FLVazia(TipoLista *Lista)
{ Lista -> Primeiro = (TipoApontador) malloc(sizeof(TipoCelula));
  Lista -> Ultimo = Lista -> Primeiro;
  Lista -> Primeiro -> Prox = NULL;
}

int Vazia(TipoLista Lista)
{ return (Lista.Primeiro == Lista.Ultimo);
}

void Insere(Produto x, TipoLista *Lista)
{ Lista -> Ultimo -> Prox = (TipoApontador) malloc(sizeof(TipoCelula));
  Lista -> Ultimo = Lista -> Ultimo -> Prox;
  Lista -> Ultimo -> Item = x;
  Lista -> Ultimo -> Prox = NULL;
}

/** | q | -->  | p | -->  | r |
Deseja -se remover p
Busca p pelo código
Busca o anterior a p (chamado q)
Aponta q para r
libera p
 */
void Retira(int codigo, TipoLista *Lista, Produto *Item)
{
  TipoApontador  p = BuscaCodigo(codigo, Lista);
  TipoApontador q;
  if (Vazia(*Lista) || p == NULL || p -> Prox == NULL)
  { printf(" Erro   Lista vazia ou posicao n  a o existe\n");
    return;
  }
  //Busca apontador anterior a p
  q = Lista -> Primeiro;
  while ( q-> Prox != p)
      q = q-> Prox;
  //Fim busca anterior
  *Item = p -> Item;
  q -> Prox = p -> Prox;
  if (q -> Prox == NULL) Lista -> Ultimo = q;
  free(p);
}

TipoApontador BuscaCodigo(int codigo, TipoLista *Lista)
{ TipoApontador Aux;
  Aux = Lista->Primeiro -> Prox;
  while (Aux != NULL)
    {
      if (Aux -> Item.codigo == codigo)
        return Aux;
      Aux = Aux -> Prox;
    }
   return NULL;
}


void ImprimeLista(TipoLista Lista)
{ TipoApontador Aux;
  Aux = Lista.Primeiro -> Prox;
  while (Aux != NULL)
    {
      ImprimeProduto(Aux -> Item);
      Aux = Aux -> Prox;
    }
}




Produto  criaProduto(int cod)
{
   Produto p;
   p.codigo = cod;
   return p;
}

void ImprimeProduto(Produto p)
{
 printf("cod:%d\n", p.codigo);
}
