/**
@file dados.h
Definição do estado e das funções que o manipulam
*/

#ifndef ___DADOS_H___
#define ___DADOS_H___

#include "listas.h"

/**
\brief Refere-se ao tipo de uma casa do tabuleiro.
*/
typedef enum {VAZIO, BRANCA, PRETA} CASA;

/**
 * \brief Refere-se às coordenadas de uma casa do tabuleiro.
 */
typedef struct
{ /** refere-se a uma coluna do tabuleiro;*/
  int coluna;
  /** refere-sea uma linha do tabuleiro.*/
  int linha; }
  /** Refere-se a uma coordenada*/ COORDENADA;

/**
 * \brief Referem-se à jogada feita pelo jogador1 e pelo jogador2.
 */
typedef struct
{ /** Coordenada do jogador 1;*/
  COORDENADA jogador1;
  /** Coordenada do jogador 2.*/
  COORDENADA jogador2; }
  /** Refere-se a uma jogada*/ JOGADA;

/**
 * \brief Referem-se às jogadas.
 */
typedef JOGADA JOGADAS[32];

/**
 * \brief Refere-se ao estado do jogo.
 */
typedef struct
{ /** armazena informação sobre o tabuleiro;*/
  CASA tab[8][8];
  /** a coordenada da última jogada;*/
  COORDENADA ultima_jogada;
  /** armazena informação sobre as jogadas;*/
  JOGADAS jogadas;
  /** indica quantas jogadas foram efetuadas;*/
  int num_jogadas;
  /** indica qual é o jogador a jogar.*/
  int jogador_atual;
  /** indica quantos comandos foram efetuados.*/
  int num_comandos;}
 /** Refere-se a um estado*/  ESTADO;

/**
 * \brief Função que inicializa o estado do jogo.
 * @return Estado inicial do jogo.
 */
ESTADO *inicializar_estado();

/**
 * \brief Função que obtém o jogador atual.
 * @param e Apontador para o estado.
 * @return Jogador atual.
 */
int obter_jogador_atual(ESTADO *e);

/**
 * \brief Função que obtém o numero de jogadas.
 * @param e Apontador para o estado.
 * @return Numero de jogadas.
 */
int obter_numero_de_jogadas(ESTADO *e);

/**
 * \brief Função que obtém o estado da casa de uma coordenada.
 * @param e Apontador para o estado.
 * @param c Coordenada de uma casa.
 * @return Estado da casa.
 */
CASA obter_estado_casa(ESTADO *e, COORDENADA c);

/**
 * \brief Função que obtém a ultima jogada efetuada.
 * @param e Apontador para o estado.
 * @return Coordenada da ultima jogada efetuada.
 */
COORDENADA obter_ultima_jogada(ESTADO *e);

/**
 * \brief Função que altera o estado de uma casa de uma coordena para branca.
 * @param e Apontador para o estado.
 * @param c Coordenada de uma casa.
 */
void altera_para_branca (ESTADO *e, COORDENADA c);

/**
 * \brief Função que altera o estado de uma casa de uma coordena para preta.
 * @param e Apontador para o estado.
 * @param c Coordenada de uma casa.
 */
void altera_para_preta (ESTADO *e, COORDENADA c);

/**
 * \brief Função que altera o estado de uma casa de uma coordena para vazio.
 * @param e Apontador para o estado.
 * @param c Coordenada de uma casa.
 */
void altera_para_vazio (ESTADO *e, COORDENADA c);

/**
 * \brief Função que atualiza a ultima jogada efetuada.
 * @param e Apontador para o estado.
 * @param c Coordenada de uma casa.
 */
void atualiza_ultima_jogada (ESTADO *e, COORDENADA c);

/**
 * \brief Função que atualiza o jogador atual.
 * @param e Apontador para o estado.
 */
void atualiza_jog_atual (ESTADO *e);

/**
 * \brief Função que obtém o numero de comandos efetuados.
 * @param e Apontador para o estado.
 * @return Numero de comandos efetuados.
 */
int obter_num_comandos(ESTADO *e);

/**
 * \brief Função que adiciona 1 ao numero de jogadas efetuadas.
 * @param e Apontador para o estado.
 */
void adic_num_jogadas (ESTADO *e);

/**
 * \brief Função que adiciona 1 ao numero de comandos efetuadas.
 * @param e Apontador para o estado.
 */
void adic_num_comandos (ESTADO *e);

/**
 * \brief Função que altera o tabuleiro do jogo.
 * @param e Apontador para o estado.
 * @param d Caractere que verifica o estado de uma casa.
 * @param cord Coordenada de uma casa.
 */
void altera_tabuleiro (ESTADO *e, char d, COORDENADA cord);

/**
 * \brief Função que adiciona um movimento às jogadas de cada jogador.
 * @param e Apontador para o estado.
 * @param c Coordenada de uma casa.
 */
void adic_jogadas (ESTADO *e, COORDENADA c);

/**
 * \brief Função que dá uma jogada.
 * @param e Apontador para o estado.
 * @param i indice do numero de jogadas.
 * @return Jogada de um jogador.
 */
JOGADA obter_jogada (ESTADO *e, int i);

/**
 * \brief Função que indica que o primeiro jogador a jogar é o jogador1.
 * @param e Apontador para o estado.
 */
void start_jogador (ESTADO *e);

/**
 * \brief Função que indica que o numero de jogadas efetuadas no inicio do jogo é 0.
 * @param e Apontador para o estado.
 */
void start_num_jogadas (ESTADO *e);

/**
 * \brief Função que subtrai jogadas.
 * @param e Apontador para o estado.
 */
void subt_num_jogadas (ESTADO *e);

/**
 * \brief Função que dada uma lista devolve uma coordenada.
 * @param l Lista de jogadas.
 * @return Coordenada.
 */
COORDENADA devolve_coordenada (LISTA l);

#endif //__DADOS_H___
