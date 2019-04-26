#include "listahet.h"



//////////////////////
#define IMOV 0
#define MOV 1
#define NOTITEM 69

//////////////////////

typedef struct cliente {
    char *nome;
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
    Cliente *dono;
    void* item;
    ListaHet *Prox;
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
Cliente* cria_cliente (char *nome, int id){
    if(nome == NULL) return NULL;
    Cliente *cli = (Cliente*) malloc(sizeof(Cliente));
    cli->nome = (char*) malloc(sizeof(char) * (strlen(nome) + 1));
    strcpy(cli->nome,nome);
    cli->id = id;
    return cli;
}

/*Dá free nos maluco*/
void libera_cliente(Cliente *cli){
    if(cli == NULL)
        return;
    if(cli->nome != NULL)
        free(cli->nome);
    free(cli);
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
ListaHet* insere_movel (ListaHet *lista, Cliente *dono, Movel *item){
    if(lista == NULL)
        return NULL;

    //Dessa vez vou tentar criar tudo por cópia
    ListaHet *inserir = cria();
    inserir->dono = cria_cliente(dono->nome, dono->id);
    inserir->item = cria_movel(item->placa, item->ano, item->valor);
    inserir->identificador = MOV; //!!!!!!

    if(lista->identificador == NOTITEM){ 
        //aqui eu preencho a cabeça da lista como se fosse a porcaria de um item normal
        //caso a lista esteja declarada e sem elementos;
        free(lista);
        lista = inserir;
        return lista;
    }

    inserir->Prox = lista;
    return inserir;
}

/*Insere um item (do tipo Imovel) na primeira posicao da lista 
* inputs: a lista, o cliente dono do imovel e o item a ser inserido
* output: a lista atualizada
* pre-condicao: lista, cliente e imovel validos
* pos-condicao: lista atualizada com o item inserido na primeira posicao
*/
ListaHet* insere_imovel (ListaHet *lista, Cliente *dono, Imovel *item){
    if(lista == NULL)
        return NULL;

    //Dessa vez vou tentar criar tudo por cópia
    ListaHet *inserir = cria();
    inserir->dono = cria_cliente(dono->nome, dono->id);
    inserir->item = cria_movel(item->identificador, item->ano, item->valor);
    inserir->identificador = IMOV; //!!!!!!

    if(lista->identificador == NOTITEM){ 
        //aqui eu preencho a cabeça da lista como se fosse a porcaria de um item normal
        //caso a lista esteja declarada e sem elementos;
        free(lista);
        lista = inserir;
        return lista;
    }

    inserir->Prox = lista;
    return inserir;
}

//filtro de impressão
void imprimeItem(ListaHet *item){
    if(item != NULL)
        switch(item->identificador){
            case MOV:
                printf("\tPlaca: %d, Ano: %d, Valor: %.2f\n_________________\n", ((Movel*)item->item)->placa, ((Movel*)item->item)->ano, ((Movel*)item->item)->valor);
            break;
            case IMOV:
                printf("\tIdentificador: %d, Ano: %d, Valor: %.2f\n_________________\n", ((Imovel*)item->item)->identificador, ((Imovel*)item->item)->ano, ((Imovel*)item->item)->valor);
            break;
            default:
                printf("#EXCUSE ME WTF!#\n");
        }
}

void imprimeCliente(Cliente *cli){
    if(cli == NULL)
        return;

    printf("Cliente: %s\nID: %d\n", cli->nome, cli->id);
}

/*Imprime os elementos da lista. Para cada elemento da lista, deve-se imprimir os dados do Cliente, seguido dos dados do im�vel (caso o item seja um im�vel) ou dos dados do autom�vel (caso o item seja um movel)
* inputs: a lista
* output: nao tem
* pre-condicao: lista valida
* pos-condicao: lista inalterada
*/
void imprime (ListaHet *lista){
    if(lista != NULL)
        if(lista->identificador == NOTITEM)
            return;

    ListaHet *selecionada = lista;

    while(selecionada != NULL){
        imprimeCliente(selecionada->dono);
        imprimeItem(selecionada);
        selecionada = selecionada->Prox;
    }
}

void removeCelula(ListaHet *selecionada){
    if(selecionada == NULL)
        return;

    libera_cliente(selecionada->dono);
    free(selecionada->item);
    free(selecionada);
}

/*Retira da lista todos os itens assegurados de um dado cliente 
* inputs: a lista e o identificador do cliente
* output: lista atualizada
* pre-condicao: lista e identificador do cliente validos
* pos-condicao: lista nao contem itens do cliente cujo identificador eh id_cliente
*/
ListaHet* retira_cliente (ListaHet *lista, int id_cliente){
    if(lista == NULL)
        return NULL;
    if(lista->identificador == NOTITEM)
        return lista;
    
    ListaHet *selecionada = lista;
    ListaHet *anterior = NULL;

    while(selecionada != NULL && selecionada->dono->id != id_cliente){
        anterior = selecionada;
        selecionada = selecionada->Prox;
    }

    if(selecionada == NULL) //não encontrou nada
        return lista;
    if(anterior == NULL)
        lista = selecionada->Prox;
    else
        anterior->Prox = selecionada->Prox;

    removeCelula(selecionada);


    // CAUTION, ~REAL PROGRAMMING~ JANK BELOW:
    selecionada = lista; //percorro pra saber se tem mais algum, se tiver, executo a função denovo
                        //é muito ineficiente, mas é oq eu consigo fazer sem dar erro de leitura
                        //com o tempo de tenho, tô morrendo de sono
                        //então ela virou meio recursiva, meio iterativa. Bosta.
    while(selecionada != NULL && selecionada->dono->id != id_cliente)
        selecionada = selecionada->Prox;
    if(selecionada != NULL) //encontrou algo
        lista = retira_cliente(lista, id_cliente);


    return lista;
}

/*Calcula o valor total assegurado de um dado cliente (incluindo moveis e imoveis). Note que o valor assegurado depende da taxa estipulada para o tipo do item. O calculo do valor assegurado para UM dado item deve ser: valor_item*taxa_item
* inputs: a lista, o endereco do cliente, e as taxas para o calculo do valor assegurado. 
* output: valor total assegurado, que deve ser a soma dos valores assegurados de todos os itens do dado cliente
* pre-condicao: lista e identificador do cliente validos
* pos-condicao: lista inalterada
*/
float calcula_valor_assegurado (ListaHet *lista, Cliente *dono, float taxa_movel, float taxa_imovel){
    if(lista == NULL || lista->identificador == NOTITEM)
        return 0;
    
    float acumulador = 0;
    ListaHet *selecionada = lista;

    while(selecionada != NULL){
        if(selecionada->dono->id == dono->id)
            switch(selecionada->identificador){
            case MOV:
                acumulador += ((Movel*)selecionada->item)->valor * taxa_movel;
            break;
            case IMOV:
                acumulador += ((Imovel*)selecionada->item)->valor * taxa_imovel;
            break;
            default:
                printf("#HOL UP!#\n");
        }

        selecionada = selecionada->Prox;
    }
    return acumulador;
}

void destroi_lista(ListaHet *lista){
    ListaHet *primeiro = NULL;
    while(lista != NULL){
        primeiro = lista;
        lista = lista->Prox;
        removeCelula(primeiro);
    }
}