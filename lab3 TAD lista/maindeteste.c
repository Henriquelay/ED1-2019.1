#include "listaproduto.h"

int main(void){
    int codigo, quantidade;
    float preco;
    char nome[30];

    puts("Cod do produto:");
    scanf(" %d", &codigo);
    puts("Nome dele:");
    scanf(" %s", nome);
    puts("Preco:");
    scanf(" %f", &preco);
    puts("Quantidade:");
    scanf(" %d", &quantidade);

    tProduto produto = criaProduto(&codigo, nome, &preco, &quantidade);
    imprimeProduto(&produto);




    return 0;
}