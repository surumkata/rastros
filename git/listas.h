
#ifndef ___LISTAS_H___
#define ___LISTAS_H___

#include "dados.h"

typedef struct slist *LISTA;

typedef struct slist {
    void *valor;
    LISTA prox;
} Nodo;

LISTA criar_lista();
LISTA insere_cabeca(LISTA L, void *valor);
void * devolve_cabeca(LISTA L);
LISTA proximo(LISTA L);
LISTA remove_cabeca(LISTA L);
int lista_esta_vazia(LISTA L);

#endif //___LISTAS_H___

