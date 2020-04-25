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
    void *valor;
    struct list *prox;
} *LISTA, Nodo;

/**
 * \brief Função que cria uma lista vazia.
 * @return Uma lista l vazia
 */
LISTA criar_lista();

/**
 * \brief Função que insere um valor na cabeça da lista.
 * @param L Lista
 */
LISTA insere_cabeca(LISTA l, void* valor);

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

/**
 * \brief Função que devolve a lista de jogadas possíveis
 * @param e Apontador para o estado
 * @return l Lista com as jogadas possíveis
 */
LISTA obtem_jogadas_possiveis (ESTADO *e);

/**
 * \brief Função que nos devolve uma lista com a melhor jogada possível
 * @param l Lista
 * @return l Lista com a melhor jogada
 */
LISTA melhor_jogada (ESTADO e, LISTA l, int jogador);

/**
 * \brief Função conta o número de elementos que estão na lista
 * @param l Lista
 * @return número de elementos
 */
int contaLista (LISTA l);

/**
 * \brief Função que insere uma coordenada na lista
 * @param L Lista
 * @param c Coordenada
 */
LISTA aux_insere_cord (LISTA l, COORDENADA c);

/**
 * \brief Função que imprime a lista
 * @param l Lista
 * @return uma lista
 */
void imprimeLista (LISTA l);

/**
 * \brief Função que indica ao jogador uma jogada aleatória possível quando o mesmo pede ajuda ao computador
 * @param L Lista de jogadas possíveis
 * @return c Coordenada de uma jogada possível, sugerida pelo computador
 */
COORDENADA heuristica_aleatoria (LISTA l);

/**
 * \brief Função que dada uma lista devolve uma coordenada
 * @param l Lista de jogadas
 * @return Coordenada
 */
COORDENADA devolve_coordenada (LISTA l);

/**
 * \brief Função que sugere uma jogada utilizando a heurística da distância euclidiana
 * @param e Apontador para o estado
 * @param l Lista de jogadas possiveis
 * @return Jogada sugerida pela heurística
 */
COORDENADA heuristica_euclidiana (ESTADO *e, LISTA l);
#endif //___LISTAS_H___








