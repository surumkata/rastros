#include <stdio.h>
#include <stdlib.h>
#include "listas.h"

LISTA criar_lista(){
    LISTA l = NULL;
    return l;
}

LISTA insere_cabeca(LISTA L, void *v){
    Nodo *n = (Nodo *)malloc(sizeof(Nodo));
    n->valor = v;
    n->prox = L;
    return n;
}

void * devolve_cabeca(LISTA L){
    return L->valor;
}

LISTA proximo(LISTA L){
    LISTA l_prox = L->prox;
    return l_prox;
}

LISTA remove_cabeca(LISTA L){
    LISTA l_prox = L->prox;
    free (L);
    return l_prox;
}

int lista_esta_vazia(LISTA L){
    int resultado;
    if (L->valor == NULL) resultado = 1;
    else resultado = 0;
}
