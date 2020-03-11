#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dados.h"

#define BUF_SIZE 1024


//teste spsc

// teste23
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
    return e;
}

int jogar(ESTADO *e, COORDENADA c) {
    printf("jogar %d %d\n", c.coluna, c.linha);
    return 1;
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

void mostrar_tabuleiro(ESTADO estado) {
    for (int l = 0; l <= 7; l++) {
        for (int c = 0; c <= 7; c++) {
            if (estado.tab[l][c]==BRANCA) putchar ('*') ;
            else if (c==7 && l==0) putchar ('2');
            else if (c==0 && l==7) putchar ('1');
            else if (estado.tab[l][c]==PRETA) putchar ('#') ;
            else putchar ('.');
        }
        putchar('\n');
    }
}

int main () {
    ESTADO *e = inicializar_estado();
    mostrar_tabuleiro(*e);
    return 0;
}