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

COORDENADA heuristica_euclidiana (ESTADO *e, LISTA l) {
    int valor, melhores_pontos, pontos;
    COORDENADA c, melhor_jogada;

    if (obter_jogador_atual(e) == 1) {
        valor = 1;
        melhores_pontos = 15;
    }
    else {
        valor = -1;
        melhores_pontos = 1;
    }
    while (lista_esta_vazia(l) != 1) {
        c = devolve_coordenada(l);
        pontos = ((7-c.linha) + c.coluna) * valor;
        if (pontos == melhores_pontos) {
            srand(time(NULL));
            int p = rand () % 2;
            if (p == 1) {
                melhores_pontos = pontos;
                melhor_jogada = c;
            }
        }
        if (pontos < melhores_pontos) {
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
