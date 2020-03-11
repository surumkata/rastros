#ifndef ___LOGICA_H___
#define ___LOGICA_H___

#include "dados.h"

int jogar(ESTADO *e, COORDENADA c); //Função que realiza cada jogada;
int jogada_possivel (ESTADO *e, COORDENADA c);
int acabar (ESTADO *e);             //Função boleana que verifica se o jogo acabou.

#endif //___LOGICA_H___
