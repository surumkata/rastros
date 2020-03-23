#define BUF_SIZE 1024

#include <stdio.h>
#include <string.h>
#include "logica.h"
#include "dados.h"
char rastros [] = "/home/spsc/Desktop/Projeto/Rastros/git/rastros.txt";
//char rastros [] = "/home/geremias/Desktop/LI2/git/rastros.txt";
//char rastros [] = "rastros.txt";

void mostrar_prompt (ESTADO *e){
    int num_comandos = obter_num_comandos(e);
    int num_jogadas = obter_numero_de_jogadas(e);
    int jogador = obter_jogador_atual(e);
    printf("# %d JOG%d N%d\n",num_comandos,jogador,num_jogadas);
}

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
void gravar_tabuleiro(ESTADO e,FILE *filename) {
    for (int lin = 0; lin <= 7; lin++) {
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
        fprintf(filename, "\n");
    }
}


void gravar (ESTADO e, const char *filename, const char *mode){
    FILE *ficheiro;
    ficheiro = fopen(filename,mode);
    gravar_tabuleiro(e,ficheiro);
    fclose(ficheiro);
}

void ler (ESTADO *e, const char *filename, const char *mode) {
    FILE *ficheiro;
    ficheiro = fopen(filename,mode);
    char d;
    COORDENADA cord;
    for (int lin = 0; lin <=7 ; lin++ ) {
        cord.linha=lin;
        for (int col = 0; col <=8 ; col++) {
            cord.coluna = col;
            fscanf(ficheiro,"%c",&d);
            if (d != '\n') {
                   altera_tabuleiro(e,d,cord);
            }
        }
    }
    mostrar_tabuleiro(*e);
    mostrar_prompt(e);
    fclose(ficheiro);
}

int interpretador(ESTADO *e) {
    char linha[BUF_SIZE];
    char col[2], lin[2], a, b, c;
    mostrar_tabuleiro(*e);
    mostrar_prompt(e);
    while (acabou(e) != 1) {
        if(fgets(linha, BUF_SIZE, stdin) == NULL) return 0;
        if(strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", col, lin) == 2) {
            COORDENADA coord = {*col - 'a', '8' - *lin};
            jogar(e, coord);
            adic_num_comandos(e);
            mostrar_tabuleiro(*e);
            mostrar_prompt(e);
        }
        else if (strlen(linha) == 3 && sscanf(linha,"%c%c",&a,&b)==2 && a == 'g' && b == 'r') {
            gravar(*e,rastros,"w+");
            printf("Gravado com sucesso.\n");
            adic_num_comandos(e);
        }
        else if (strlen(linha) == 4 && sscanf(linha,"%c%c%c",&a,&b,&c)==3 && a == 'l' && b == 'e' && c == 'r'){
            ler(e,rastros,"r");
            adic_num_comandos(e);
        }
        else if (strlen(linha) == 2 && sscanf(linha,"%c",&a)==1 && a == 'Q') return 1;
    }

    if (quem_ganhou(e) == 1)
        printf("Parabéns jogador 1, és o grande vencedor!");
    else
        printf("Parabéns jogador 2, és o grande vencedor!");
    return 1;
}



