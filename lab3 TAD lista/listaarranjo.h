#ifndef LISTAARR_H_
#define LISTAARR_H_

#include <stdio.h>
#include <stdlib.h>
#define INICIOARRANJO   1
#define MAXTAM          1000




typedef struct {
  int Chave;
  /* outros componentes */
} TipoItem;

typedef struct {
  TipoItem Item[MAXTAM];
  Posicao Primeiro, Ultimo;
} TipoLista;


/* Faz a lista ficar vazia */
void FLVazia(TipoLista *Lista);

/*Verifica se a lista est� vazia*/
int Vazia(TipoLista Lista);

/* Insere x ap�s o �ltimo elemento da lista */
void Insere(TipoItem x, TipoLista *Lista);

/*Op��o que n�o modifica o lista.h */
void Retira(Posicao p, TipoLista *Lista, TipoItem *Item);
/*Imprime a lista */
void Imprime(TipoLista Lista);

/*Quantidade de elementos na lista*/
int Quantidade(TipoLista Lista);

/*Copia uma lista */
void copiaLista(TipoLista *ListaOrigem, TipoLista *ListaDestino);

/*Copia uma lista */
void partirLista(int p, TipoLista *ListaOrigem, TipoLista *ListaDestino);


TipoItem Recupera(Posicao p, TipoLista *Lista);

#endif /* LISTAARR_H_ */
