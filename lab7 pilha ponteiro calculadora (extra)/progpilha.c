#include "pilha.h"

char intValido(char *str){
    for(int i = 0; str[i] != '\0'; i++)
        if(str[i] < '0' || str[i] > '9')
            return 0;
    return 1;
}

char calcula(Sentinela *p, char op){
    if(p == NULL)
        return 0;
    if(p->qtd < 2)
        return 0;

    No *no1 = desemPilha(p);
    No *no2 = desemPilha(p);
    switch(op){
        case '+':
            emPilha(p, iniciaNo(no1->valor + no2->valor));
            break;
        case '-':
            emPilha(p, iniciaNo(no1->valor - no2->valor));
            break;
        case 'x':
            emPilha(p, iniciaNo(no1->valor * no2->valor));
            break;
        case '/':
            emPilha(p, iniciaNo(no1->valor / no2->valor));
            break;
        default:
            puts("operacao invalida");
    }
    free(no1);
    free(no2);
    return 1;
}


int main(int argc, char *argv[]){
    puts("Nota: foi usado 'x' no lugar de '*' para evitar erros com comandos do linux (selecionar todos os arquivos da pasta)");
    if(argc == 0)
        return 0;

    No *no = NULL;
    Sentinela *pilha = iniciaSent();
    for(int i = 1; i < argc; i++){
        if(intValido(argv[i])){
            no = iniciaNo(atoi(argv[i]));
            if(emPilha(pilha, no))
                printf("empilhado!\n");
            else
                free(no);
            printaPilha(pilha);
        }
        else{
            if(calcula(pilha, argv[i][0]))  
                printf("calculado!\n");
            printaPilha(pilha);
        }
    }
    printaPilha(pilha);
    freePilha(pilha);
    return 0;
}
