/**
@file logica.h
Módulo da lógica do jogo e das funções que o manipulam
*/

#ifndef ___LOGICA_H___
#define ___LOGICA_H___

#include "dados.h"
#include "listas.h"

/**
 * \brief Função que realiza cada jogada.
 * @param e Apontador para o estado.
 * @param c Coordenada da jogada.
 */
int jogar(ESTADO *e, COORDENADA c);

/**
 * \brief Função boleana que verifica se uma jogada é inválida.
 * @param e Apontador para o estado.
 * @param c Coordenada da jogada.
 * @return 1 se verdadeiro ou 0 se falso.
 */
int jogada_invalida (ESTADO *e, COORDENADA c);

/**
 * \brief Função boleana que verifica se o jogo acabou. Testa se algum jogador ficou preso, senão testa se algum dos jogadores já chegou às casas a1 ou h8.
 * @param e Apontador para o estado
 * @return 1 se verdadeiro ou 0 se falso
 */
int acabou (ESTADO *e);

/**
 * \brief Função boleana que verifica se existem jogadas possíveis.
 * @param e Apontador para o estado.
 * @return 1 se verdadeiro ou 0 se falso.
 */
int ha_jogadas_possiveis (ESTADO *e);

/**
 * \brief Função que nos indica que jogador ganhou a partida. Esta função só é chamada tendo a certeza que o jogo acabou.
 * @param e Apontador para o estado.
 * @return O vencedor.
 */
int quem_ganhou (ESTADO *e);

/**
 * Função auxiliar que anda à volta da jogada anterior e vê as jogadas possíveis naquele momento.
 * @param c Coordenada da jogada anterior.
 * @param i Indice.
 */
void aux_jog_poss (COORDENADA *c, int i);

/**
 * \brief Função que sugere uma coordenada aleatória possível.
 * @param l Lista de jogadas possíveis.
 * @return c Coordenada de uma jogada possível, sugerida pelo computador.
 */
COORDENADA heuristica_aleatoria (LISTA l);

/**
 * \brief Função que sugere uma coordenada utilizando a distância euclidiana.
 * @param e Apontador para o estado.
 * @param l Lista de jogadas possiveis.
 * @return Jogada sugerida pela heurística.
 */
COORDENADA heuristica_euclidiana (ESTADO *e, LISTA l);

/**
 * \brief Função que nos devolve uma lista com as jogadas possíveis.
 * @param e Apontador para o estado.
 * @return l Lista com as jogadas possíveis.
 */
LISTA obtem_jogadas_possiveis (ESTADO *e);

/**
 * \brief Função que avança para uma certa jogada.
 * @param e Apontador para o estado.
 * @param p Indica a jogada para onde se quer avançar.
 * @param nj Número de jogadas existentes.
 */
void avanca_pos (ESTADO *e, int p, int nj);

/**
 * \brief Função que retrocede para uma certa jogada.
 * @param e Apontador para o estado.
 * @param p Indica a jogada para onde se quer retroceder.
 * @param nj Número de jogadas existentes.
 */
void retrocede_pos (ESTADO *e, int p, int nj);

/**
 * Função que permite ir para uma certa jogada.
 * @param e Apontador para o estado.
 * @param p Indica a jogada para onde se quer ir.
 */
void pos (ESTADO *e, int p);
#endif //___LOGICA_H___
