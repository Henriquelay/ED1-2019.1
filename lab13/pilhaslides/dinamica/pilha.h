#ifndef PILHA_H_
#define PILHA_H_

typedef struct tipoitem TipoItem;
typedef struct tipopilha TipoPilha;

struct tipoitem {
	int valor;
	/* outros componentes */
}; 

typedef struct celula_str {
	TipoItem Item;
	 struct celula_str* Prox;
}	Celula;

struct tipopilha {
	Celula* Fundo, Topo;
	int Tamanho;
};


TipoPilha* InicializaPilha();
void FPVazia(TipoPilha *Pilha);
int Vazia (TipoPilha* Pilha);
void Empilha (TipoItem* x, TipoPilha* Pilha);
void Desempilha (TipoPilha* Pilha, TipoItem* Item);
int Tamanho (TipoPilha* Pilha);
TipoItem* InicializaTipoItem (int n);
void Imprime (TipoPilha* pilha);


#endif /* PILHA_H_ */
