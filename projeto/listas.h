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
typedef struct list{
    /** Refere-se ao primeiro elemento da lista. */
    void *valor;
    /** Refere-se ao resto dos elementos da lista. */
    struct list *prox;
} /** Nome1 para nodo da lista */*LISTA,
  /** Nome2 para nodo da lista */ Nodo;

/**
 * \brief Função que cria uma lista vazia.
 * @return Uma lista l vazia.
 */
LISTA criar_lista();

/**
 * \brief Função que insere um elemento no início de uma lista.
 * @param l Lista.
 * @param valor Elemento a inserir.
 * @return Lista com o novo elemento inserido.
 */
LISTA insere_cabeca(LISTA l, void* valor);

/**
 * \brief Função que devolve a cabeça da lista.
 * @param L Lista.
 * @return Cabeça da lista.
 */
void * devolve_cabeca(LISTA L);

/**
 * \brief Função que devolve a cauda da lista.
 * @param L Lista.
 * @return Cauda da lista.
 */
LISTA proximo(LISTA L);

/**
 * \brief Função que remove a cabeça da lista (libertando o espaço ocupado) e devolve a cauda.
 * @param L Lista.
 * @return Cauda da lista.
 */
LISTA remove_cabeca(LISTA L);

/**
 * \brief Função que nos indica se a lista é vazia.
 * @param L Lista.
 * @return 1 se verdadeiro ou 0 se falso.
 */
int lista_esta_vazia(LISTA L);


/**
 * \brief Função conta o número de elementos que estão na lista.
 * @param L Lista.
 * @return Número de elementos.
 */
int contaLista (LISTA L);

/**
 * \brief Função que conta o número de elementos que estão na lista.
 * @param L Lista.
 * @param p Índice da lista.
 * @return Valor do índice p da lista.
 */
void * procuraNaLista (LISTA L, int p);

#endif //___LISTAS_H___






