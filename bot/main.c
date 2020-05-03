/**
@file main.c
Módulo principal do bot do jogo Rastros.
*/
#include "dados.h"
#include "interface.h"
#include "logica.h"
#include <stdio.h>
int main(int argc, char *argv[])
{
    if (argc >= 2)
    {
        ESTADO *e = inicializar_estado();
        ler (e, argv[1]);
        LISTA l = obtem_jogadas_possiveis (e);
        COORDENADA c = heuristica_euclidiana (e,l);
        jogar (e,c);
        gravar (e, argv[2]);
    }
    return 0;
}
