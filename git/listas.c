#include <stdio.h>
#include <stdlib.h>
#include "listas.h"
#include "logica.h"
#include <time.h>

LISTA insere_cabeca(LISTA L, void* valor){
    if (lista_esta_vazia(L) == 1) {
        LISTA aux = (LISTA)malloc(sizeof(Nodo));
        aux->valor = valor;
        aux->prox = NULL;
        return aux;
    }
    else{
        L->prox = insere_cabeca(L->prox, valor);
        return L;
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
    if(L == NULL) return 1;
    return 0;
}

LISTA obtem_jogadas_possiveis (ESTADO *e) {
    LISTA l = criar_lista();
    COORDENADA c = obter_ultima_jogada(e);
    COORDENADA v[sizeof(COORDENADA)*8];
    for(int i = 0; i <= 7; i++) {
        aux_jog_poss (&c,i);
        if (jogada_invalida(e, c) == 0) {
            v[i] = c;
            l = insere_cabeca(l,(void *) &v[i]);
        }
    }
    return l;
}

int contaLista (LISTA l) {
    int i = 0;
    while (lista_esta_vazia(proximo(l)) == 0) {
        i++;
        l = proximo(l);
    }
    return i+1;
}
/*
void imprimeLista (LISTA l) {
    while (lista_esta_vazia(l) == 0) {
        void * v = devolve_cabeca(l);
        COORDENADA c = * (COORDENADA *) v;
        printf("%d %d\n", c.linha, c.coluna);
        l = proximo(l);
    }
}
*/
void * procuraNaLista (LISTA l, int p) {
    for (int i = 0; i < p; i++ ) l = remove_cabeca(l);
    return devolve_cabeca(l);
}

COORDENADA devolve_coordenada (LISTA l) {
    return *(COORDENADA *) devolve_cabeca(l);
}

COORDENADA heuristica_aleatoria (LISTA l) {
    srand(time(NULL));
    int p = rand () % contaLista(l);
    COORDENADA c = *(COORDENADA *) procuraNaLista(l,p);
    return c;
}

COORDENADA heuristica_euclidiana (ESTADO *e, LISTA l)  {
    int valor, melhores_pontos, pontos;
    COORDENADA c, melhor_jogada;

    if (obter_jogador_atual(e) == 1) {
        valor = 1;
        melhores_pontos = 15;
    }
    else {
        valor = -1;
        melhores_pontos = 1;
    }
    while (lista_esta_vazia(l) != 1) {
        c = devolve_coordenada(l);
        pontos = ((7-c.linha) + c.coluna) * valor;
        if (pontos < melhores_pontos) {
            melhores_pontos = pontos;
            melhor_jogada = c;
        }
        l = remove_cabeca(l);

    }
    return melhor_jogada;
}