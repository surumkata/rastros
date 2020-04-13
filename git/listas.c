#include <stdio.h>
#include <stdlib.h>
#include "listas.h"
#include "logica.h"

LISTA insere_cabeca(LISTA l, void* valor){
    if (l==NULL) {
        LISTA aux = (LISTA)malloc(sizeof(Nodo));
        aux->valor = valor;
        aux->prox = NULL;
        return aux;
    }
    else{
        l->prox = insere_cabeca(l->prox, valor);
        return l;
    }
}

LISTA criar_lista(){
    LISTA l = NULL;
    return l;
}

void * devolve_cabeca(LISTA L) {
    return L->valor;
}

LISTA proximo(LISTA L) {
    return L->prox;
}

LISTA remove_cabeca(LISTA L) {
    LISTA prox = L->prox;
    free(L);
    return prox;
}

int lista_esta_vazia(LISTA L) {
    if(L->valor == NULL) return 1;
    return 0;
}

LISTA obtem_jogadas_possiveis (ESTADO *e) {
    LISTA l = criar_lista();
    COORDENADA c = obter_ultima_jogada(e);
    for(int i = 0; i <= 7; i++) {
        if (i == 0) c.linha += 1;
        if (i == 1) c.coluna += 1;
        if (i == 2 || i == 3) c.linha -= 1;
        if (i == 4 || i == 5) c.coluna -= 1 ;
        if (i == 6 || i == 7) c.linha += 1;
        if (jogada_invalida(e, c) == 0) {
            l = insere_cabeca(l,(void *) &c);
        }
    }
    return l;
}