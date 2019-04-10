#include "listaproduto.h"

int main(void){
    int codigo, quantidade;
    float preco;
    char nome[30], maisumproduto = 0;
    tLista listaProdutos = criaListaVazia();

    do{
    printf("\nCodigo do produto: ");
    scanf(" %d", &codigo);
    printf("Nome do produto numero %d: ", codigo);
    scanf(" %29[^\n]", nome);
    printf("Preco do(a) %s: ", nome);
    scanf(" %f", &preco);
    printf("Quantidade: ");
    scanf(" %d", &quantidade);
    printf("_________________\n\n");

    tProduto produto = criaProduto(&codigo, nome, &preco, &quantidade);
    
    imprimeProduto(&produto);
    insere(&listaProdutos, &produto);

    printf("Item inserido!\nDigite S/s para continuar adicionando produtos, qualquer outra letra para sair:");
    scanf(" %c", &maisumproduto);
    if(maisumproduto != 'S' && maisumproduto != 's')
        maisumproduto = 0;

    }while(maisumproduto);

    printf("Lista dos produtos:\n______________________________________\n");
    
    imprimeLista(&listaProdutos);

    puts("");
    return 0;
}