#include "listahet.h"
#include <stdlib.h>
#include <string.h>


//////////////////////
#define IMOV 0;
#define MOV 1;

//////////////////////

typedef struct cliente {
    char* nome;
    int id;
} Cliente;

typedef struct movel {
    int placa, ano;
    float valor;
} Movel;

typedef struct imovel {
    int identificador, ano;
    float valor;
} Imovel;

typedef struct listahet {
    Cliente* dono;
    void* item;
    ListaHet* Prox;
    int identificador;
} ListaHet;


/*Cria lista vazia
* inputs: nenhum
* output: lista vazia
* pre-condicao: nenhuma
* pos-condicao: lista criada e vazia
*/
ListaHet* cria(void){
    ListaHet *resultado = (ListaHet*) malloc(sizeof(ListaHet));
    resultado->Prox = NULL;
    return resultado;
}

/*Cria uma estrutura do tipo Cliente
* inputs: nome do cliente e o identificador do cliente
* output: Endere�o da estrutura cliente criada
* pre-condicao: nome e id validos
* pos-condicao: estrutura cliente criada, com os campos nome e id corretamente atribuidos
*/
Cliente* cria_cliente (char* nome, int id){
    if(nome == NULL) return NULL;
    Cliente *cli = (Cliente*) malloc(sizeof(Cliente));
    cli->nome = (char*) malloc(sizeof(char) * strlen(nome));
    strcpy(cli->nome,nome);
    cli->id = id;
    return cli;
}

/*Cria uma estrutura do tipo Movel
* inputs: placa, ano de fabricacao e valor do automovel 
* output: Endere�o da estrutura movel criada
* pre-condicao: placa, ano e valor validos
* pos-condicao: estrutura movel criada
*/
Movel* cria_movel (int placa, int ano, float valor){
    Movel *mov = (Movel*) malloc(sizeof(Movel));
    mov->placa = placa;
    mov->ano = ano;
    mov->valor = valor;
    return mov;
}

/*Cria uma estrutura do tipo Imovel
* inputs: identificador, ano de construcao e o valor do imovel
* output: Endere�o da estrutura imovel criada
* pre-condicao: id, ano e valor validos
* pos-condicao: estrutura imovel criada
*/
Imovel* cria_imovel (int id, int ano, float valor){
    Imovel *imov = (Imovel*) malloc(sizeof(Imovel));
    imov->identificador = id;
    imov->ano = ano;
    imov->valor = valor;
    return imov;
}

/*Insere um item (do tipo Movel) na primeira posicao da lista 
* inputs: a lista, o cliente dono do automovel e o item a ser inserido
* output: a lista atualizada
* pre-condicao: lista, cliente e automovel validos
* pos-condicao: lista atualizada com o item inserido na primeira posicao
*/
ListaHet* insere_movel (ListaHet* lista, Cliente* dono, Movel* item){
    ListaHet *Celula = cria();
    Celula->dono = dono;
    Celula->item = item;
    
    if(lista == NULL){
        lista = Celula;
        return lista;
    }

    ListaHet* atual = lista;
    int cont = 0;

    while(atual->Prox != NULL){
        cont = atual->identificador++;
        atual = atual->Prox;
    }
    Celula->identificador = cont;

    atual->Prox = Celula;

    return lista;
}

/*Insere um item (do tipo Imovel) na primeira posicao da lista 
* inputs: a lista, o cliente dono do imovel e o item a ser inserido
* output: a lista atualizada
* pre-condicao: lista, cliente e imovel validos
* pos-condicao: lista atualizada com o item inserido na primeira posicao
*/
ListaHet* insere_imovel (ListaHet* lista, Cliente* dono, Imovel* item){
    ListaHet *Celula = cria();
    Celula->dono = cria_cliente(dono->nome, dono->id);
    Celula->item = cria_imovel(item->identificador, item->ano, item->valor);
    
    if(lista == NULL){
        return Celula;
    }

    ListaHet* atual = lista;

    while(atual->Prox != NULL)
        atual = atual->Prox;

    atual->Prox = Celula;

    return lista;
}

/*Imprime os elementos da lista. Para cada elemento da lista, deve-se imprimir os dados do Cliente, seguido dos dados do im�vel (caso o item seja um im�vel) ou dos dados do autom�vel (caso o item seja um movel)
* inputs: a lista
* output: nao tem
* pre-condicao: lista valida
* pos-condicao: lista inalterada
*/
void imprime (ListaHet* lista);

/*Retira da lista todos os itens assegurados de um dado cliente 
* inputs: a lista e o identificador do cliente
* output: lista atualizada
* pre-condicao: lista e identificador do cliente validos
* pos-condicao: lista nao contem itens do cliente cujo identificador eh id_cliente
*/
ListaHet* retira_cliente (ListaHet* lista, int id_cliente);

/*Calcula o valor total assegurado de um dado cliente (incluindo moveis e imoveis). Note que o valor assegurado depende da taxa estipulada para o tipo do item. O calculo do valor assegurado para UM dado item deve ser: valor_item*taxa_item
* inputs: a lista, o endereco do cliente, e as taxas para o calculo do valor assegurado. 
* output: valor total assegurado, que deve ser a soma dos valores assegurados de todos os itens do dado cliente
* pre-condicao: lista e identificador do cliente validos
* pos-condicao: lista inalterada
*/
float calcula_valor_assegurado (ListaHet* lista, Cliente* dono, float taxa_movel, float taxa_imovel);