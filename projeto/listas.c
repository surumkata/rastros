/**
@file listas.c
Módulo de listas ligadas do jogo e das funções que o manipulam
*/
#include <stdio.h>
#include <stdlib.h>
#include "logica.h"
#include <time.h>

LISTA insere_cabeca(LISTA L, void* valor)
{
    if (lista_esta_vazia(L) == 1)
    {
        LISTA aux = (LISTA)malloc(sizeof(Nodo));
        aux->valor = valor;
        aux->prox = NULL;
        return aux;
    }
    else
    {
        L->prox = insere_cabeca(L->prox, valor);
        return L;
    }
}

LISTA criar_lista()
{
    LISTA l = NULL;
    return l;
}

void * devolve_cabeca(LISTA L)
{
    return L->valor;
}

LISTA proximo(LISTA L)
{
    return L->prox;
}

LISTA remove_cabeca(LISTA L)
{
    LISTA prox = L->prox;
    free(L);
    return prox;
}

int lista_esta_vazia(LISTA L)
{
    if (L == NULL) return 1;
    else return 0;
}

int contaLista (LISTA L)
{
    int i = 0;
    while (lista_esta_vazia(proximo(L)) == 0)
    {
        i++;
        L = proximo(L);
    }
    return i+1;
}

void * procuraNaLista (LISTA L, int p)
{
    for (int i = 0; i < p; i++)
        L = remove_cabeca(L);

    return devolve_cabeca(L);
}



