#include <ctype.h>
#include "hash-lista.h"

#define NPAL 80

/* ================================= */
int le_palavra( FILE *fp, char *s ){
  int i = 0;
  int c;
  while ((c = fgetc( fp )) != EOF){
    if (isalpha(c)||isdigit(c))
    break;
  }
  if (c == EOF)
    return 0;
  else
    s[i++] = c;
  while (i<NPAL-1 && (c = fgetc(fp))!= EOF && (isalpha(c)||isdigit(c)))
    s[i++] = c;
  s[i] = '\0';
  return 1;
}


int main(int argc, char *argv[])
{
  TipoDicionario Tabela;
  TipoItem Elemento;
  TipoPesos p;
  TipoApontador i;
  Inicializa(Tabela);
  GeraPesos(p);

  FILE* fp;
  fp = fopen (argv[1], "rt");
  if (fp == NULL) {
    printf ("Erro na abertura do arquivo!\n");
    exit(1);
  }


  char palavra[NPAL];
  /***
  Modificar a partir deste trecho para criar lista,
  inserir palavras na lista juntamente com numero de ocorrencias da palavra,
  e imprimir a lista
   */
  while (le_palavra(fp, palavra)){
     printf("%s\n", palavra);
	strcpy(Elemento.Chave, palavra);
	Insere(Elemento, p, Tabela);
   }

  //Imprime a tabela e a lista em cada posi��o
  Imprime(Tabela);

  //Ter� que fazer uma nova fun��o para imprimir cada chave e cada valor
  //->> Imprimir chave e valor de ocorrencia

  //printf com tamanho da tabela e colisoes
  //printf("M: %d - COLISOES: %d", M, <<variavel que criou >>);
  return 0;
}
