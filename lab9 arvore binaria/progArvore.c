#include "ArvoreBinaria.h"
int main(){
    int N = 8, dados[8] = {50,100,30,20,40,45,35,37};

    NO *raiz = NULL;
    int i, deubom;
    for(i=0; i < N; i++){
        deubom = insere_No(&raiz,dados[i]);
        printf("Deubom? %d\n", deubom);
    }
    //Alterar o valor de p para testar valores que existem e não
    int p = 30;
    if (consulta_No(raiz, p))
	    printf("Achou o elemento %d\n",p);
    else
    	printf("Elemento %d nao encontrado\n", p);
	

    emOrdem_No(raiz);
    printf("\n");
    preOrdem_No(raiz);
    printf("\n");
    posOrdem_No(raiz);
    printf("\n");

    libera_No(raiz);

    return 0;
}
