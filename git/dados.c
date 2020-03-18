
#include <stdlib.h>
#include "dados.h"

ESTADO *inicializar_estado() {
    ESTADO *e = (ESTADO *) malloc(sizeof(ESTADO));
    e->jogador_atual = 1;
    e->num_jogadas = 0;
    int l,c;
    for (l = 0; l <= 7; l++) {
        for (c = 0; c<=7; c++) {
            e->tab[l][c]= VAZIO;
        }
    }
    e->tab[3][4]=BRANCA;
    e->ultima_jogada.linha = 3;
    e->ultima_jogada.coluna = 4;
    return e;
}

int obter_jogador_atual(ESTADO *estado) {
    return (*estado).jogador_atual;
}
int obter_numero_de_jogadas(ESTADO *estado) {
    return (*estado).num_jogadas;
}
CASA obter_estado_casa(ESTADO *e, COORDENADA c) {
    int lin = c.linha;
    int col = c.coluna;
    CASA casa = e->tab[lin][col];
    return casa;
}

COORDENADA obter_ultima_jogada(ESTADO *e) {
    return e->ultima_jogada;
}

void altera_para_branca (ESTADO *e, COORDENADA c) {
    e->tab[c.linha][c.coluna]=BRANCA;
}

void altera_para_preta (ESTADO *e, COORDENADA c) {
    e->tab[c.linha][c.coluna]=PRETA;
}

void atualiza_ultima_jogada (ESTADO *e, COORDENADA c) {
    e->ultima_jogada = c;
}

void atualiza_jog_atual (ESTADO *e) {
    int n = obter_jogador_atual(e);
    if (n == 1) e->jogador_atual = 2;
    else e->jogador_atual = 1;
}