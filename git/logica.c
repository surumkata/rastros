#include <stdio.h>
#include <stdlib.h>
#include "dados.h"

int acabar (ESTADO *e) {
    if (e->tab[0][7]==BRANCA || e->tab[7][0]==BRANCA) return 1;
    else return 0;
}

int jogada_possivel (ESTADO *e, COORDENADA c){
    if (e->tab[c.linha][c.coluna]==PRETA) return 0;
    if (e->tab[c.linha][c.coluna]==BRANCA) return 0;
    int diflinha = e->ultima_jogada.linha - c.linha;
    int difcoluna = e->ultima_jogada.coluna - c.coluna;
    if ((abs(diflinha) > 1) || (abs(difcoluna) > 1)) return 0;
    return 1;
}

int jogar(ESTADO *e, COORDENADA c) {
    if (jogada_possivel(e,c) == 1) {
        e->tab[c.linha][c.coluna]=BRANCA;
        e->tab[e->ultima_jogada.linha][e->ultima_jogada.coluna]=PRETA;
        e->ultima_jogada.linha=c.linha;
        e->ultima_jogada.coluna=c.coluna;
        printf("jogar %d %d\n", c.coluna+1, c.linha+1);
    }
    else printf ("Jogada invalida\n");
    return 1;
}


