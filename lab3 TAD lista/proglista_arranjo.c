
/*
Baseado na implementa��o do livro Projeto de Algoritmos
Modifica��es: VM
========================================================================== */
#include <sys/time.h>

#include "listaarranjo.h"


/* ========================================================================== */

int main(int argc, char *argv[])
{ struct timeval t;

  TipoLista lista;
  TipoItem item;
  int vetor[MAXTAM];
  int i, j, k, n, max;
  gettimeofday(&t,NULL);
  srand((unsigned int)t.tv_usec);
  max = 10;
  FLVazia(&lista);

  /*Gera uma permutacao aleatoria de chaves entre 1 e max*/
  for(i = 0; i < max; i++) vetor[i] = i + 1;
  for(i = 0; i < max; i++)
    { k =  (int) (10.0 * rand()/(RAND_MAX + 1.0));
      j =  (int) (10.0 * rand()/(RAND_MAX + 1.0));
      n = vetor[k];
      vetor[k] = vetor[j];
      vetor[j] = n;
    }
  /*Insere cada chave na lista */
  for (i = 0; i < max; i++)
    { item.Chave = vetor[i];
      Insere(item, &lista);
      printf("Inseriu: %d \n", item.Chave);
    }
  Imprime(lista);

  TipoLista lista2;
  copiaLista(&lista, &lista2);
  Imprime(lista2);
  partirLista(4, &lista, &lista2);
  printf("Lista 1: \n");
  Imprime(lista);
  printf("Lista 2: \n");
  Imprime(lista2);

  /*Retira cada chave da lista */
  i = 1;
  while( Quantidade(lista) > 0)
    {
      /*retira chave apontada */
      Retira(i, &lista, &item);
      printf("Retirou: %d\n", item.Chave);
    }
  Imprime (lista);
  return(0);
}
