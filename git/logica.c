#include <stdio.h>
#include <stdlib.h>
#include "dados.h"



int jogada_invalida (ESTADO *e, COORDENADA c){
    if (c.linha >= 0 && c.linha <= 7 && c.coluna >= 0 && c.coluna <= 7 ) {
        if (e->tab[c.linha][c.coluna]==PRETA) return 1;
        if (e->tab[c.linha][c.coluna]==BRANCA) return 1;

        int diflinha = e->ultima_jogada.linha - c.linha;
        int difcoluna = e->ultima_jogada.coluna - c.coluna;

        if ((abs(diflinha) > 1) || (abs(difcoluna) > 1)) return 1;
        return 0;
    }
    else return 1;
}

int jogadas_possiveis (ESTADO *e){
    COORDENADA c = e->ultima_jogada;
    c.linha+=1;
    if (jogada_invalida(e,c) == 0 ) return 1;
    c.coluna+=1;
    if (jogada_invalida(e,c) == 0 ) return 1;
    c.linha-=1;
    if (jogada_invalida(e,c) == 0 ) return 1;
    c.linha-=1;
    if (jogada_invalida(e,c) == 0 ) return 1;
    c.coluna-=1;
    if (jogada_invalida(e,c) == 0 ) return 1;
    c.coluna-=1;
    if (jogada_invalida(e,c) == 0 ) return 1;
    c.linha+=1;
    if (jogada_invalida(e,c) == 0 ) return 1;
    c.linha+=1;
    if (jogada_invalida(e,c) == 0 ) return 1;
    return 0;
}

int acabar (ESTADO *e) {
    if (jogadas_possiveis(e) == 1){
        if (e->tab[0][7]==BRANCA) return -1;
        if (e->tab[7][0]==BRANCA) return 1;
        else return 0;
    }
    else if (e->jogador_atual == 1)
        return -2;
    else return 2;
}

int jogar(ESTADO *e, COORDENADA c) {
    if (jogada_invalida(e,c) == 0) {
        e->tab[c.linha][c.coluna]=BRANCA;
        e->tab[e->ultima_jogada.linha][e->ultima_jogada.coluna]=PRETA;
        e->ultima_jogada.linha=c.linha;
        e->ultima_jogada.coluna=c.coluna;
        int n = obter_jogador_atual(e);
        if (n == 1) e->jogador_atual = 2;
        else e->jogador_atual = 1;
        printf("jogar %d %d\n", c.coluna+1, c.linha+1);
    }
    else printf ("Jogada invalida\n");
    return 1;
}


