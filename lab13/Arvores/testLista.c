#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "listaencadeada.h"

int main(int argc, char *argv[ ]){
    int N;


   int total;

    if(argc != 2){
   	 printf("Parametros incorretos. Use os parametros: "
   	 "<qtd de elementos a buscar>  \n");
   	 return -1;
  	}

    TipoLista lista;
    Produto item;

    FLVazia(&lista);

    int qtdBusca = atoi(argv[1]);

    int j=0;
    scanf("%d", &total);
    int *aux =  malloc(sizeof(int)*(total+1));

    clock_t t;
    t = clock();
    while ( 1 == scanf("%d", &N)  ){
        aux[j]= N;
        j++;
      item = criaProduto(N);
      Insere(item, &lista);


   }
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
    ImprimeLista(lista);


    printf("Carregar: %f sec\n", time_taken);

//    srand(time(0));
    srand(100);
    t = clock();
    for(j =0; j < qtdBusca; j++){
        TipoApontador p = BuscaCodigo(aux[rand() % total], &lista);
    }
    t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds

    printf("Qtd pesquisa %d: %f sec\n", qtdBusca, time_taken);
    return 0;
}
