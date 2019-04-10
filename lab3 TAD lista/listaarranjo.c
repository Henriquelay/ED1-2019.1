/*
 * lista.c
 *
 *  Created on: 05/04/2019
 *      Author: vm
 */

#include "listaarranjo.h"


typedef int Posicao;

void FLVazia(TipoLista *Lista)
{ Lista -> Primeiro = INICIOARRANJO;
  Lista -> Ultimo = Lista -> Primeiro;
}  /* FLVazia */

int Vazia(TipoLista Lista)
{ return (Lista.Primeiro == Lista.Ultimo);
}  /* Vazia */

void Insere(TipoItem x, TipoLista *Lista)
{ if (Lista -> Ultimo > MAXTAM) printf("Lista esta cheia\n");
  else { Lista -> Item[Lista -> Ultimo - 1] = x;
         Lista -> Ultimo++;
       }
}  /* Insere */

void Retira(Posicao p, TipoLista *Lista, TipoItem *Item)
{ int Aux;

  if (Vazia(*Lista) || p >= Lista -> Ultimo)
  { printf(" Erro   Posicao nao existe\n");
    return;
  }
  *Item = Lista -> Item[p - 1];
  Lista -> Ultimo--;
  for (Aux = p; Aux < Lista -> Ultimo; Aux++)
    Lista -> Item[Aux - 1] = Lista -> Item[Aux];
}  /* Retira */

TipoItem Recupera(Posicao p, TipoLista *Lista)
{

  if (Vazia(*Lista) || p >= Lista -> Ultimo)
  { printf(" Erro   Posicao nao existe\n");
    return;
  }
  TipoItem item = Lista -> Item[p];
  return item;
}  /* Recupera */


void Imprime(TipoLista Lista)
{ int Aux;

  for (Aux = Lista.Primeiro - 1; Aux <= (Lista.Ultimo - 2); Aux++)
    printf("%d\n", Lista.Item[Aux].Chave);
}  /* Imprime */

int Quantidade(TipoLista Lista)
{
 if (Vazia(Lista))
  {
    return 0;
  }

  return Lista.Ultimo-1;
}

void copiaLista(TipoLista *ListaOrigem, TipoLista *ListaDestino)
{
  if (Vazia(*ListaOrigem))
  {
    printf(" Erro   Lista vazia\n");
    return;
  }
  FLVazia(ListaDestino);

  // ( int p = ListaOrigem->Primeiro-1; p < ListaOrigem->Ultimo-1; p++)
  for (int p = 0; p < Quantidade(*ListaOrigem); p++)
  {
    Insere(Recupera(p,ListaOrigem), ListaDestino);
  }
}

void partirLista(int p, TipoLista *ListaOrigem, TipoLista *ListaDestino)
{
  if (Vazia(*ListaOrigem))
  {
    printf(" Erro   Lista vazia\n");
    return;
  }
   TipoItem item;
   FLVazia(ListaDestino);
   while (p < ListaOrigem->Ultimo)
   {
      Retira(p, ListaOrigem, &item);
      Insere(item, ListaDestino);
   }
}
