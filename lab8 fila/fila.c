No* inicia_No(Pessoa *p){
    if(p == NULL) return NULL;
    
    No *novono = (No*) malloc(sizeof(No));
    if(novono == NULL) return NULL;
    novono->p = p;
    novono->prox = NULL;
    return novono;
}

Fila *cria_fila(void){
    Fila *f = (Fila*) malloc(sizeof(Fila));
    if(f == NULL) return NULL;
    f->qtd = 0;
    f->ini = f->fim = NULL;
    return f;    
}

int Vazia_fila(Fila *f){
    if(f == NULL) return 1;
    return (f->qtd == 0);
}

void insere(Pessoa *pessoa, Fila *f){
    if(f == NULL || pessoa == NULL) return;
    
    No *novono = inicia_No(pessoa);
    if(Vazia_fila(f))
        f->ini = f->fim = novono;
    else{
        f->fim->prox = novono;
        f->fim = novono;
    }
    return;
}

Pessoa *retira(Fila *f){
    if(f == NULL) return NULL;
    

}
