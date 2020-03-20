/**
@file logica.h
Módulo da lógica do jogo e das funções que o manipulam
*/

#ifndef ___LOGICA_H___
#define ___LOGICA_H___

#include "dados.h"

/**
 * \brief Função que realiza cada jogada;
 * @param e Apontador para o estado
 * @param c Coordenada da jogada
 */
int jogar(ESTADO *e, COORDENADA c);

/**
 * \brief Função boleana que verifica se uma jogada é inválida.
 * @param e Apontador para o estado
 * @param c Coordenada da jogada
 * @return 1 se verdadeiro ou 0 se falso
 */
int jogada_invalida (ESTADO *e, COORDENADA c);

/**
 * \brief Função boleana que verifica se o jogo acabou.
 * Testa se algum jogador ficou preso, senão testa se algum dos jogadores já chegou às casas a1 ou h8.
 * @param e Apontador para o estado
 * @return 1 se verdadeiro ou 0 se falso
 */
int acabou (ESTADO *e);

/**
 * \brief Função boleana que verifica se existem jogadas possíveis.
 * @param e Apontador para o estado
 * @return 1 se verdadeiro ou 0 se falso
 */
int ha_jogadas_possiveis (ESTADO *e);

/**
 * \brief Função que nos indica que jogador ganhou a partida.
 * Esta função só é chamada tendo a certeza que o jogo acabou.
 * @param e Apontador para o estado
 * @return O vencedor
 */
int quem_ganhou (ESTADO *e);

#endif //___LOGICA_H___
