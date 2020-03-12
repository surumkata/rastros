#define BUF_SIZE 1024

#include <stdio.h>
#include <string.h>
#include "logica.h"
#include "dados.h"

void mostrar_tabuleiro(ESTADO estado) {
    printf("==========\n");
    for (int l = 0; l <= 7; l++) {
        printf("|");
        for (int c = 0; c <= 7; c++) {
            if (estado.tab[l][c]==BRANCA) putchar ('*') ;
            else if (c==7 && l==0) putchar ('2');
            else if (c==0 && l==7) putchar ('1');
            else if (estado.tab[l][c]==PRETA) putchar ('#') ;
            else putchar ('.');
        }
        printf("| %d\n",8-l);
    }
    printf("==========\n ABCDEFGH\n");
}

int interpretador(ESTADO *e) {
    char linha[BUF_SIZE];
    char col[2], lin[2];

    mostrar_tabuleiro(*e);

    while (acabar(e)==0) {
        int n = obter_jogador_atual(e);
        printf("Vez do jogador %d\n",n);
        if(fgets(linha, BUF_SIZE, stdin) == NULL) return 0;
        if(strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", col, lin) == 2) {
            COORDENADA coord = {*col - 'a', '8' - *lin};
            jogar(e, coord);
            mostrar_tabuleiro(*e);
        }
    }

    if (acabar(e) == 1)
        printf("Parabéns jogador 1, és o grande vencedor!");
    else if (acabar(e) == -1)
        printf("Parabéns jogador 2, és o grande vencedor!");
    else if (acabar(e)== -2)
        printf("Parabéns jogador 2, o jogador 1 ficou sem jogadas. ");
    else printf("Parabéns jogador 1, o jogador 2 ficou sem jogadas. ");
    return 1;
}


