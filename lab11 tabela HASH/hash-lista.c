#include "hash-lista.h"

void FLVazia(TipoLista *Lista)
{ Lista->Primeiro = (TipoCelula *)malloc(sizeof(TipoCelula));
    Lista->Ultimo = Lista->Primeiro; Lista->Primeiro->Prox = NULL;
}

short Vazia(TipoLista Lista)
{ return (Lista.Primeiro == Lista.Ultimo); }

void Ins(TipoItem x, TipoLista *Lista)
{ Lista->Ultimo->Prox = (TipoCelula *)malloc(sizeof(TipoCelula));
    Lista->Ultimo = Lista->Ultimo->Prox; Lista->Ultimo->Item = x;
    Lista->Ultimo->Prox = NULL;
}

void Ret(TipoApontador p, TipoLista *Lista, TipoItem *Item)
{  /* -- Obs.: o item a ser retirado o seguinte ao apontado por p -- */
    TipoApontador q;
    if (Vazia(*Lista) || p == NULL || p->Prox == NULL)
    { printf(" Erro Lista vazia ou posicao nao existe\n");
        return;
    }
    q = p->Prox; *Item = q->Item; p->Prox = q->Prox;
    if (p->Prox == NULL)
        Lista->Ultimo = p;
    free(q);
}



void GeraPesos(TipoPesos p)
{ /* Gera valores randomicos entre 1 e 10.000 */
    int i, j;
    struct timeval semente;
    /* Utilizar o tempo como semente para a funcao srand() */
    //gettimeofday(&semente, NULL);
    //srand((int)(semente.tv_sec + 1000000 * semente.tv_usec));
    /* Usando semente fixa para garantir resultados iguais*/
    srand(1000);
    for (i = 0; i < N; i++)
        for (j = 0; j < TAMALFABETO; j++)
            p[i][j] = 1 + (int)(10000.0 * rand() / (RAND_MAX + 1.0));
}

TipoIndice h(TipoChave Chave, TipoPesos p)
{ int i; unsigned int Soma = 0;
    int comp = strlen(Chave);
    for (i = 0; i < comp; i++) Soma += p[i][(unsigned int)Chave[i]];
    return (Soma % M);
}

void Inicializa(TipoDicionario T)
{ int i;
    for (i = 0; i < M; i++) FLVazia(&T[i]);
}

TipoApontador Pesquisa(TipoChave Ch, TipoPesos p, TipoDicionario T)
{ /* Obs.: TipoApontador de retorno aponta para o item anterior da lista */
    TipoIndice i;
    TipoApontador Ap;
    i = h(Ch, p);
    if (Vazia(T[i])) return NULL;  /* Pesquisa sem sucesso */
    else
    { Ap = T[i].Primeiro;
        while (Ap->Prox->Prox != NULL &&
                strncmp(Ch, Ap->Prox->Item.Chave, sizeof(TipoChave)))
            Ap = Ap->Prox;
        if (!strncmp(Ch, Ap->Prox->Item.Chave, sizeof(TipoChave)))
            return Ap;
        else return NULL;  /* Pesquisa sem sucesso */
    }
}

    void Insere(TipoItem x, TipoPesos p, TipoDicionario T)
{ if (Pesquisa(x.Chave, p, T) == NULL)
    Ins(x, &T[h(x.Chave, p)]);
    else printf(" Registro ja  esta  presente\n");
}

void Retira(TipoItem x, TipoPesos p, TipoDicionario T)
{ TipoApontador Ap; Ap = Pesquisa(x.Chave, p, T);
    if (Ap == NULL)
        printf(" Registro nao esta  presente\n");
    else Ret(Ap, &T[h(x.Chave, p)], &x);
}

void Imp(TipoLista Lista)
{ TipoApontador Aux;
    Aux = Lista.Primeiro->Prox;
    while (Aux != NULL)
    { printf("%.*s ", N, Aux->Item.Chave);
        Aux = Aux->Prox;
    }
}

void Imprime(TipoDicionario Tabela)
{ int i;
    for (i = 0; i < M; i++)
    { printf("%d: ", i);
        if (!Vazia(Tabela[i]))
            Imp(Tabela[i]);
        putchar('\n');
    }
}
