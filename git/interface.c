#define BUF_SIZE 1024

#include <stdio.h>
#include <string.h>
#include "logica.h"
#include "dados.h"
char rastros [] = "/home/geremias/Desktop/LI2/git/rastros.txt";

void mostrar_tabuleiro(ESTADO e) {
    printf("==========\n");
    for (int lin = 0; lin <= 7; lin++) {
        printf("|");
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
        printf("| %d\n",8-lin);
    }
    printf("==========\n ABCDEFGH\n");
}
void gravar_tabuleiro(ESTADO *e,FILE *filename) {
    fprintf(filename,"==========\n");
    for (int lin = 0; lin <= 7; lin++) {
        fprintf(filename,"|");
        for (int col = 0; col <= 7; col++) {
            COORDENADA c;
            c.linha = lin;
            c.coluna = col;
            if (obter_estado_casa(&e,c)==BRANCA) fprintf (filename,"*") ;
            else if (col==7 && lin==0) fprintf (filename,"2");
            else if (col==0 && lin==7) fprintf (filename,"1");
            else if (obter_estado_casa(&e,c)==PRETA) fprintf (filename,"#") ;
            else fprintf (filename,".");
        }
        fprintf(filename,"| %d\n",8-lin);
    }
    fprintf(filename,"==========\n ABCDEFGH\n");
}

void gravar (ESTADO *e, const char *filename, const char *mode){
    FILE *ficheiro;
    ficheiro = fopen(filename,mode);
    gravar_tabuleiro(e,ficheiro);
    fclose(ficheiro);
}

void ler (ESTADO *e, const char *filename, const char *mode) {
    FILE *ficheiro;
    ficheiro = fopen(filename,mode);
    fclose(ficheiro);
}

int interpretador(ESTADO *e) {
    char linha[BUF_SIZE];
    char col[2], lin[2], a, b, c;
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
        else if (strlen(linha) == 3 && sscanf(linha,"%c%c",&a,&b)==2 && a == 'g' && b == 'r') {
            printf("teste");
            gravar(e,rastros,"w+");
        }
        else if (strlen(linha) == 4 && sscanf(linha,"%c%c%c",&a,&b,&c)==3 && a == 'l' && b == 'e' && c == 'r'){
            printf("teste");
            ler(e,rastros,"r"); }
        else if (strlen(linha) == 2 && sscanf(linha,"%c",&a)==1 && a == 'q') return 1;
    }

    if (quem_ganhou(e) == 1)
        printf("Parabéns jogador 1, és o grande vencedor!");
    else
        printf("Parabéns jogador 2, és o grande vencedor!");
    return 1;
}



