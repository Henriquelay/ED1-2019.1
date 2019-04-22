#include "listahet.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


//////////////////////
#define IMOV 0
#define MOV 1
#define NOTITEM 69

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
    if(resultado == NULL){
        printf("DEU RUIM EM ALOCAR");
        return NULL;
    }
    resultado->Prox = NULL;
    resultado->identificador = NOTITEM;
    resultado->dono = NULL;
    resultado->item = NULL;
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
    cli->nome = (char*) malloc(sizeof(char) * (strlen(nome) + 1));
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
    if(lista == NULL || lista->Prox == NULL || dono == NULL || item == NULL)
        return NULL;

    ListaHet *Celula = cria();
    Celula->dono = dono;
    Celula->item = item;
    Celula->identificador = MOV;

    ListaHet *atual = lista->Prox;  //primeiro elemento

    while(atual->Prox != NULL)  //deveria parar no ultimo
        atual = atual->Prox;

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
    if(lista == NULL || lista->Prox == NULL || dono == NULL || item == NULL)
        return NULL;

    ListaHet *Celula = cria();
    Celula->dono = dono;
    Celula->item = item;
    Celula->identificador = IMOV;

    ListaHet *atual = lista->Prox;  //primeiro elemento

    while(atual->Prox != NULL)  //deveria parar no ultimo
        atual = atual->Prox;

    atual->Prox = Celula;

    return lista;
}
/*Imprime o Cliente*/
void imprimeCliente(Cliente *cli){
    if(cli != NULL)
        printf("Cliente: %s\nID:%d\n", cli->nome, cli->id);
}

/*Imprime o móvel/imóvel*/
void imprimeItem(ListaHet *item){
    if(item != NULL)
        switch(item->identificador){
            case MOV:
                printf("\tAno: %d\t Placa:%d\n\tValor:%.2f\n", ((Movel*)item->item)->ano, ((Movel*)item->item)->placa, ((Movel*)item->item)->valor);
            break;
            case IMOV:
                printf("\tAno: %d\t Identificador:%d\n\tValor:%.2f\n", ((Imovel*)item->item)->ano, ((Imovel*)item->item)->identificador, ((Imovel*)item->item)->valor);
            break;
            default: 
                printf("#EXCUSE ME WTF#\n");
                printf("\tNUMERO ZOADO: %d\n", item->identificador);
        }
}


/*Imprime os elementos da lista. Para cada elemento da lista, deve-se imprimir os dados do Cliente, seguido dos dados do im�vel (caso o item seja um im�vel) ou dos dados do autom�vel (caso o item seja um movel)
* inputs: a lista
* output: nao tem
* pre-condicao: lista valida
* pos-condicao: lista inalterada
*/
void imprime (ListaHet* lista){    
    if(lista == NULL || lista->Prox == NULL)
        return;
    ListaHet *atual = lista->Prox;

    while(atual != NULL){
        imprimeCliente(atual->dono);
        imprimeItem(atual);
        printf("_______________________\n");

        atual = atual->Prox;
    }
}

/*Libera todo o espaço de memoria alocado pela celula, corretamente, e retorna qual seria a próxima célula*/
ListaHet* liberaCelula(ListaHet *celula){
    if(celula != NULL){
        ListaHet *proxima = celula->Prox;
        free(celula->dono->nome);
        free(celula->dono);
        free(celula->item);
        free(celula);
        return proxima;
    }
    return NULL;
}

/*Retira da lista todos os itens assegurados de um dado cliente 
* inputs: a lista e o identificador do cliente
* output: lista atualizada
* pre-condicao: lista e identificador do cliente validos
* pos-condicao: lista nao contem itens do cliente cujo identificador eh id_cliente
*/
ListaHet* retira_cliente (ListaHet* lista, int id_cliente){
    if(lista == NULL || lista->Prox == NULL)
        return NULL;

    ListaHet *atual = lista->Prox;
    ListaHet *anterior, *proxima = NULL;

    while(atual != NULL){
        if(atual->identificador == id_cliente){
            proxima = liberaCelula(atual);
            if(anterior != NULL)
                anterior->Prox = proxima;
        }

        anterior = atual;
        atual = atual->Prox;
    }

    return lista;
}

/*Calcula o valor total assegurado de um dado cliente (incluindo moveis e imoveis). Note que o valor assegurado depende da taxa estipulada para o tipo do item. O calculo do valor assegurado para UM dado item deve ser: valor_item*taxa_item
* inputs: a lista, o endereco do cliente, e as taxas para o calculo do valor assegurado. 
* output: valor total assegurado, que deve ser a soma dos valores assegurados de todos os itens do dado cliente
* pre-condicao: lista e identificador do cliente validos
* pos-condicao: lista inalterada
*/
float calcula_valor_assegurado (ListaHet* lista, Cliente* dono, float taxa_movel, float taxa_imovel){
    if(lista == NULL)
        return 0;

    ListaHet *atual = lista;
    float acumulador = 0;

    while(atual != NULL){
        if(atual->dono->id == dono->id){
            switch(atual->identificador){
                case MOV:
                    acumulador += ((Movel*)atual->item)->valor * taxa_movel;
                break;
                case IMOV:
                    acumulador += ((Movel*)atual->item)->valor * taxa_imovel;
                break;
                default:
                    printf("AI CE TA TROLANO NE PARSA\n");
            }
        }
        atual = atual->Prox;
    }

    return acumulador;
}