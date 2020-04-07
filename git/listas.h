/**
@file listas.h
Módulo de listas ligadas do jogo e das funções que o manipulam
*/

#ifndef ___LISTAS_H___
#define ___LISTAS_H___

#include "dados.h"

/**
 * \brief Refere-se à estrutura para as listas ligadas.
 */
typedef struct slist *LISTA;

typedef struct slist {
    void *valor;
    LISTA prox;
} Nodo;

/**
 * \brief Função que cria uma lista vazia.
 * @return Uma lista l vazia
 */
LISTA criar_lista();

/**
 * \brief Função que insere um valor na cabeça da lista.
 * @param L Lista
 */
LISTA insere_cabeca(LISTA L, void *valor);

/**
 * \brief Função que devolve a cabeça da lista.
 * @param L Lista
 * @return Cabeça da lista
 */
void * devolve_cabeca(LISTA L);

/**
 * \brief Função que devolve a cauda da lista.
 * @param L Lista
 * @return Cauda da lista
 */
LISTA proximo(LISTA L);

/**
 * \brief Função que remove a cabeça da lista (libertando o espaço ocupado) e devolve a cauda.
 * @param L Lista
 * @return Cauda da lista
 */
LISTA remove_cabeca(LISTA L);

/**
 * \brief Função que nos indica se a lista é vazia.
 * @param L Lista
 * @return 1 se verdadeiro ou 0 se falso
 */
int lista_esta_vazia(LISTA L);

#endif //___LISTAS_H___

