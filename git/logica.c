#include <stdio.h>
#include "dados.h"

int acabar (ESTADO *e) {
    if (e->tab[0][7]==BRANCA || e->tab[7][0]==BRANCA) return 1;
    else return 0;
}

int jogar(ESTADO *e, COORDENADA c) {
    e->tab[c.linha][c.coluna]=BRANCA;
    e->tab[e->ultima_jogada.linha][e->ultima_jogada.coluna]=PRETA;
    e->ultima_jogada.linha=c.linha;
    e->ultima_jogada.coluna=c.coluna;
    printf("jogar %d %d\n", c.coluna+1, c.linha+1);
    return 1;
}

