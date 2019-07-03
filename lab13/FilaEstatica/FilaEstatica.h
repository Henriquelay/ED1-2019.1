//Arquivo FilaEstatica.h
#define MAX 5
struct aluno{
    int matricula;
    char nome[30];
    float n1,n2,n3;
};

typedef struct fila Fila;

typedef struct aluno Aluno;

/*Cria uma fila vazia, alocando dinamicamente um vetor de 5 posicoes
* inputs: nenhum
* output: fila alocada e vazia
* pre-condicao: nao tem
* pos-condicao: fila alocada e vazia*/
Fila* cria_Fila();
void libera_Fila(Fila* fi);
/* Consulta o primeiro da fila
* inputs: fila e aluno que
* output: true se operação ocorreu corretamente
* pre-condicao: Fila nao vazia
* pos-condicao: fila não alterada*/
int consulta_Fila(Fila* fi, struct aluno *al);

/* Consulta e remove da fila o primeiro da lista
* inputs: fila e aluno que
* output: true se operação ocorreu corretamente
* pre-condicao: Fila nao vazia
* pos-condicao: fila sem o primeiro elemento*/
int desinfileira(Fila* fi, struct aluno *al);

int insere_Fila(Fila* fi, struct aluno al);
//int remove_Fila(Fila* fi);


/* Retorna o tamanho da fila
* inputs: a fila de alunos
* output: Tamanho da fila
* pre-condicao: fila não é nula
* pos-condicao: não modifica fila
*/
int tamanho_Fila(Fila* fi);

/*Verfica se a fila está vazia
* inputs: a fila de alunos
* output: true se está vazia e false caso contrário
* pre-condicao: fila não é nula
* pos-condicao: não modifica fila
*/
int Fila_vazia(Fila* fi);

/*Verfica se a fila está cheia
* inputs: a fila de alunos
* output: true se está cheia e false caso contrário
* pre-condicao: fila não é nula
* pos-condicao: não modifica fila
*/
int Fila_cheia(Fila* fi);

/*Imprime os dados de todos os alunos da fila (do inicio ao fim da fila!). Imprime mensagem de fila vazia, caso a fila esteja vazia.
* inputs: a fila de alunos
* output: nenhum
* pre-condicao: fila não é nula
* pos-condicao: dados dos alunos impressos na saida padrao
*/
void imprime_Fila(Fila* fi);

//----------------------------------

int RemDir(Fila* fi);

int RemEsq(Fila* fi);

int InsDir(Fila* fi, struct aluno al);

int InsEsq(Fila *fi, struct aluno al);
