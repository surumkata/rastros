#define BUF_SIZE 1024

#include <stdio.h>
#include <string.h>
#include "logica.h"
#include "dados.h"

void mostrar_tabuleiro(ESTADO e) {
    fprintf(stdout,"==========\n");
    for (int lin = 0; lin <= 7; lin++) {
        fprintf(stdout,"|");
        for (int col = 0; col <= 7; col++) {
            COORDENADA c;
            c.linha = lin;
            c.coluna = col;
            if (obter_estado_casa(&e,c)==BRANCA) putchar ('*') ;
            else if (col==7 && lin==0) putchar ('2');
            else if (col==0 && lin==7) putchar ('1');
            else if (obter_estado_casa(&e,c)==PRETA) putchar ('#') ;
            else putchar ('.');
        }
        fprintf(stdout,"| %d\n",8-lin);
    }
    fprintf(stdout,"==========\n ABCDEFGH\n");
}

int interpretador(ESTADO *e) {
    char linha[BUF_SIZE];
    char col[2], lin[2];

    mostrar_tabuleiro(*e);

    while (acabou(e) != 1) {
        int n = obter_jogador_atual(e);
        printf("Vez do jogador %d\n",n);
        if(fgets(linha, BUF_SIZE, stdin) == NULL) return 0;
        if(strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", col, lin) == 2) {
            COORDENADA coord = {*col - 'a', '8' - *lin};
            jogar(e, coord);
            mostrar_tabuleiro(*e);
        }
    }

    if (quem_ganhou(e) == 1)
        printf("Parabéns jogador 1, és o grande vencedor!");
    else
        printf("Parabéns jogador 2, és o grande vencedor!");
    return 1;
}


