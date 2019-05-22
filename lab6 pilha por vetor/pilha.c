#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct pessoa{
    char *nome, *endereco;
    int idade;
} Pessoa;

#define maxtam 10

typedef struct pilha{
    Pessoa *vetor[maxtam];
    int quantidade;
} Pilha;

Pilha* cria_pilha(){
    Pilha *pilha = (Pilha*) malloc(sizeof(Pilha));
    pilha->quantidade = 0;
    return pilha;
}

void push(Pessoa *pessoa, Pilha *pilha){
    if(pessoa == NULL || pilha == NULL)
        return;
    if(pilha->quantidade >= maxtam)
        return;
    
    pilha->vetor[pilha->quantidade] = pessoa;
    pilha->quantidade++;
}

Pessoa* pop(Pilha *pilha){
    Pessoa *pessoa = pilha->vetor[pilha->quantidade-1];
    pilha->vetor[pilha->quantidade-1] = NULL;
    pilha->quantidade--;
    return pessoa;    
}

void imprime_pessoa(Pessoa *pessoa){
    printf("Nome: %s\nEndereco: %s\nIdade:%d\n", pessoa->nome, pessoa->endereco, pessoa->idade);
}

void imprime_pilha(Pilha *pilha){
    for(int i = pilha->quantidade; i > 0; i--){
        imprime_pessoa(pilha->vetor[i-1]);
        puts("--");
    }
}

void destroi_pessoa(Pessoa *pessoa){
    free(pessoa->nome);
    free(pessoa->endereco);
    free(pessoa);
}

Pilha* destroi_pilha(Pilha *pilha){
    for(int i = pilha->quantidade; i > 0; i--){
        destroi_pessoa(pilha->vetor[i-1]);
    }
    free(pilha);
    return pilha; //deveria ser NULL 
}

Pessoa* inicializaPessoa(char *nome, int idade, char *endereco){
    Pessoa *pessoa = (Pessoa*) malloc(sizeof(Pessoa));
    pessoa->nome = (char*) malloc(sizeof(char) * (strlen(nome) + 1));
    strcpy(pessoa->nome, nome);
    pessoa->endereco = (char*) malloc(sizeof(char) * (strlen(endereco) + 1));
    strcpy(pessoa->endereco, endereco);
    pessoa->idade = idade;
    return pessoa;
}
