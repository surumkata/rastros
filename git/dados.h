#ifndef __DADOS_H___
#define __DADOS_H___

// Refere-se ao tipo de uma casa do tabuleiro.
typedef enum {VAZIO, BRANCA, PRETA} CASA;

// Refere-se às coordenadas de uma casa do tabuleiro.
typedef struct
{ int coluna;
  int linha; }
  COORDENADA;

//Referem-se à jogada feita pelo jogador1 e pelo jogador2.
typedef struct
{ COORDENADA jogador1;
  COORDENADA jogador2; }
  JOGADA;

//Referem-se às jogadas.
typedef JOGADA JOGADAS[32];

//Referem-se ao Estado do jogo.
typedef struct
{ CASA tab[8][8];           // armazena informação sobre o tabuleiro;
  COORDENADA ultima_jogada; // a coordenada da última jogada;
  JOGADAS jogadas;          // armazena informação sobre as jogadas;
  int num_jogadas;          // indica quantas jogadas foram efetuadas;
  int jogador_atual; }      // indica qual é o jogador a jogar.
  ESTADO;

//Função que inicializa o estado do jogo;
ESTADO *inicializar_estado();

int obter_jogador_atual(ESTADO *estado);        //Função que obtém o jogador atual;
int obter_numero_de_jogadas(ESTADO *estado);    //Função que obtém o numero de jogadas;
CASA obter_estado_casa(ESTADO *e, COORDENADA c); //Função que obtém o estado de uma casa de uma coordenada do tabuleiro.
COORDENADA obter_ultima_jogada(ESTADO *e);
void altera_para_branca (ESTADO *e, COORDENADA c);
void altera_para_preta (ESTADO *e, COORDENADA c);
void atualiza_ultima_jogada (ESTADO *e, COORDENADA c);
void atualiza_jog_atual (ESTADO *e);

#endif //__DADOS_H___
