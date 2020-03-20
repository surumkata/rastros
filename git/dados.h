/**
@file dados.h
Definição do estado e das funções que o manipulam
*/

#ifndef __DADOS_H___
#define __DADOS_H___

/**
\brief Refere-se ao tipo de uma casa do tabuleiro.
*/
typedef enum {VAZIO, BRANCA, PRETA} CASA;

/**
\brief Refere-se às coordenadas de uma casa do tabuleiro.
 */
typedef struct
{ int coluna;
  int linha; }
  COORDENADA;

/**
\brief Referem-se à jogada feita pelo jogador1 e pelo jogador2.
*/
typedef struct
{ COORDENADA jogador1;
  COORDENADA jogador2; }
  JOGADA;

/**
\brief Referem-se às jogadas.
*/
typedef JOGADA JOGADAS[32];

/**
\brief Referem-se ao Estado do jogo.
*/
typedef struct
{ CASA tab[8][8];           /**! armazena informação sobre o tabuleiro;*/
  COORDENADA ultima_jogada; /**! a coordenada da última jogada;*/
  JOGADAS jogadas;          /**! armazena informação sobre as jogadas;*/
  int num_jogadas;          /**! indica quantas jogadas foram efetuadas;*/
  int jogador_atual;
  int num_comandos;}      /**! indica qual é o jogador a jogar.*/
  ESTADO;

/**
\brief Função que inicializa o estado do jogo.
*/
ESTADO *inicializar_estado();
/*! Nesta função, tornamos todas as casas do tabuleiro como sendo "vazias" no inicio do jogo.
   O jogador1 encontra-se na casa e5 e é ele quem começa a jogar.*/

/**
\brief Função que obtém o jogador atual.
*/
int obter_jogador_atual(ESTADO *estado);

/**
\brief Função que obtém o numero de jogadas.
*/
int obter_numero_de_jogadas(ESTADO *estado);

/**
\brief Função que obtém o estado de uma casa de uma coordenada do tabuleiro.
*/
CASA obter_estado_casa(ESTADO *e, COORDENADA c);
/*! Nesta função, conseguimos obter uma casa através da sua linha e da sua coluna. */

/**
\brief Função que obtém a ultima jogada efetuada.
*/
COORDENADA obter_ultima_jogada(ESTADO *e);

/**
\brief Função que altera uma casa para a cor branca.
*/
void altera_para_branca (ESTADO *e, COORDENADA c);

/**
\brief Função que altera uma casa para a cor preta.
*/
void altera_para_preta (ESTADO *e, COORDENADA c);


void altera_para_vazio (ESTADO *e, COORDENADA c);

/**
\brief Função que atualiza uma jogada.
*/
void atualiza_ultima_jogada (ESTADO *e, COORDENADA c);

/**
\brief Função que atualiza um jogador.
*/
void atualiza_jog_atual (ESTADO *e);
/*! Nesta função, determinamos qual foi o jogador anterior a jogar.
   Se foi o jogador1, entao é o jogador2 a jogar (ou vice-versa). */

int obter_num_comandos(ESTADO *e);

void adic_num_jogadas (ESTADO *e);

void adic_num_comandos (ESTADO *e);

void altera_prompt (ESTADO *e, int nc, int nj, int ja);

void altera_tabuleiro (ESTADO *e, char d, COORDENADA cord);

#endif //__DADOS_H___
