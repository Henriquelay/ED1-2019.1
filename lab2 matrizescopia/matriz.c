#include <stdio.h>
#include <stdlib.h>

#include "matriz.h"

struct matriz{
    int nLinhas, nColunas, **matriz;
};


/*Verifica e retorna se Matriz está definida e válida
* inputs: ponteiro para Matriz
* output: 1 quando está definida e 0 quando não está
* pre-condicao: -
* pos-condicao: -
*/
int estaDefinida(Matriz *mat){
    if(mat != NULL){
        if(mat->matriz != NULL){
            if(mat->matriz[0] != NULL){
                    return 1;
            } else printf("Por algum motivo, nao encontrei \"matriz[0]\".\n");
        } else printf("Por algum motivo, nao encontrei \"matriz\".");
    } else printf("Por algum motivo, nao encontrei \"mat\".");

    return 0;
}

/*Troca 2 variáveis inteiras de lugar
* inputs: variaveis a serem trocadas
* output: as variáveis trocadas
* pre-condicao: -
* pos-condicao: -
*/
void swap4(int *a, int *b, int *c, int *d){
    int holder = *a;
    *a = *b;
    *b = *c;
    *c = *d;
    *d = holder;
}

/*Inicializa uma matriz de nlinhas e ncolunas
* inputs: nlinhas (no de linhas) e ncolunas (no de colunas)
* output: ponteiro para a matriz inicializada
* pre-condicao: nlinhas e ncolunas diferentes de 0
* pos-condicao: matriz de retorno existe e contem nlinhas e ncolunas  
*/
Matriz* inicializaMatriz (int nlinhas, int ncolunas){
    Matriz *mat = (Matriz*) malloc(sizeof(Matriz));
    mat->nLinhas = nlinhas;
    mat->nColunas = ncolunas;
    mat->matriz = (int**) malloc(sizeof(int*) * mat->nLinhas);  

    for(int i = 0; i < mat->nLinhas; i++)
        mat->matriz[i] = (int*) malloc(sizeof(int) * mat->nColunas);

    return mat;
}

/*Modifica o elemento [linha][coluna] da matriz mat
* inputs: a matriz, a linha, a coluna, e o novo elemento
* output: nenhum
* pre-condicao: matriz mat existe, linha e coluna são válidos na matriz
* pos-condicao: elemento [linha][coluna] da matriz modificado
*/
void modificaElemento (Matriz* mat, int linha, int coluna, int elem){
    if(estaDefinida(mat))
        if(coluna <= mat->nColunas && linha <= mat->nLinhas)
            mat->matriz[linha][coluna] = elem;

}

/*Retorna o elemento mat[linha][coluna]
* inputs: a matriz, a linha e a coluna
* output: elemento mat[linha][coluna]
* pre-condicao: matriz mat existe, linha e coluna são válidos na matriz
* pos-condicao: mat não é modificada
*/
int recuperaElemento(Matriz* mat, int linha, int coluna){
    if(estaDefinida(mat)) return mat->matriz[linha][coluna];
    else puts("DEU MERDA");
    EXIT_FAILURE;
    return 1;
}

/*Retorna o número de colunas da matriz mat
* inputs: a matriz
* output: o número de colunas da matriz
* pre-condicao: matriz mat existe
* pos-condicao: mat não é modificada
*/
int recuperaNColunas (Matriz* mat){
    if(estaDefinida(mat)) return mat->nColunas;
    else puts("DEU MERDA");
    EXIT_FAILURE;
    return 1;
}

/*Retorna o número de linhas da matriz mat
* inputs: a matriz
* output: o número de linhas da matriz
* pre-condicao: matriz mat existe
* pos-condicao: mat não é modificada
*/
int recuperaNLinhas (Matriz* mat){
    if(estaDefinida(mat)) return mat->nLinhas;
    else puts("DEU MERDA");
    EXIT_FAILURE;
    return 1;
}

