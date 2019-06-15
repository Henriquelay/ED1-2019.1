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

    printf("Deseja remover algum produto da lista? S/s caso queira: ");
    scanf(" %c", &maisumproduto);
    if(maisumproduto == 'S' || maisumproduto == 's'){
        do{
            printf("Deseja remover por indice ou por codigo? I/C, qualquer outro para cancelar :");
            scanf(" %c", &maisumproduto);

            if(maisumproduto == 'I'){
                int indice;
                printf("Qual o indice do produto que quer remover?");
                scanf(" %d", &indice);
                removeItemIndice(&listaProdutos, &indice);
            }

            if(maisumproduto == 'C'){
                int codigoRemover;
                printf("Qual o codigo do produto que quer remover?");
                scanf(" %d", &codigoRemover);
                removeItemIndice(&listaProdutos, &codigoRemover);
            }

            printf("Item removido!\nDigite S/s para continuar removendo produtos, qualquer outra letra para sair:");
            scanf(" %c", &maisumproduto);
            if(maisumproduto != 'S' && maisumproduto != 's')
                maisumproduto = 0;

        }while(maisumproduto);

        printf("Lista dos produtos:\n______________________________________\n");
    
        imprimeLista(&listaProdutos);
    }

    printf("\nO produto mais barato eh:\n");
    tProduto maisbarato = maisBarato(&listaProdutos);
    imprimeProduto(&maisbarato);
    
    puts("");
    return 0;
}