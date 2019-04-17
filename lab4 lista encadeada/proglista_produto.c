
/*
Implementacao Laboratorio 2
Modifica��es: VM
========================================================================== */
#include <sys/time.h>

#include "listaencadeada.h"


/* ========================================================================== */

int main(int argc, char *argv[])
{

  TipoLista lista;
  Produto item;

  FLVazia(&lista);
  item = criaProduto(1,"Sabonete", 10, 3.90);
    Insere(item, &lista);
  item = criaProduto(2,"Arroz", 20, 13.90);
  Insere(item, &lista);
  item = criaProduto(3,"Feijao", 1, 17.90);
  Insere(item, &lista);
  item = criaProduto(4,"Tomate", 0, 10);
  Insere(item, &lista);
  item = criaProduto(5,"Uva", 5, 8);
  Insere(item, &lista);
//  Insere(item, &lista);
  ImprimeLista(lista);
  Retira(4, &lista, &item);
  ImprimeLista(lista);
  TipoApontador p = BuscaCodigo(3, &lista);
  ImprimeProduto(p->Item);
  item = maisBarato(&lista);
  Imprime(item);
  return(0);
}
