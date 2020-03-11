#ifndef __DADOS_H___
#define __DADOS_H___

typedef enum {VAZIO, BRANCA, PRETA} CASA;

typedef struct
{ int coluna;
  int linha; }
  COORDENADA;

typedef struct
{ COORDENADA jogador1;
  COORDENADA jogador2; }
  JOGADA;

typedef JOGADA JOGADAS[32];

typedef struct
{ CASA tab[8][8]; // armazena informação sobre o tabuleiro;
  COORDENADA ultima_jogada; // a coordenada da última jogada;
  JOGADAS jogadas; // armazena informação sobre as jogadas;
  int num_jogadas; //indica quantas jogadas foram efetuadas;
  int jogador_atual; } //indica qual é o jogador a jogar;
  ESTADO;

#endif //__DADOS_H___
