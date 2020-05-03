/**
@file interface.c
Módulo da interface do jogo e das funções que o manipulam
*/
#define BUF_SIZE 1024

#include <stdio.h>
#include <string.h>
#include "logica.h"
#include "dados.h"
#include "listas.h"


void gravar_movs (ESTADO *e, FILE *filename)
{
    int n, j;
    JOGADA jgd;
    COORDENADA c1,c2;
    char col1, col2;
    n = obter_numero_de_jogadas(e);
    j = obter_jogador_atual(e);

    for (int i = 0; i<n; i++)
    {
        jgd = obter_jogada(e,i);
        c1 = jgd.jogador1;
        c2 = jgd.jogador2;
        col1 = (char) (97 + c1.coluna);
        col2 = (char) (97 + c2.coluna);
        if (i < 9)
            fprintf(filename,"0%d: %c%d %c%d\n", i+1, col1, (8 - c1.linha), col2, (8 - c2.linha));
        else
            fprintf(filename,"%d: %c%d %c%d\n", i+1, col1, (8 - c1.linha), col2, (8 - c2.linha));
    }
    if (j == 2)
    {
        jgd = obter_jogada(e, n);
        c1 = jgd.jogador1;
        if (n < 9)
            fprintf(filename,"0%d: %c%d", n+1, (char) (97+c1.coluna), (8 - c1.linha));
        else
            fprintf(filename,"%d: %c%d", n+1, (char) (97+c1.coluna), (8 - c1.linha));
    }
}

void gravar_tabuleiro(ESTADO *e,FILE *filename)
{
    COORDENADA c;
    for (int lin = 0; lin <= 7; lin++)
    {
        for (int col = 0; col <= 7; col++)
        {
            c.linha = lin;
            c.coluna = col;
            if (obter_estado_casa(e,c)==BRANCA) fprintf (filename,"*") ;
            else if (col==7 && lin==0) fprintf (filename,"2");
            else if (col==0 && lin==7) fprintf (filename,"1");
            else if (obter_estado_casa(e,c)==PRETA) fprintf (filename,"#") ;
            else fprintf (filename,".");
        }
        fprintf(filename, "\n");
    }
    fprintf(filename, "\n");
}

void gravar (ESTADO *e, const char *filename)
{
    FILE *ficheiro;
    ficheiro = fopen(filename,"w");
    gravar_tabuleiro(e,ficheiro);
    gravar_movs (e,ficheiro);
    fclose(ficheiro);
}

int ler_aux_pecas_pretas (ESTADO *e, FILE *ficheiro)
{
    char d;
    int p=0;
    COORDENADA cord;

    for (int lin = 0; lin <=7 ; lin++)
    {
        cord.linha=lin;
        for (int col = 0; col <=8 ; col++)
        {
            cord.coluna = col;
            if (fscanf(ficheiro,"%c",&d) == 1)
            {
                if (d != '\n')
                {
                    altera_tabuleiro(e,d,cord);
                    if (d=='#') p++;
                }
            }
        }
    }

    return p;
}

void ler_aux_movs (ESTADO *e, FILE *ficheiro, int p)
{
    start_num_jogadas (e);
    start_jogador (e);

    for (int i=0; i<p/2; i++)
    {
        int c1l, c2l;
        char n1, n2, c1c, c2c;
        if (fscanf (ficheiro, "%c%c: %c%d %c%d\n", &n1, &n2, &c1c, &c1l, &c2c, &c2l) == 6)
        {
            COORDENADA cord1, cord2;
            cord1.linha=8-c1l;
            cord2.linha=8-c2l;
            cord1.coluna=(int) c1c-97;
            adic_jogadas (e, cord1);
            atualiza_jog_atual(e);
            cord2.coluna=(int) c2c-97;
            adic_jogadas (e, cord2);
            adic_num_jogadas(e);
            atualiza_jog_atual(e);
        }
    }
}

void ler (ESTADO *e, const char *filename)
{
    FILE *ficheiro;
    ficheiro = fopen(filename,"r");
    int p = ler_aux_pecas_pretas (e,ficheiro);
    if (fscanf (ficheiro, "\n") == 0)
        ler_aux_movs (e,ficheiro,p);

    if (p%2!=0)
    {
        char n1, n2, c1c;
        int c1l;
        if (fscanf (ficheiro, "%c%c: %c%d\n", &n1, &n2, &c1c, &c1l) == 4)
        {
            COORDENADA cord1;
            cord1.linha=8-c1l;
            cord1.coluna=(int)c1c-97;
            adic_jogadas(e, cord1);
            atualiza_jog_atual(e);
        }
    }
    fclose(ficheiro);
}
