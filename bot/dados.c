/**
@file dados.c
Definição do estado e das funções que o manipulam
*/
#include <stdlib.h>
#include "dados.h"
#include "listas.h"

ESTADO *inicializar_estado()
{
    ESTADO *e = (ESTADO *) malloc(sizeof(ESTADO));
    e->jogador_atual = 1;
    e->num_jogadas = 0;
    int l, c;

    for (l = 0; l <= 7; l++) {
        for (c = 0; c<=7; c++) {
            e->tab[l][c]= VAZIO;
        }
    }
    e->tab[3][4]=BRANCA;
    e->ultima_jogada.linha = 3;
    e->ultima_jogada.coluna = 4;
    e->num_comandos = 0;
    return e;
}

int obter_jogador_atual(ESTADO *estado)
{
    return (*estado).jogador_atual;
}

int obter_numero_de_jogadas(ESTADO *estado)
{
    return (*estado).num_jogadas;
}

CASA obter_estado_casa(ESTADO *e, COORDENADA c)
{
    int lin, col;
    lin = c.linha;
    col = c.coluna;
    CASA casa = e->tab[lin][col];
    return casa;
}

COORDENADA obter_ultima_jogada(ESTADO *e)
{
    return e->ultima_jogada;
}

int obter_num_comandos(ESTADO *e)
{
    return (*e).num_comandos;
}

void altera_para_branca (ESTADO *e, COORDENADA c)
{
    e->tab[c.linha][c.coluna]=BRANCA;
}

void altera_para_preta (ESTADO *e, COORDENADA c)
{
    e->tab[c.linha][c.coluna]=PRETA;
}

void altera_para_vazio (ESTADO *e, COORDENADA c)
{
    e->tab[c.linha][c.coluna]=VAZIO;
}

void atualiza_ultima_jogada (ESTADO *e, COORDENADA c)
{
    e->ultima_jogada = c;
}

void atualiza_jog_atual (ESTADO *e)
{
    int n;
    n = obter_jogador_atual(e);

    if (n == 1)
        e->jogador_atual = 2;
    else
        e->jogador_atual = 1;
}

void adic_num_comandos (ESTADO *e)
{
    e->num_comandos += 1;
}

void adic_num_jogadas (ESTADO *e)
{
    int j;
    j = obter_jogador_atual(e);

    if (j == 2)
        e->num_jogadas += 1;
}

void subt_num_jogadas (ESTADO *e)
{
    e->num_jogadas -= 1;
}

void altera_tabuleiro (ESTADO *e, char d, COORDENADA cord)
{
    if (d == '#')
        altera_para_preta(e,cord);
    else if (d == '*') {
        altera_para_branca(e,cord);
        atualiza_ultima_jogada(e,cord);
    }
    else altera_para_vazio(e,cord);
}

void adic_jogadas (ESTADO *e, COORDENADA c)
{
    int n, j;
    n = obter_numero_de_jogadas(e);
    j = obter_jogador_atual(e);

    if (j == 1)
        e->jogadas[n].jogador1 = c;
    else
        e->jogadas[n].jogador2 = c;
}

JOGADA obter_jogada (ESTADO *e, int i)
{
    return e->jogadas[i];
}

void start_jogador (ESTADO *e)
{
    e->jogador_atual=1;
}

void start_num_jogadas (ESTADO *e)
{
    e->num_jogadas=0;
}

COORDENADA devolve_coordenada (LISTA l)
{
    return *(COORDENADA *) devolve_cabeca(l);
}
