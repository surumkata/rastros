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
        aux_jog_poss (&c,i);
        if (jogada_invalida(e, c) == 0) {
            l = insere_cabeca(l,(void *) &c);
        }
    }
    return l;
}

LISTA melhor_jogada (ESTADO e, LISTA l,int jogador) {
    if (lista_esta_vazia(l) == 1) {;
        return NULL;
    }
    COORDENADA c1 = *(COORDENADA *) devolve_cabeca(l);
    ESTADO e1 = e;
    jogar (&e1,c1);
    if (acabou(&e1) == 1) {
        if (quem_ganhou(&e1) == jogador) {
            l->prox = NULL;
            return l;
        }
        else {
            l = remove_cabeca(l);
            return melhor_jogada (e,l,jogador);
        }
    }
    LISTA l1 = obtem_jogadas_possiveis(&e1);
    if (melhor_jogada(e1,l1,jogador) == NULL) {
        l = remove_cabeca(l);
        return melhor_jogada (e,l,jogador);
    }
    else return melhor_jogada(e1,l1,jogador);
}

