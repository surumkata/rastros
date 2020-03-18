#ifndef ___LOGICA_H___
#define ___LOGICA_H___

#include "dados.h"

int jogar(ESTADO *e, COORDENADA c); //Função que realiza cada jogada;
int jogada_invalida (ESTADO *e, COORDENADA c);
int acabou (ESTADO *e);             //Função boleana que verifica se o jogo acabou.
int ha_jogadas_possiveis (ESTADO *e);
int quem_ganhou (ESTADO *e);

#endif //___LOGICA_H___
