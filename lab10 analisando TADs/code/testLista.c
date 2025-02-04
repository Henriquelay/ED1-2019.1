#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "listaencadeada.h"

int main(int argc, char *argv[ ]){
    int N, total;

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
//    ImprimeLista(lista);


    printf("%f ", time_taken);

    //    srand(time(0));
    srand(100);
    t = clock();

    for(j =0; j < qtdBusca; j++)
        BuscaCodigo(aux[rand() % total], &lista);

    t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds

    printf("%f\n",time_taken);

    DestroiLista(lista);
    free(aux);

    return 0;
}
