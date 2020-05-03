/**
@file interface.h
Módulo da interface do jogo e das funções que o manipulam
*/

#ifndef ___INTERFACE_H___
#define ___INTERFACE_H___

#include <bits/types/FILE.h>
#include <sched.h>

/**
 * \brief Função que desenvolve o jogo. Esta função adiciona comandos que auxiliam os jogadores no que toca ao desenvolvimento do jogo.
 * @param e Apontador para o estado.
 */
int interpretador(ESTADO *e);

/**
 * \brief Função que mostra o tabuleiro. Esta função recebe um estado do jogo e desenha no terminal o tabuleiro. Desenha um '#' para casas pretas, um '*' para casas brancas, um '.' para casas vazias e o numero de jogador nas respetivas casas de vitória.
 * @param e Apontador para o estado.
 */
void mostrar_tabuleiro(ESTADO *e);

/**
 * \brief Função que mostra o prompt. Esta função recebe um estado do jogo e desenha no terminal o prompt. Desenha # (numero de comandos efetuados) JOG(jogador atual) N(numero de jogadas efetuadas).
 * @param e Apontador para o estado.
 */
void mostrar_prompt (ESTADO *e);

/**
 * \brief Função que grava o tabuleiro num ficheiro txt.
 * @param e Apontador para o estado.
 * @param f Nome do ficheiro.
 */
void gravar_tabuleiro(ESTADO *e,FILE *f);

/**
 * \brief Função que grava um estado do jogo num ficheiro txt.
 * @param e Apontador para o estado.
 * @param file_name Nome do ficheiro.
 */
void gravar (ESTADO *e, const char *file_name);

/**
 * \brief Função que lê o último estado gravado do jogo de um ficheiro txt. Esta função lê o tabuleiro e o prompt de um ficheiro e atualiza o estado atual com isso.
 * @param e Apontador para o estado.
 * @param file_name Nome do ficheiro.
 */
void ler (ESTADO *e, const char *file_name);

/**
 * \brief Função que mostra as jogadas feitas.
 * @param e Apontador para o estado.
 */
void movs (ESTADO *e);

/**
 * \brief Função que grava os movimentos feitos pelos jogadores no ficheiro .txt.
 * @param e Apontador para o estado.
 * @param file_name Nome do ficheiro.
 */
void gravar_movs (ESTADO *e, FILE *file_name);

/**
 * \brief Função auxiliar da função "ler" que conta o número de peças pretas no tabuleiro.
 * @param e Apontador para o estado.
 * @param ficheiro Apontador para um ficheiro.
 * @return Número de peças pretas.
 */
int ler_aux_pecas_pretas (ESTADO *e, FILE *ficheiro);

/**
 * \brief Função auxiliar da função "ler" que lê as jogadas finalizadas (os 2 jogadores jogaram).
 * @param e Apontador para o estado.
 * @param ficheiro Apontador para o ficheiro.
 * @param p Número de peças pretas.
 */
void ler_aux_movs (ESTADO *e, FILE *ficheiro, int p);
#endif //___INTERFACE_H___