/*Retorna a matriz transposta de mat
* inputs: a matriz
* output: a matriz transposta
* pre-condicao: matriz mat existe
* pos-condicao: mat não é modificada e matriz transposta existe
*/
Matriz* transposta (Matriz* mat){
    Matriz *mat2 = inicializaMatriz(mat->nColunas, mat->nLinhas);

    if(estaDefinida(mat)){
        for(int i = 0; i < mat2->nLinhas; i++)
            for(int j = 0; j < mat2->nColunas; j++)
                mat2->matriz[i][j] = mat->matriz[j][i];
        
        return mat2;
    }else puts("DEU MERDA");
    EXIT_FAILURE;
    return NULL;
}

/*Retorna a matriz multiplicacao entre mat1 e mat2
* inputs: as matrizes mat1 e mat2
gcc -c -o progmat.o progmat.c -I. -Wall -g
* output: a matriz multiplicação
* pre-condicao: matrizes mat1 e mat2 existem, e o numero de colunas de mat1 
* correponde ao numero de linhas de mat2 
* pos-condicao: mat1 e mat2 não são modificadas e a matriz multiplicacao existe
*/
Matriz* multiplicacao (Matriz* mat1, Matriz* mat2){
    if(estaDefinida(mat1) && estaDefinida(mat2)){
        if(mat1->nColunas == mat2->nLinhas){
            Matriz *matResult = inicializaMatriz(mat1->nLinhas, mat2->nColunas);
            for(int i = 0; i < mat1->nLinhas; i++)
                for(int j = 0; j < mat2->nColunas; j++){
                    int acc = 0;
                    for(int k = 0; k < mat1->nColunas; k++)
                        acc += mat1->matriz[i][k] * mat2->matriz[k][j];
                    matResult->matriz[i][j] = acc;
                }
        return matResult;


        } else puts("Voce nao pode multiplicar essas matrizes!");
    }else {
        puts("DEU MERDA");
        EXIT_FAILURE;
        return NULL;
    }
    return NULL;
}

/*Imprime a matriz
* inputs: matriz mat
* output: nenhum
* pre-condicao: matriz mat existe  
* pos-condicao: nenhuma
*/
void imprimeMatriz(Matriz* mat){
    if(estaDefinida(mat)) 
        for(int i = 0; i < mat->nLinhas; i++){
            for(int j = 0; j < mat->nColunas; j++)  
                printf("[%d]\t", mat->matriz[i][j]);
            puts("");
        }

    else puts("DEU MERDA");
    EXIT_FAILURE;
}


/*Libera memória alocada para a matriz
* inputs: matriz mat
* output: nenhum
* pre-condicao: matriz mat existe  
* pos-condicao: toda a memória alocada para matriz foi liberada
*/
void destroiMatriz(Matriz* mat){
    if(estaDefinida(mat)){
        for(int i = 0; i < mat->nLinhas; i++)
            free(mat->matriz[i]);
        free(mat->matriz);
        free(mat);
    }
    else puts("DEU MERDA");
    EXIT_FAILURE;
}

/*  BONUS
 *
 * Rotaciona os valores da matriz NxN em 90º (como se fosse uma imagem)
 * A rotação deve ocorrer localmente, isto é, sem uso de matrizes auxiliares
* inputs: a matriz
* output: nenhum
* pre-condicao: matriz mat existe, linha e coluna são válidos e iguais
* pos-condicao: mat e rotacionada 90º
*/
void giraMatriz(Matriz* mat){
    if(estaDefinida(mat)){
        if(mat->nColunas == mat->nLinhas){
            for(int i = 0; i < mat->nLinhas / 2; i++)
                for(int j = i; j < mat->nColunas - i -1; j++)
                    swap4(&mat->matriz[i][j], &mat->matriz[j][mat->nColunas - i - 1], &mat->matriz[mat->nColunas - i - 1][mat->nColunas - j - 1], &mat->matriz[mat->nColunas - j - 1][i]);


        }else puts("Nao posso girar matrizes nao quadradas!");
    }else puts("Essa matriz n esta definida para rotacionar!");
    EXIT_FAILURE;
}