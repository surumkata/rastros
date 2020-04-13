#include <stdio.h>
#include <stdlib.h>
#include "dados.h"



int jogada_invalida (ESTADO *e, COORDENADA c){
    if (c.linha >= 0 && c.linha <= 7 && c.coluna >= 0 && c.coluna <= 7 ) {
        if (obter_estado_casa(e,c)==PRETA) return 1;
        if (obter_estado_casa(e,c)==BRANCA) return 1;

        COORDENADA uj = obter_ultima_jogada(e);
        int diflinha = uj.linha - c.linha;
        int difcoluna = uj.coluna - c.coluna;

        if ((abs(diflinha) > 1) || (abs(difcoluna) > 1)) return 1;
        return 0;
    }
    else return 1;
}

int ha_jogadas_possiveis (ESTADO *e){
    COORDENADA c = obter_ultima_jogada(e);
    for(int i = 0; i <= 7; i++) {
        if (i == 0) c.linha += 1;
        if (i == 1) c.coluna += 1;
        if (i == 2 || i == 3) c.linha -= 1;
        if (i == 4 || i == 5) c.coluna -= 1;
        if (i == 6 || i == 7) c.linha += 1;
        if (jogada_invalida(e, c) == 0) return 1;
    }
    return 0;
}

int acabou (ESTADO *e) {
    if (ha_jogadas_possiveis(e) == 1){
        COORDENADA c1, c2;
        c1.linha = 0; c1.coluna = 7;
        c2.linha = 7; c2.coluna = 0;
        if (obter_estado_casa(e,c1)==BRANCA || obter_estado_casa(e,c2)==BRANCA) return 1;
        else return 0;
    }
    return 1;
}

int quem_ganhou (ESTADO *e) {
    COORDENADA c;
    c.linha = 0; c.coluna = 7;
    if (obter_estado_casa(e,c)==BRANCA) return 2;
    c.linha = 7; c.coluna = 0;
    if (obter_estado_casa(e,c)==BRANCA) return 1;
    if (obter_jogador_atual(e)==1) return 2;
    else return 1;
}


int jogar(ESTADO *e, COORDENADA c) {
    if (jogada_invalida(e,c) != 1) {
        altera_para_branca(e,c);
        COORDENADA uj = obter_ultima_jogada(e);
        altera_para_preta(e,uj);
        atualiza_ultima_jogada(e,c);
        adic_jogadas(e,c);
        adic_num_jogadas(e);
        atualiza_jog_atual(e);
    }
    else printf ("Jogada inválida, tenta outra vez!\n");
    return 1;
}


