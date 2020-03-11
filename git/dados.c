
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
int obter_estado_casa(ESTADO *e, COORDENADA c) {
    int lin = c.linha;
    int col = c.coluna;
    return (*e).tab[lin][col];
}
