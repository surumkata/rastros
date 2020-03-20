/**
@file interface.h
Definição da interface do jogo e das funções que o manipulam
*/

#ifndef ___INTERFACE_H___
#define ___INTERFACE_H___

#include <bits/types/FILE.h>

/**
\brief Função que desenvolve o jogo;
*/
int interpretador(ESTADO *e);
/*! Nesta função, tornámos o jogo mais interativo,
   onde aparecem mensagens a indicar a vez de um jogador e de parabenização. */

/**
\brief Função que mostra o tabuleiro com o estado atual.
*/
void mostrar_tabuleiro(ESTADO estado);
/*! Nesta função, desenhamos o tabuleiro.
   -Começamos por desenhar as partes de cima e de baixo do tabuleiro;
   -Desenhamos uma linha com as letras das colunas e uma coluna com a numeração de linhas;
   -Sempre que movemos a peça branca, esse proxima casa fica com o símbolo "*";
   -A casa preta fica com o símbolo "#";
   -Desenhamos com um "1" e com o "2" nas casas onde os seus jogadores querem chegar para ganhar a partida;
   */

void gravar_tabuleiro(ESTADO *e,FILE *filename);
void gravar (ESTADO *e, const char *filename, const char *mode);
void ler (ESTADO *e, const char *filename, const char *mode);
void mostrar_prompt (ESTADO *e);
void gravar_prompt (ESTADO *e,FILE *filename);
#endif //___INTERFACE_H___
