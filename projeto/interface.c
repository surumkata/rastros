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


void mostrar_prompt (ESTADO *e)
{
    int num_comandos, num_jogadas, jogador;
    num_comandos = obter_num_comandos(e);
    num_jogadas = obter_numero_de_jogadas(e);
    jogador = obter_jogador_atual(e);

    printf("--------------\n");
    printf("JG[%d] #%d NJ[%d]\n",jogador, num_comandos, num_jogadas);
    printf("--------------\n");
}

void mostrar_tabuleiro(ESTADO *e)
{
    printf(" ==========\n");
    for (int lin = 0; lin <= 7; lin++)
    {
        printf(" |");
        for (int col = 0; col <= 7; col++)
        {
            COORDENADA c;
            c.linha = lin;
            c.coluna = col;
            if (obter_estado_casa(e,c) == BRANCA) putchar ('*');
            else if (col==7 && lin==0) putchar ('2');
            else if (col==0 && lin==7) putchar ('1');
            else if (obter_estado_casa(e,c) == PRETA) putchar ('#');
            else putchar ('.');
        }
        printf("| %d\n",8-lin);
    }
    printf(" ==========\n");
    printf("  ABCDEFGH\n");
    mostrar_prompt(e);
}

void movs (ESTADO *e)
{
    int n, j;
    JOGADA jgd;
    COORDENADA c1, c2;
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
            printf("0%d: %c%d %c%d\n", i+1, col1, (8 - c1.linha), col2, (8 - c2.linha));
        else
            printf("%d: %c%d %c%d\n", i+1, col1, (8 - c1.linha), col2, (8 - c2.linha));
    }
    if (j == 2)
    {
        jgd = obter_jogada(e, n);
        c1 = jgd.jogador1;
        if (n < 9)
            printf("0%d: %c%d \n", n+1, (char) (97+c1.coluna), (8 - c1.linha));
        else
            printf("%d: %c%d \n", n+1, (char) (97+c1.coluna), (8 - c1.linha));
    }
}

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
    ficheiro = fopen(filename,"w+");
    gravar_tabuleiro(e,ficheiro);
    gravar_movs (e,ficheiro);
    fclose(ficheiro);
    printf("Gravado com sucesso.\n");
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
    mostrar_tabuleiro(e);
    fclose(ficheiro);
}

int interpretador(ESTADO *e)
{
    char linha[BUF_SIZE] ,col[2], lin[2], cmd[5], file_name[50];
    int numj;

    mostrar_tabuleiro(e);
    while (acabou(e) != 1)
    {
        if(fgets(linha, BUF_SIZE, stdin) == NULL)
            return 0;
        if(strlen(linha) == 3 &&
           sscanf(linha, "%[a-h]%[1-8]", col, lin) == 2)
        {
            COORDENADA coord = {*col - 'a', '8' - *lin};
            jogar(e, coord);
            adic_num_comandos(e);
            mostrar_tabuleiro(e);
        }
        else if (sscanf(linha,"%s %[^\n]",cmd,file_name) == 2 &&
                 strcmp(cmd,"gr") == 0)
        {
            gravar(e,file_name);
            adic_num_comandos(e);
        }
        else if (sscanf(linha,"%s %[^\n]",cmd,file_name)==2 &&
                 strcmp(cmd,"ler") == 0)
        {
            ler(e,file_name);
            adic_num_comandos(e);
        }
        else if (strlen(linha) == 5 &&
                 sscanf(linha,"%s",cmd)==1 &&
                 strcmp(cmd,"movs") == 0)
        {
            movs(e);
            adic_num_comandos(e);
        }
        else if (strlen(linha) <= 7 &&
                 sscanf(linha,"%s%d",cmd,&numj)==2 &&
                 strcmp(cmd,"pos") == 0)
        {
            pos(e,numj);
            adic_num_comandos(e);
            mostrar_tabuleiro(e);
            }
        else if (strlen(linha) == 4 &&
                 sscanf(linha,"%s",cmd)==1 &&
                 strcmp(cmd,"jog") == 0)
        {
            LISTA l = obtem_jogadas_possiveis(e);
            COORDENADA c = heuristica_aleatoria(l);
            jogar(e,c);
            adic_num_comandos(e);
            mostrar_tabuleiro(e);
        }
        else if (strlen(linha) == 5 &&
                 sscanf(linha,"%s",cmd) == 1 &&
                 strcmp(cmd,"jog2") == 0)
        {
            LISTA l = obtem_jogadas_possiveis(e);
            COORDENADA c = heuristica_euclidiana(e,l);
            jogar(e,c);
            adic_num_comandos(e);
            mostrar_tabuleiro(e);
        }
        else if (strlen(linha) == 2 &&
                 sscanf(linha,"%s",cmd) == 1 &&
                 strcmp(cmd,"Q") == 0)
            return 1;
        }

    printf("Parabéns jogador %d, és o grande vencedor!\n",quem_ganhou(e));
    return 1;
}

