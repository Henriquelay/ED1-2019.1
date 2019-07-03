#include <stdio.h>
#include <stdlib.h>
#include "FilaEstatica.h" //inclui os Protótipos

//Definição do tipo Fila
struct fila{
    int inicio, final;
    int qtd;
    struct aluno dados[MAX];
};

Fila* cria_Fila(){
    Fila *fi;
    fi = (Fila*) malloc(sizeof(struct fila));
    if(fi != NULL){
        fi->inicio = 0;
        fi->final = 0;
        fi->qtd = 0;
    }
    return fi;
}

void libera_Fila(Fila* fi){
    free(fi);
}

int consulta_Fila(Fila* fi, struct aluno *al){
    if(fi == NULL || Fila_vazia(fi))
        return 0;
    int pos = (fi->inicio+1)%MAX;
    *al = fi->dados[pos];
    return 1;
}

int desinfileira(Fila* fi, struct aluno *al){
    if(fi == NULL || Fila_vazia(fi))
        return 0;
    int pos = (fi->inicio+1)%MAX;
    fi->inicio = (fi->inicio+1)%MAX;
    *al = fi->dados[pos];
     fi->qtd--;
    return 1;
}


int insere_Fila(Fila* fi, struct aluno al){
    if(fi == NULL)
        return 0;
    if(Fila_cheia(fi))
        return 0;
    fi->dados[fi->final] = al;
    fi->final = ((fi->final+1)%MAX); 
    fi->qtd++;
    return 1;
}


int tamanho_Fila(Fila* fi){
    if(fi == NULL)
        return -1;
    return fi->qtd;
}

int Fila_cheia(Fila* fi){
    if(fi == NULL)
        return -1;
    //if (fi->inicio == (fi->final+1)%MAX)
    if (fi->qtd == MAX)
        return 1;
    else
        return 0;
}

int Fila_vazia(Fila* fi){
    if(fi == NULL)
        return -1;
    return (fi->inicio == fi->final);
}

void imprime_Aluno(Aluno a){
   printf("Matricula: %d\n",a.matricula);
   printf("Nome: %s\n",a.nome);
        printf("Notas: %f %f %f\n",a.n1,
                                   a.n2,
                                   a.n3);
        printf("-------------------------------\n");


} 

void imprime_Fila(Fila* fi){
    if(fi == NULL)
        return;
    int i = fi->inicio;
    while(i != ((fi->inicio + fi->qtd)-1) % MAX){
	imprime_Aluno(fi->dados[i]);        
	i = (i + 1) % MAX;

    }
    //Imprime o último da fila
    imprime_Aluno(fi->dados[i]);   
}

//------------------------------------------------------------------

int RemDir(Fila* fi){
    if(fi == NULL || Fila_vazia(fi))
        return 0;
    fi->final = (fi->final-1)%MAX;
    fi->qtd--;
    return 1;
}

int RemEsq(Fila* fi){
    if(fi == NULL || Fila_vazia(fi))
        return 0;
    fi->inicio = (fi->inicio+1)%MAX;
    fi->qtd--;
    return 1;
}

int InsDir(Fila* fi, struct aluno al){
    return insere_Fila(fi, al);
}

int InsEsq(Fila *fi, struct aluno al){
   if(fi == NULL) return 0;
   if(Fila_cheia(fi)) return 0;
   fi->inicio--;
   if(fi->inicio < 0)
       fi->inicio = MAX-1;
   fi->dados[fi->inicio] = al;
   fi->qtd++;
   return 1;
}
