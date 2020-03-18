/**
@file logica.h
Definição da lógica do jogo e das funções que o manipulam
*/

#ifndef ___LOGICA_H___
#define ___LOGICA_H___

#include "dados.h"

/**
\brief Função que realiza cada jogada;
 */
int jogar(ESTADO *e, COORDENADA c);

/**
\brief Função que verifica todas as formas consideradas como jogadas inválidas.
*/
int jogada_invalida (ESTADO *e, COORDENADA c);
/* Nesta função, o jogador só pode jogar em casas do tabuleiro (linhas 1 a 8 e colunas A a H);
                         e só pode jogar na casa imediatamente a seguir em todas as direções. */

/**
\brief Função boleana que verifica se o jogo acabou.
*/
int acabou (ESTADO *e);
/* Nesta função, verificamos se algum dos jogadores chega à casa a1 ou h8 (sem determinar quem ganha.*/

/**
\brief Função que verifica se existem jogadas possiveis.
*/
int ha_jogadas_possiveis (ESTADO *e);
/*Nesta função, verificamos se é possivel avançar uma casa em qualquer das direções.
  Caso falhe todas as condições da função "ha_jogadas_possiveis", o jogo acaba e ganhará o adversário. */

/**
\brief Função que nos indica quem ganhou.
 */
int quem_ganhou (ESTADO *e);
/* Nesta função, verificamos se o jogador chega à casa a1 (ganha o jogador1),
                          ou se o jogador chega à casa h8 (ganha o jogador2). */

#endif //___LOGICA_H___
