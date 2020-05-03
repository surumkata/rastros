/**
@file logica.c
Módulo da lógica do jogo e das funções que o manipulam
*/
#include <stdio.h>
#include <stdlib.h>
#include "dados.h"
#include "listas.h"
#include <time.h>


int jogada_invalida (ESTADO *e, COORDENADA c)
{
    if (c.linha >= 0 && c.linha <= 7 && c.coluna >= 0 && c.coluna <= 7 ) {
        if (obter_estado_casa(e,c)==PRETA) return 1;
        if (obter_estado_casa(e,c)==BRANCA) return 1;

        COORDENADA uj;
        int diflinha, difcoluna;
        uj = obter_ultima_jogada(e);
        diflinha = uj.linha - c.linha;
        difcoluna = uj.coluna - c.coluna;

        if ((abs(diflinha) > 1) || (abs(difcoluna) > 1)) return 1;
        return 0;
    }
    else return 1;
}

void aux_jog_poss (COORDENADA *c, int i)
{
    if (i == 0) (*c).linha += 1;
    if (i == 1) (*c).coluna += 1;
    if (i == 2 || i == 3) (*c).linha -= 1;
    if (i == 4 || i == 5) (*c).coluna -= 1;
    if (i == 6 || i == 7) (*c).linha += 1;
}


int ha_jogadas_possiveis (ESTADO *e)
{
    COORDENADA c;
    c = obter_ultima_jogada(e);
    for (int i = 0; i <= 7; i++)
    {
        aux_jog_poss(&c,i);
        if (jogada_invalida(e, c) == 0) return 1;
    }
    return 0;
}

int acabou (ESTADO *e)
{
    if (ha_jogadas_possiveis(e) == 1)
    {
        COORDENADA c1, c2;
        c1.linha = 0; c1.coluna = 7;
        c2.linha = 7; c2.coluna = 0;
        if (obter_estado_casa(e,c1)==BRANCA || obter_estado_casa(e,c2)==BRANCA)
            return 1;
        else
            return 0;
    }
    return 1;
}

int quem_ganhou (ESTADO *e)
{
    COORDENADA c;
    c.linha = 7; c.coluna = 0;
    if (obter_estado_casa(e,c)==BRANCA) return 1;
    c.linha = 0; c.coluna = 7;
    if (obter_estado_casa(e,c)==BRANCA) return 2;
    if (obter_jogador_atual(e)==1) return 1;
    else return 2;
}


int jogar(ESTADO *e, COORDENADA c)
{
    COORDENADA uj;
    if (jogada_invalida(e,c) != 1)
    {
        uj = obter_ultima_jogada(e);
        altera_para_branca(e,c);
        altera_para_preta(e,uj);
        atualiza_ultima_jogada(e,c);
        adic_jogadas(e,c);
        adic_num_jogadas(e);
        atualiza_jog_atual(e);
    }
    else printf ("Jogada inválida, tenta outra vez!\n");
    return 1;
}

COORDENADA heuristica_aleatoria (LISTA l)
{
    int p;
    COORDENADA c;

    srand(time(NULL));
    p = rand () % contaLista(l);
    c = *(COORDENADA *) procuraNaLista(l,p);
    return c;
}

COORDENADA heuristica_euclidiana (ESTADO *e, LISTA l)
{
    int valor, melhores_pontos, pontos;
    COORDENADA c, melhor_jogada;

    if (obter_jogador_atual(e) == 1)
    {
        valor = 1;
        melhores_pontos = 15;
    }
    else
    {
        valor = -1;
        melhores_pontos = 1;
    }
    while (lista_esta_vazia(l) != 1)
    {
        c = devolve_coordenada(l);
        pontos = ((7-c.linha) + c.coluna) * valor;
        if (pontos < melhores_pontos)
        {
            melhores_pontos = pontos;
            melhor_jogada = c;
        }
        l = remove_cabeca(l);
    }
    return melhor_jogada;
}

LISTA obtem_jogadas_possiveis (ESTADO *e)
{
    LISTA l = criar_lista();
    COORDENADA c = obter_ultima_jogada(e);
    COORDENADA v[sizeof(COORDENADA)*8];

    for(int i = 0; i <= 7; i++)
    {
        aux_jog_poss (&c,i);
        if (jogada_invalida(e, c) == 0)
        {
            v[i] = c;
            l = insere_cabeca(l,(void *) &v[i]);
        }
    }
    return l;
}

void retrocede_pos (ESTADO *e, int p, int nj)
{
    COORDENADA uc = obter_ultima_jogada(e);
    altera_para_vazio(e,uc);
    if (obter_jogador_atual(e) == 2) atualiza_jog_atual(e);
    for (; nj >= p; nj--)
    {
        JOGADA j = obter_jogada(e, nj-1);
        COORDENADA j1 = j.jogador1;
        COORDENADA j2 = j.jogador2;
        if (nj == p)
        {
            if (nj == 0)
            {
                COORDENADA inicial;
                inicial.linha = 3;
                inicial.coluna = 4;
                altera_para_branca(e,inicial);
                altera_para_vazio(e, j1);
                altera_para_vazio(e, j2);
                atualiza_ultima_jogada (e,inicial);
            }
            else
            {
                altera_para_branca(e, j2);
                atualiza_ultima_jogada(e, j2);
            }
        }
        else
        {
            subt_num_jogadas(e);
            altera_para_vazio(e, j1);
            altera_para_vazio(e, j2);
        }
    }
}

void avanca_pos (ESTADO *e, int p, int nj)
{
    for (;nj < p;nj++)
    {
        JOGADA j = obter_jogada(e, nj);
        COORDENADA j1 = j.jogador1;
        COORDENADA j2 = j.jogador2;
        jogar(e,j1);
        jogar(e,j2);
    }
}

void pos (ESTADO *e, int p)
{
    int nj;
    nj = obter_numero_de_jogadas(e);

    if (p <= nj) retrocede_pos (e, p, nj);
    else avanca_pos (e, p, nj);
}
